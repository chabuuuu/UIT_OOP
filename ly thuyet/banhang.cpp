#include <iostream>
#include <vector>
#include <string>
#include<map>
using namespace std;

class SanPham {
protected:
    string maSo;
    string tieuDe;
    double giaBan;

public:
    SanPham()
        : maSo(0), tieuDe(""), giaBan(0.0) {}

    // virtual void nhap() = 0;
    virtual void nhap() {
        cout << "Ma so: ";
        cin >> maSo;
        cout << "Tieu de: ";
        cin.ignore();
        getline(cin, tieuDe);
        cout << "Gia ban ";
        cin >> giaBan;
    }

    virtual void hienThiThongTin() {
        cout << "Ma so: " << maSo << endl;
        cout << "Tieu de: " << tieuDe << endl;
        cout << "Gia ban " << giaBan << endl;
    }

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
    void nhap()  override {
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

    void hienThiThongTin() override {
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

  

    string layTenKhachHang() const {
        return tenKhachHang;
    }

    string laySoDienThoai() const {
        return soDienThoai;
    }
    string layMaKhachHang() const {
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

            SanPham* sanPham = new SanPham();
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
    KhachHang* thongTinKhachHang(){
        return khachHang;
    }
};



class QuanLyHoaDon {
private:
    vector<HoaDon*> danhSachHoaDon;

public:
    ~QuanLyHoaDon (){
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

    double tinhTongThuNhap() const {
        double tongThuNhap = 0;
        for (const auto& hoaDon : danhSachHoaDon) {
            tongThuNhap += hoaDon->tinhTongGiaTri();
        }
        return tongThuNhap;
    }

    // HoaDon* timKhachHangMuaNhieuNhat() const {
    //     // HoaDon* hoaDonMuaNhieuNhat = nullptr;
    //     // double maxTongGiaTri = 0;
    //     // for (const auto& hoaDon : danhSachHoaDon) {
    //     //     double tongGiaTri = hoaDon->tinhTongGiaTri();
    //     //     if (tongGiaTri > maxTongGiaTri) {
    //     //         maxTongGiaTri = tongGiaTri;
    //     //         hoaDonMuaNhieuNhat = hoaDon;
    //     //     }
    //     // }
    //     // return hoaDonMuaNhieuNhat;
    // }
    void timKhachHangMuaNhieuNhat(){
       map<KhachHang*, int> soLuongHoaDon;

    // Duyệt qua danh sách hóa đơn và tăng số lượng hóa đơn tương ứng cho từng khách hàng
    for (const auto& hoaDon : danhSachHoaDon) {
        KhachHang* khachHang = hoaDon->thongTinKhachHang();
        if (soLuongHoaDon.find(khachHang) != soLuongHoaDon.end()) {
            soLuongHoaDon[khachHang]++;
        } else {
            soLuongHoaDon[khachHang] = 1;
        }
    }

    // Tìm khách hàng có số lượng hóa đơn nhiều nhất
    KhachHang* khachHangMuaNhieuNhat = nullptr;
    int maxSoLuongHoaDon = 0;
    for (const auto& pair : soLuongHoaDon) {
        if (pair.second > maxSoLuongHoaDon) {
            khachHangMuaNhieuNhat = pair.first;
            maxSoLuongHoaDon = pair.second;
        }
    }

    // Xuất thông tin khách hàng có nhiều hóa đơn nhất (nếu có)
    if (khachHangMuaNhieuNhat != nullptr) {
        cout << "Khách hàng mua nhiều hóa đơn nhất: " << khachHangMuaNhieuNhat->layTenKhachHang() << endl;
        cout << "Số lượng hóa đơn: " << maxSoLuongHoaDon << endl;
    } else {
        cout << "Không có khách hàng nào mua hóa đơn." << endl;
    }
        
    }
};

int main() {
    QuanLyHoaDon quanLy;

    // Nhập danh sách hoá đơn
    quanLy.nhapDanhSachHoaDon();

    // Hiển thị danh sách hoá đơn
    quanLy.hienThiDanhSachHoaDon();

    // Tính tổng thu nhập
    double tongThuNhap = quanLy.tinhTongThuNhap();
    cout << "Tong thu nhap cua cua hang: " << tongThuNhap << endl;

    quanLy.timKhachHangMuaNhieuNhat();
    // // Tìm khách hàng mua nhiều nhất
    // HoaDon* hoaDonMuaNhieuNhat = quanLy.timKhachHangMuaNhieuNhat();
    // if (hoaDonMuaNhieuNhat != nullptr) {
    //     cout << "Khách hàng mua nhiều nhất: " << hoaDonMuaNhieuNhat->layKhachHang()->layTenKhachHang() << endl;
    // }

    // // Giải phóng bộ nhớ
    // for (const auto& hoaDon : quanLy.danhSachHoaDon) {
    //     delete hoaDon;
    // }

    return 0;
}
