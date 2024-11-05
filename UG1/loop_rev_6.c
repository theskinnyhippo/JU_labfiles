#include<stdio.h>
 int main() {
	int m, rem, w;
	printf("enter your number here:",m);
   scanf("%d", &m);
  
while( m !=0) {
  	rem = m % 10;
  	w = w*10 + rem;
  	m /= 10;
   printf("reverse of your number is: %d",w);
  }
return 0;
}

