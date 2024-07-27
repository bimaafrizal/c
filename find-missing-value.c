#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void findMissingValue(int arr[], int n) {
    // Bubble Sort
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }

    int first = arr[0];
    int last  = arr[n-1];
    int length = last - first + 1;
    int expectedArray[length];

    for(int i = 0; i < length; i++) {
        expectedArray[i] = first + i;
    }

    // Mencari nilai yang hilang
    int missingValue = -1;
    int found;
    for(int i = 0; i < length; i++) {
        found = 0;
        for(int j = 0; j < n; j++) {
            if(expectedArray[i] == arr[j]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            missingValue = expectedArray[i];
            printf("Nilai yang hilang adalah: %d\n", missingValue);
        }
    }

    if(missingValue == -1) {
        printf("Tidak ada nilai yang hilang.\n");
    }
}

int main(int argc, char const *argv[])
{
    int n;
    int tempInput = 0;
    
    printf("Input panjang array : ");
    scanf("%d", &n);

    int dataInput[n -1];
    for(int i = 0; i < n-1; i++) {
        printf("Array ke %d => ", i);
        scanf("%d" , &tempInput);
        dataInput[i] = tempInput;
    }

    findMissingValue(dataInput, n-1);
    
    /* code */
    return 0;
}
