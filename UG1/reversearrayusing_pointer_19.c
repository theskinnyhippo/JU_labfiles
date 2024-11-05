#include<stdio.h>


void reverser(int *x, int n){
	int i;
	for(i=0; i<n/2; i++){
		int t = *(x+i);
		*(x+i) = *(x+n-1-i);
		*(x+n-1-i) = t;
	}
	return ;
}

int main(){
	int n,i;
	printf("Enter the numbers of elements of array :");
		scanf("%d", &n);
	int arr[n];
	printf("Enter the elements of array :");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	reverser(arr, n);
	printf("Elements after reversing them ...\n");
	for(i=0; i<n; i++){
		printf("%d", arr[i]);
	}
	return 0;
}
        
