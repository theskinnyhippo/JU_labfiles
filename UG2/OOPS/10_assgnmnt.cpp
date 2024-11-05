#include <bits/stdc++.h>
using namespace std;

int swap_by_value(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int swap_by_reference(int &i, int &j){
	int t = i;
	i = j;
	j = t;
}


int main(){
	int m =12, n =10;

	clock_t t1, t2, t3;	
		t1 = clock();
			for(int i=0; i<100000000; i++){
				swap_by_reference( m, n);	//time1 -> by reference
			}
		t2 = clock();
			for(int j=0; j<100000000; j++){
				swap_by_value( &m, &n);		//time2 -> by value
			}
		t3 = clock();
	double time2 = double(t3 - t2) / double(CLOCKS_PER_SEC);
	cout << endl <<"Time taken for swapping by value : "<< time2 << "seconds" ;	
		
	double time1 = double(t2 - t1) / double(CLOCKS_PER_SEC);
	cout << endl <<"Time taken for swapping by reference : " << time1 << "seconds" <<endl;
} 
