#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SinhVien {
protected:
    string maSV;
    string hoTen;
    string diaChi;
    int tongTinChi;
    float diemTrungBinh;

public:
    virtual void nhap() {
        cout << "Nhap ma so sinh vien: ";
        cin >> maSV;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap tong so tin chi: ";
        cin >> tongTinChi;
        cout << "Nhap diem trung binh: ";
        cin >> diemTrungBinh;
    }

    virtual bool kiemTraTotNghiep() = 0;

    virtual void xuat() {
        cout << "Ma SV: " << maSV << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "Tong tin chi: " << tongTinChi << endl;
        cout << "Diem trung binh: " << diemTrungBinh << endl;
    }
    float getDiemTrungBinh() const {
        return diemTrungBinh;
    }
};

class SinhVienCaoDang : public SinhVien {
private:
    float diemThiTotNghiep;

public:
    void nhap() override {
        SinhVien::nhap();
        cout << "Nhap diem thi tot nghiep: ";
        cin >> diemThiTotNghiep;
    }

    bool kiemTraTotNghiep() override {
        return (tongTinChi >= 120 && SinhVien::diemTrungBinh >= 5 && diemThiTotNghiep >= 5);
    }

    void xuat() override {
        cout << "-- Sinh vien Cao dang --" << endl;
        SinhVien::xuat();
        cout << "Diem thi tot nghiep: " << diemThiTotNghiep << endl;
    }
};

class SinhVienDaiHoc : public SinhVien {
private:
    string tenLuanVan;
    float diemLuanVan;

public:
    void nhap() override {
        SinhVien::nhap();
        cout << "Nhap ten luan van: ";
        cin.ignore();
        getline(cin, tenLuanVan);
        cout << "Nhap diem luan van: ";
        cin >> diemLuanVan;
    }

    bool kiemTraTotNghiep() override {
        return (tongTinChi >= 170 && SinhVien::diemTrungBinh >= 5 && diemLuanVan >= 5);
    }

    void xuat() override {
        cout << "-- Sinh vien Dai hoc --" << endl;
        SinhVien::xuat();
        cout << "Ten luan van: " << tenLuanVan << endl;
        cout << "Diem luan van: " << diemLuanVan << endl;
    }
};

class DanhSachSinhVien {
private:
    vector<SinhVien*> danhSach;

public:
    void nhapDanhSach() {
        int n;
        cout << "Nhap so luong sinh vien: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            int choice;
            cout << "Chon loai sinh vien (1 - Cao dang, 2 - Dai hoc): ";
            cin >> choice;

            SinhVien* sinhVien;

            if (choice == 1) {
                sinhVien = new SinhVienCaoDang();
            }
            else if (choice == 2) {
                sinhVien = new SinhVienDaiHoc();
            }
            else {
                cout << "Loai sinh vien khong hop le!" << endl;
                i--;
                continue;
            }

            sinhVien->nhap();
            danhSach.push_back(sinhVien);
        }
    }

    void xetTotNghiep() {
        int count = 0;

        for (SinhVien* sinhVien : danhSach) {
            if (sinhVien->kiemTraTotNghiep()) {
                count++;
            }
        }

        cout << "So luong sinh vien du dieu kien tot nghiep: " << count << endl;
    }

    void timSVCoDiemTBMax() {
        float maxDiem = 0;
        SinhVien* svTBMax = nullptr;

        for (SinhVien* sinhVien : danhSach) {
            if (sinhVien->getDiemTrungBinh() > maxDiem) {
                maxDiem = sinhVien->getDiemTrungBinh();
                svTBMax = sinhVien;
            }
        }

        cout << "-- Sinh vien co diem trung binh cao nhat --" << endl;
        if (svTBMax != nullptr) {
            svTBMax->xuat();
        }
        else {
            cout << "Khong co sinh vien nao!" << endl;
        }
    }

    void timSVCaoDangCoDiemTBMax() {
        float maxDiem = 0;
        SinhVienCaoDang* svTBMax = nullptr;

        for (SinhVien* sinhVien : danhSach) {
            SinhVienCaoDang* svCaoDang = dynamic_cast<SinhVienCaoDang*>(sinhVien);
            if (svCaoDang != nullptr && svCaoDang->getDiemTrungBinh() > maxDiem) {
                maxDiem = svCaoDang->getDiemTrungBinh();
                svTBMax = svCaoDang;
            }
        }

        cout << "-- Sinh vien cao dang co diem trung binh cao nhat --" << endl;
        if (svTBMax != nullptr) {
            svTBMax->xuat();
        }
        else {
            cout << "Khong co sinh vien cao dang nao!" << endl;
        }
    }
};

int main() {
    DanhSachSinhVien dsSinhVien;
    dsSinhVien.nhapDanhSach();

    dsSinhVien.xetTotNghiep();
    dsSinhVien.timSVCoDiemTBMax();
    dsSinhVien.timSVCaoDangCoDiemTBMax();

    return 0;
}