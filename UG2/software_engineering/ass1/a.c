#include "f.h"

int f0(int *p)
{
    int x, cntr = 1;
    printf("Enter a number between 2 and 6 (non-inclusive): \n");
    scanf("%d", &x);
    while ((x <= 2) || (x >=6)) {
        printf("You have entered %d which is wrong.Please Reenter:\n",x);
        scanf("%d", &x);
        cntr++;
        if (cntr > 5) {
            printf("Max number of Invalid input reached.Program will QUIT...\n");
            return 1;
        }
        
    }
    printf("You have entered %d\n",x);
    *p = x;
    return 0;
}
int main()
{
    int cntr = 0 , i;
    if (f0(&cntr) != 0 )
        return 0;
    for(i =0 ;i < cntr; i++) {
        int a,b;
        a = 100 / (i+2);
        b = 327 / (i+2);
        f1(a,b);
        f2(&a,&b);
        printf("After operation %d ", i+1);
        f1(a,b);
    }
}


