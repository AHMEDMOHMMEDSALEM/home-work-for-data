#include <stdio.h>
#include <stdlib.h>

// Defining structure for student information
typedef struct Student {
    int student_number;
    char name[50];
    int age;
    struct Student *next;
} Student;

// Function to insert student information into the linked list
void insert_student(Student **head, int student_number, char *name, int age) {
    Student *new_student = (Student *) malloc(sizeof(Student));
    new_student->student_number = student_number;
    strcpy(new_student->name, name);
    new_student->age = age;
    new_student->next = *head;
    *head = new_student;
}

// Function to print student information
void print_student_info(Student *node) {
    while (node != NULL) {
        printf("Student Number: %d\n", node->student_number);
        printf("Name: %s\n", node->name);
        printf("Age: %d\n\n", node->age);
        node = node->next;
    }
}

// Function to count the number of students in the linked list
int count_students(Student *node) {
    int count = 0;
    while (node != NULL) {
        count++;
        node = node->next;
    }
    return count;
}

int main() {
    Student *head = NULL;

    // Inserting students into the linked list
    insert_student(&head, 1, "Alice", 22);
    insert_student(&head, 2, "Bob", 23);
    insert_student(&head, 3, "Charlie", 24);

    // Printing student information and counting the number of students
    print_student_info(head);
    int count = count_students(head);
    printf("Number of students: %d\n", count);

    return 0;
}
