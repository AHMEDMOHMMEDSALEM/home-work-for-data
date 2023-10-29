#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    char name[100];
    int age;
    struct Record* next;
} Record;

void printRecordWithLongestName(Record* head) {
    Record* current = head;
    Record* longestNameRecord = NULL;
    int longestNameLength = 0;

    while (current != NULL) {
        int currentNameLength = strlen(current->name);

        if (currentNameLength > longestNameLength) {
            longestNameLength = currentNameLength;
            longestNameRecord = current;
        }

        current = current->next;
    }

    if (longestNameRecord != NULL) {
        printf("Student with longest name: %s, Age: %d\n", longestNameRecord->name, longestNameRecord->age);
    } else {
        printf("No student records to display.\n");
    }
}

// Function to insert a new student record to the list
void insertRecord(Record** head, char* name, int age)
