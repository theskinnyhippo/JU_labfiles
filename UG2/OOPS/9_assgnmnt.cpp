#include<iostream>
using namespace std;


void str_swap_by_value( string *i, string *j){
	string x;
	x = *i;
	*i = *j;
	*j = x;
}

void str_swap_by_Reference(string &a, string &b){
	string t;
 	t = a;
	a = b;
	b = t;
}

int main(){
	string m, n;
	n = "DAY", m = "ONE";
cout << "BEFORE SWAPPING... "<< endl << m <<" " << n << endl;
	str_swap_by_value( &m, &n);
cout << "AFTER SWAPPING(called by value)... "<< endl << m <<" " << n << endl;

	n = "DAY", m = "ONE";
	str_swap_by_Reference( m, n);
cout << "AFTER SWAPPING(called by reference)... " << endl << m << " " << n << endl;
}
