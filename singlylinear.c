// WAP to implement Singly Linked List
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct node {
    int data;
    struct node *next;
};
struct node* getNode(int data) {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}
void addItem(struct node **head) {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    struct node *newNode = getNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}
void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void removeFront(struct node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = *head;
    *head = temp->next;
    free(temp);
    printf("Removed from front.\n");
}
void removeEnd(struct node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Removed from end.\n");
        return;
    }

    struct node *temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    printf("Removed from end.\n");
}
void removeAny(struct node **head) {
    int key;
    printf("Enter value to remove: ");
    scanf("%d", &key);

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->data == key) {
        struct node *temp = *head;
        *head = temp->next;
        free(temp);
        printf("Item removed.\n");
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Item not found.\n");
    } else {
        struct node *del = temp->next;
        temp->next = del->next;
        free(del);
        printf("Item removed.\n");
    }
}
void insertAfter(struct node *head) {
    int key, data;
    printf("Insert after which value: ");
    scanf("%d", &key);
    printf("Enter data: ");
    scanf("%d", &data);

    while (head != NULL && head->data != key)
        head = head->next;

    if (head == NULL) {
        printf("Value not found.\n");
    } else {
        struct node *newNode = getNode(data);
        newNode->next = head->next;
        head->next = newNode;
        printf("Inserted successfully.\n");
    }
}
void insertBefore(struct node **head) {
    int key, data;
    printf("Insert before which value: ");
    scanf("%d", &key);
    printf("Enter data: ");
    scanf("%d", &data);

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->data == key) {
        struct node *newNode = getNode(data);
        newNode->next = *head;
        *head = newNode;
        printf("Inserted successfully.\n");
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Value not found.\n");
    } else {
        struct node *newNode = getNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted successfully.\n");
    }
}

int main() {
    struct node *list = NULL;
    int choose;

    do {
        system("cls");  
        printf("======== MENU ========\n");
        printf("1. Add Item\n");
        printf("2. Display Item\n");
        printf("3. Insert Before\n");
        printf("4. Insert After\n");
        printf("5. Remove from front\n");
        printf("6. Remove from end\n");
        printf("7. Remove any\n");
        printf("8. Exit\n");
        printf("Select an Option: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1: addItem(&list); break;
            case 2: display(list); break;
            case 3: insertBefore(&list); break;
            case 4: insertAfter(list); break;
            case 5: removeFront(&list); break;
            case 6: removeEnd(&list); break;
            case 7: removeAny(&list); break;
            case 8: exit(0);
            default: printf("Invalid Option.\n");
        }

        printf("\nPress any key to continue...");
        getchar();
        getchar();

    } while (TRUE);

    return 0;
}
