#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int totalHours;
    float totalPay, payWithDiscount, discount;
    
    printf("Selamat Datang di Aplikasi Diskon Game\n");
    printf("Masukan total jam sewa: ");
    scanf("%d", &totalHours);
    if(totalHours < 0) {
        printf("Wrong input!\n");
        exit(1);
    } else if(totalHours == 0) {
        printf("Total biaya sewa adalah: 0\n");
        return 0;
    }

    if(totalHours >= 4 && totalHours <= 6) {
        discount = 0.1;
    } else if(totalHours > 6 && totalHours <= 8) {
        discount = 0.15;
    } else if(totalHours > 8) {
        discount = 0.2;
    } else {
        discount = 0;
    }
    totalPay = totalHours * 10000;
    payWithDiscount= totalPay * (1 - discount);
    printf("Total biaya sewa adalah: %2.f \n", payWithDiscount);

    return 0;
}
