#include<stdio.h>

int main() {
	int row, col, i, j;
	printf("Enter the number of rows :");
		scanf("%d", &row);
	printf("Enter the numbers of coloumns here :");
		scanf("%d", &col);
	int arr[row][col],tran[col][row];
	printf("Now time to enter the elements of the matrix . . . \n");
	for(i=0; i<row; i++){
	    printf("Elements of row %d :", i);
		for(j=0; j<col; j++){
		 scanf("%d", &arr[i][j]);
	    }
	}
	for(i=0; i<col; i++){
		for(j=0; j<row; j++){
			tran[i][j] = arr[j][i];
	    }
	}
	printf("\nTranspose of the above matrix is ...");
	for(i=0; i<col; i++){
		printf("\n");
	    for(j=0; j<row; j++){
		printf("%d", tran[i][j]);
	    }
	printf("\n");
	}
    return 0;
}
