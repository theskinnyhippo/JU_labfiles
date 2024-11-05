#include<stdio.h>
 #include<math.h>
  float h;
  float func(float x,float y){
     float ans = (pow(x,2)) + (pow(y,2)) ;
     return ans;
 }
  float newele(float x,float y){
     float k1 = h * (func(x,y)) ;
     printf("k1 = %f \n",k1);
     float k2 = h * (func((x+(h/2)),(y+(k1/2)))) ;
     printf("k2 = %f \n",k2);
     float k3 = h * (func((x+(h/2)),(y+(k2/2)))) ;
     printf("k3 = %f \n",k3);
     float k4 = h * (func((x+h),(y+k3))) ;
     printf("k4 = %f \n",k4);
     float ans ;
     ans = y + ((k1 + (2*k2) + (2*k3) + k4)/6) ;
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
         printf("%dth y is : %f \n",j,y);
          printf("%dth x is : %f \n",j,x);
      }
     printf("The answer is : %f",y) ;
     return 0;
}
