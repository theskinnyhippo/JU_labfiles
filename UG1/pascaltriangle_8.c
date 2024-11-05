#include<stdio.h>


int main() {
	int n,i,j;
	printf("enter the number of rows u want");
	scanf("%d",&n);
	int arr[n][n];
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(j==0 || i==j){
					arr[i][j] = 1;
				}else{
					arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
				}
			}
		}
	printf("The pascal's triangle you wanted is here : \n");
	for(i=0; i<n; i++){
		for(j=n-1; j>i; j--){
			printf("  ");
		}
		for(j=0; j<i+1; j++){
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
}
