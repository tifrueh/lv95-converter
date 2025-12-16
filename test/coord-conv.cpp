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

// Define useful constants.
#define COORD_CNT 8
#define CMP_ATOL 1.0e-8

/*
 * Globals
 *
 */

// Define LV95 test vectors.
static const coord::coordinates lv95_test_inp[COORD_CNT] = {
    { coord::LV95, 0.0, 0.0 },
    { coord::LV95, 0.0, 0.0 },
    { coord::LV95, 0.0, 0.0 },
    { coord::LV95, 0.0, 0.0 },
    { coord::LV95, 0.0, 0.0 },
    { coord::LV95, 0.0, 0.0 },
    { coord::LV95, 0.0, 0.0 },
    { coord::LV95, 0.0, 0.0 }
};

static const coord::coordinates lv95_test_exp[COORD_CNT] = {
    { coord::WGS84, 0.0, 0.0 },
    { coord::WGS84, 0.0, 0.0 },
    { coord::WGS84, 0.0, 0.0 },
    { coord::WGS84, 0.0, 0.0 },
    { coord::WGS84, 0.0, 0.0 },
    { coord::WGS84, 0.0, 0.0 },
    { coord::WGS84, 0.0, 0.0 },
    { coord::WGS84, 0.0, 0.0 }
};

// Define WGS84 test vectors.
static const coord::coordinates wgs84_test_inp[COORD_CNT] = {
    { coord::WGS84, 0.0, 0.0 },
    { coord::WGS84, 0.0, 0.0 },
    { coord::WGS84, 0.0, 0.0 },
    { coord::WGS84, 0.0, 0.0 },
    { coord::WGS84, 0.0, 0.0 },
    { coord::WGS84, 0.0, 0.0 },
    { coord::WGS84, 0.0, 0.0 },
    { coord::WGS84, 0.0, 0.0 }
};

static const coord::coordinates wgs84_test_exp[COORD_CNT] = {
    { coord::LV95, 0.0, 0.0 },
    { coord::LV95, 0.0, 0.0 },
    { coord::LV95, 0.0, 0.0 },
    { coord::LV95, 0.0, 0.0 },
    { coord::LV95, 0.0, 0.0 },
    { coord::LV95, 0.0, 0.0 },
    { coord::LV95, 0.0, 0.0 },
    { coord::LV95, 0.0, 0.0 }
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
static void test(const coord::coordinates &test, const coord::coordinates &exp, coord::coordinates (*f)(const coord::coordinates& input_coord)) {
    test_cnt++;
    coord::coordinates recv = f(test);
    bool isequal = compare(exp, recv, CMP_ATOL);
    if (isequal) {
        good_cnt++;
        std::printf("%sTest %d: GOOD%s\n", ANSI_GOOD, test_cnt, ANSI_RST);
        return;
    } else {
        std::printf("%sTest %d: BAD%s\n", ANSI_BAD, test_cnt, ANSI_RST);
        std::printf("    expected: %d E %f N %f\n", exp.f, exp.e, exp.n);
        std::printf("    received: %d E %f N %f\n", recv.f, recv.e, recv.n);
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
        test(lv95_test_inp[i], lv95_test_exp[i], &coord::lv95ToWgs84);
    }
    for (int i = 0; i < COORD_CNT; i++) {
        test(wgs84_test_inp[i], wgs84_test_exp[i], &coord::wgs84ToLv95);
    }
    bool passed = good_cnt == test_cnt;
    std::string clr = (passed) ? (ANSI_GOOD) : (ANSI_BAD);
    std::printf("\nPASSED %s[%d/%d]%s\n", clr.c_str(), good_cnt, test_cnt, ANSI_RST);
    return !passed;
}
