#include<iostream>
using namespace std;

int add(int j, int a[3]){
	int sum = 0;
	a[2] = 0;
	a[1] = 0;
		for(int i=0; i<j; i++){
			sum += a[i];
		}
	return sum ;
}

int main(){
	cout << "Enter the number of input numbers(max 3) : ";
	int n, m[3]; 
	cin >> n;
	if(n<=3){
	for(int k=0; k<n; k++){
		cin >> m[k];}
	int s = add(n, m);
	cout << "sum = " << s << "\n";
	}else{
		cout << "atmax 3 numbers u can add\n" ; 
}}
