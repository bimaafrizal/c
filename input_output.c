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
    // int a;
    // system("cls");
    // printf("Enter a number: ");
    // scanf("%d", &a);
    // printf("You entered: %d\n", a);
    // getch();
    // return 0;

    // contoh tidak diformat
    // char ch;
    // printf("Enter a character: ");
    // ch = getche();
    // printf("\nYou entered: ");
    // putchar(ch);

    // output
    // printf -> output yang diformat (harus mendeklarasikan studio.h)
    // putch -> output mencetak karakter yang tidak diformat (harus mendeklarasikan conio.h)
    //  puts -> output mencetak string yang tidak diformat (harus mendeklarasikan studio.h)

    // input
    // scanf -> input yang diformat (harus mendeklarasikan studio.h)
    //getChar -> fungsi input yang tidak diformat  berupa karakter (harus mendeklarasikan conio.h)
    // getch -> fungsi input yang tidak diformat, digunakan untuk menunggu inputan dari keyboard (harus mendeklarasikan conio.h)
    // getche -> mirip dengan getch, namun menampilkan karakter yang diinputkan (harus mendeklarasikan conio.h)
    // gets -> input yang tidak diformat berupa string (harus mendeklarasikan studio.h)

}