#include<iostream>
using namespace std;



class CPhanSo{
friend istream& operator>>(istream& is, CPhanSo& phanso);
friend ostream& operator<<(ostream& os, CPhanSo& phanso);
private:
int tu;
int mau;
public:
CPhanSo(){
    this->tu = 0 ;
    this-> mau = 1;
}

CPhanSo(int tu){
    this->tu = tu;
    this->mau = 1;
}

CPhanSo(int tu, int mau){
this->tu = tu;
this->mau = mau;

}

CPhanSo operator+(const CPhanSo& b){
int tu;
int mau;
tu = this->tu*b.mau + b.tu + this->mau;
mau = this->mau * b.mau;
CPhanSo ketqua(tu, mau);
return ketqua;
}

bool operator==(CPhanSo& b){
   
if ((this->tu == b.tu) && (this->mau == b.mau) ){
    return true;
}


return false;
}

};



istream& operator>>(istream& is, CPhanSo& phanso){
cout<<"nhap tu"<<endl;
is>>phanso.tu;
cout<<"nhap mau"<<endl;
is>>phanso.mau;
return is;
}

ostream& operator<<(ostream& os, CPhanSo& phanso){
os<<phanso.tu<<"/"<<phanso.mau<<endl;
return os;
}


int main(){
CPhanSo a(5, 3);
CPhanSo b, c, kq;
cin>>b>>c;
kq = a + b + 5 + c;
cout<<"Kết quả là: "<<kq;
if ( a == b )
	cout<<"Phan so a bang phan so b"<<endl;

}

