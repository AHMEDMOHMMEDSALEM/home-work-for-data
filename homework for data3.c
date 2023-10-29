#include <stdio.h>
#include <stdlib.h>


typedef struct Student {
    int student_number;
    char name[50];
    int age;
    struct Student *next;
} Student;


void insert_student(Student **head, int student_number, char *name, int age) {
    Student *new_student = (Student *) malloc(sizeof(Student));
    new_student->student_number = student_number;
    strcpy(new_student->name, name);
    new_student->age = age;
    new_student->next = *head;
    *head = new_student;
}


void print_student_info(Student *node) {
    while (node != NULL) {
        printf("Student Number: %d\n", node->student_number);
        printf("Name: %s\n", node->name);
        printf("Age: %d\n\n", node->age);
        node = node->next;
    }
}


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

  
    insert_student(&head, 1, "Alice", 22);
    insert_student(&head, 2, "Bob", 23);
    insert_student(&head, 3, "Charlie", 24);


    print_student_info(head);
    int count = count_students(head);
    printf("Number of students: %d\n", count);

    return 0;
}
