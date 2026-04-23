/* design a menu driven application that implentets general list 
example of empolyee management system 
available fuctionality :
1.Employee registration 
2.update of employee record  
3.listing all employee 
4.remove a specific employee
5.search a specific employee ( by name or id )
*/

#include <stdio.h>
#include <string.h>

#define MAX 100   // maximum number of employees

// Employee structure
struct Employee {
    int id;
    char name[50];
    float salary;
};

struct Employee empList[MAX];
int count = 0;

// Function prototypes
void addEmployee();
void updateEmployee();
void listEmployees();
void removeEmployee();
void searchEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n========= Employee Management System =========\n");
        printf("1. Employee Registration\n");
        printf("2. Update Employee Record\n");
        printf("3. List All Employees\n");
        printf("4. Remove a Specific Employee\n");
        printf("5. Search an Employee (by Name or ID)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: updateEmployee(); break;
            case 3: listEmployees(); break;
            case 4: removeEmployee(); break;
            case 5: searchEmployee(); break;
            case 6: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

// 1. Add Employee
void addEmployee() {
    if (count >= MAX) {
        printf("Employee list is full!\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &empList[count].id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]s", empList[count].name);

    printf("Enter Salary: ");
    scanf("%f", &empList[count].salary);

    count++;
    printf("Employee added successfully!\n");
}

// 2. Update Employee
void updateEmployee() {
    int id, i, found = 0;
    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (empList[i].id == id) {
            printf("Enter New Name: ");
            scanf(" %[^\n]s", empList[i].name);
            printf("Enter New Salary: ");
            scanf("%f", &empList[i].salary);
            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}

// 3. List All Employees
void listEmployees() {
    if (count == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\n--- Employee List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Salary: %.2f\n",
               empList[i].id, empList[i].name, empList[i].salary);
    }
}

// 4. Remove Employee
void removeEmployee() {
    int id, i, j, found = 0;
    printf("Enter Employee ID to remove: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (empList[i].id == id) {
            for (j = i; j < count - 1; j++) {
                empList[j] = empList[j + 1];  // shift elements left
            }
            count--;
            found = 1;
            printf("Employee removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}

// 5. Search Employee
void searchEmployee() {
    int id, choice, found = 0;
    char name[50];

    printf("Search by:\n1. ID\n2. Name\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter ID: ");
        scanf("%d", &id);

        for (int i = 0; i < count; i++) {
            if (empList[i].id == id) {
                printf("Found → ID: %d | Name: %s | Salary: %.2f\n",
                       empList[i].id, empList[i].name, empList[i].salary);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        printf("Enter Name: ");
        scanf(" %[^\\n]s", name);

        for (int i = 0; i < count; i++) {
            if (strcmp(empList[i].name, name) == 0) {
                printf("Found → ID: %d | Name: %s | Salary: %.2f\n",
                       empList[i].id, empList[i].name, empList[i].salary);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}
