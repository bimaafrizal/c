#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i, j;
    bool isPrime;

    for (i = 2; i < 100; i++)
    {
        isPrime = true;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            printf("%d ", i);
        }
    }
    return 0;
}