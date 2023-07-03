#include<iostream>
using namespace std;

class Cha{
protected:
int a;
int b;


public:
 
 Cha(){
    a = 0;
    b = 0;
 }

 virtual void nhap(){
    cout<<"hello";
 }

    void xuat(){
    cout<<a<<b;
}
};

class Con : public Cha{
    private:
    int c;
public:

Con(){
    a = 1;
    b = 1;
}

void nhap(){
    cin>>c;
    cout<<"cin>>c";
}


};

class Con2 : public Cha{

public:
Con2(){
    a = 5;
    b = 5;
}

};

int main(){
Cha* object;
object = new Con();
object->xuat();
object->nhap();
object = new Con2;
object->xuat();
object->nhap();
}