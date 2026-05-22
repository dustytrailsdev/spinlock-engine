#pragma once

#include <cstdio>

// Log labels
#define LOG_LABEL_TRACE "TRACE"
#define LOG_LABEL_DEBUG "DEBUG"
#define LOG_LABEL_INFO  "INFO"
#define LOG_LABEL_WARN  "WARN"
#define LOG_LABEL_ERROR "ERROR"
#define LOG_LABEL_FATAL "FATAL"

// Private log implementation
#define LOG_IMPL(label, fmt, ...) \
    do { \
        std::fprintf(stderr, "[%s] %s:%d (%s) " fmt "\n", \
            label, __FILE__, __LINE__, __FUNCTION__, \
            ##__VA_ARGS__); \
        std::fflush(stderr); \
    } while(0)

// Public log macros
#define LOG_TRACE(fmt, ...)   LOG_IMPL(LOG_LABEL_TRACE, fmt, ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...)   LOG_IMPL(LOG_LABEL_DEBUG, fmt, ##__VA_ARGS__)
#define LOG_INFO(fmt, ...)    LOG_IMPL(LOG_LABEL_INFO,  fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...)    LOG_IMPL(LOG_LABEL_WARN,  fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...)   LOG_IMPL(LOG_LABEL_ERROR, fmt, ##__VA_ARGS__)
#define LOG_FATAL(fmt, ...)   LOG_IMPL(LOG_LABEL_FATAL, fmt, ##__VA_ARGS__)
