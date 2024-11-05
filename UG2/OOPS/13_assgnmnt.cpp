#include<iostream>
using namespace std;


inline float add(float a, float b, float c){
	return (a + b + c);
}


int main(){
	float m , n , k;
	cout << "ENTER THREE NUMBERS HERE : ";
	cin >> m >> n >> k;
	float s = add( m , n , k);
	cout << "the sum is : " << s;
	return 0;
}
