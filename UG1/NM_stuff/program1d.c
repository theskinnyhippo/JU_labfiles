#include<stdio.h> 
#include<math.h> 
#include<stdbool.h>
  float augmat[3][4] , arr[3] ; int acc ;
  void matmkr(){     int i,j;
     printf("Enter the system of linear eqns .. \n");
     for(i=0;i<3;i++){
         printf("Enter the terms of the %dth eqn : ",i);
         for(j=0;j<4;j++){
             scanf("%f",&augmat[i][j]);
         }
     }
 }
  void arrcop(float l[]){
     int i;
     for(i=0;i<3;i++){
         arr[i] = l[i] ;
     }
     return ;
 }
  bool checker(float x,float y){
     int c;
     c = pow(10,acc);
     int a = x * c ;
     int b = y * c ;
     if(a==b){
         return true;
     }
     return false;
 }
  float summer(){
     int i;
     float sum ;
     for(i=0;i<3;i++){
         sum = sum + arr[i] ;
     }
     return sum;
}
  void newele(){
     int i,j;
     float l[3] ;
     for(i=0;i<3;i++){
         float ans=0;
         for(j=0;j<4;j++){
             if(j==3){
                 ans = ans + augmat[i][j] ;
             }else{
                 if(j!=i){
                     ans = ans - ((arr[j])*(augmat[i][j])) ;
                 }
             }
         }
         l[i] = ans/augmat[i][i] ;
     }
     arrcop(l) ;
     return ; }
  void printer(){
     int i;
     printf("The solution set : ");
     for(i=0;i<3;i++){
         printf("%f ",arr[i]);
     }
     printf("\n");
     return ; }
  int main(){
     printf("Enter the degree of accyuracy : ");
     scanf("%d",&acc);
          matmkr();
          float u,v;
     u=summer();
     newele();
     v=summer();
          while(!(checker(u,v))){

        u = v ;
         newele();
         v = summer();
     }
          printer();
          return 0;
 }

