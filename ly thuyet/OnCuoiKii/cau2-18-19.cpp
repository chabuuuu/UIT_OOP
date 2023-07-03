#include<iostream>
using namespace std;
class Time{
private:
	int gio;
	int phut;
	int giay;

public:
	friend istream& operator>>(istream& is, Time& time);
	friend ostream& operator<<(ostream& os, Time& time);
    void Tang(){
        this->giay++;
	if (this->giay>=60){
	this->giay = 0;
	this->phut ++;
	if (this->phut >= 60){
	this->phut = 0;
	this->gio ++;
	if (this->gio >= 24){
	this->gio = 0;
	}
	}
	}
    }
	Time operator++(){
	this->Tang();
    return *this;
   }

    Time operator++(int){
        Time temp;
        temp = *this;
        this->Tang();
        return temp;
    }
};

istream& operator>>(istream&is, Time &time){
	cout<<"nhap gio"<<endl;
	is>>time.gio;
	cout<<"nhap phut"<<endl;
	is>>time.phut;
	cout<<"nhap giay"<<endl;
	is>>time.giay;
	return is;
}

ostream& operator<<(ostream& os, Time& time){
	os<<time.gio<<" ";
	os<<time.phut<<" ";
	os<<time.giay<<" ";
	return os;
}



int main(){
    Time time;
    cin>>time;
    cout<<time;
    Time time2;

    time2 = time++;
    cout<<time2;
}