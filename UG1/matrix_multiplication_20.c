#include<stdio.h>

void printer(int *mat,int row,int col){
        int i,j ;
        for(i=0;i<row;i++){
                for(j=0;j<col;j++){
                        printf("%d ",*((mat+i*col)+j));
                }
                printf("\n");
        }
        return ;
}

void matmul(int *mat1,int r1,int c1,int *mat2,int r2,int c2,int *mat3){
        int i,j,k;
        for(i=0;i<r1;i++){
                for(j=0;j<c2;j++){
                        int x=0;
                        for(k=0;k<r2;k++){
                                x = x+((*((mat1+i*c1)+k))*(*((mat2+k*c2)+j))) ;
                        }
                        *((mat3+i*c2)+j)=x ;
                }
        }
        return ;
}

int cntr=1;

void matin(int *mat,int m,int n){
        int i=0,j=0;
        printf("Enter matrix %d .... \n\n",cntr);
        for(i=0;i<m;i++){
                printf("Enter the elements of row %d : ",i);
                for(j=0;j<n;j++){
                        scanf("%d",&(*((mat+i*n)+j)));
                }
        }
        cntr++;
        return ;
}

int main(){
        int r1,c1,r2,c2;
        printf("Enter the rows and columns of 1st matrix : ");
        scanf("%d%d",&r1,&c1);
        printf("Enter the rows and columns of 2nd matrix : ");
        scanf("%d%d",&r2,&c2);
        if(c1!=r2){
                printf("Matrix multiplication not posssible !");
                return 0;
        }
        int mat1[r1][c1],mat2[r2][c2],mat3[r1][c2] ;
        matin((int *)mat1,r1,c1);
        matin((int *)mat2,r2,c2);
        matmul((int *)mat1,r1,c1,(int *)mat2,r2,c2,(int *)mat3);
        printer((int *)mat3,r1,c2);
        return 0;
}
