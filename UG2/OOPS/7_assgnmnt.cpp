#include<iostream>
using namespace std;

int fac(const int n){
	
	int prod = 1;
	for(int i=2; i<=n; i++){
		prod *= i;
	}
	return prod;
}

int main(){
int m;
	cout << "ENTER A NUMBER : ";
	cin >> m;

int f = fac(m);
	cout << m << "! = " << f << endl;
	
}

