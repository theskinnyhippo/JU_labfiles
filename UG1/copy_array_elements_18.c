#include<stdio.h>

void swapper(int *x, int n, int *y){
	int i;
	for(i=0; i<n; i++){
		*(y+i) = *(x+i);
	}
}

int main(){
	int n, i;
	printf("Enter the numbers of elements in array :");
		scanf("%d", &n);
	int arr_1[n], arr_2[n];
	printf("ENter the elemets of array :");
		for(i=0; i<n; i++){
		scanf("%d", &arr_1[i]);
	}
	swapper(arr_1, n, arr_2);
	for(i=0; i<n; i++){		
		printf("%d ", arr_2[i]);
	}
	return 0;
}
