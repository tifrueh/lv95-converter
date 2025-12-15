/*
 * Copyright (C) 2022-2025 Timo Früh
 * Full copyright notice in main.cpp
 *
 */

#include "coord-conv.hpp"

using namespace coord;

// Function to convert lv95 to wgs84.
coordinates coord::lv95ToWgs84(const coordinates& input_coord) {

  // Convert the projection coordinates E (easting) and N (northing) in LV95
  // (or y / x in LV03) into the civilian system (Bern = 0 / 0) and express in
  // the unit [1000 km].
  double y_prime = (input_coord.e - 2600000.0) / 1000000.0;
  double x_prime = (input_coord.n - 1200000.0) / 1000000.0;

  // Calculate longitude lambda and latitude phi in the unit [10000"].
  double lambda_prime =
      2.6779094 + 4.728982 * y_prime + 0.791484 * y_prime * x_prime +
      0.1306 * y_prime * std::pow(x_prime, 2.0) - 0.0436 * std::pow(y_prime, 3.0);

  double phi_prime =
      16.9023892 + 3.238272 * x_prime - 0.270978 * std::pow(y_prime, 2.0) -
      0.002528 * std::pow(x_prime, 2.0) - 0.0447 * std::pow(y_prime, 2.0) * x_prime -
      0.0140 * std::pow(x_prime, 3.0);

  // Convert longitude and latitude to the unit [°].
  double lambda = lambda_prime * 100.0 / 36.0;
  double phi = phi_prime * 100.0 / 36.0;

  // Return the result as wgs84 coordinates.
  coordinates result;
  result.f = WGS84;
  result.e = lambda;
  result.n = phi;

  return result;
}

coordinates coord::wgs84ToLv95(const coordinates& input_coord) {

    // Convert the ellipsoidal latitudes phi and longitudes lambda into
    // arcseconds ["].
    double lambda = input_coord.e * 3600;
    double phi = input_coord.n * 3600;

    // Calculate the auxiliary values (differences of latitude and longitude
    // relative to Bern in the unit [10000"]).
    double phi_prime = (phi - 169028.66) / 10000;
    double lambda_prime = (lambda - 26782.5) / 10000;

    // Calculate projection coordinates in LV95 (E, N).
    double e = 2600072.37
        + 211455.93 * lambda_prime
        - 10938.51 * lambda_prime * phi_prime
        - 0.36 * lambda_prime * std::pow(phi_prime, 2)
        - 44.54 * std::pow(lambda_prime, 3);

    double n = 1200147.07
        + 308807.95 * phi_prime
        + 3745.25 * std::pow(lambda_prime, 2)
        + 76.63 * std::pow(phi_prime, 2)
        - 194.56 * std::pow(lambda_prime, 2) * phi_prime
        + 119.79 * std::pow(phi_prime, 3);

    // Return the result as lv95 coordinates.
    coordinates result;
    result.f = LV95;
    result.e = e;
    result.n = n;

    return result;
}

static void print_mro(const coordinates& c) {

    std::string fmt;
    switch (c.f) {
    case LV95:
        fmt = "lv95";
    case WGS84:
        fmt = "wgs84";
    }

    std::cout
        << "{ "
        << "\"format\": \"" << fmt << "\", "
        << "\"e\": " << c.e << ", "
        << "\"n\": " << c.n
        << " }\n";
}

static void print_hro(const coordinates& c) {

    std::string fmt;
    switch (c.f) {
    case LV95:
        fmt = "LV95";
    case WGS84:
        fmt = "WGS84";
    }

    std::cout << "Coordinates in " << fmt << ": E " << c.e << " N " << c.n << "\n";
}

void coord::print(const coordinates& c, bool mro) {
    if (mro) {
        print_mro(c);
    } else {
        print_hro(c);
    }
}
