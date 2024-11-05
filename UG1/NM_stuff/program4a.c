#include<stdio.h>
#include<math.h>  
#define e 2.71828
  float h;
  float func(float x,float y){
     float ans = 2 - (2*y) - (pow(e,(-4*x))) ;
     return ans;
 }
  float newele(float x,float y){
     float k = h * (func(x,y)) ;
     float ans ;
     ans = y + k ;
     return ans;
 }
  int main() {
     printf("Enter the step size : ") ;
     scanf("%f",&h);
     float x,y,xn ;
     printf("Enter the first instance of x : ");
     scanf("%f",&x);
     printf("Enter y(%f) : ",x);
     scanf("%f",&y);
     printf("Enter the x for which you want to find y(x) : ");
     scanf("%f",&xn);
     float k=((xn-x)/h);
     int j ;
     for(j=0;j<k;j++){
         y = newele(x,y) ;
         x = x + h ;
         printf("%dth x is : %f \n",j+1,x);
          printf("y(%f) is : %f \n\n",x,y);
      }
     printf("The answer is : %f",y) ;
     return 0;
 }
