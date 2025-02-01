void insertAtPosition(Node** head, int value, int k) {
    Node* newNode = createNode(value);

    if (k == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    int index = 0;

    while (current != NULL && index < k - 1) {
        current = current->next;
        index++;
    }

    if (current == NULL && index < k - 1) {
        printf("Error !");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;


}
