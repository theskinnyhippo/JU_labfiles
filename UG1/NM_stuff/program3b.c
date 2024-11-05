#include<stdio.h>
 #include<math.h>
 #include<stdbool.h>
  int p;
  void funcmkr(float *l){
     int i;
     printf("Enter the function ...\n");
     for(i=p;i>=0;i--){
         printf("Enter the coefficient of %dth degree of x : ",i);
         scanf("%f",(l+i));     } }  float value(float x,float l[]){
     float sum=0 ;
     int i;
     for(i=0;i<=p;i++){
         sum = sum + ((pow(x,i))*l[i]) ;
     }
     return sum; }
  int main(){
     printf("Enter the highest degree of the integrative function : ");
     scanf("%d",&p);
          float func[p];
     funcmkr(func);
          float a,b;
     int n;
     printf("Enter the upper limit and lower limit of the integration : ");
     scanf("%f %f",&b,&a);
     printf("Enter the number of intervals : ");
     scanf("%d",&n);
          float dx = (b-a)/(float)n ;
     float ans = 0 ;
          int i;
     for(i=0;i<=n;i++){
         float j = a + i*dx ;
         float z = value(j,func) ;
         if(i%2==0){
             if(i==0 || i==n){
                 ans = ans + z ;
             }else{
                 ans = ans + 2*z ;
             }
         }else{
             if(i==n){
                 ans = ans + z ;
             }else{
                 ans = ans + 4*z ;
             }
         }
     }
     ans = ((b-a)/(3*n))*ans ;
          printf("The answer is : %f",ans);
          return 0;
 } 
