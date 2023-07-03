#include<iostream>




using namespace std;


class Date{
friend istream& operator>>(istream& is, Date& date);
friend ostream& operator<<(ostream& os, Date& date);



private:
int ngay;
int thang;
int nam;

public:

Date(){
this->ngay = 1;
this->thang = 1;
this->nam = 1;
}

Date(int nam, int thang){
this->nam = nam;
this->thang = thang;
this->ngay = 1;
}

Date(int nam, int thang, int ngay){
this->ngay = ngay;
this->thang = thang;
this->nam = nam;
}

Date operator++(int){
Date temp = *this;
ngay++;
if (thang == 1 || thang == 3 || thang == 5 || 
thang == 7 ||thang == 8 || thang == 10 || thang == 12){
if (ngay >= 32){
ngay = 1;
thang ++;}
}
else{
if (ngay >= 31){
ngay = 1;
thang++;
}
}
if (thang >= 13){
thang = 1;
nam ++;
}
return temp;
}

bool operator<(Date date){
if (this->nam < date.nam){
return true;
}
if (this->thang < date.thang){
return true;
}
if (this->ngay < date.ngay){
return true;

}
return false;
}
};


istream& operator>>(istream& is, Date& date){
is>>date.ngay>>date.thang>>date.nam;
return is;
}

ostream& operator<<(ostream& os, Date& date){
os<<date.ngay<<"/"<<date.thang<<"/"<<date.nam<<endl;
return os;
}

 
int main() {
Date ng1; // ng1 sẽ có giá trị là ngày 1 tháng 1 năm 1
Date ng2(2017, 1); // ng2 sẽ có giá trị là ngày 1 tháng 1 năm 2017
Date ng3(2017, 1, 7); // ng3 sẽ có giá trị là ngày 7 tháng 1 năm 2017
cin >> ng1;
ng1++;
cout << ng1;
if (ng1 < ng2)
cout << "Ngay 1 truoc ngay 2" << endl;
else
cout << "Ngay 1 khong truoc ngay 2" << endl;
return 0;
}