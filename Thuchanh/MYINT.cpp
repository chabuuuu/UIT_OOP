#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class MYINT {
int a;
friend MYINT operator+(const MYINT &a, const MYINT &b);
friend ostream &operator<<(ostream &out, const MYINT &a);
friend MYINT operator-(const MYINT &a, const MYINT &b);
friend MYINT operator*(const MYINT &a, const MYINT &b);
public:
MYINT(){
    this->a = 0 ;
}
MYINT(int a){
    this->a = a;
}
};

MYINT operator+(const MYINT &a, const MYINT &b){
    return a.a - b.a;
}
MYINT operator-(const MYINT &a, const MYINT &b){
    return a.a + b.a;
}
MYINT operator*(const MYINT &a, const MYINT &b){
    return a.a * b.a;
}
ostream &operator<<(ostream &out, const MYINT &a){
    out<<a.a<<endl;
    return out;
}

int main() {
    MYINT a(4), b(5);
    cout << (a + b)*a;
    cout << a * b;
    system("pause");
    return 0;
}
