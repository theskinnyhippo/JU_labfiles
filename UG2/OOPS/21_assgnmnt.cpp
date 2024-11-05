#include<iostream>
#include<cmath>
using namespace std;

class vector{
	int size;
	double* a;
	double mod;

	void magnitude(){
		double mod = 0;
		
		for(int i=0; i<size; i++){
			mod += pow(a[i],2);
		}
		mod = pow(mod, 0.5);
	}

	public :
		vector(int sz, bool empty = false) : size(sz){
			a = new double[size];
			if(!empty){
				cout << "Enter vector data : " ;
				for(int i=0; i< size ; i++){
					cin >> *(a+i);
				}
			}else{
				for(int i=0; i<size ; i++){
					*(a+i) = 0;
			}
			magnitude();
		}

		vector(const vector &other) : size(other.size){
			a = new double[size];

			for(int i=0; i<size ; i++){
				*(a+i) = *(other.a + i);
			}
			mod = other.magnitude();
		}

		~vector(){
			delete[] a;
		}

		double add(const vector &m) const{
			if(size == m.size){
				vector result(size, true);
				for(int i=0; i<size; i++){
					result.a[i] = a[i] + m.a[i];
				}
			return result;
			mod = result.magnitude();
			}else{
				return vector(0);
			}
		} 

		double substract(const vector &m) const{
			if(size == m.size){
				vector result(size, true);
				for(int i=0; i<size; i++){
                                        result.a[i] = a[i] - m.a[i];
                                }
                        return result;
                        mod = result.magnitude();
                        }else{
                                return vector(0);
                        }
		}

		bool isEqual(const vector &m) const {
			if(size == m.size){
				for(int i=0; i<size; i++){
					if( a[i] != m.a[i]){
						return false;
					}
				}
					return true;
			}else{
				return false;
			}
		}
		

		bool isGreater(const vector &m) const {
			if(size == m.size){
				return mod > m.mod;
			}else{
				return false;
			}
		}

		bool isLess(const vector &m) const {
                        if(size == m.size){
                                return mod < m.mod;
                        }else{
                                return false;
                        }
                }
				
		void print(){
			cout << "[ ";
				for(int i=0; i<size; i++){
				cout << a[i] << " ";
				}
			cout << "]" << endl;
		}
};

int main(){
	int s;

	cout << "Enter the size of the vectors : " ;
		cin >> s;

	cout << "vector 1 components...\n( x y z w ...) : ";
		vector v1(s);
        cout << "vector 2 components...\n( x y z w ...) : ";
                vector v2(s);       
	
	
	vector sum = v1.add(v2);
	vector diff = v1.substract(v2);
	
	cout << endl << "Sum : ";
		sum.print();
	cout << endl << "Difference : ";
	diff.print();
	
	cout << "Equality : " << v1.isEqual(v2) << endl;
	cout << "is Greater : " << v1.greater(v2) << endl;
	cout << "is Lesser : " << v1.less(v2) << endl;
}



			
		
