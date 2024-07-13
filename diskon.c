#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void append(Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while(last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

int addList(Node *node) {
    int data = 0;
    while (node != NULL) {
        data += node->data;
        node = node->next;
    }
    return data;
}

int main(int argc, char const *argv[])
{
    struct Node* head = NULL;
    int input = 1;
    int inputHarga;
    printf("Selamat datang di sitem informasi kasir \n");
    while (input != 0)
    {
        printf("masukan pilihan anda: 1(masukan harga), 2(hitung), 0(exit): ");
        inputHarga = 0;
        scanf("%d", &input);
        if(input == 1) {
            printf("Inputkan harga belanja : ");
            scanf("%d", &inputHarga);
            append(&head, inputHarga);
        } else if(input == 2) {
            if(head == NULL) {
                printf("Total Rp0, diskon0%");
                return 0;
            }
            float diskon= 0;
            int kupon = 0;
            int jumlah = addList(head);
            float total = jumlah;
            kupon =jumlah / 100000;
            if(jumlah >= 100000) {
                diskon = 0.05 * jumlah;
    
                total = jumlah - diskon;
            }

            printf("Jumlah %d \n", jumlah);
            printf("Kupon %d \n", kupon);
            printf("Diskon %.2f \n", diskon);
            printf("Total %.2f \n", total);
            break;
        }
    }

    
    return 0;
}
