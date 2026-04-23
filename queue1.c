#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
#define MAX 10
struct queue{
    int front;
    int rear;
    int items[MAX];
};
int isfull(struct queue *q){
    if(q->rear==MAX-1)
    return true;
    else 
    return false;
}
int isempty(struct queue *q){
    if(q->front>q->rear)
    return true;
    else 
    return false;
}


void enqueue(struct queue*q){
    int num;
    if(q->rear==MAX-1)
        printf("queue is full");
    else{
        printf("enter a number : ");
        scanf("%d",&num);
        q->items[++q->rear]=num;
        printf("%d added successfully",num);
    }
}
void dequeue(struct queue*q)
{
    if(isempty(q))
    printf("queue is empty");
    else
        printf("%d was removed from the queue",q->items[q->front++]);

}
void display(struct queue*q){
    if(isempty(&q))
        printf("queue is empty");
    else{
        printf("queue contains: ");
        for(int i=q->front;i<=q->rear;i++)
            printf("%d ",q->items[i]);
    }
}



int main(){
    struct queue q;
    q.front = 0;// empty :front>rear
    q.rear = -1;
    int choice;
    do{
        system("cls");
        printf("select an option\n1. enqueue\n2. dequeue\n3. display\n4. exit");
        
        scanf("%d",&choice);
        fflush(stdin);

        switch(choice){
            case 1:
                enqueue(&q);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("exiting...");
                return 0;
            default:
                printf("invalid choice");
        }
        printf("\npress enter to continue...");
        getchar();
    
    }while(true);

    return 0;
}
