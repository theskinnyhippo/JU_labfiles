#include<iostream>
#include<cmath>

using namespace std;

class device{
	double x,y,r; //transmission range
	
	public :

		device(double a=0, double b=0, double c=0) : x(a), y(b), r(c){}

		int neighbour(device p) {
			double d =pow((pow(this->x - p.x,2)+pow(this->y -p.y,2)),0.5);
			if(this->r >= d){
				return 1;
			}else{
				return 0;
			}
		}

		void legitification(device n){
			if(this->x == n.x && this->y == n.y){
				cout << "Invalid positioning... \n try again x y : "<< endl;
			double a, b;
			cin >> a >> b;
				this->x = a;
				this->y = b;
				legitification(n);
			}
		}

};

int main(){
	cout << "Enter number of devices : ";
	int k;
	cin >> k;
	device * a = new device[k];
	for(int i=0; i<k; i++){
		double xc, yc, range;

		cout << "Enter data about the device ID" << i << " \n (x y range) : ";
		cin >> xc >> yc >> range;
			a[i] = device(xc, yc, range);
	
		for(int j=0; j<i; j++){
			a[i].legitification(a[j]);
		}
	}

	int l, count=0;
	cout << "device u wanna find the neighbour of : " ;
	cin >> l;
	int j=0;
	cout <<" the neighbours of device ID " << l << " is/are... " << endl;
	while(j<k){
		if(j!=l){
			if(a[l].neighbour(a[j])){
				cout << "device ID " << j << endl;
				count++;
			}
		}j++;
	}

	if(count == 0){
		cout << "NO neighbour found!" << endl;
	}
}
	
			
	
		

 





