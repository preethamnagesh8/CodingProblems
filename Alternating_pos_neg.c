#include <stdio.h>

int* partition(int *arr, int len);
void swap(int *arr, int i, int j);

int main()
{
    int array[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int *a = partition(array, 9);
    displayElements(a, 9);
    alternatingArray(array, 9);
    displayElements(a, 9);
}

int* partition(int *arr, int len)
{
    int pivot = 0;
    int i = 0, j = len - 1;
    
    while((i < len) && (j >= 0) && (i < j)){
        
        while(arr[i] > pivot)
            i++;
        
        while(arr[j] < pivot)
            j--;
        
        swap(arr, i, j);
        
    }
    swap(arr, j, i);
    return arr;
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void displayElements(int *arr, int len)
{
    printf("\nArray Elements are : ");
    for(int i = 0; i < len; i++){
        printf("%d ",arr[i]);
    }
}

void alternatingArray(int *arr, int len)
{
    for(int i = 1, j = len-1; i < j; i = i + 2,j--){
        if(arr[i] > arr[j])
            swap(arr, i, j);
    }
}
