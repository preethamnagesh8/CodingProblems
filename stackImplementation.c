#include <stdio.h>

#define STACK_SIZE 100

typedef struct
{
    int elements[STACK_SIZE];
    int top;
}stack;

int main()
{
    stack s;
    s.top = -1;
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("\nThe size of stack is : %d",s.top);
    
    int p1 = pop(&s);
    displayElements(&s);
    return 0;
}

void push(stack *s, int num)
{
    if (s->top <= STACK_SIZE){
        s->elements[++s->top] = num;
    }
    else
        printf("Stack is full");
}

int pop(stack *s)
{
    if(s->top > 0){
        return (s->elements[s->top--]);
    }
    return -1;
}

void displayElements(stack *s)
{
    printf("\nThe elements of the stack are : ");
    for(int i = 0; i <= s->top; i++){
        printf("\n %d ",s->elements[i]);
    }
}
