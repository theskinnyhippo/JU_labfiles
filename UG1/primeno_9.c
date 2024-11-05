#include<stdio.h>
#include<math.h>

int uniflag=0;

void prime(int n){
        int i,flag=0;
        for(i=2;i<=sqrt(n);i++){
                if(n%i==0){
                        flag++;
                        break;
                }
        }
        if(flag==0)
                printf("%d ",n);
                uniflag++;
}

int main(){
        int a , b, i ;
        printf("Enter the upper limit : ");
        scanf("%d",&a);
        printf("Enter the lower limit : ");
        scanf("%d",&b);
        for(i=b;i<=a;i++){
                prime(i);
        }
        if(uniflag==0){
                printf("No prime numbers in the given interval !");
        }
        return 0;
}

