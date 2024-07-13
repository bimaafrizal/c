#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void delete(struct Node** head_ref, int key) {
     struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    struct Node* head = NULL;
    push(&head, 7);
    push(&head, 8);
    append(&head, 9);

    printList(head);

    return 0;
}

