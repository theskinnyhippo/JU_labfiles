#include<stdio.h>
#include<math.h>
void main() {
float a,b,c,d,r,p,r1,r2;
	printf("write the coefficient of x^2:\n",a);
  scanf("%f",&a);
	printf("write the coefficient of x:\n",b);
  scanf("%f",&b);	
	printf("constant:\n",c);
  scanf("%f",&c);
		d=(b*b)-(4*a*c);
if(d<0) {
	printf("oops! u got no roots outta the equation");
}
else if(d==0) {
		r=-b/(2*a);
	printf("you got only one root %f",r);
}
else {
		p=pow(d,0.5);
		r1=(d-b)/(2*a);
		r2=-(d+b)/(2*a);
	printf("the two roots of ther equation are: %f and %f",r1,r2);
     }
}
