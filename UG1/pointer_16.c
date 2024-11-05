#include<stdio.h>


void swapper(int *a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}


int main() {
	int a, b;
	printf("Enter a number : ");
		scanf("%d", &a);
	printf("enter another number here : ");
		scanf("%d", &b);
	printf("\nBefore swapping the numbers respectively are : %d and %d \n", a, b);
		swapper( &a, &b);
		printf("\nAfter swapping a and b respectively are : %d and %d", a, b);
	return 0;
}

