#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int n;

void funcmkr(float *l1,float *l2){
        int i;
        for(i=0;i<n+1;i++){
                printf("Enter the coefficient of the %dth degree of x : ",i);
                scanf("%f",(l1+i));
        }
        for(i=0;i<n;i++){
                *(l2+i) = (i+1)*(*(l1+i+1)) ;
        }
        return ;
}

float func(float x,float fx[]){
        float l[n+1], b=0 ;
        int i;
        for(i=0;i<n+1;i++){
                l[i] = (fx[i])*(pow(x,i)) ;
                b = b + l[i] ;
        }
        return b;
}

float der(float x,float dfx[]){
        float l[n],b=0 ;
        int i;
        for(i=0;i<n;i++){
                l[i] = (dfx[i])*(pow(x,i)) ;
                b = b + l[i] ;
        }
        return b ;
}

float newe(float x,float fx[],float dfx[]){
        float a,b,c;
        a = func(x,fx);
        b = der(x,dfx);
        c = x - (a/b);
        return c;
}

bool check(float a,float b,int x){
        int y = pow(10,x);
        if((int)(a*y)==(int)(b*y)){
                return 1;
        }
        return 0;
}

int main(){
        printf("Enter the degree of the function : ");
        scanf("%d",&n);
        float fx[n+1],dfx[n];
        funcmkr(&fx[0],&dfx[0]);

        float itr;
        int acc,cntr=1;
        printf("Enter first iterator : ");
        scanf("%f",&itr);
        printf("Enter the number of decimal points of accuracy : ");
        scanf("%d",&acc);

        while(!check(itr,newe(itr,fx,dfx),acc)){
                printf("Iteration %d is : %f \n",cntr,itr);
                itr = newe(itr,fx,dfx) ;
                cntr++ ;
        }

        int ans, med = pow(10,acc) ;
        ans = med * newe(itr,fx,dfx) ;
        float answer = ans / (float)med ;
        printf("The answer is : %f",answer);

        return 0;
}


