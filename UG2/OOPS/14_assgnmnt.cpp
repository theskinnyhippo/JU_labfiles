#include<bits/stdc++.h>
using namespace std;

inline int add_inline(float a, float b, float c){
	return a + b + c;
}

int add(float a, float b, float c){
	return a + b + c;
}


int main(){
int x = 3 , y = 4 , z = 5, w, s;
	clock_t t1, t2, t3;
	t1 = clock();
		for(int i=0; i<300000000; i++){
			w = add_inline( x, y, z);
		}
	t2 = clock();
		for(int i=0; i<300000000; i++){
			s = add( x, y, z);
		}
	t3 = clock();

	double time_1 = double(t2 - t1) / double(CLOCKS_PER_SEC);
	double time_2 = double(t3 - t2) / double(CLOCKS_PER_SEC);

	cout << "Time taken for inline addition function : " << time_1 << endl;
	cout << "Time taken for normal addition function : " << time_2 << endl;
}
