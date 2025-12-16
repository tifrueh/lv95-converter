/*
 * Copyright (C) 2022-2025 Timo Früh
 * Full copyright notice in ../src/main.cpp
 *
 */


#include <cstdio>
#include "coord-conv.hpp"

/*
 * Macros
 *
 */

// Define useful ANSI color codes.
#define ANSI_GOOD "\033[32m"
#define ANSI_BAD  "\033[31m"
#define ANSI_RST  "\033[0m"

// Define amount of test coordinate sets.
#define COORD_CNT 8

// Define absolute tolerances for equality.
// Note: These tolerances allow for errors of about 1 m and 1 " for LV95 and
// WGS84, respectively. This *roughly* corresponds to the expected errors of
// the used formulae, but is a bit more pessimistic.
#define LV95_ATOL 1.0
#define WGS84_ATOL 2.0e-4

/*
 * Globals
 *
 */

// Define test vectors.
static const coord::coordinates lv95_vec[COORD_CNT] = {
    { coord::LV95, 2598633.81, 1200386.67 }, // Bern.
    { coord::LV95, 2683741.14, 1247865.17 }, // The HG building of ETHZ.
    { coord::LV95, 2680704.65, 1251418.28 }, // ETHZ Hönggerberg.
    { coord::LV95, 2533079.41, 1152606.25 }, // EPFL.
    { coord::LV95, 2493047.22, 1120972.75 }, // CERN.
    { coord::LV95, 2633205.57, 1087349.63 }, // The Dufourspitze.
    { coord::LV95, 2656866.36, 1173854.39 }, // The Reichenbachfall.
    { coord::LV95, 2687820.90, 1202641.59 } // The Rütli.
};

static const coord::coordinates wgs84_vec[COORD_CNT] = {
    { coord::WGS84, 7.420685, 46.954559 },
    { coord::WGS84, 8.547478, 47.376301 },
    { coord::WGS84, 8.507916, 47.408634 },
    { coord::WGS84, 6.566525, 46.521400 },
    { coord::WGS84, 6.052204, 46.231674 },
    { coord::WGS84, 7.866757, 45.936924 },
    { coord::WGS84, 8.182360, 46.713474 },
    { coord::WGS84, 8.592686, 46.969040 }
};

// Define global counters.
static int test_cnt = 0;
static int good_cnt = 0;

/*
 * Helpers
 *
 */

// Check if two sets of coordinates are close enough to be equal.
static bool compare(const coord::coordinates &a, const coord::coordinates &b, double atol) {

    if (a.f != b.f) {
        return false;
    }

    if (std::abs(a.e - b.e) > atol) {
        return false;
    }

    if (std::abs(a.n - b.n) > atol) {
        return false;
    }

    return true;
}

// Run a test.
static void test(const coord::coordinates &test, const coord::coordinates &exp, coord::coordinates (*f)(const coord::coordinates& input_coord), double atol) {
    test_cnt++;
    coord::coordinates recv = f(test);
    bool isequal = compare(exp, recv, atol);
    if (isequal) {
        good_cnt++;
        std::printf("%sTest %2d: GOOD%s\n", ANSI_GOOD, test_cnt, ANSI_RST);
        return;
    } else {
        std::printf("%sTest %2d: BAD%s\n", ANSI_BAD, test_cnt, ANSI_RST);
        std::printf("    expected: ");
        coord::print(exp, true);
        std::printf("    received: ");
        coord::print(recv, true);
        return;
    }
}

/*
 * Main Functions
 *
 */

// Run main tests.
int main(void) {
    for (int i = 0; i < COORD_CNT; i++) {
        test(lv95_vec[i], wgs84_vec[i], &coord::lv95ToWgs84, WGS84_ATOL);
    }
    for (int i = 0; i < COORD_CNT; i++) {
        test(wgs84_vec[i], lv95_vec[i], &coord::wgs84ToLv95, LV95_ATOL);
    }
    bool passed = good_cnt == test_cnt;
    std::string clr = (passed) ? (ANSI_GOOD) : (ANSI_BAD);
    std::printf("\nPASSED %s[%d/%d]%s\n", clr.c_str(), good_cnt, test_cnt, ANSI_RST);
    return !passed;
}
