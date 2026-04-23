//implement doubly linked list
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node* header(int data) {
    struct node*ptrNew;
    ptrNew = (struct node*)malloc(sizeof(struct node));
    if(ptrNew == NULL) {
        printf("Memory not allocated\n");
        exit(0);
    }
    ptrNew->data = data;
    ptrNew->next = ptrNew->prev = NULL;
    return ptrNew;
  }
  int main() {
    char choice;
    do{
        system("cls");
        printf("select an option:\n1. Insert at Front\n2. Insert at End\n");
        printf("3. Insert Beore\n4. Insert After\n5. Display\n6.Exit\n");
        printf("6. Remove from End\n7. Remove Any\n8. Display List\n9. Exit\n");
        fflush(stdin); 
        choice = getchar();
        switch(choice) {
            case '1':insertFront();break;
            case '2':insertEnd();break;
            case '3':insertBefore();break;
            case '4':insertAfter();break;
            case '5':display();break;
            case '6':removeEnd();break;
            case '7':removeAny();break;
            case '8':displayList();break;
            case '9':exit(0);
            default:printf("Invalid choice, try again\n");
        }
        fflush(stdin);  
    }}