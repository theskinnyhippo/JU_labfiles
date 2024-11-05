#include<stdio.h>
void main(){
	float a,b,r;
	int option;
	printf("enter your numbers here:");
		scanf("%f%f",&a,&b);
		printf("1. addition\n");
		printf("2. substraction\n");
		printf("3. multiplication\n");
		printf("4. division\n");
	scanf("%d",&option);
	switch(option){
		case 1: r=a+b;	
			printf("sum,%f",r);
		case 2: r=a-b;
			printf("substraction,%f",r);
		case 3: r=a*b;
			printf("product,%f",r);
		case 4: r=a/b;
			printf("division,%f",r);
	}
}	
