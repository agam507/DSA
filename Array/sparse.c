#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
} Node;

Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int row, int col, int value) {
    Node* newNode = createNode(row, col, value);
    newNode->next = *head;
    *head = newNode;
}

void delete(Node** head, int row, int col) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->row == row && temp->col == col) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Element at (%d, %d) deleted.\n", row, col);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Element at (%d, %d) not found.\n", row, col);
}

void display(Node* head) {
    Node* temp = head;
    printf("Row\tColumn\tValue\n");
    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    Node* sparseMatrix = NULL;
    int n, row, col, value, delRow, delCol;

    printf("Enter the number of non-zero elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter row, column, and value for element %d: ", i + 1);
        scanf("%d %d %d", &row, &col, &value);
        insert(&sparseMatrix, row, col, value);
    }

    printf("\nSparse Matrix after insertion:\n");
    display(sparseMatrix);

    printf("\nEnter the row and column of the element to delete: ");
    scanf("%d %d", &delRow, &delCol);
    delete(&sparseMatrix, delRow, delCol);

    printf("\nSparse Matrix after deletion:\n");
    display(sparseMatrix);

    // Freeing memory
    while (sparseMatrix != NULL) {
        delete(&sparseMatrix, sparseMatrix->row, sparseMatrix->col);
    }

    return 0;
}