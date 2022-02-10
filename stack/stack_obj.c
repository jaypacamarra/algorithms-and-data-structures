#include <stdio.h>
#include <stdlib.h>

void stackPush(int x) {
    printf("pushed %d\n",x);
}

typedef struct {
	int top;
    void (*push)(int);
}stack_t;

stack_t createStack() {
    stack_t st;
	st.top = -1;
    st.push = stackPush;
    return st;
}

int main() {
    stack_t myStack = createStack();
    myStack.push(5);
    myStack.push(915);
    printf("top=%d\n",myStack.top);

    return 0;
}
