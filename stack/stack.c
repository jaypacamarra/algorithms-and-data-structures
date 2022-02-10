#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE  5
int stack[STACK_SIZE];
int top = -1;

void push(int x) {
    if(STACK_SIZE==top+1)
        printf("STACK OVERFLOW\n");
    else
        stack[++top] = x;
}

int pop() {
    if(-2==top-1) {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
    else
        return stack[top--];
}

int peek() {
    return stack[top];
}
void display() {
    printf("stack: ");
    for(int i=0;i<=top;i++)
        printf("%d ",stack[i]);
    puts("");
}

int main() {

    push(5);
    push(9);
    push(1);
    push(4);
    push(8);
    push(9);
    printf("peek: %d\n",peek());
    pop();
    pop();
    printf("peek: %d\n",peek());

    return 0;
}
