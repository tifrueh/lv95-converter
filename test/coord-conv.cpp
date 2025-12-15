/*
 * Copyright (C) 2022-2025 Timo Früh
 * Full copyright notice in ../src/main.cpp
 *
 */


#include <cstdio>
#include "coord-conv.hpp"

#define ANSI_GOOD "\033[32m"
#define ANSI_BAD  "\033[31m"
#define ANSI_RST  "\033[0m"

int main(void) {
    std::printf("%sGOOD%s\nRST\n%sBAD%s\n", ANSI_GOOD, ANSI_RST, ANSI_BAD, ANSI_RST);
    return 0;
}
