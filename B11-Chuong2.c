#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//3 6 4 9 2 5
int main(void){
    int a[50];
    int i,j,max,n,k=1,sum=0;
    FILE *file;
    if (NULL == file) {
        printf("file can't be opened \n");
    }
    if (file = fopen("SEQUENCE.INP", "r")){
        fscanf(file, "%d", &n);
        while (fscanf(file, "%d", &a[k]) != EOF){
            k++;
        }
        fclose(file);
    }
    for (i = 1; i<=n; i++){
        for (j = n; j>i; j--){
            if(i>=j){
                break;
            }else{
                sum=a[j]-a[i];
                max=(max>sum)?max:sum;
            }
        }
    }
    // printf("max=%d",max);
    FILE *filePointer ;
    char buf[100]="Max";
    filePointer = fopen("SEQUENCE.OUT", "w") ;
    if ( filePointer == NULL ){
        printf( "Error" ) ;
    }
    else{       
        fprintf(filePointer,"%s = %d",buf,max);
    }
    return 0;
}
