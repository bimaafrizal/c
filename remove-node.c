#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int value;
    struct ListNode *next;
};

void append(struct ListNode **head_ref, int new_data)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *last = *head_ref;

    new_node->value = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
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

// Fungsi untuk mencetak linked list
void printList(struct ListNode *node)
{
    while (node != NULL)
    {
        printf("%d->", node->value);
        node = node->next;
    }
    printf("\n");
}

void deleteNode(struct ListNode **head_ref, int input)
{
    struct ListNode *first = *head_ref;
    struct ListNode *second = *head_ref;
    struct ListNode *prev = NULL;

    for (int i = 0; i < input; i++)
    {
        if (first == NULL)
            return;
        first = first->next;
    }

    if (first == NULL)
    {
        struct ListNode *temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        return;
    }

    while (first != NULL && first->next != NULL)
    {
        prev = second;
        first = first->next;
        second = second->next;
    }

    if (second->next != NULL)
    {
        struct ListNode *temp = second->next;
        second->next = second->next->next;
        free(temp);
    }
    else
    {
        if (prev != NULL)
        {
            prev->next = NULL;
            free(second);
        }
    }
}

int main(int argc, char const *argv[])
{
    int input, search, length, delete;
    struct ListNode *head = NULL;
    printf("Input panjang linked list: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++)
    {
        printf("Masukkan angka: ");
        scanf("%d", &input);
        append(&head, input);
    }

    printf("N? ");
    scanf("%d", &delete);
    if (delete >= length)
    {
        printf("Invalid input\n");
        return 0;
    }
    //delete node
    deleteNode(&head, delete);

    // print linked list
    printList(head);

    /* code */
    return 0;
}
