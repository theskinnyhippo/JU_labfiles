#include<stdio.h>

int main() {
	int n,i,j;
	printf("Enter the order of square matrix :");
	scanf("%d", &n);
	int arr[n][n];
	printf("Enter the elemenrs of the square matrix . . . . . \n");
	for(i=0;i<n;i++){
	    printf("Enter the elements of row %d :", i);
	    for(j=0;j<n;j++){
		 scanf("%d",&arr[i][j]);
	    }
	}
	for(i=0 ; i<n ; i++){
	    if(i==(n-1-i)){
		continue;
	    }
	    arr[i][i] = arr[i][i] + arr[i][n-1-i];
		arr[i][n-1-i] = arr[i][i] - arr[i][n-1-i];
	    arr[i][i] = arr[i][i] - arr[i][n-1-i];
	}
	printf("Matrix after changes . . . \n");
	for(i=0;i<n;i++){
	   for(j=0;j<n;j++){
		printf("%d", arr[i][j]);
            }
	    printf("\n");
	}
	return 0;
}
