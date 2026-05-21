#pragma once

#include <stdio.h>

#if defined(_WIN64)
    #define PLATFORM_WINDOWS 1
#elif defined(__linux__)
    #define PLATFORM_LINUX 1
#elif defined(__APPLE__)
    #define PLATFORM_MACOS 1
#else
    #define PLATFORM_UNKNOWN 1
#endif

inline void PrintPlatform() {
#if PLATFORM_WINDOWS
    printf("Platform: Windows\n");
#elif PLATFORM_LINUX
    printf("Platform: Linux\n");
#elif PLATFORM_MACOS
    printf("Platform: macOS\n");
#else
    printf("Platform: Unknown\n");
#endif
}
