#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define SIZE 20

typedef struct
{
    int elements[STACK_SIZE];
    int top;
}stack;

int main()
{
    stack s;
    s.top = -1;
    char str[SIZE] = "5+9*3";
    
    convertToPostfix(str, &s);
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
    if(s->top >= 0){
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

int stackTop(stack *s)
{
    return s->elements[s->top];
}

int isDig(int c)
{
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}

int myStrLen(char *str)
{
    int i;
    for(i = 0; str[i] != '\0'; i++);
    return i;
}

void strAppend(char* str, int c)
{
    int i = 0;
    for(i = 0; str[i] != '\0'; i++);
    str[i] = c;
    str[i + 1] = '\0';
}

int checkPriority(stack *s, int optr)
{
    if(stackTop(s) == '*' && optr == '+')
        return 1;
    return 0;
}

void convertToPostfix(char *str, stack *stck)
{
    char *postFixString = (char *)(malloc(SIZE * sizeof(char)));
    
    for(int i = 0; str[i] != '\0'; i++){
        if(isDig(str[i]))
            strAppend(postFixString, str[i]);
        else{
            if(checkPriority(stck, str[i])){
                int num = pop(stck);
                strAppend(postFixString, num);
                push(stck, str[i]);
            }
            else{
                push(stck, str[i]);
            }
        }
    }
    
    while(stck->top >= 0){
        int num = pop(stck);
        strAppend(postFixString, num);
    }
    
    printf("\n%s",postFixString);
}
