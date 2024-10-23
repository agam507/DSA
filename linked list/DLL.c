#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtStart(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    
    if (position == 0) {
        insertAtStart(head, data);
        return;
    }

    struct Node* temp = *head;

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds. Inserting at the end instead.\n");
        insertAtEnd(head, data);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Function to delete a node by value
void deleteByValue(struct Node** head, int value) {
    struct Node* temp = *head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next; // Update head if needed
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Function to display the doubly linked list with addresses
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List:\n");
    while (temp != NULL) {
        printf("Value: %d, Address: %p\n", temp->data, (void*)temp);
        temp = temp->next;
    }
}

// Main function
int main() {
    struct Node* head = NULL; // Initialize the head of the list
    int n;

    // Asking for the number of initial nodes
    printf("Enter the number of initial nodes: ");
    scanf("%d", &n);

    // Loop to insert initial nodes at the end
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    // Display the doubly linked list
    displayList(head);

    // Prompt for new value insertion
    int data, position;
    printf("\nEnter the value to insert: ");
    scanf("%d", &data);
    printf("Enter the position to insert at: ");
    scanf("%d", &position);
    insertAtPosition(&head, data, position);
    displayList(head);

    // Prompt for value deletion
    int valueToDelete;
    printf("\nEnter the value to delete: ");
    scanf("%d", &valueToDelete);
    deleteByValue(&head, valueToDelete);
    
    // Display the final doubly linked list
    displayList(head);

    // Free the memory before exiting
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
