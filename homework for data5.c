#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[100];
    int age;
    struct Node* next;
} Node;

Node* newNode(char* name, int age) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->age = age;
    node->next = NULL;
    return node;
}

void deleteNextNode(Node** head, char* search_name) {
    Node* current = *head;

    while (current != NULL) {
        if (strcmp(current->name, search_name) == 0) {
            if (current->next != NULL) {
                Node* nextNode = current->next;
                current->next = nextNode->next;
                free(nextNode);
            } else {
                printf("No student next to the searched student to delete.\n");
            }
            return;
        }
        current = current->next;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("Student: %s, Age: %d\n", current->name, current->age);
        current = current->next;
    }
}

int main() {
    Node* head = newNode("Alice", 22);
    head->next = newNode("Bob", 24);
    head->next->next = newNode("Charlie", 25);

    printf("Original list:\n");
    printList(head);

    deleteNextNode(&head, "Alice");

    printf("\nList after deleting the next node of Alice:\n");
    printList(head);

    return 0;
}
