#include "../../dbgprint/debug_print.h"
#include "string.h"

int main() {
    // pointer and dereferencing a pointer
    int num = 10;
    int *pNum = &num;
    DEBUG_PRINT("address of pointer to num: %p. value at this pointer address is %d", pNum, *pNum);

    // modify value at the pointer address
    *pNum = *pNum * 2;
    DEBUG_PRINT("address of pointer to num: %p. value at this pointer address is %d", pNum, *pNum);

    // string array
    char str1[] = "hello world char array"; // 22 characters
    DEBUG_PRINT("str1: %s", str1);

    // difference of sizeof vs strlen on string array. sizeof will have extra string terminator byte
    DEBUG_PRINT("size of str1: %lu", sizeof(str1));
    DEBUG_PRINT("strlen str1: %lu", strlen(str1));

    // modify first char of string (string array)
    str1[0] = 'H';
    DEBUG_PRINT("str1: %s", str1);

    // string pointer. string pointer is always immutable
    char *str2 = "hello world char pointer"; // 24 characters
    DEBUG_PRINT("str2: %s", str2);
    DEBUG_PRINT("strlen str2: %lu", strlen(str2));

    // following code does not work because string pointer is immutable
    /* *str2 = 'H'; */
    /* DEBUG_PRINT("str2: %s", str2); */
}
