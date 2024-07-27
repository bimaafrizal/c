#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char input[100];
    char str[5] = {'a', 'i', 'u', 'e', 'o'};
    char *month[12] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

    while (strlen(input) != 1)
    {
        printf("Enter first letter: ");
        fgets(input, sizeof(input), stdin);
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        if (strlen(input) > 1)
        {
            printf("\nJust input one letter");
        }
    }
    char *monthResult[12];
    char letter = tolower(input[0]);
    int incement = -1;
    for (int i = 0; i < 12; i++)
    {
        if (letter == month[i][0])
        {
            if (incement == -1)
            {
                incement = 0;
            }
            monthResult[incement] = month[i];
            incement++;
        }
    }

    if (incement != -1)
    {
        int length = 0;
        int vokal = 0;
        int found;
        printf("bulan: ");
        //loop word
        for (int i = 0; i < incement; i++) {
            vokal = 0;
            printf("%s \n", monthResult[i]);
            length = strlen(monthResult[i]);
            //loop letter
            for(int j = 0; j < length; j++) {
                //loop vocal
                for(int k = 0; k < 5; k++) {
                    if(monthResult[i][j] == str[k]) {
                        vokal++;
                    }
                }
            }
            printf("Jumlah huruf vokal : %d \n", vokal);
            printf("Jumlah huruf non vokal : %d \n", length - vokal);
        }
    } else {
        printf("tidak ditemukan!");
    }
    return 0;
}
