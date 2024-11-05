#include <cstdlib>
#include <iostream>
using namespace std;
#define rate 9

class SavingsAccount {

private:
    const int acno;
    int bal;

public:
    SavingsAccount(int a) : acno(a) {
        bal = random(100000, 10000);
    }

    int random(int u, int l) {
        int r = u - l + 1;
        r = (rand() % r) + l;
        return r;
    }

    void deposit(int taka) {  
        bal = bal + taka;
    }

    void withdraw(int taka) {
        bal = bal - taka;
    }

    int getAccountNumber() const {  
        return acno;
    }

    int getbal() const {  
        return bal;
    }
};

int main() {
    SavingsAccount* a[100];  
    int total_interest = 0;

    cout << "ac_no  |  Balance  | interest ->  cuurent_balance" <<endl;
    cout << "=============================================="<< endl;
    for (int i = 0; i < 100; i++) {
            
            a[i] = new SavingsAccount(i + 165);
        
            cout << "00" << a[i]->getAccountNumber() <<"  |  "<< a[i]->getbal() << "    |   " ;
            int interest = rate*a[i]->getbal()/100;

        total_interest +=interest;

        a[i]->deposit(interest);
        cout << interest << "      ----> " << a[i]->getbal() << endl;
    }

    cout << endl << "Total amount of interest paid to all accounts : " << total_interest <<endl;

    for (int i = 0; i < 100; i++) {
        delete a[i];
    }

    return 0;
}
