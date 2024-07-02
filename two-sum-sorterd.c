#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_INPUT 8

int* calculateTarget(int *input, int target, int length)
{
    int resultSize = 2;
    int *result = (int *)malloc(resultSize * sizeof(int));

    for (int i = 0; i < sizeof(input); i++)
    {
        for (int j = i + 1; j < sizeof(input); j++)
        {
            if (input[i] + input[j] == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    
    
    return 0;
}

int main(int argc, char const *argv[])
{
    int i = 0;
    int init = INITIAL_INPUT;
    int *input = (int *)malloc(init * sizeof(int));
    int statusInput = 1;
    int target;
    bool status = true;

    do {
        printf("Masukan nilai: ");
        scanf("%d", &input[i]);
        printf("Masukan nilai lagi? (1/0): ");
        scanf("%d", &statusInput);
        if (statusInput == 1)
        {
            i++;
            if (i >= init)
            {
                init += 8;
                input = (int *)realloc(input, init * sizeof(int));
            }
        } else if(statusInput== 0) {
            printf("Masukan target: ");
            scanf("%d", &target);
            statusInput = 0;
            int *result = calculateTarget(input, target, i);
            if (result != 0)
            {
                printf("Result: [%d, %d]\n", result[0], result[1]);
                return 0;
            }
            return 0;
        } else {
            goto error;
        }        
    } while (statusInput == 1);


    error:
        printf("Wrong input!\n");
        return 1;

    return 0;
}
