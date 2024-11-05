#include<stdio.h>
   int main() {
	int a, first_digit, last_digit;
	printf("enter your number here:");
     scanf("%d",&a);
 first_digit=a;
while(first_digit >= 10) {
	first_digit /= 10;
   }
last_digit= a % 10;
  printf("first digit: %d\n", first_digit);
  printf("last digit: %d\n", last_digit);
}

