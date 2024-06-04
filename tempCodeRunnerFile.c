#include <stdio.h>
#include <conio.h>

int main(void) {
    // stdin = standard input
    // stdout = standard output
    // stderr = standard error
    // input dan output dilakukan dengan urutan byte disebut stream
    // fungsi input-ouput yang diformat menerima  memungkinkan untuk memasuk input output dalam format yang diinginkan
    // fungsi input-ouput yang tidak diformat tidak memungkinkan untuk memasuk input output dalam format yang diinginkan
    //contoh yang diformat printf dan scanf
    // contoh yang tidak diformat getch, getche, getChar, putchar, putch, putChar

    // contoh diformat
    int a;
    clrscr();
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("You entered: %d\n", a);
    getch();
}