#include <stdio.h>

int main(int argc, char const *argv[])
{
    // binary search
    //  int c, first, last, middle, n, search, array[100];

    // printf("Enter number of elements\n");
    // scanf("%d", &n);

    // printf("Enter %d integers\n", n);
    // for (c = 0; c < n; c++)
    //     scanf("%d", &array[c]);
    // printf("Enter value to find\n");
    // scanf("%d", &search);
    // first = 0;
    // last = n - 1;
    // middle = (first + last) / 2;

    // while (first <= last)
    // {
    //     if (array[middle] < search)
    //     {
    //         first = middle + 1;
    //     }
    //     else if (array[middle] == search)
    //     {
    //         printf("%d found at location %d.\n", search, middle + 1);
    //         break;
    //     }
    //     else
    //     {
    //         last = middle - 1;
    //     }
    //     middle = (first + last) / 2;
    // }
    // if (first > last)
    // {
    //     printf("Not Found!");
    // }

    // interpolasi
    int arr[] = {20, 30, 40, 50, 60, 70};

    int n = sizeof(arr) / sizeof(int);

    int index = -1; // index array mulai dari 0, maka di set -1

    int find = 40;

    int mid, low = 0, high =  n - 1;

    while (arr[low] < find && arr[high] > find)
    {

        mid = ((find - arr[low]) / (arr[high] - arr[low])) * (high - low) + low;

        if (arr[mid] < find)
        {

            low = mid + 1;
        }

        else if (arr[mid] > find)
        {

            high = mid - 1;
        }

        else
        {

            index = mid;

            break;
        }
    }

    if (arr[low] == find)
    {

        index = low;
    }

    else if (arr[high] == find)
    {

        index = high;
    }

    if (index == -1)
    {

        printf("Data tidak ditemukan\n");
    }

    else
    {

        printf("Data berada pada index ke - % d\n", index);
    }
    return 0;
}
