#include<iostream>
using namespace std;

class IntArr {
friend istream& operator>>(istream& is, IntArr& l);
friend ostream& operator<<(ostream& os, IntArr& l);

private:
int count; // tổng số lượng phần tử có trong values
int* values; // mảng các số nguyên đang có trong đối tượng hiện tại
public:
/* Sinh viên bổ sung đầy đủ các thành phần cần thiết để hàm main hoạt động 
 như mong đợi */
IntArr(){

}

IntArr(int soPhanTu, int giaTri){
count = soPhanTu;
values= new int[count];
for (int i = 0; i< count; i++){
    values[i] = 2;
}
}

void xuat(){
for (int i = 0; i < count; i++){
    cout<<values[i];
}
}


IntArr(int soPhanTu){
    count = soPhanTu;
    values = new int [soPhanTu];
    for (int i = 0 ; i< count; i++){
        values[i] = 0;
    }
}

IntArr concat(IntArr& l3){
    IntArr l4;
    l4.count = this->count + l3.count;
    l4.values = new int [l4.count];
    for (int i = 0; i < this->count; i++){
        l4.values[i] = this->values[i];
    }
    int temp = 0;
    for (int i = this->count; i < this->count + l3.count; i++){
        l4.values[i] = l3.values[temp];
        temp++;
    }
    return l4;

}

void push(int value){
    IntArr l1 = (1, value);
    *this = this->concat(l1);
}
 


};


istream& operator>>(istream& is, IntArr& l){
    delete[] l.values;
    cout<<"nhap so phan tu"<<endl;
    is>>l.count;
    l.values = new int[l.count];
    cout<<"nhap phan tu"<<endl;
    for (int i = 0 ; i < l.count; i++){
        is>>l.values[i];
    }
    return is;

}

ostream& operator<<(ostream& os, IntArr& l){
    for (int i = 0 ; i < l.count; i ++){
        os<<l.values[i];
    }
    return os;
}


int main() {
IntArr l1; // tạo mảng không chứa bất kì phần tử nào
IntArr l2(3, 2); /* tạo một mảng với 3 phần tử, tất cả phần tử đều có giá trị
 là 2 */
IntArr l3(2);//tạo một mảng với 2 phần tử, tất cả phần tử đều có giá trị là 0
IntArr l4 = l2.concat(l3); /* tạo ra một IntArr mới có nội dung là kết quả
 của việc nối các phần tử l3 vào cuối các phần tử của l2 theo thứ tự */
l2.push(3); // thêm số 3 vào cuối danh sách trong đối tượng l2
// cin>> l2; /* Xoá các giá trị hiện có trong l2 và cho phép người dùng nhập
//  số lượng phần tử mới và giá trị các phần tử mới vào l2 (cần xoá các vùng nhớ
//  không sử dụng nếu có) */
// cout << l2; // in ra các số nguyên có trong danh sách
// l4.xuat();
cin>>l4;
cout<<l4;
 /* Khi vượt quá phạm vi sử dụng cần huỷ tất cả các vùng nhớ được cấp phát cho
 các values của IntArr */
return 0;
}