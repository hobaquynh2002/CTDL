#include <stdio.h>
#include <stdlib.h>
void quicksort(int a[],int l,int r){
    if(l>=r)return;
    int pivot=a[(l+r)/2];
    int i=l , j=r;
    do{
        while(a[i]<pivot) i++;
        while(a[j]>pivot) j--;
        if(i<=j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;j--;
        }
    }while(i<j);
    quicksort(a,l,j);
    quicksort(a,i,r);
}
int main(){
    int *a,n,i;
    scanf("%d",&n);
    a=(int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++){
        scanf("%d",a+i);
    }
    quicksort(a,0,n-1);
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
}