// by : featas cherif
#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse the linked list
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int n, value;

    printf("Enter the size of the list: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The list is empty.\n");
        return 0;
    }

    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Original list: ");
    printList(head);

    head = reverse(head);

    printf("Reversed list: ");
    printList(head);

    return 0;
}
