// WAP to implement ascending priority queue
#include <stdio.h>
#define MAX 10

struct queue {
    int rear;
    int item[MAX];
};

int isempty(struct queue *q) {
    return (q->rear == -1);
}

int isfull(struct queue *q) {
    return (q->rear == MAX - 1);
}

void enqueue(struct queue *q) {
    if (isfull(q)) {
        printf("Queue is full\n");
    } else {
        q->rear++;
        printf("Enter the number: ");
        scanf("%d", &q->item[q->rear]);
        printf("%d item inserted successfully.\n", q->item[q->rear]);
    }
}

int getsmallestposition(struct queue *q) {
    int p = 0;
    for (int i = 1; i <= q->rear; i++) {
        if (q->item[i] < q->item[p]) {
            p = i;
        }
    }
    return p;
}

void dequeue(struct queue *q) {
    if (isempty(q)) {
        printf("Queue is empty\n");
    } else {
        int pos = getsmallestposition(q);
        printf("%d was dequeued from the queue.\n", q->item[pos]);
        // Now shift all the remaining items to the left
        for (int i = pos; i < q->rear; i++) {
            q->item[i] = q->item[i + 1];
        }
        q->rear--;
    }
}

void display(struct queue *q) {
    if (isempty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("The items in the queue are:\n");
        for (int i = 0; i <= q->rear; i++) {
            printf("%d\n", q->item[i]);
        }
    }
}

int main() {
    struct queue q;
    q.rear = -1;  //Empty queue
    do {
        printf("Select an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        int ch = getchar();
        switch (ch) {
            case '1':
                enqueue(&q);
                break;
            case '2':
                dequeue(&q);
                break;
            case '3':
                display(&q);
                break;
            case '4':
                return 0;
        }
        fflush(stdin);
        getchar();
    } while (1);
    return 0;
}