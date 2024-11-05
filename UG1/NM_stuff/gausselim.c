#include<stdio.h>

#include<stdbool.h>

#include<math.h>  

 

float augmat[3][4] ;  

void printer(){    

     int i,j;    

     for(i=0;i<3;i++){        

     for(j=0;j<4;j++){

            printf("%f ",augmat[i][j]);

        }        

printf("\n");    

}

}

 bool checker(){    

   int i,j ;

    for(i=0;i<3;i++){

        int flag = 0;

        for(j=0;j<4;j++){

            if(augmat[i][j]!=0){

                flag++ ;

            }

        }

        if(flag==0){

            return false ;

        }

    }

    return true ;

}  

int main(){

    int i,j,k;    

printf("A linear eqn is of the form ax + by + cz = d \n") ;

    for(i=0;i<3;i++){

        int a = i+1 ;

        printf("Enter a%d , b%d , c%d and d%d for eqn %d : ",a,a,a,a,a);

         for(j=0;j<4;j++){

            float f;

            scanf("%f",&f);

            augmat[i][j] = f ;

        }

    }

    for(i=0;i<3;i++){

        float x = augmat[i][i] ;

        for(j=0;j<4;j++){

            augmat[i][j] = augmat[i][j]/x ;

        }         for(j=0;j<3;j++){

            if(j!=i){

                float y = augmat[j][i] ;

                for(k=0;k<4;k++){

                    augmat[j][k] = augmat[j][k] - (y*augmat[i][k]) ;

                }

            }else{

                continue ;

            }

        }

        if(checker()){

            printf("There are no solutions for these equations !!!");

            return 0;

        }

        printf("%dth matrix ... \n",i);

        printer();

    }

    int a = checker() ;

    char arr[3]={'x','y','z'};

         for(i=0;i<3;i++){

        printf("%c = %f \n",arr[i],augmat[i][3]);

    }

         return 0;

} 
