void reverse_L(Node** head) {
    Node* current = *head;
    Node* temp = NULL;
    while (current != null) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp>prev;
    }
}
