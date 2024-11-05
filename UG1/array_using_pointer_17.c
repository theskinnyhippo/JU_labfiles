#include<stdio.h>

void printer(int l[], int n){
	int i, *p=l;
	printf("The elements of the  array are as follows :");
	for( i=0; i<n; i++){
		printf("%d ",*(p+i));
	}
}

int main(){
	int n, i;
	printf("Enter the size of the array here :");
		scanf("%d", &n);
	int arr[n], a;
	for(i=0; i<n; i++){
		scanf("%d", &a);
		arr[i] = a;
	}
	printer(arr,n);
	return 0;
}
