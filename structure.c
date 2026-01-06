#include <stdio.h>

#define MAX 50

// Structure definition
struct Student {
    int roll;
    char name[20];
    int m1, m2, m3;
};

// Function declarations
void addStudent(struct Student s[], int *n);
void displayStudents(struct Student s[], int n);
void searchStudent(struct Student s[], int n);
float calculateAverage(struct Student st);

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}

// Function to add student
void addStudent(struct Student s[], int *n) {
    if(*n >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("\nEnter Roll No: ");
    scanf("%d", &s[*n].roll);

    printf("Enter Name: ");
    scanf("%s", s[*n].name);

    printf("Enter 3 Marks: ");
    scanf("%d %d %d",
          &s[*n].m1,
          &s[*n].m2,
          &s[*n].m3);

    (*n)++;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents(struct Student s[], int n) {
    int i;

    if(n == 0) {
        printf("No student records available!\n");
        return;
    }

    for(i = 0; i < n; i++) {
        printf("\nRoll No: %d", s[i].roll);
        printf("\nName   : %s", s[i].name);
        printf("\nMarks  : %d %d %d",
               s[i].m1, s[i].m2, s[i].m3);
        printf("\nAverage: %.2f\n",
               calculateAverage(s[i]));
    }
}

// Function to search student
void searchStudent(struct Student s[], int n) {
    int roll, i, found = 0;

    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    for(i = 0; i < n; i++) {
        if(s[i].roll == roll) {
            printf("\nStudent Found!");
            printf("\nName   : %s", s[i].name);
            printf("\nMarks  : %d %d %d",
                   s[i].m1, s[i].m2, s[i].m3);
            printf("\nAverage: %.2f\n",
                   calculateAverage(s[i]));
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Student not found!\n");
}

// Function to calculate average
float calculateAverage(struct Student st) {
    return (st.m1 + st.m2 + st.m3) / 3.0;
}
