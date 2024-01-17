// Copyright (C) 2022-2024 Timo Früh
// Full copyright notice in main.cpp


#include <math.h>
#include "coord-conv.hpp"

// function to convert lv95 to wgs84
coord::wgs84 coord::lv95ToWgs84(const coord::lv95& input_coord) {

	/* convert the projection coordinates E (easting) and N (northing) 
	in LV95 (or y / x in LV03) into the civilian system (Bern = 0 / 0) 
	and express in the unit [1000 km] */
	double y_prime = (input_coord.e - 2600000.0) / 1000000.0;
	double x_prime = (input_coord.n - 1200000.0) / 1000000.0;

	// calculate longitude lambda and latitude phi in the unit [10000"]:
	double lambda_prime = 2.6779094
		+ 4.728982 * y_prime
		+ 0.791484 * y_prime * x_prime
		+ 0.1306 * y_prime * pow(x_prime, 2.0)
		- 0.0436 * pow(y_prime, 3.0);

	double phi_prime = 16.9023892
		+ 3.238272 * x_prime
		- 0.270978 * pow(y_prime, 2.0)
		- 0.002528 * pow(x_prime, 2.0)
		- 0.0447 * pow(y_prime, 2.0) * x_prime
		- 0.0140 * pow(x_prime, 3.0);

	// convert longitude and latitude to the unit [°]
	double lambda = lambda_prime * 100.0 / 36.0;
	double phi = phi_prime * 100.0 / 36.0;

	// return the result as wgs84 coordinates
	wgs84 result;
	result.e = lambda;
	result.n = phi;

	return result;
}

coord::lv95 coord::wgs84ToLv95(const coord::wgs84& input_coord) {

	// convert the ellipsoidal latitudes phi and longitudes lambda into arcseconds ["]
	double lambda = input_coord.e * 3600;
	double phi = input_coord.n * 3600;

	/* calculate the auxiliary values (differences of latitude and longitude 
	relative to Bern in the unit [10000"]): */
	double phi_prime = (phi - 169028.66) / 10000;
	double lambda_prime = (lambda - 26782.5) / 10000;

	// calculate projection coordinates in LV95 (E, N)
	double e = 2600072.37
		+ 211455.93 * lambda_prime
		- 10938.51 * lambda_prime * phi_prime
		- 0.36 * lambda_prime * pow(phi_prime, 2)
		- 44.54 * pow(lambda_prime, 3);

	double n = 1200147.07
		+ 308807.95 * phi_prime
		+ 3745.25 * pow(lambda_prime, 2)
		+ 76.63 * pow(phi_prime, 2)
		- 194.56 * pow(lambda_prime, 2) * phi_prime
		+ 119.79 * pow(phi_prime, 3);

	// return the result as lv95 coordinates
	lv95 result;
	result.e = e;
	result.n = n;

	return result;
}
