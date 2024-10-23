#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly circular linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Point to itself for circular
    newNode->prev = newNode; // Point to itself for circular
    return newNode;
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if (position == 0) {
        struct Node* last = (*head)->prev; // Get the last node
        newNode->next = *head; // New node points to the head
        newNode->prev = last; // New node points to the last node
        last->next = newNode; // Last node points to the new node
        (*head)->prev = newNode; // Head's previous points to the new node
        *head = newNode; // Update head
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode; // Update the next node's previous
    temp->next = newNode; // Link the new node in the list
}

// Function to delete a node by value
void deleteByValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    do {
        if (temp->data == value) {
            // Node to be deleted is found
            if (temp->next == temp) { // Only one node
                free(temp);
                *head = NULL;
                return;
            } else {
                temp->prev->next = temp->next; // Bypass the node
                temp->next->prev = temp->prev; // Bypass the node
                if (*head == temp) {
                    *head = temp->next; // Update head if needed
                }
                free(temp);
                return;
            }
        }
        temp = temp->next;
    } while (temp != *head);

    printf("%d not found in the list.\n", value);
}

// Function to display the doubly circular linked list with addresses
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Circular Linked List:\n");
    do {
        printf("Value: %d, Address: %p, Next Address: %p, Prev Address: %p\n",
               temp->data, (void*)temp, (void*)temp->next, (void*)temp->prev);
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

    // Display the doubly circular linked list
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
    
    // Display the final doubly circular linked list
    displayList(head);

    // Free the memory before exiting
    if (head != NULL) {
        struct Node* temp = head;
        struct Node* nextNode;
        do {
            nextNode = temp->next;
            free(temp);
            temp = nextNode;
        } while (temp != head);
    }

    return 0;
}
