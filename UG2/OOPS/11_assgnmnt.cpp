#include<iostream>
using namespace std;


void refFact(int &k){
	int prod = 1;
	for(int i=2; i<=k; i++){
		prod *= i;
	}
	k = prod;
}


int main(){
	int m;
	cout << "Enter the number u want to factorial! : ";
	cin >> m ;
	refFact(m);
	cout << "factorial = " << m << endl;
}
