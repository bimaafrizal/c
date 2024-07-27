#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

void appendLinkedList(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    new_node->data = data;
    new_node->next = NULL;

    if(temp == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void printList(struct Node* node) {
    struct Node* last;
    printf("Traversal in forward direction \n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
}

void pairsTarget(struct Node* node, int target) {
    struct Node* first = node;
    struct Node* second = node;

    while (first->next != NULL) {
        second = first->next;
        while (second->next != NULL)
        {
            if(first->data + second->data == target) {
                printf("{ %d %d } \n", first->data, second->data);
            }
            second = second->next;
        }
        first = first->next;
    }
}

int main(int argc, char const *argv[])
{
     struct Node* head = NULL;
     int input = 0;

    // Append nodes
    for(int i = 1; i < 10; i++) {
        appendLinkedList(&head, i);
    }
    printf("Masukan data yang ingin di cari : ");
    scanf("%d", &input);

    pairsTarget(head, input);
    return 0;
}
