#include <stdio.h>

int factorialRecrusive(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorialRecrusive(n - 1);
    }
}

int factorialIterative(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int i = 10;
    printf("Factorial of %d is %d\n", i, factorialRecrusive(i));
    printf("Factorial of %d is %d\n", i, factorialIterative(i));
    return 0;
}
