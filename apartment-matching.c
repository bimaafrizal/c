#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

void matchApartment(int *apartments, int sizeApartments, char customerName[][MAX_NAME_LENGTH], int *customerSize, int sizeCustomer)
{
    int diff;
    for(int i = 0; i < sizeCustomer; i++) {
        for(int j = 0; j < sizeApartments; j++) {
            diff = customerSize[i] - apartments[j];
            if(diff >= -5 && diff <= 5) {
                printf("Customer %s memilih apartment ukuran %d\n", customerName[i], customerSize[i]);
                printf("Customer %s match dengan apartemen dengan ukuran %d\n", customerName[i], apartments[j]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int apartments[] = {30,60, 75};
    int sizeCustomer;

    printf("Masukan jumlah customer: ");
    scanf("%d", &sizeCustomer);
    
    char customerName[sizeCustomer][MAX_NAME_LENGTH];
    int *customerSize = (int *)malloc(sizeCustomer * sizeof(int));
    
    for (int i = 0; i < sizeCustomer; i++)
    {
        printf("Masukan nama customer ke-%d: ", i + 1);
        scanf("%s", &customerName[i]);
        printf("Masukan ukuran apartemen ke-%d: ", i + 1);
        scanf("%d", &customerSize[i]);
    }
    matchApartment(apartments, sizeof(apartments) / sizeof(apartments[0]), customerName, customerSize, sizeCustomer);

    /* code */
    return 0;
}
