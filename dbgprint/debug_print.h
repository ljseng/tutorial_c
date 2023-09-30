#ifndef DEBUG_PRINT_H
#define DEBUG_PRINT_H

#include <stdio.h>

#define DEBUG_PRINT(msg, ...) \
    do { \
        printf(msg "\n", ##__VA_ARGS__); \
    } while (0)

#endif // DEBUG_PRINT_H
