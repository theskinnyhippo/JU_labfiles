#include<iostream>
using namespace std;

int f(int n){
	if(n>1){
		return n*f(n-1);
	} else {
		return 1;
	}
}

int main(){
	for( int i=1; i<=6; i++){
		cout << i << "! = " << f(i) << "\n";
	}
}
