#include<iostream>
using namespace std;
#define PI 3.1415

int main(){
float r, area;
	cout << "Enter the radius : " ;
	 cin >> r;
	area = PI * r*r;
	cout << "area of the circle with given radius " << r << "unit is... " << area << " squnits" << endl;
} 
