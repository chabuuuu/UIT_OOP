#include<iostream>
using namespace std;

class test{
    private:
    int x, y;
    public:
    int Trung(test P);
    test (int ox, int oy){
        this->x = ox;
        this->y = oy;
    }
    void print(){
        cout<<x<<y;
    }
};


int test::Trung(test P){
    x = P.x;
}

int main(){
    test Thu(2,3);
    Thu.print();

    return 0;
}