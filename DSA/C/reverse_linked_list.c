#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Recursive function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    // Base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Reverse the remaining list
    struct Node* newHead = reverseList(head->next);

    // Reverse the current connection
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);

        if (head->next != NULL) {
            printf(" -> ");
        }

        head = head->next;
    }

    printf("\n");
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original list:\n");
    printList(head);

    head = reverseList(head);

    printf("Reversed list:\n");
    printList(head);

    return 0;
}
