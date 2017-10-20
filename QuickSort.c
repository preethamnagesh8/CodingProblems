#include <stdio.h>

void quicksort(int *, int, int);
int partition(int *arr, int start, int end);
void display(int* arr, int len);

int main(void) 
{
    int array[] = {5, 3, 8, 9, 4, 6};
    display(array, 6);
    quicksort(array, 0, 5);
    display(array, 6);
	return 0;
}

void quicksort(int *arr, int start, int end)
{
    if(start < end){
        int pivotPosition = partition(arr, start, end);
        quicksort(arr, start, pivotPosition-1);
        quicksort(arr, pivotPosition + 1, end);
    }
}

int partition(int *arr, int start, int end)
{
    int pivotPos = end;
    int pivotVal = arr[pivotPos];
    int i = start;
    int j = end - 1;
    
    while(i < j){
        while(arr[i] < pivotVal && i < end)
            i++;
        
        while(arr[j] > pivotVal && j > start)
            j--;
            
        swap(arr, i, j);
    }
    swap(arr, i, j);
    
    if(arr[i] > arr[pivotPos])
        swap(arr, i, pivotPos);
        
    return i;
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void display(int* arr, int len)
{
    printf("\nThe elements of the array are : ");
    for(int i = 0; i < len; i++){
        printf("%d ",arr[i]);
    }
}
