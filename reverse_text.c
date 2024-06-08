#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void reverseText(char text[], char reversedText[]);
int countWords(char text[]);

int main(void)
{
    char text1[100], text2[100], text3[100], reversedText1[100], reversedText2[100], reversedText3[100];
    int countText1, countText2, countText3;

    printf("Enter the first text: ");
    gets(text1);
    printf("Enter the second text: ");
    gets(text2);
    printf("Enter the third text: ");
    gets(text3);

    reverseText(text1, reversedText1);
    reverseText(text2, reversedText2);
    reverseText(text3, reversedText3);

    countText1 = countWords(text1);
    countText2 = countWords(text2);
    countText3 = countWords(text3);
    

    printf("Gabungan text: %s %s %s\n", text3, text2, text1);
    printf("Hasil membalik kalimat gabungan: %s %s %s\n", reversedText3, reversedText2, reversedText1);
    printf("Jumlah huruf pada text pertama: %d\n", countText1);
    printf("Jumlah huruf pada text kedua: %d\n", countText2);
    printf("Jumlah huruf pada text ketiga: %d\n", countText3);
    printf("Total Jumlah huruf: %d\n", countText1 + countText2 + countText3);


    /* code */
    return 0;
}

int countWords(char text[])
{

    return strlen(text);
}

void reverseText(char text[], char reversedText[])
{
     int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        reversedText[i] = text[length - i - 1];
    }
    reversedText[length] = '\0';
}
