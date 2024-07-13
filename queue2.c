#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct queueNode
{
    char data;
    struct queueNode *nextPtr;
};


typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

// Prototipe fungsi
int isEmpty(QueueNodePtr headPtr);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value);

int main(int argc, char const *argv[])
{
    QueueNodePtr headPtr = NULL; // Inisialisasi head pointer
    QueueNodePtr tailPtr = NULL; // Inisialisasi tail pointer

    // Enqueue beberapa elemen
    enqueue(&headPtr, &tailPtr, 'A');
    enqueue(&headPtr, &tailPtr, 'B');
    enqueue(&headPtr, &tailPtr, 'C');

    // Dequeue dan cetak elemen
    while (!isEmpty(headPtr)) {
        printf("%c ", dequeue(&headPtr, &tailPtr));
    }

    return 0;
}


// Fungsi untuk memeriksa apakah antrian kosong
int isEmpty(QueueNodePtr headPtr) {
    return headPtr == NULL;
}

// Fungsi untuk menambah elemen ke antrian
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value) {
    QueueNodePtr newPtr = malloc(sizeof(QueueNode));
    if (newPtr != NULL) {
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        if (isEmpty(*headPtr)) {
            *headPtr = newPtr;
        } else {
            (*tailPtr)->nextPtr = newPtr;
        }

        *tailPtr = newPtr;
    } else {
        printf("%c not inserted. No memory available.\n", value);
    }
}

// Fungsi untuk menghapus elemen dari antrian
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr) {
    char value;
    QueueNodePtr tempPtr;

    value = (*headPtr)->data;
    tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    if (*headPtr == NULL) {
        *tailPtr = NULL;
    }

    free(tempPtr);
    return value;
}