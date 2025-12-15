/*
 * Copyright (C) 2022-2025 Timo Früh
 * Full copyright notice in ../src/main.cpp
 *
 */


#ifndef COORD_CONV
#define COORD_CONV

namespace coord {

    // Define lv95 datatype.
    struct lv95 {
        double e;
        double n;
    };

    // Define wgs84 datatype.
    struct wgs84 {
        double e;
        double n;
    };

    // Declare function to convert lv95 to wgs84 for later definition.
    wgs84 lv95ToWgs84(const lv95& input_coord);

    // Declare function to convert wgs84 to lv95 for later definition.
    lv95 wgs84ToLv95(const wgs84& input_coord);

}
#endif
