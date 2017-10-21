#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

typedef struct{
    int elements[SIZE];
    int front;
    int end;
}queue;

void enqueue(queue *q, int num);
int dequeue(queue *q);
bool isFull(queue *q);
bool isEmpty(queue *q);
void displayElements(queue *q);

int main(void) {
	queue que;
	que.front = 0;
	que.end = 0;
	
	enqueue(&que, 10);
	enqueue(&que, 20);
	enqueue(&que, 30);
	enqueue(&que, 30);
	enqueue(&que, 30);
	//enqueue(&que, 30);
	displayElements(&que);
	int num1 = dequeue(&que);
	displayElements(&que);
	
	return 0;
}

bool isFull(queue *q)
{
    if((q->end + 1) % SIZE == q->front)
        return true;
    return false;
}

bool isEmpty(queue *q)
{
    if(q->front == q->end)
        return true;
    return false;
}

void enqueue(queue *q, int num)
{
    if(!isFull(q))
        q->elements[q->end++] = num;
    else
        printf("\nQueue Full");
}

int dequeue(queue *q)
{
    if(!isEmpty(q))
        return (q->elements[++q->front]);
    
    printf("\nQueue empty");
    return -1;
}

void displayElements(queue *q)
{
    printf("\nThe elements of the queue are : ");
    for(int i = q->front; i < q->end; i++)
        printf("%d ",q->elements[i]);
}
