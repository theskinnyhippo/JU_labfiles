#include<iostream>
#include<vector>
using namespace std;

void print(int* vec, int s ){
	int i;
	for( i=0; i<s ; i++){
		cout << *(vec + i) << " " ;
	}
}


void print(int m, int n, int *a){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			cout << *((a+i*m)+j) << " ";
		}
		cout << endl;
	}
}


int main(){
	int a=3, b=2, y ,z;
	int v[] = {2, 3, 6, 12, 36, 72};

	int k[3][2] = {1, 2, 3,
	               4, 5, 6};
	
	
	/*for(y=0; y<a; y++){
		for(z=0; z<b; z++){
			cin >> *((k+y*b)+z);
		}
	}*/
	

	cout << "The matrix prints... " << endl;
	print(3, 2, *k);
	cout << endl;


	cout << "The vector prints... " << endl;
	print(v, 6);
	cout << endl;

}
