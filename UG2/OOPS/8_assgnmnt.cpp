#include<iostream>
using namespace std;

void swap(int *m,int *n){
	int temp = *m;
	*m = *n;
	*n = temp;
}


int main(){
    int a, b;
	cout << "ENTER TWO NUMBERS : ";
	cin >> a >> b;
cout << "BEFORE SWAPPING... " << a << " & " << b << "\n";
	swap(&a, &b);
cout << "AFTER SWAPPING... " << a << " & " << b << "\n";
}
