#include<stdio.h>

int main(){
        int row ,col ;
        int i=0 , j=0 ;
        printf("Enter number of rows : ");
        scanf("%d",&row);
        printf("Enter number of columns : ");
        scanf("%d",&col);
        int arr[row][col];
        printf("\nNow enter elements of the matrix ...\n");
        for(i=0;i<row;i++){
                printf("Elements of row %d : ",i);
                for(j=0;j<col;j++){
                        scanf("%d",&arr[i][j]);
                }
        }
        int flag=0;
        for(i=0;i<row;i++){
                for(j=0;j<col;j++){
                        if(arr[i][j]==0){
                                flag ++;
                        }
                }
        }
        float s = (row*col*2)/(float)3 ;
        if(flag>=s){
                printf("The given matrix is a Sparse matrix !");
                return 0 ;
        }
        printf("The given matrix is NOT a Sparse matrix !");
        return 0 ;
}


