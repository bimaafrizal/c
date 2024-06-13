#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


float discount(int input);
void formatCurrency(int input, char output[]);

int main(int argc, char const *argv[])
{
    int input, playAgain;
    char output[100];
    float hasilAkhir;
    bool correct = false;
    int i = 0;
    
    while (!correct)
    {
        printf("Masukan total belanja anda: ");
        scanf("%d", &input);
        if(input <= 0) {
            printf("Total belanja tidak boleh kurang dari 0\n");
            return 0;
        }
        
        if(i != 0 && i % 4 == 0) {
            hasilAkhir = hasilAkhir - (hasilAkhir * 0.05);
        } else {
            hasilAkhir = discount(input);
        }
        
        formatCurrency(hasilAkhir, output);
        printf("Total belanja anda setelah diskon adalah:  Rp%s\n", output);
        printf("Apakah anda ingin mengulang lagi? (1 = ya, 2 = tidak): ");
        scanf("%d", &playAgain);
        if(playAgain == 2) {
            correct = true;
            printf("Terima kasih telah menggunakan program ini\n");
        } else if(playAgain == 1) {
            i++;
        } else {
            printf("Input tidak valid\n");
            printf("Terima kasih telah menggunakan program ini\n");
            return 0;
        }
    }
    return 0;
}

float discount(int input){
    float hasilAkhir;
    if(input >= 200000 && input <= 500000) {
        hasilAkhir = input - (input * 0.1);
    } else if (input >= 550000 && input <= 1000000) {
        hasilAkhir = input - (input * 0.2);
    } else if (input >= 1000000) {
        hasilAkhir = input - (input * 0.3);
    } else {
        hasilAkhir = input;
    }

    return hasilAkhir;
}

//format currency and . in the number
void formatCurrency(int input, char output[]) {
    itoa(input, output, 10);
    int length = strlen(output);
    while (length > 3) {
        length -= 3;
        memmove(output + length + 1, output + length, strlen(output + length) + 1);
        output[length] = '.';
    }
}