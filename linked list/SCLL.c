#include <stdio.h>
#include <stdlib.h>

// Node structure for the singly circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        newNode->next = newNode; // Point to itself
        *head = newNode;
        return;
    }

    if (position == 0) {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode; // Update the last node
        *head = newNode; // Update head
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node by value
void deleteByValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Check if the head needs to be deleted
    if (temp->data == value) {
        if (temp->next == *head) { // Only one node
            free(temp);
            *head = NULL;
            return;
        } else {
            while (temp->next != *head) {
                temp = temp->next;
            }
            struct Node* toDelete = *head;
            *head = (*head)->next; // Update head
            temp->next = *head; // Update last node
            free(toDelete);
            return;
        }
    }

    // Search for the value to delete
    while (temp->next != *head && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == *head) {
        printf("%d not found in the list.\n", value);
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// Function to display the singly circular linked list with next addresses
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Singly Circular Linked List:\n");
    do {
        printf("Value: %d, Address: %p, Next Address: %p\n", temp->data, (void*)temp, (void*)temp->next);
        temp = temp->next;
    } while (temp != head);
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
        insertAtPosition(&head, data, i); // Insert at end
    }

    // Display the singly circular linked list
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
    
    // Display the final singly circular linked list
    displayList(head);

    // Free the memory before exiting
    while (head != NULL) {
        struct Node* temp = head;
        if (temp->next == head) {
            free(temp);
            head = NULL;
            break;
        }
        head = head->next;
        free(temp);
    }

    return 0;
}