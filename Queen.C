#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//vị trí đặt con Hậu đặt là 1 ,các vị trí còn lại đặt là 0
void results(int a[][8],int n){
	//in kết quả
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
bool check(int a[][8], int row, int col){
	int i,j;
	//ktra col, chỉ cần ktra đến col mình đang đặt k cần ktra hết
	//đặt từ trái sang phải
	for(i=0;i<col;i++){
		if(a[row][i]==1){
			return false;
		}
	}
	//ktra chéo trên
	i = row;j=col;
	while (i>=0 && j>=0){
		if(a[i][j]==1){
			return false;
		}
		i--;j--;
	}
	//ktra chéo dưới
	i = row;j=col;
	while (i< 8 && j>=0){
		if(a[i][j]==1){
			return false;
		}
		i++;j--;
	}
	return true;
}
bool setQueens(int a[][8], int col){
	int i;
	if(col>=8){
		return true;
	}
	for(i=0; i<8;i++){
		if(check(a, i, col)){
			a[i][col]=1;//đặt Hậu
			if(setQueens(a, col+1)){
				return true;
			}
			a[i][col] = 0;//quay lui
		}
	}
	return false;
}
int main(){
	int i,j,a[8][8];
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			a[i][j] =0;
		}
	}
	
	if(setQueens(a,0)){
		results(a,8);
	}else{
		printf("Error!");
	}
	return 0;
}