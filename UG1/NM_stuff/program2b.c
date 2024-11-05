#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int n;

void funcmkr(float *l){
    int i;
    for(i=0;i<n+1;i++){
        printf("Enter the coefficeient of %dth degree of x : ",i);
        scanf("%f",(l+i));
    }
    return ;
}

float funval(float x,float l[]){
    float b=0;
    int i;
    for(i=0;i<n+1;i++){
        b = b + (l[i]*(pow(x,i))) ;
    }
    return b;
}

bool checker(float a,float b,int p){
    float x,y;
    x = a * (pow(10,p)) ;
    y = b * (pow(10,p)) ;
    if((int)x==(int)y){
        return 0;
    }
    return 1;
}

int main(){
    
    printf("Enter the highest degree of function : ");
    scanf("%d",&n);
    float arr[n+1];
    funcmkr(&arr[0]);

    int acc;
    float u_l,v_l ;
    printf("Enter the lower limit and upper :");
    scanf("%f %f",&u_l,&v_l);
    printf("Enter the number of decimal places for accuracy : ");
    scanf("%d",&acc);

    float x;

    while(checker(u_l,v_l,acc)){
        x = (u_l + v_l)/2 ;
        if(funval(x,arr)==0){
            break ;
        }else if((funval(u_l,arr))*(funval(x,arr))<0){
            v_l = x ;
        }else{
            u_l = x ;
        }
    }

    int ans,med = pow(10,acc) ;
    ans = med * x ;
    float answer = ans / (float)med ;
    printf("The answer is : %f",answer);
    
    return 0;
}
