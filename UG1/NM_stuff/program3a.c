#include<stdio.h>
#include<math.h> 
#include<stdbool.h>
  int p;
  void funcmkr(float *l){
     int i;
     printf("Enter the eqn ...\n");
     for(i=p;i>=0;i--){
         printf("Enter the coefficient of the %dth degree of x : ",i);
         scanf("%f",(l+i));
     }
 }
  float value(float x,float l[]){
     float ans=0;
     int i;
     for(i=0;i<=p;i++){
         ans = ans + ((pow(x,i))*l[i]) ;
     }
     return ans ;
 }
  int main(){
     printf("Enter the degree of the integrative function : ");
     scanf("%d",&p);
          float func[p];
     funcmkr(func);
          float a,b;
     int n;
     printf("Enter the upper limit and lower limit of the integration : ");
     scanf("%f%f",&b,&a);
     printf("Enter the number of intervals : ");
     scanf("%d",&n);
          float dx = (b-a)/(float)n ;
     float ans = 0 ;
     float p,q ;
     p = value(a,func) ;
     q = value(b,func) ;
     while(a!=(b+dx)){
 
        float z = value(a,func);
         ans = ans + 2*z ;
         a = a + dx ;
     }
     ans = (dx/2)*(ans - p - q) ;
          printf("The answer is : %f",ans) ;
      return 0;
 } 
