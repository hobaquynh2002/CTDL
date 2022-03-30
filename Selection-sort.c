#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void selectionSort(int arr[], int n){
	int i, j, min;
	for (i = 0; i < n-1; i++){
		min = i;
		for (j = i+1; j < n; j++)
		// if (arr[j] < arr[min])
		// 	min = j;
        min=(arr[j] > arr[min])?min:j;    
		swap(&arr[min], &arr[i]);
	}
}
void printArray(int arr[], int size){
	int i;
	for (i=0; i < size; i++){
		printf("%d ", arr[i]);
    }    
	printf("\n");
}
int main(){
	int *arr,n,i;
    printf("Nhap so luong ptu: ");
    scanf("%d",&n);
    arr=(int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++){
        scanf("%d",arr+i);
    }
	selectionSort(arr, n);
	printArray(arr, n);
    free(arr);
	return 0;
}
