#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk linked list
struct ListNode {
    int value;
    struct ListNode *next;
};

// Fungsi untuk membuat node baru
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menggabungkan dua linked list yang terurut
void mergeTwoLists(struct ListNode** list1, struct ListNode** list2, struct ListNode** mergedList) {
    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;

    // Merge kedua linked list
    while (*list1 != NULL && *list2 != NULL) {
        if ((*list1)->value <= (*list2)->value) {
            tail->next = *list1;
            *list1 = (*list1)->next;
        } else {
            tail->next = *list2;
            *list2 = (*list2)->next;
        }
        tail = tail->next;
    }

    // Jika ada node yang tersisa di salah satu linked list
    if (*list1 != NULL) {
        tail->next = *list1;
    } else {
        tail->next = *list2;
    }

    *mergedList = dummy.next;
}

// Fungsi untuk mencetak linked list
void printList(struct ListNode *node) {
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);

    struct ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct ListNode* mergedList = NULL;
    mergeTwoLists(&list1, &list2, &mergedList);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
