#include<iostream>
using namespace std;

int strcpy(const char *a, char *b){
	while(*a){
		*b = *a;
	a++;
	b++;
	}
	*b = '\0' ;
}


int main(){
	const char* m = "ONE PIECE IS REAL!";
	char n[50];
	strcpy( m , n);
	

		cout <<"m :" << m << "\n";
		cout << "Performing string copy :\n";
		cout << "n :" << n << endl;
}
