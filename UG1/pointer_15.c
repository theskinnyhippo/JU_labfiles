#include<stdio.h>

int main(){
	int a, b, *x, *y;
	printf("Enter a number :");
		scanf("%d", &a);
	printf("Enter another number :");
		scanf("%d", &b);
					x = &a;
					y = &b;
		printf("The sum of the two numbers is : %d", *x +*y);
	return 0;
}

