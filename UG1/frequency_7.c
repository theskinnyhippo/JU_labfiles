#include<stdio.h>
int() {
int a, digit, count;
	printf("enter your number here:",a);
	scanf("%d",%a);
   printf("the digit you wanna find the frequency of:", digit);
   scanf("%d", %digit);

while( a != 0) {
  if( a % 10 == digit)
	count++;

	a /= 10;
   }
	printf("the frequency of the digit in the number: %d",count);
return 0;
}

