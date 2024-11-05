#include<iostream>
using namespace std;

int max( int a, int b, int c){
	int m = a;
	if(b > m){
		m = b;}
	if(c > m){
		m = c;
	}
	return m;
}

int max( int a[10]){
	int max1 = a[0];
		for(int j=1; j<10; j++){
			if(a[j]>max1){
				max1 = a[j];
			}
		}
	return max1;
}

int main(){
	int x, y, z;
		cout << "Enter three constants here :\n";
		cin >> x >> y >> z ;
			int max2 = max(x,y,z);
		cout << "the largest integer is " << max2 << endl ;

	int m[10];
			cout << "Enter 10 elements here :\n";
			for(int i=0; i<10; i++){
				cin >> m[i];
			}
				int max3 = max(m);
			cout << "largest integer is : " << max3 ;
}	
		
