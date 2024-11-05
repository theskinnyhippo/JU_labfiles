#include<stdio.h> 
#include<math.h> 
#include<stdbool.h>
 int n;
 float s;
 float value(float arr[],float x,float y,int k){
 float u=1,l=1 ;
 int i;
 for(i=0;i<n;i++){
 if(i!=k){
 u = u * (s - arr[i]);
 l = l * (x - arr[i]);
 }
 }
 float ans = (u/l)*y; return ans;
 }
  int main(){
     printf("Enter the number of intervals : ");
     scanf("%d",&n);
          int i;
     float x[n],y[n];
     for(i=0;i<n;i++){
         printf("Enter x and y(x) : ");
         scanf("%f %f",&x[i],&y[i]);
     }
          printf("Enter the x for which y(x) is required : ");
     scanf("%f",&s);
          float sum;
     for(i=0;i<n;i++){
         float z = value(x,x[i],y[i],i) ;
         sum = sum + z;
     }
          printf("The y(%f) is : %f",s,sum);
          return 0;
 } 
