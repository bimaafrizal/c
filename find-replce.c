#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

void printArray(char **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s ", array[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    char inputText[MAX], inputReplace[MAX], inputFind[MAX], temp[MAX];
    char *tempResult[MAX];
    printf("Enter a text: ");
    fgets(inputText, MAX, stdin);

    // write to file
    FILE *file;
    file = fopen("./file2.txt", "w");
    if (file == NULL)
    {
        perror("Error");
    }
    else
    {
        fputs(inputText, file);
        fclose(file);
    }

    printf("Enter a text to find: ");
    scanf("%s", inputFind);

    printf("Enter a text to replace: ");
    scanf("%s", inputReplace);

    // replace text
    file = fopen("./file2.txt", "r");
    int i = 0;
    if (file == NULL)
    {
        perror("Error");
    }
    else
    {
        while (fscanf(file, "%s", temp) != EOF)
        {
            if (strcmp(temp, inputFind) == 0)
            {
                tempResult[i] = strdup(inputReplace); 
            }
            else
            {
                tempResult[i] = strdup(temp);
            }
            i++;
        }
        fclose(file);
    }

    printArray(tempResult, i);

    // add to file
    file = fopen("./file2.txt", "w");
    if (file == NULL)
    {
        perror("Error");
    }
    else
    {
        for (int j = 0; j < i; j++)
        {
            fputs(tempResult[j], file);
            if (j < i - 1)
            {
                fputs(" ", file);
            }
        }
        fclose(file);
    }

    // Free memory
    for (int j = 0; j < i; j++)
    {
        free(tempResult[j]);
    }


    return 0;
}
