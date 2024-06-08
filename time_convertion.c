#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int input;
    printf("Enter the number of seconds: ");
    scanf("%d", &input);
    int hours = input / 3600;
    int minutes = (input % 3600) / 60;
    int seconds = (input % 3600) % 60;
    printf("The time is %d hours, %d minutes, and %d seconds.\n", hours, minutes, seconds);
    return 0;
}
