#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert(Node **head, int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int number;
    printf("Enter numbers: ");
    while (1) {
        scanf("%d", &number);
        if (number == -1)
            break;
        if (number % 2 != 0)
            insert(&head, number);
        else {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            insert(&(temp->next), number);
        }
    }
    printf("Created list: ");
    display(head);
    return 0;
}
