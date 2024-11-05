#include<stdio.h>
#include<math.h>
#include<stdbool.h>


float augmat[3][4] ,
arr[3];
 int acc;
 void inputter(){
    int i,j ;
    printf("Enter the eqns ...\n");
    for(i=0;i<3;i++){
        printf("Enter the %dth eqn terms : ",i);
        for(j=0;j<4;j++){
            scanf("%f",&augmat[i][j]) ;
        }
    }
}
 bool checker(float x,float y){
    int c;
    c = pow(10,acc) ;
    int a = x * c ;
    int b = y * c ;
    if(a==b){
        return true;
    }
    return false;
}
 float summer(){
    int i;
    float sum =0;
    for(i=0;i<3;i++){
        sum = sum + arr[i];
    }
    return sum ;
}
 void newele(){
    int i,j;
    for(i=0;i<3;i++){
        float ans=0;
        for(j=0;j<4;j++){
            if(j==3){
                ans = ans + augmat[i][j] ;
            }else{
                if(j!=i){
                     ans = ans - ((arr[j])*(augmat[i][j]));
                 }
            }
        }
        arr[i] = ans/augmat[i][i] ;
    }
    return ;
}
 void printer(){
    int i;
    printf("The solution set : ");
     for(i=0;i<3;i++){
        printf("%f ",arr[i]);
    }
    printf("\n");
    return ;
}
 int main(){
    printf("Enter the degree of accuracy : ");
    scanf("%d",&acc);
         inputter();
         float u,v;
    u = summer() ;
    newele();
    v = summer() ;
         while(!checker(u,v)){
        u = v ;
        newele() ;
        v = summer() ;
    }
         printer();
         return 0;
} 


