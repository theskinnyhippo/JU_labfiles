#include<iostream>
using namespace std;

int main(){
	cout << "Enter tempetature in celcius : ";
    double c, f;
	for( c=0; c<=100; c++){
		f = (9*c/5)+32;
		cout << c << "`C = " << f << "`F" <<endl;
	}
}
