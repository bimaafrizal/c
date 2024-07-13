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

struct Node* searchList(Node *node, int key) {
   if(node == NULL) {
    return NULL;
   } 
   if(node->data == key){
        return node;
   }
   return searchList(node->next, key);
}

void printList(Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    struct Node* head = NULL;
    int input;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    printf("Masukan nilai yang ingin dicari: ");
    scanf("%d", &input);

    struct Node *result = searchList(head, input);
    
    if (result != NULL) {
        printf("Node with data %d found.\n", result->data);
    } else {
        printf("Node with data %d not found.\n", input);
    }

    // printList(head);
    return 0;
}
