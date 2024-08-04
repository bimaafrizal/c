#include <stdio.h>
#include <stdlib.h>

#define MAX 200

int interpolationSearch(int arr[], int bottom, int top, int item)
{
    int mid;
    while (bottom <= top)
    {
        mid = bottom + (top - bottom) * ((item - arr[bottom]) / (arr[top] - arr[bottom]));

        if (item == arr[mid])
        {
            return mid + 1;
        }
        if (item < arr[mid])
        {
            top = mid - 1;
        }
        else
        {
            bottom = mid + 1;
        }
    }

    return -1;
}

void printResult(int result)
{
    if (result == -1)
    {
        printf("Element not found in the array\n");
    }
    else
    {
        printf("Element found at index %d\n", result);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 1, 2, 2, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 2;
    int result = interpolationSearch(arr, 0, n - 1, x);
    printResult(result);

    x = 4;
    result = interpolationSearch(arr, 0, n - 1, x);
    printResult(result);

    return 0;
}
