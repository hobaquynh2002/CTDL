#include <stdio.h>
#include <stdlib.h>
void merge(int l,int m,int r,int a[]){
    int i=l,j=m+1,k,h;
    int n =r-l+1;
    int *b=(int *)malloc(n * sizeof(int));
    for(k=0;k<=r-l;k++){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
        }else{
            b[k]=a[j];
            j++;
        }

        if(i==m+1){
            while(j<=r){
                k++;
                b[k]=a[j];
                j++;
            }
            break;
        }
        if(j==r+1){
            while(i<=m){
                k++;
                b[k]=a[i];
                i++;
            }
            break;
        }
    }    
    for(k=0;k<=r-l;k++){
        a[k+l]=b[k];
    }
    free(b);
}
void mergesort(int l,int r,int a[]){
    if(l<r){
        int m=(l+r)/2;
        mergesort(l,m,a);
        mergesort(m+1,r,a);
        merge(l,m,r,a);
    }
}

int main(){
    int *a,n,i;
    scanf("%d",&n);
    a=(int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d",a+i);
    }
    mergesort(0,n-1,a);
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    
}
