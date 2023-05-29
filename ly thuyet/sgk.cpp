#include<iostream>
#include<vector>
#include<string>
using namespace std;

class SachGiaoKhoa{
private:
 string m_maSach, m_tenSach, m_nhaXuatBan;
 int m_soLuong;
 float m_donGia;
 bool m_tinhTrang;
 float m_thanhTien;
public:
    SachGiaoKhoa(const string& maSach, const string& tenSach, const string& nhaXuatBan, int soLuong, float donGia, bool tinhTrang): 
    m_maSach(maSach), m_tenSach(tenSach), m_nhaXuatBan(nhaXuatBan), m_soLuong(soLuong), m_donGia(donGia), m_tinhTrang(tinhTrang), 
    m_thanhTien(tinhTrang == 1 ? (soLuong * donGia) : (soLuong * donGia * 0.5)){}
    
    void xuatThongTin(){
        cout << "Ma sach: " << m_maSach ;
        cout << ", Ten sach: " << m_tenSach ;
        cout << ", Nha xuat ban: " << m_nhaXuatBan ;
        cout << ", So luong: " << m_soLuong ;
        cout << ", Don gia: " << m_donGia ;
        cout<< ", Tinh trang: "<<m_tinhTrang;
        cout<<", Thanh tien: "<<m_thanhTien<<endl;
    }
    float getThanhTien(){
        return m_thanhTien;
    }
    string getNhaXuatBan(){
        return m_nhaXuatBan;
    }

};

class SachThamKhao{
private:
 string m_maSach, m_tenSach, m_nhaXuatBan;
 int m_soLuong;
 float m_donGia;
 float m_tienThue;
 float m_thanhTien;
public:
    SachThamKhao(const string& maSach, const string& tenSach, const string& nhaXuatBan, int soLuong, float donGia , float tienThue): 
    m_maSach(maSach), m_tenSach(tenSach), m_nhaXuatBan(nhaXuatBan), m_soLuong(soLuong), m_donGia(donGia), m_tienThue(tienThue), m_thanhTien(soLuong*donGia + tienThue){}
    

    void xuatThongTin(){
        cout << "Ma sach: " << m_maSach;
        cout << ", Ten sach: " << m_tenSach ;
        cout << ", Nha xuat ban: " << m_nhaXuatBan ;
        cout << ", So luong: " << m_soLuong ;
        cout << ", Don gia: " << m_donGia ;
        cout<< ", Tien thue: "<<m_tienThue;
        cout<<", Thanh tien: "<<m_thanhTien<<endl;
    }
    float getThanhTien(){
        return m_thanhTien;
    }
   

};


void nhapDanhSachSach(vector<SachGiaoKhoa>& dsSachGiaoKhoa, vector<SachThamKhao>& dsSachThamKhao) {
int nSachThamKhao, nSachGiaoKhoa;
cout << "Nhap so luong sach giao khoa ";
cin >> nSachGiaoKhoa;
cout << "Nhap thong tin " << nSachGiaoKhoa << " sach giao khoa" << endl;
for (int i = 0; i < nSachGiaoKhoa; i++) {
string maSach, tenSach, nhaXuatBan;
 int soLuong;
 float donGia;
 bool tinhTrang;
 

cout << "Nhap thong tin sach thu " << i+1 << endl;
cout << "Ma Sach: ";
cin >> maSach;
cout << "Ten sach: ";
cin.ignore();
getline(cin, tenSach);
cout << "Nha xuat ban: ";
getline(cin, nhaXuatBan);
cout << "So luong: ";
cin >> soLuong;
cout << "Don gia: ";
cin >> donGia;
cout << "Tinh trang: (1: moi/0: cu):  ";
cin >> tinhTrang;
SachGiaoKhoa sgk(maSach, tenSach, nhaXuatBan, soLuong, donGia, tinhTrang);
dsSachGiaoKhoa.push_back(sgk);
}


cout << "Nhap so luong sach tham khao ";
cin >> nSachThamKhao;
cout << "Nhap thong tin " << nSachThamKhao << " sach tham khao" << endl;


for (int i = 0; i < nSachThamKhao; i++) {
string maSach, tenSach, nhaXuatBan;
 int soLuong;
 float donGia;
 float tienThue;
 

cout << "Nhap thong tin sach thu " << i+1 << endl;
cout << "Ma Sach: ";
cin >> maSach;
cout << "Ten sach: ";
cin.ignore();
getline(cin, tenSach);
cout << "Nha xuat ban: ";
getline(cin, nhaXuatBan);
cout << "So luong: ";
cin >> soLuong;
cout << "Don gia: ";
cin >> donGia;
cout << "Tien thue: ";
cin >> tienThue;
SachThamKhao stk(maSach, tenSach, nhaXuatBan, soLuong, donGia, tienThue);
dsSachThamKhao.push_back(stk);
}


}


void xuatDsSach (vector<SachGiaoKhoa> dsSachGiaoKhoa, vector<SachThamKhao> dsSachThamKhao){
    cout<<endl;
    cout<<"Danh sach sach giao khoa: \n";
    for (int i = 0 ; i < dsSachGiaoKhoa.size(); i++){
        dsSachGiaoKhoa[i].xuatThongTin();
    }
     cout<<"Danh sach sach tham khao: \n";
    for (int i = 0 ; i < dsSachThamKhao.size(); i++){
        dsSachThamKhao[i].xuatThongTin();
    }
}

void thanhTienTungLoaiSach(vector<SachGiaoKhoa> dsSachGiaoKhoa, vector<SachThamKhao> dsSachThamKhao){
    float thanhTienSGK = 0;
    float thanhTienSTK = 0;
    float minThanhTien = 10000000000;
    cout<<endl;
    cout<<"Thanh tien sach giao khoa: ";
    for (int i = 0 ; i < dsSachGiaoKhoa.size(); i++){
        thanhTienSGK = thanhTienSGK + dsSachGiaoKhoa[i].getThanhTien();
        if (dsSachGiaoKhoa[i].getThanhTien() < minThanhTien){
            minThanhTien = dsSachGiaoKhoa[i].getThanhTien();
        }
    }
    cout<<thanhTienSGK;
    cout<<endl;
    cout<<"Thanh tien sach tham khao: ";
    
    for (int i = 0 ; i < dsSachThamKhao.size(); i++){
        thanhTienSTK = thanhTienSTK + dsSachThamKhao[i].getThanhTien();
        if (dsSachThamKhao[i].getThanhTien() < minThanhTien){
            minThanhTien = dsSachThamKhao[i].getThanhTien();
        }
    }
    cout<<thanhTienSTK;

    cout<<endl;
    cout<<"Nhung sach co thanh tien phai tra it nhat: \n";

    for (int i = 0 ; i < dsSachGiaoKhoa.size(); i++){
        if (dsSachGiaoKhoa[i].getThanhTien() == minThanhTien){
            dsSachGiaoKhoa[i].xuatThongTin();
        }
    }
    for (int i = 0 ; i < dsSachThamKhao.size(); i++){
        if (dsSachThamKhao[i].getThanhTien() == minThanhTien){
            dsSachThamKhao[i].xuatThongTin();
        }
    }
}

void timSach (vector<SachGiaoKhoa> dsSachGiaoKhoa, string& nhaXuatBan){
    cout<<endl;
    cout<<"Cac sach giao khoa cua nha xuat ban da nhap: \n";
for (int i = 0 ; i < dsSachGiaoKhoa.size(); i++){
        if (nhaXuatBan.compare(dsSachGiaoKhoa[i].getNhaXuatBan()) == 0  ){
            dsSachGiaoKhoa[i].xuatThongTin();
        }
    }

}
 


int main(){
    vector<SachGiaoKhoa> dsSachGiaoKhoa;
 vector<SachThamKhao> dsSachThamKhao;
 int choice;
 cout<<"Chon chuc nang: \n 1. Nhap danh sach sach giao khoa va sach tham khao\n 2. Xuat danh sach sach giao khoa va sach tham khao\n 3. Thanh tien thu vien phai tra tung loai sach, hien thi thong tin sach co thanh tien it nhat\n 4. Tim thong tin cac sach giao khoa co ten do nguoi dung nhap vao\n 5. Thoat chuong trinh\n";
 cin>>choice;
 
 while (choice != 5){
    if (choice == 1){
         nhapDanhSachSach(dsSachGiaoKhoa, dsSachThamKhao);

    }
    if (choice == 2){
        xuatDsSach(dsSachGiaoKhoa,dsSachThamKhao);

    }
    if (choice == 3){
        thanhTienTungLoaiSach(dsSachGiaoKhoa, dsSachThamKhao);
    }

    if (choice == 4){
        string nhaXuatBan;
        cout<<"Nhap nha xuat ban: \n";
        cin.ignore();
        getline(cin, nhaXuatBan);
        cout<<nhaXuatBan;
        timSach(dsSachGiaoKhoa, nhaXuatBan);
    }


    cout<<"----------------------------------------------\nChon chuc nang: \n 1. Nhap danh sach sach giao khoa va sach tham khao\n 2. Xuat danh sach sach giao khoa va sach tham khao\n 3. Thanh tien thu vien phai tra tung loai sach, hien thi thong tin sach co thanh tien it nhat\n 4. Tim thong tin cac sach giao khoa co ten do nguoi dung nhap vao\n 5. Thoat chuong trinh\n--------------------------------------------------------";
 cin>>choice;
 }


    return 0;
}