#include<iostream>
using namespace std;

class complex{
	private :
		double a, b;
	public :
		complex(){
			this->a = 0;
			this->b = 0;
		}
		
		void SetReal(double r){
			this-> a = r;
		}
		void SetImg(double i){
			this-> b = i;
		}
		double Getreal(){
			return this->a;
		}
		double GetImg(){
			return this->b;
		}

		complex sum(complex m){
			complex temp;
			temp.a = a + m.a;
			temp.b = b + m.b;
		    return temp;
		}
		
		void disp(){
			cout << a << " + i" << b << endl;
		}
};


int main(){
	complex ob1, ob2, ob3;

	ob1.SetReal(2.21);
	ob1.SetImg(9.65);

	ob1.disp();

	ob2.SetReal(6.91);
	ob2.SetImg(1.11);

	ob2.disp();
	
	ob3 = ob1.sum(ob2);

	ob3.disp();
	
}
