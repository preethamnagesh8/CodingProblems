#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 5

void quicksort(int arr[], int start, int end);
int partition(int arr[], int start, int end);

int main() {

    int array[SIZE];
    int length = 0;
    
    for(int i = 0; i < SIZE - 1; i++){
        scanf("%d",&array[i]);
        length++;
    }
    
    quicksort(array, 0 , length-1);
    
    printf("\nThe sorted array : ");
    for(int i = 0; i < SIZE - 1; i++){
        printf("%d\n",array[i]);
    }
    
    return 0;
}

void quicksort(int arr[], int start, int end)
{
    if(start < end){
        int part = partition(arr, start, end);
        quicksort(arr, start, part - 1);
        quicksort(arr, part + 1, end);
    }
}

int partition(int arr[], int start, int e)
{
    int pivot = arr[start];
    int i = start + 1;
    int j = e;
    
    while(i <= j){
        
        while(arr[i] <= pivot && i <= e)
            i++;
        
        while(arr[j] >= pivot && j > start)
            j--;
        
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
    
    t = arr[j];
    arr[j] = arr[start];
    arr[start] = t;
    
    return j;
}

