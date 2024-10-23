#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
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

// Function to insert a node at the beginning
void insertAtStart(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
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
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 0) {
        insertAtStart(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
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
    temp->next = newNode;
}

// Function to delete a node by value
void deleteByValue(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == value) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not found in the list
    if (temp == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list with addresses
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List:\n");
    while (temp != NULL) {
        printf("Value: %d, Address: %p\n", temp->data, (void*)temp);
        temp = temp->next;
    }
}

// Main function
int main() {
    struct Node* head = NULL; // Initialize the head of the list
    int n, data, value, position;

    // Asking for the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Loop to insert nodes
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    // Display the linked list
    displayList(head);

    // Insertions
    printf("\nChoose where to insert a new value:\n");
    printf("0 for start\n");
    printf("1 for middle\n");
    printf("2 for end\n");
    scanf("%d", &position);

    printf("Enter value to insert: ");
    scanf("%d", &data);

    if (position == 0) {
        insertAtStart(&head, data);
    } else if (position == 1) {
        printf("Enter the position to insert in the middle: ");
        scanf("%d", &position);
        insertAtPosition(&head, data, position);
    } else if (position == 2) {
        insertAtEnd(&head, data);
    } else {
        printf("Invalid position. Inserting at the end instead.\n");
        insertAtEnd(&head, data);
    }

    // Display the updated linked list
    displayList(head);

    // Deletion
    printf("\nEnter a value to delete: ");
    scanf("%d", &value);
    deleteByValue(&head, value);

    // Display the updated linked list
    displayList(head);

    return 0;
}
