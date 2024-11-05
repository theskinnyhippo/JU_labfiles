#include<bits/stdc++.h>
using namespace std;


class rctngl{
	const float a, b;
	public :
		rctngl(float x=0, float y=0): a(x), b(y){}		
		float area() const {
		float area = a * b;
			return area;
		}
};

int main() {
	rctngl R1(2.1, 6.9);
	rctngl R2(2.6, 1.9);
	rctngl R3(1.3, 2);
	rctngl R4(4, 5.1);

	cout << "area of first rectangle is " << R1.area() << " squnits" << endl;
	cout << "area of second rectangle is " << R2.area() << " squnits" << endl;
	cout << "area of third rectangle is " << R3.area() << " squnits" << endl;
	cout << "area of fourth rectangle is " << R4.area() << " squnits" << endl;
    return 0;
}

