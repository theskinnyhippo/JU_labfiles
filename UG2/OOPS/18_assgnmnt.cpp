#include<iostream>
#include<cmath>

using namespace std;

class point{
	private :
		float x,y,z;			
	
	public :
 	point(float a=0, float b=0, float c=0):x(a),y(b),z(c){}
	
	float distance(point A) {
		float d = sqrt(pow((A.x - x),2) + pow((A.y - y),2) + pow((A.z - z),2));
		return d;
	}
};


int main(){
	point p1(3,4,5);
	point p2(3,1,1);

	cout << " the distance between the two points is... \n ";
	float dist = p1.distance(p2);
	cout << dist << endl;
}
