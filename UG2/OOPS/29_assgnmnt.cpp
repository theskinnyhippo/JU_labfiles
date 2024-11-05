#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;

class book{
	private :
		const string isbn;
		string title;
		const int a_no;
		string* author;
		const int price;
	
	public :
		book() : isbn(), title(), price(), a_no() {
			author = new string[a_no];
		}

		book(string i, string t, int p, int a): isbn(i), title(t), a_no(a), price(p) {
			author = new string[a_no];
		}

		book copyB(const book &B) const{
			book newB;
			newB.isbn = B.isbn;
			newB.title = B.title;
			newB.a_no = B.a_no;
			
