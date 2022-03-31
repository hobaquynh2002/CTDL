#include <stdio.h>
#include <stdlib.h>
void hienThi(int arr[],int n){
	int i;
	for(i = 0; i< n; i++ ){
		printf("%d ", arr[i]);
	}
}

void sort(int arr[],int n){
	int i, j;
	for(i = 0; i< n-1; i++){
		for(j= n-1; j> i; j-- ){
			if(arr[j] < arr[j-1]){
				int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] =tmp;
			}
		}
	}
}
int binarySearch( int arr[], int x ,int n){
	int left = 0, right = n-1;
	while(left <= right){
		int mid = (left+right)/2;
		if(arr[mid] == x)
			return 1; // tim thay
		else if(arr[mid] < x) 
			left = mid+1;
		else right = mid-1;
	}
	return 0;
}

int main(){
	int n,i;
	printf("Nhap n: ");
	scanf("%d", &n);
	int arr[n];
	for(i = 0; i< n; i++ ){
		scanf("%d", &arr[i]);
	}
	sort(arr,n);
	hienThi(arr,n);
	printf("\n");
	int ch,x;
	while(1){
		printf("1.Nhap x: \n");
        printf("2.Thoat\n");
		printf("Nhap lua chon:\n");
		scanf("%d", &ch);
		switch(ch){
			case(1):{
				printf("\nNhap x:");scanf("%d", &x);
				if(binarySearch(arr, x,n)){
					printf("\nTim thay x.\n");
				}else {
					printf("\nKhong tim thay x\n.");
				}
				break;
			}
			case(2):{
                exit(0);
            }
			default: {
                printf("Khong co chuc nang nay!");
                break;
            }
        }
	}
	return 0;
}	
	
