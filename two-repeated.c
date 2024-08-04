#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int countElement(int arr[], int n, int element)
{
    int count = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] == element)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int length;
    srand(time(0));

    printf("Input panjang array (N): ");
    scanf("%d", &length);
    int arr[length + 2];

    for (int i = 0; i < length + 2; i++)
    {
        arr[i] = rand() % length + 1;
    }

    // Mencetak array
    printf("Array: ");
    for (int i = 0; i < length + 2; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < length + 2; i++)
    {
        int element = arr[i];
        int count = countElement(arr, length + 2, element);

        if (count == 2)
        {
            printf("%d, ", element);

            for (int j = 0; j < length + 2; j++)
            {
                if (arr[j] == element)
                {
                    arr[j] = 0;
                }
            }
        }
    }
    printf("\n");

    return 0;
}
