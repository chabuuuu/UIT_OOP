#include <iostream>
#include <vector>
#include <string>
#include<map>

using namespace std;

class SanPham {
protected:
    int maSo;
    string tieuDe;
    double giaBan;

public:
    SanPham()
        : maSo(0), tieuDe(""), giaBan(0.0) {}

    virtual void nhap() {
         cout << "Ma so: ";
        cin >> maSo;
        cout << "Tieu de: ";
        cin.ignore();
        getline(cin, tieuDe);
        cout << "Gia ban ";
        cin >> giaBan;
    };

    virtual void hienThiThongTin() {
         cout << "Ma so: " << maSo << endl;
        cout << "Tieu de: " << tieuDe << endl;
        cout << "Gia ban: " << giaBan << endl;
    };

    double layGiaBan() const {
        return giaBan;
    }
};

class TranhAnh : public SanPham {
private:
    int chieuRong;
    int chieuCao;
    string tenHoaSi;

public:
    void nhap() override {
        cout << "Nhap thong tin tranh anh" << endl;
        SanPham::nhap();
        cout << "Chieu rong: ";
        cin >> chieuRong;
        cout << "Chieu cao: ";
        cin >> chieuCao;
        cout << "Ten hoa si: ";
        cin.ignore();
        getline(cin, tenHoaSi);
    }

    void hienThiThongTin()  override {
        SanPham::hienThiThongTin();
        cout << "Kich thuoc: "<<"Chieu rong: " << chieuRong << "Chieu cao: " << chieuCao << endl;
        cout << "Hoa si: " << tenHoaSi << endl;
    }
};

class CDAmNhac : public SanPham {
private:
    string tenCaSi;
    string tenDonViSanXuat;

public:
    void nhap() override {
        cout << "Nhap thong tin CD am nhac" << endl;
        SanPham::nhap();
        cout << "Ten ca si: ";
        cin.ignore();
        getline(cin, tenCaSi);
        cout << "Ten don vi san xuat: ";
        getline(cin, tenDonViSanXuat);
    }

    void hienThiThongTin()  override {
        SanPham::hienThiThongTin();
        cout << "Ca si: " << tenCaSi << endl;
        cout << "Don vi san xuat: " << tenDonViSanXuat << endl;
    
    }
};

class KhachHang {
private:
    string maKhachHang;
    string tenKhachHang;
    string soDienThoai;

public:
    void nhap() {
        cout << "Nhap thong tin khach hang" << endl;
        cout << "Ma khach hang:  ";
        cin >> maKhachHang;
        cout << "Ten khach hang: ";
        cin.ignore();
        getline(cin, tenKhachHang);
        cout << "So dien thoai ";
        getline(cin, soDienThoai);
    }
    void xuat(){
           cout << "Ma khach hang:  ";
        cout<< maKhachHang<<endl;
        cout << "Ten khach hang: ";
        cout<<tenKhachHang<<endl;
        cout << "So dien thoai ";
        cout<<soDienThoai<<endl;
    }

    string layTenKhachHang() const {
        return tenKhachHang;
    }

    string laySoDienThoai() const {
        return soDienThoai;
    }
    string layMaSo(){
        return maKhachHang;
    }
};

class HoaDon {
private:
    string maHoaDon;
    KhachHang* khachHang;
    string ngayLapHoaDon;
    vector<SanPham*> danhSachSanPham;

public:
    void nhap() {
        cout << "Nhap thong tin hoa don: " << endl;
        cout << "Ma hoa don: ";
        cin >> maHoaDon;

        khachHang = new KhachHang();
        khachHang->nhap();

        cout << "Ngay lap hoa don: ";
        cin.ignore();
        getline(cin, ngayLapHoaDon);

        int soLuongSanPham;
         cout << "Nhap so luong san pham: ";
        cin >> soLuongSanPham;

        for (int i = 0; i < soLuongSanPham; i++) {
            int loaiSanPham;
            cout << "Nhap loai san pham (1 - Tranh anh, 2 - CD am nhac): ";
            cin >> loaiSanPham;

            SanPham* sanPham;
            if (loaiSanPham == 1) {
                sanPham = new TranhAnh();
            } else if (loaiSanPham == 2) {
                sanPham = new CDAmNhac();
            } else {
                cout << "Loai san pham khong hop le" << endl;
                continue;
            }

            sanPham->nhap();
            danhSachSanPham.push_back(sanPham);
        }
    }

    double tinhTongGiaTri() const {
        double tongGiaTri = 0;
        for (const auto& sanPham : danhSachSanPham) {
            tongGiaTri += sanPham->layGiaBan();
        }
        return tongGiaTri;
    }

    void hienThiThongTin() const {
       cout << "Ma hoa don: " << maHoaDon << endl;
        cout << "Thong tin khach hang: " << khachHang->layTenKhachHang() << " - " << khachHang->laySoDienThoai() << endl;
        cout << "Ngay lap hoa don: " << ngayLapHoaDon << endl;
        cout << "Danh sach san pham: " << endl;
        for (const auto& sanPham : danhSachSanPham) {
            sanPham->hienThiThongTin();
            cout << endl;
        }
        cout << "Tong gia tri: " << tinhTongGiaTri() << endl;
    }
    KhachHang* layKhachHang(){
        return khachHang;
    }
    string layMaSoKhachHang(){
        return khachHang->layMaSo();
    }
};

class QuanLyHoaDon {
private:
    vector<HoaDon*> danhSachHoaDon;

public:

    ~QuanLyHoaDon(){
   // Giải phóng bộ nhớ
    for (const auto& hoaDon : danhSachHoaDon) {
        delete hoaDon;
    }
    }
  

    void themHoaDon(HoaDon* hoaDon) {
        danhSachHoaDon.push_back(hoaDon);
    }

    void nhapDanhSachHoaDon() {
        int soLuongHoaDon;
        cout << "Nhap so luong hoa don: ";
        cin >> soLuongHoaDon;

        for (int i = 0; i < soLuongHoaDon; i++) {
            HoaDon* hoaDon = new HoaDon();
            hoaDon->nhap();
            themHoaDon(hoaDon);
        }
    }

    void hienThiDanhSachHoaDon() const {
        cout << "Danh sach hoa don: " << endl;
        for (const auto& hoaDon : danhSachHoaDon) {
            hoaDon->hienThiThongTin();
            cout << endl;
        }
    }

    void tinhTongThuNhap() const {
        double tongThuNhap = 0;
        for (const auto& hoaDon : danhSachHoaDon) {
            tongThuNhap += hoaDon->tinhTongGiaTri();
        }
        cout << "Tong thu nhap cua cua hang " << tongThuNhap << endl;
    }

   void xuatKhachHangMuaNhieuNhat() {

    map<string, double> tongGiaTriHoaDon;

 
    for (const auto& hoaDon : danhSachHoaDon) {
    
        string khachHang = hoaDon->layMaSoKhachHang();
        double tongGiaTri = hoaDon->tinhTongGiaTri();
     
        if (tongGiaTriHoaDon.find(khachHang) != tongGiaTriHoaDon.end()) {
            tongGiaTriHoaDon[khachHang] += tongGiaTri;
        } else {
            tongGiaTriHoaDon[khachHang] = tongGiaTri;
        }
    }
    

    // Tìm khách hàng có tổng giá trị hóa đơn lớn nhất
    
    string khachHangMuaNhieuNhat ;
    double maxTongGiaTri = 0;
    for (const auto& pair : tongGiaTriHoaDon) {
        if (pair.second > maxTongGiaTri) {
            khachHangMuaNhieuNhat = pair.first;
            maxTongGiaTri = pair.second;
        }
    }

    // Xuất thông tin khách hàng mua nhiều nhất 
  
      
        for (const auto& hoaDon : danhSachHoaDon) {
        
        if (khachHangMuaNhieuNhat == hoaDon->layMaSoKhachHang()){
            KhachHang* khachHangMuaNhieu = hoaDon->layKhachHang();
            cout<<"Khach hang mua nhieu nhat: \n";
            khachHangMuaNhieu->xuat();
            break;
        }
        }
   
        cout << "Tong gia tri hoa don " << maxTongGiaTri << endl;
}

};

int main() {
    QuanLyHoaDon quanLy;
    quanLy.nhapDanhSachHoaDon();
    quanLy.hienThiDanhSachHoaDon();
    quanLy.tinhTongThuNhap();
    quanLy.xuatKhachHangMuaNhieuNhat();
    return 0;
}
