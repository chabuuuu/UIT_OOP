#include<iostream>
#include<iomanip>
using namespace std;

class Base{

public:
	virtual void xuat(int x = 0){
		cout<<"base";
	}
};

class Con : public Base{
	public:
	void xuat(int x){
		cout<<"hello";
	}
	
};
class Con2 : public Base{
	public:
	void xuat(int x){
		cout<<x;
	}
};

int main() {
	// Base* a;
	// a= new Con;
	// a->xuat();
	// a = new Con2;
	// a->xuat();
	    double number = 1.9e+09;
    cout << setprecision(100) << number << endl;
	return 0;
}