#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    int input;
    printf("Masukan nilai dalam kilo meters: ");
    scanf("%d", &input);
    int meters = input * 1000;
    getchar();
    printf("Silahkan klik enter untuk menampilkan hasil\n");
    getchar();
    int centimeters = input * 100000;
    printf("Jarak dalam meters: %d\n", meters);
    getchar();
    printf("Jarak dalam centimeters: %d\n", centimeters);

    /* code */
    return 0;
}
