#include<stdio.h>

int uflag=0;

void chkper(int n){
	int i, sum=0;
	for( i=1;i<(n/2)+1;i++){
    	    if(n%i==0){
		sum = sum + i;
 	    }
	}
	if(sum==n)
	    printf("%5d",n);
	    uflag++;
}

int main(){
   int a,b,i;
	printf("enter upper limit");
	scanf("%d", &a);
	printf("enter your lower limit here");
	scanf("%d", &b);
	for(i=b;i<=a;i++){
	    chkper(i);
	}
	if(uflag==0){
	    printf("NO PERFECT NUMBERS IN THE GIVEN INTERVAL !!!");
     }
     return 0;
}
