#include <stdio.h>
#include <stdlib.h>

void mergesort(int *arr, int start, int end);
void merge(int *arr1, int start, int mid, int end);

int main(void) {
	int array[] = {4,3,2,1,9};
	mergesort(array, 0, 4);
	
	printf("\nThe elements of the array are : ");
	for(int i = 0; i < 5; i++){
	    printf("%d ",array[i]);
	}
	
	return 0;
}

void mergesort(int *arr, int start, int end)
{
    if(start >= end)
        return;
    
    int middle = (start + end) / 2;
    
    mergesort(arr, start, middle);
    mergesort(arr, middle + 1, end);
    merge(arr, start, middle, end);
}

void merge(int *array, int s, int m, int e)
{
    int i = s;
    int j = m + 1;
    
    int *tempArray = (int *)malloc(sizeof(int) * (e - s + 1));
    int k = 0;
    
    while((i <= m) && (j <= e)){
        if(array[i] <= array[j]){
            tempArray[k] = array[i];
            i++;
        }
        else{
            tempArray[k] = array[j];
            j++;
        }
        k++;
    }
    
    while(i <= m){
        tempArray[k++] = array[i++];
    }
    
    while(j <= e){
        tempArray[k++] = array[j++];
    }
    
    k = 0;
    for(int i = s; i <= e; i++){
        array[i] = tempArray[k];
        k++;
    }
}

void displayElements(int *a, int s, int e)
{
    printf("\n");
    for(int i = s; i <= e; i++){
        printf("%d ",a[i]);
    }
}
