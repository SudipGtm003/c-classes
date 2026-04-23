//circular queue implementation using arrary
#include<stdio.h>
#include<stdlib.h>
#define max 5
#define true 1
#define false 0

struct queue{
    int front;
    int rear;
    int item[max];
};
int getnext(int p){
    /*p++;
    if(p==max){
        p=0;
    }
    return p;*/
    
    return (p+1)%max;
}
int isempty(struct queue *q){
    if(q->front==q->rear){
        return true;
    }
    else{
        return false;
    }

}

int isfull(struct queue *q){
    if(q->front==getnext(q->rear)){
        return true;        
    }
    else{
        return false;
    }
}

void insert(struct queue *q){
    if(isfull(q)){
        printf("queue is full\n");
    }
    else{
        q->rear=getnext(q->rear);
        printf("enter the number:");
        scanf("%d",&q->item[q->rear]);
        printf("%d Item inserted succesfully.",q->item[q->rear]);
    }
}
void dequeue(struct queue *q){
    if(isempty(q)){
        printf("queeue is empty.");
    }
    else{
        q->front=getnext(q->front);
        printf("%d was removed from the queeue.", q->item[q->front]);
    }
}

void display(struct queue *q){
    if(isempty(q)){
        printf("queue is empty.");
    }
    else{
        printf("queue contains:\n");
        for(int i=getnext(q->front);i!=getnext(q->rear);i=getnext(i)){
            printf("%d ",q->item[i]);
        }
    }
}
int main(){

    struct queue q;
    char choice;
    q.rear=q.front=max-1;// empty value
    do{
        system("cls");
        printf("enter your choice:\n1.insert\n2.delete\n3.display\n4.exit\n");
        fflush(stdin);
        choice=getchar();
        switch(choice){
            case '1':
                insert(&q);
                break;
            case '2':
                dequeue(&q);
                break;
            case '3':
                display(&q);
                break;
            case '4':
                return 0;;
        }
        fflush(stdin);
        choice=getchar();
    }while(true);


}