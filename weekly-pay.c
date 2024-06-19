#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    int inputType, type, totalHors;
    float totalPay, payWithOvertime;
    int gaji[3] = {50000, 100000, 125000};
    int overTime[3] = {1.5, 1.5, 0};
    bool status = true;

    while (status)
    {
        printf("Selamat Datang di Aplikai Perhitungan Gaji \n");
        printf("Masukan Type karyawan 1 = Internship, 2 = Kartap, 3 = Kontrak \n");
        scanf("%d", &inputType);
        if(inputType < 1 || inputType > 3) {
            goto inputInvalid;
        }
        // perhitungan gaji
        printf("Masukan total jam kerja: ");
        scanf("%d", &totalHors);
        if(totalHors < 0) {
            goto inputInvalid;
        }

        totalPay = gaji[inputType - 1] * 40;
        payWithOvertime = totalPay;
        if(totalHors > 40) {
            payWithOvertime += (totalHors - 40) * gaji[inputType -1] * overTime[inputType - 1];
        } 
        printf("Total gaji anda adalah: %2.f \n", totalPay);
        printf("Total gaji anda dengan overtime adalah: %2.f \n", payWithOvertime);
        printf("Apakah anda ingin mengulang lagi? (1 = ya, 2 = tidak): ");
        scanf("%d", &type);

        if(type == 2) {
            status = false;
            printf("Terima kasih telah menggunakan program ini\n");
            return 0;
        } else if(type == 1) {
            continue;
        } else {
            goto inputInvalid;
        }
    }
    
    inputInvalid:
        printf("Wrong input!\n");
        exit(1);

    return 0;
}

