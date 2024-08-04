#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_HISTORY 100
#define MAX_LEN 100

typedef struct
{
    char nama[MAX_LEN];
    char jenis[MAX_LEN];
    float harga;
} Buku;

typedef struct
{
    Buku buku[MAX_BOOKS];
    int jumlah;
} DataBuku;

typedef struct
{
    char nama[MAX_LEN];
    char jenis[MAX_LEN];
    float harga;
} History;

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
