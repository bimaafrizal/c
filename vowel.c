#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define INITIAL 5

int checkVowels(char letter)
{
    letter = tolower(letter);
    return letter == 'a' || letter == 'i' || letter == 'u' || letter == 'e' || letter == 'o';
}

int calculateVowels(char **array, int size)
{
    int countVowels = 0;
    for (int i = 0; i < size; i++)
    {
        int lengthString = strlen(array[i]);
        for (int j = 0; j < lengthString; j++)
        {
            if (checkVowels(array[i][j]))
            {
                countVowels++;
            }
        }
    }
    return countVowels;
}

void addData(char ***array, int *size)
{
    int i = 0;
    int current = INITIAL;
    bool status = true;
    int statusInput;

    *array = (char **)malloc(current * sizeof(char *));
    if (*array == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    do
    {
        if (i >= current)
        {
            current += 10;
            *array = (char **)realloc(*array, current * sizeof(char *));
            if (*array == NULL)
            {
                printf("Memory reallocation failed\n");
                exit(1);
            }
        }
        printf("Masukkan teks-%d\n", i + 1);
        char *text = (char *)malloc(100 * sizeof(char));
        if (text == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
        printf("Masukan text: ");
        scanf("%s", text);
        (*array)[i] = text;

        printf("\nApakah anda ingin menambahkan nilai lagi? (1 = ya, 2 = tidak): ");
        scanf("%d", &statusInput);
        if (statusInput == 2)
        {
            status = false;
        }
        else if (statusInput == 1)
        {
            i++;
        }
        else
        {
            printf("Wrong input!\n");
            status = false;
        }

    } while (status);

    *size = i + 1;
}

void printArray(char **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s \n", array[i]);
    }
}

void freeArray(char **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(array[i]);
    }
    free(array);
}

int main(int argc, char const *argv[])
{
    char **vowels1 = NULL;
    char **vowels2 = NULL;
    int size1 = 0;
    int size2 = 0;
    int countVowels1 = 0;
    int countVowels2 = 0;

    printf("Input array pertama! \n");
    addData(&vowels1, &size1);
    printf("Input array kedua! \n");
    addData(&vowels2, &size2);

    printf("Array pertama: \n");
    printArray(vowels1, size1);
    printf("Array kedua: \n");
    printArray(vowels2, size2);

    countVowels1 = calculateVowels(vowels1, size1);
    countVowels2 = calculateVowels(vowels2, size2);
    printf("Jumlah Huruf Vokal 1: %d\n", countVowels1);
    printf("Jumlah Huruf Vokal 2: %d\n", countVowels2);

    if (countVowels1 > countVowels2)
    {
        printf("Array pertama memiliki jumlah huruf vokal lebih banyak dari array kedua\n");
    }
    else if (countVowels1 < countVowels2)
    {
        printf("Array kedua memiliki jumlah huruf vokal lebih banyak dari array pertama\n");
    }
    else
    {
        printf("Array pertama dan kedua memiliki jumlah huruf vokal yang sama\n");
    }

    freeArray(vowels1, size1);
    freeArray(vowels2, size2);

    return 0;
}
