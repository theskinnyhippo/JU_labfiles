#include<iostream>
using namespace std;


class Queue{
    private :
        const int size;
        int *data;
        int front, rear;

    public :
        Queue(int s) : size(s){
            data = new int[size];
            rear = 0;
            front = 0;
        }

        void add(int val) {
            if(front == (rear+1)%size){
                cout << "There's no space in the Queue!" << endl;
            }else{
                data[rear] = val;
                rear = (rear + 1)%size;
            }
        }

        int remove() {
            if (front == rear) {
                cout << "Nothing to return!" << endl;
            } else {
                int val = data[front];
                front = (front + 1) % size;
                return val;
            }
        }

        void display(){
            int s = rear - front; 
            if(s < 0){
                s = 7 + s;
            }else if(s == 0){
                cout << "Empty queue!" << endl;
            }
                for(int i=0; i<s; i++){
                    cout << data[(front + i)%size] << " ";
                }
        }
};

int main(){
    Queue q(10);
    q.add(2);
    q.add(3);
    q.add(4);
    q.add(5);

    cout << q.remove() << " has been removed" <<endl ; 
    cout << q.remove() << " has been removed" << endl; 

    q.display();
    
    return 0;
}
	
