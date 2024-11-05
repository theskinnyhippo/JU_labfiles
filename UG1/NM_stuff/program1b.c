#include<stdio.h>
#include<math.h>
#include<stdbool.h>



float am[3][6] ;
 void printer(){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<6;j++){
            printf("%f ",am[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
 bool checker(){
    int i,j ;
    for(i=0;i<3;i++){
        int flag = 0;
        for(j=0;j<3;j++){
            if(am[i][j]!=0){
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
    printf("Enter the matrix ... \n");
    int i,j,k;
         for(i=0;i<3;i++){
        printf("Enter the elements of row %d : ",i);
        for(j=0;j<6;j++){
            if(j<3){
                float f;
                scanf("%f",&f);
                am[i][j] = f;
            }else{
                if(j==i+3){
                    am[i][j] = 1 ; 
  }else{
            am[i][j] = 0 ;
               }
          }
     }
}
for(i=0;i<3;i++){
             float x = am[i][i] ;
       for(j=0;j<6;j++){
         am[i][j] = am[i][j]/x ;
}
	for(j=0;j<3;j++){
		if(j!=i){
	float y = am[j][i] ;
		for(k=0;k<6;k++){
		am[j][k] = am[j][k] - (y * am[i][k]);
		}
	}
}
if(checker()){
			printf("Matrix Inverse doesnt exist !!!"); return 0;
			}
			printer();
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
					printf("%f ",am[i][j+3]);
					}
		printf("\n");
		}
return 0;
} 
