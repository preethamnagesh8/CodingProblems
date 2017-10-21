#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 100

struct listStruct{
    int number;
    struct listStruct *next;
};
typedef struct listStruct list;

list* allocateNode();
void displayElementsOfAList(list *l);
void insertAtFirst(list **l, int num);
bool searchElement(list *l, int num);

int main(void)
{
    list *newList = allocateNode();
    newList->number = 10;
    newList->next = NULL;
    
    insertAtFirst(&newList, 9);
    insertAtFirst(&newList, 8);
    insertAtFirst(&newList, 7);
    insertAtFirst(&newList, 6);
    
    displayElementsOfAList(newList);
    
    printf("\n%d",searchElement(newList,10));
    
	return 0;
}

list* allocateNode()
{
    return (list *) malloc(sizeof(list));    
}

void displayElementsOfAList(list *l)
{
    if(l == NULL){
        printf("\nThere are no elements in the list");
        return;
    }
    
    printf("\nThe elements of the list are : ");
    while(l->next != NULL){
        printf("%d ",l->number);
        l = l->next;
    }
    printf("%d",l->number);
}

void insertAtFirst(list **l, int num)
{
    list *temp = allocateNode();
    temp->number = num;
    temp->next = *l;
    *l = temp;
}

bool searchElement(list *l, int n)
{
    while(l){
        if(l->number == n)
            return true;
        l = l->next;
    }
    return false;
}
