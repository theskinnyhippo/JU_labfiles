#include<stdio.h>

int flag=0;

int fact(int n){
    if(n<1){
	return 1;
    }
	return n*fact(n-1);
}

void strong(int n){
     int sum=0, temp=n;
     while(n>0){
	int a = n%10;
	sum = sum + fact(a);
	n=n/10;
    }
    if(sum==temp){
	printf("%d",temp);
	flag++;
    }
}

int main() {
	int a,b,i;
	printf("enter your upper limit :");
	scanf("%d", &a);
	printf("enter your lower limit here :");
	scanf("%d", &b);

    for(int i=b;i<=a; a++){
	strong(i);
    }
    if (flag==0){
	printf("no strong numbers present in the given interval");
    }
return 0;
} 

