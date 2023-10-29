#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    char name[50];
    int age;
    float gpa;
} Record;

void searchByName(Record* records, int numOfRecords, char* searchName) {
    int found = 0;

    for (int i = 0; i < numOfRecords; i++) {
        if (strcmp(records[i].name, searchName) == 0) {
            printf("Found: Name - %s, Age - %d, GPA - %.2f\n", records[i].name, records[i].age, records[i].gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No student found with the name '%s'\n", searchName);
    }
}

int main() {
    Record records[] = {
        {"Alice", 21, 3.5},
        {"Bob", 20, 3.2},
        {"Charlie", 22, 3.8},
        {"David", 21, 3.7},
        {"Eve", 20, 3.6}
    };

    int numOfRecords = sizeof(records) / sizeof(records[0]);

    char searchName[50];
    printf("Enter a student name to search: ");
    scanf("%s", searchName);

    searchByName(records, numOfRecords, searchName);

    return 0;
}
