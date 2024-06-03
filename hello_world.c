#include <stdio.h>

int main(void) {
    // math.h mathematical functions
    // stdio.h standard input/output functions
    // stdlib.h standard library functions
    // string.h string functions
    // time.h time functions
    
    printf("Hello, World!\n");
    

    //decalre variables
    int a = 5;
    int b = 10;
    int sum = a + b;
    printf("The sum of %d and %d is %d\n", a, b, sum);

    //constants
    // nilainya tidak dapat diubah
    const int c = 5;

    //suffix
    // 0x = hexadecimal
    // 0 = octal
    // 0b = binary
    int d = 0x1A;
    int e = 0b1101;\
    int f = 28f;
    return 0;
}