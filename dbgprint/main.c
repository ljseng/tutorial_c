#include <stdio.h>
#include "debug_print.h"

int main() {
    printf("Hello world!\n");

    DEBUG_PRINT("Hello world from debug print macro!");
    DEBUG_PRINT("integer\t%d", 1234);
    DEBUG_PRINT("float\t%f", 3.14);
    DEBUG_PRINT("string\t%s %s", "LOREM IPSIUM", "IS FUN!");

    return 0;
}
