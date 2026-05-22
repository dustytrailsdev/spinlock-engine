#pragma once

#include <cstdio>
#include <cstdlib>

// Debug flag
#ifndef DEBUG_BUILD
    #define DEBUG_BUILD 1
#endif

// Debug break
#if defined(_MSC_VER)
    #define DEBUG_BREAK() __debugbreak()
#elif defined(__clang__) || defined(__GNUC__)
    #define DEBUG_BREAK() __builtin_trap()
#else
    #include <csignal>
    #define DEBUG_BREAK() std::raise(SIGTRAP)
#endif

// Debug assert, removed in release builds
// fmt must be a string literal
#if DEBUG_BUILD
    #define ASSERT(cond, fmt, ...) \
    do { \
        if (!(cond)) { \
            ::fprintf(stderr, \
                "Assertion failed: [%s:%d] %s\n" \
                "  Condition: %s\n" \
                "  Message: " fmt "\n", \
                __FILE__, __LINE__, __FUNCTION__, #cond, \
                ##__VA_ARGS__); \
            std::fflush(stderr); \
            DEBUG_BREAK(); \
            ::abort(); \
        } \
    } while (0)
#else
    #define ASSERT(cond, fmt, ...) ((void)0)
#endif

// Fatal assert, included in release builds
// fmt must be a string literal
#define FATAL_ASSERT(fmt, ...) \
    do { \
        ::fprintf(stderr, \
            "Fatal error: [%s:%d] %s\n" \
            "  Message: " fmt "\n", \
            __FILE__, __LINE__, __FUNCTION__, \
            ##__VA_ARGS__); \
        std::fflush(stderr); \
        DEBUG_BREAK(); \
        ::abort(); \
    } while (0)
