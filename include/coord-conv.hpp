/*
 * Copyright (C) 2022-2025 Timo Früh
 * Full copyright notice in ../src/main.cpp
 *
 */


#ifndef COORD_CONV
#define COORD_CONV

#include <cmath>
#include <string>
#include <iostream>

namespace coord {

    // Define coordinate format enumerator.
    enum fmt {
        LV95,
        WGS84
    };

    // Define coordinate datatype.
    struct coordinates {
        fmt f;
        double e;
        double n;
    };

    // Declare function to convert lv95 to wgs84.
    coordinates lv95ToWgs84(const coordinates& input_coord);

    // Declare function to convert wgs84 to lv95.
    coordinates wgs84ToLv95(const coordinates& input_coord);

    // Print coordinates.
    void print(const coordinates& input_coord, bool mro);

}
#endif
