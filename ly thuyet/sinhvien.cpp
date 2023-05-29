#include <iostream>
#include <vector>
#include <string>
using namespace std;
class SinhVienCaoDang {
private:
    string m_maSV;
    string m_hoTen;
    string m_diaChi;
    int m_tongSoTinChi;
    float m_diemTrungBinh;
    float m_diemThiTotNghiep;
public:
      SinhVienCaoDang(): m_maSV(""), m_hoTen(""), m_diaChi(""), m_tongSoTinChi(0),
        m_diemTrungBinh(0), m_diemThiTotNghiep(0) {}


    SinhVienCaoDang(const string& maSV, const string& hoTen, const string& diaChi,
                    int tongSoTinChi, float diemTrungBinh, float diemThiTotNghiep)
        : m_maSV(maSV), m_hoTen(hoTen), m_diaChi(diaChi), m_tongSoTinChi(tongSoTinChi),
        m_diemTrungBinh(diemTrungBinh), m_diemThiTotNghiep(diemThiTotNghiep) {}

    bool duDieuKienTotNghiep() const {
        return m_tongSoTinChi >= 120 && m_diemTrungBinh >= 5 && m_diemThiTotNghiep >= 5;
    }

    void xuatThongTin() const {
        cout << "Ma SV: " << m_maSV << ", Ho Ten: " << m_hoTen << ", Dia Chi: " << m_diaChi
                  << ", Tong So Tin Chi: " << m_tongSoTinChi << ", Diem TB: " << m_diemTrungBinh
                  << ", Diem Thi Tot Nghiep: " << m_diemThiTotNghiep << endl;
    }

    float getDiemTB() const {
        return m_diemTrungBinh;
    }
};

class SinhVienDaiHoc {
private:
    string m_maSV;
    string m_hoTen;
    string m_diaChi;
    int m_tongSoTinChi;
    float m_diemTrungBinh;
    string m_tenLuanVan;
    float m_diemLuanVan;
public:
        SinhVienDaiHoc(): m_maSV(""), m_hoTen(""), m_diaChi(""), m_tongSoTinChi(0), m_diemTrungBinh(0),
m_tenLuanVan(""), m_diemLuanVan(0) {}


    SinhVienDaiHoc(const string& maSV, const string& hoTen, const string& diaChi,
                   int tongSoTinChi, float diemTrungBinh, const string& tenLuanVan, float diemLuanVan)
        : m_maSV(maSV), m_hoTen(hoTen), m_diaChi(diaChi), m_tongSoTinChi(tongSoTinChi), m_diemTrungBinh(diemTrungBinh),
m_tenLuanVan(tenLuanVan), m_diemLuanVan(diemLuanVan) {}
bool duDieuKienTotNghiep() const {
    return m_tongSoTinChi >= 150 && m_diemTrungBinh >= 5 && m_diemLuanVan >= 5;
}

void xuatThongTin() const {
    cout << "Ma SV: " << m_maSV << ", Ho Ten: " << m_hoTen << ", Dia Chi: " << m_diaChi
              << ", Tong So Tin Chi: " << m_tongSoTinChi << ", Diem TB: " << m_diemTrungBinh
              << ", Ten Luan Van: " << m_tenLuanVan << ", Diem Luan Van: " << m_diemLuanVan << endl;
}

float getDiemTB() const {
    return m_diemTrungBinh;
}
};

void nhapDanhSachSinhVien(vector<SinhVienCaoDang>& dsSVCaoDang, vector<SinhVienDaiHoc>& dsSVDaiHoc) {
int nSVCaoDang, nSVDaiHoc;
cout << "Nhap so luong sinh vien cao dang: ";
cin >> nSVCaoDang;
cout << "Nhap thong tin " << nSVCaoDang << " sinh vien cao dang" << endl;
for (int i = 0; i < nSVCaoDang; i++) {
string maSV, hoTen, diaChi;
int tongSoTinChi;
float diemTrungBinh, diemThiTotNghiep;

cout << "Nhap thong tin sinh vien thu " << i+1 << endl;
cout << "Ma SV: ";
cin >> maSV;
cout << "Ho ten: ";
cin.ignore();
getline(cin, hoTen);
cout << "Dia chi: ";
getline(cin, diaChi);
cout << "Tong so tin chi: ";
cin >> tongSoTinChi;
cout << "Diem trung binh: ";
cin >> diemTrungBinh;
cout << "Diem thi tot nghiep: ";
cin >> diemThiTotNghiep;
SinhVienCaoDang sv(maSV, hoTen, diaChi, tongSoTinChi, diemTrungBinh, diemThiTotNghiep);
dsSVCaoDang.push_back(sv);
}



cout << "Nhap so luong sinh vien dai hoc: ";
cin >> nSVDaiHoc;
cout << "Nhap thong tin " << nSVDaiHoc << " sinh vien dai hoc" << endl;
for (int i = 0; i < nSVDaiHoc; i++) {
    string maSV, hoTen, diaChi, tenLuanVan;
    int tongSoTinChi;
    float diemTrungBinh, diemLuanVan;
   
    cout << "Nhap thong tin sinh vien thu " << i+1 << endl;
cout << "Ma SV: ";
cin >> maSV;
cout << "Ho ten: ";
cin.ignore();
getline(cin, hoTen);
cout << "Dia chi: ";
getline(cin, diaChi);
cout << "Tong so tin chi: ";
cin >> tongSoTinChi;
cout << "Diem trung binh: ";
cin >> diemTrungBinh;

cout<<"Ten luan van: ";
cin.ignore();
getline(cin, tenLuanVan);
cout<<"Diem luan van: ";
cin>>diemLuanVan;
SinhVienDaiHoc svdh(maSV, hoTen, diaChi, tongSoTinChi, diemTrungBinh, tenLuanVan, diemLuanVan);
dsSVDaiHoc.push_back(svdh);
}
}

void xuatDsSinhVien (vector<SinhVienCaoDang> dsSVCaoDang, vector<SinhVienDaiHoc> dsSVDaiHoc){
    cout<<endl;
    cout<<"Danh sach sinh vien cao dang: \n";
    for (int i = 0 ; i < dsSVCaoDang.size(); i++){
        dsSVCaoDang[i].xuatThongTin();
    }
     cout<<"Danh sach sinh vien dai hoc: \n";
    for (int i = 0 ; i < dsSVDaiHoc.size(); i++){
        dsSVDaiHoc[i].xuatThongTin();
    }
}
int sinhVienDuDieuKienTotNghiep(vector<SinhVienCaoDang> dsSVCaoDang, vector<SinhVienDaiHoc> dsSVDaiHoc){
    int count = 0;
    cout<<endl;
    cout<<"So sinh vien du dieu kien tot nghiep: \n";
    for (int i = 0 ; i < dsSVCaoDang.size(); i++){
        if (dsSVCaoDang[i].duDieuKienTotNghiep() == true){
            count++;
        }
    }

    for (int i = 0 ; i < dsSVDaiHoc.size(); i++){
        if(dsSVDaiHoc[i].duDieuKienTotNghiep() == true){
            count++;
        }
    }
    return count;
}

void sinhVienDtbCaoNhat(vector<SinhVienDaiHoc> dsSVDaiHoc){
    cout<<endl;
    cout<<"Sinh vien dai hoc co diem trung binh cao nhat: \n";
    SinhVienDaiHoc maxDtbDaiHoc;

    for (int i = 0 ; i < dsSVDaiHoc.size(); i++){
       if (dsSVDaiHoc[i].getDiemTB() > maxDtbDaiHoc.getDiemTB()){
            maxDtbDaiHoc = dsSVDaiHoc[i];
        }
    }
    maxDtbDaiHoc.xuatThongTin();

}

int main(){
    vector<SinhVienCaoDang> dsSVCaoDang;
    vector<SinhVienDaiHoc> dsSVDaiHoc;
    cout<<"Chon chuc nang: \n 1. Nhap danh sach sinh vien\n 2. Xuat Danh Sach Sinh Vien \n 3. Cho biet so luong sinh vien du dieu kien tot nghiep  \n 4. Sinh vien dai hoc co diem trung binh cao nhat\n 5. Thoat chuong trinh\n";
    int choice;
    cin>>choice;
    while (choice != 5){
        if (choice == 1){
                nhapDanhSachSinhVien(dsSVCaoDang, dsSVDaiHoc);

        }
        if (choice == 2){
                xuatDsSinhVien(dsSVCaoDang, dsSVDaiHoc);

        }
        if (choice == 3){
            cout<<sinhVienDuDieuKienTotNghiep(dsSVCaoDang, dsSVDaiHoc)<<endl;
        }
        if (choice == 4){
            sinhVienDtbCaoNhat(dsSVDaiHoc);
        }

            cout<<"--------------------------------------------\nChon chuc nang: \n 1. Nhap danh sach sinh vien\n 2. Xuat Danh Sach Sinh Vien \n 3. Cho biet so luong sinh vien du dieu kien tot nghiep  \n 4. Sinh vien dai hoc co diem trung binh cao nhat\n 5. Thoat chuong trinh\n---------------------------------------------------\n";
            cin>>choice;
    }
    return 0;
}