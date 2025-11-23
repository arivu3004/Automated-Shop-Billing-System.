#include <stdio.h>
#include <string.h>

#define MAX 100
#define NAME_LEN 50

void addStudent(char names[][NAME_LEN], int attendance[], int *count);
void markAttendance(char names[][NAME_LEN], int attendance[], int count);
void viewAttendance(char names[][NAME_LEN], int attendance[], int count);

int main() {
    char names[MAX][NAME_LEN];
    int attendance[MAX];
    int count = 0;
    int choice;

    while (1) {
        printf("\n===== STUDENT ATTENDANCE MANAGER =====\n");
        printf("1. Add Student\n");
        printf("2. Mark Daily Attendance\n");
        printf("3. View Attendance Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            addStudent(names, attendance, &count);
            break;

        case 2:
            markAttendance(names, attendance, count);
            break;

        case 3:
            viewAttendance(names, attendance, count);
            break;

        case 4:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

void addStudent(char names[][NAME_LEN], int attendance[], int *count) {
    if (*count >= MAX) {
        printf("Limit reached! Cannot add more students.\n");
        return;
    }

    printf("Enter student name: ");
    scanf(" %[^\n]", names[*count]);

    attendance[*count] = 0; 
    (*count)++;

    printf("Student added successfully!\n");
}

void markAttendance(char names[][NAME_LEN], int attendance[], int count) {
    if (count == 0) {
        printf("No students available! Add students first.\n");
        return;
    }

    printf("\n--- Mark Daily Attendance ---\n");
    printf("Enter 1 for Present, 0 for Absent\n");

    for (int i = 0; i < count; i++) {
        int present;
        printf("%d. %s: ", i + 1, names[i]);
        scanf("%d", &present);

        if (present == 1)
            attendance[i]++;
    }

    printf("Attendance marked successfully!\n");
}

void viewAttendance(char names[][NAME_LEN], int attendance[], int count) {
    if (count == 0) {
        printf("No records to display!\n");
        return;
    }

    printf("\n===== ATTENDANCE REPORT =====\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %-20s  Classes Attended: %d\n", i + 1, names[i], attendance[i]);
    }
}