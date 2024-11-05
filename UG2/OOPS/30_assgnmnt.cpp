#include<bits/stdc++.h>
using namespace std;

class point{

	private :
		double x, y;

	 public :
		point( const double a=0, const double b=0) : x(a), y(b){}

		point( const point &p) : x(p.x), y(p.y){}

	
		double operator - (point p) const {
			double k = sqrt(pow(x-p.x,2)+pow(y-p.y,2));
			return k;	
		}
};


int main(){
	point a, b(4,4);
	point c(b);
	
	cout << "distance between a(0,0) and b(4,4) is " << b - a << endl;
	cout << "distance between b and c(b) is " << b - c << endl;
}
