#include<iostream>
using namespace std;


class IntArray{
    private :
        const int size;
        int* data;
        
    public :
        IntArray(int s, bool empty = false) : size(s){
            data = new int[size];
        }

        IntArray(const IntArray &cp) : size(cp.size){
            data = new int[size];
            for(int i=0; i<size; i++){
                *(data + i) = *(cp.data + i);
            }
        }

        ~IntArray(){
            delete[] data;
        }

        void Reverse(){
            for(int i=0; i<size/2; i++){
                int yay = data[i]; 
                data[i] = data[size - 1 - i];
                data[size - 1 - i] = yay;
            }
        }

        void Set_int(int k, int index){
            this->data[index] = k;
        }

        IntArray add(const IntArray &s) const {
            int carry = 0;
            
            
            if( size > s.size){
            IntArray r(size+1);
                for(int i=0; i<s.size; i++){
                    *(r.data+i+1) = (*(data+i) + *(s.data+i) + carry)%10;
                    carry = (*(data+i) + *(s.data+i) + carry)/10;
                }
                for(int i=s.size ; i<size; i++){
                    *(r.data+i+1) = (*(data+i) + carry)%10;
                    carry = (*(data+i)+carry)/10;
                }
                if(carry == 1){
                    r.data[0] = 1;
                }else if(carry == 0){
                    r.data[0] = 0;
                }
                return r;
            }

            else if( s.size > size){
            IntArray r(s.size+1);
                for(int i=0; i<size; i++){
                    *(r.data+i+1) = (*(data+i) + *(s.data+i) + carry)%10;
                    carry = (*(data+i) + *(s.data+i) + carry)/10;
                }
                for(int i=size ; i<s.size; i++){
                    *(r.data+i+1) = (*(s.data+i) + carry)%10;
                    carry = (*(s.data+i)+carry)/10;
                }
                if(carry == 1){
                    r.data[0] = 1;
                }else if(carry == 0){
                    r.data[0] = 0;
                }
                return r;
            }

            else{
            IntArray r(size+1);
                for(int i=0; i<size; i++){
                    *(r.data+i+1) = (*(data+i) + *(s.data+i) + carry)%10;
                    carry = (*(data+i) + *(s.data+i) + carry)/10;
                }
                if(carry == 1){
                    r.data[0] = 1;
                }else if(carry == 0){
                    r.data[0] = 0;
                }
                return r;
            }
                
        }

        void sort() const {
            int g;
            int sorted = 0;

            for(int j=1; j<size; j++){
                sorted = 1;		//let the array be sorted already
                for(int i=0; i<(size-j); i++){
                    if(*(data+i) > *(data + i+1)){
                        g = *(data+i);
                        *(data+i) = *(data+ i+1);
                        *(data+ i+1) = g;
                        
                        sorted = 0;       //if it deosnt go in the if condition, its already sorted  
                    }else{
                        continue;
                    }
                }
                if(sorted == 1){
                    break;
                }
            }
        }

        void print(){
            for(int d=0; d<size; d++){
                cout << *(data + d) << " " ;
            }
            cout << endl;
        }
};


int main(){
    IntArray a1(3);
    a1.Set_int(1, 0);
    a1.Set_int(2, 1);
    a1.Set_int(3, 2);

    cout << "Array 1 : ";
        a1.print();
    IntArray a2(a1);
    cout << "Array 2 (exact copy of array 1) : ";
        a2.print();

    cout << endl;
    cout << "After reversing array 2... " << endl;

    a2.Reverse();
    cout << "Array 1 : ";
        a1.print();
    cout << "Array 2 : ";
        a2.print();
}
