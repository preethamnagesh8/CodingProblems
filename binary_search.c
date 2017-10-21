#include <stdio.h>

int binarySearch(int *array, int start, int end, int elem);

int main(void) 
{
    int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    printf("Position : %d",binarySearch(array, 0, 14, 2));
	return 0;
}

int binarySearch(int *array, int s, int e, int elem)
{
    if(s >= e && array[s] == elem)
        return s;
    if(s >= e)
        return -1;
    
    int mid = (s + e) / 2;
    int n1,n2;
    
    if(array[mid] == elem){
        //printf("Here 1");
        return mid;
    }
    else if(array[mid] < elem){
        //printf("Here 2");
        return binarySearch(array, mid + 1, e, elem);
    }
    else{
        //printf("Here 3");
        return binarySearch(array, s, mid - 1, elem);
    }
}
