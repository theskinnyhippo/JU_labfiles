#include<stdio.h>
#include<math.h>

void main(){
	float a, b;
	printf("enter a number here: ");
		scanf("%f", &a);
	printf("enter its power: ");
		scanf("%f", &b);
	
printf("%f to the power %f results :%f", a, b, pow(a,b));
}
