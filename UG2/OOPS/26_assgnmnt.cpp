#include<iostream>
using namespace std;

class stack{
	int* buffer;
	int top;
	const int lim;
	
	public :
		stack(const int size): lim(size-1){
			buffer = new int[size];
			top = 0;
		}
		
		void push(const int a){
			if(top < lim){
				buffer[top] = a;
				top++;
			}else{
				cout << "Stack Overload!!" << endl;
			}
		}

		int pop(){
			if(top > 0){
				int temp = buffer[top];
				top--;
                            cout << "One element has been popped out of stack " <<endl;
				return temp;
			}else{
				cout << "Stack Empty!!" <<endl;
			}
		}

		void disp(){
		    cout << "Stack Elements... \n";
			for(int i=0; i<top; i++){
				cout << buffer[i] << " ";
			}
		}
};


int main(){
	stack m(10);
		m.push(2);
		m.push(3);
		m.push(4);
		m.push(5);
		
		m.pop();
	
		m.disp();
}
			
			
