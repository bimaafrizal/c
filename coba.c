#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int a[10] = {2, 1, 4, 22, 21, 11, 13, 7, 16, 23};

    int i, j, m;

    i = ++a[1];

    j= a[1]++;

    m = a[i++];

    printf("%d, %d, %d", i, j, m);

    return 0;
}
