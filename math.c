#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<math.h>

#define MAX 20

struct stack {
    int items[MAX];
    int tos;
};

int isEmpty(struct stack s) {
    return s.tos == -1;
}

int isFull(struct stack s) {
    return s.tos == MAX - 1;
}

void push(struct stack *s, int val) {
    if (!isFull(*s)) {
        s->items[++s->tos] = val;
    }
}

int pop(struct stack *s) {
    if (!isEmpty(*s)) {
        return s->items[s->tos--];
    }
    return 0;
}

int main() {
    struct stack s;
    s.tos = -1;

    char exp[MAX];
    int i, value, op1, op2;

    printf("Enter a valid postfix expression: ");
    fgets(exp, MAX, stdin);
    exp[strcspn(exp, "\n")] = '\0'; 

    for (i = 0; i < strlen(exp); i++) {
        if (isspace(exp[i])) {
            continue;
        } else if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');
        } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            op2 = pop(&s);
            op1 = pop(&s);

            switch (exp[i]) {
                case '+': value = op1 + op2; break;
                case '-': value = op1 - op2; break;
                case '*': value = op1 * op2; break;
                case '/':
                    if (op2 != 0) value = op1 / op2;
                    else {
                        printf("Error: Division by zero\n");
                        return 1;
                    }
                    break;
            }
            push(&s, value);
        }
     }

    printf("Final value of expression: %d\n", pop(&s));

    return 0;
 }
 // evaluate the following postfix expression:
 // a) AB-CDEF/+G-*_H
 // WHERE A=4, B=8,C=2,D=5,E=6,F=9,G=1, H=3

