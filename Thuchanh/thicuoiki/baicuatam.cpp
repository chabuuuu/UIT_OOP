#include<iostream>
#include<vector>
using namespace std;


class Ve{
protected:
    int giaVe;
    int loaiVe;
public:
    virtual void nhap(int loaiVe){
        this->loaiVe = loaiVe;
    }

    int getLoaiVe(){
        return loaiVe;
    }

    int getGiaVe(){
        return giaVe;
    }

    virtual int getSoDichVuThem(){
        return 0;
    }
    void xuat(){
        cout<<"Loai ve: "<<loaiVe<<endl;
        cout<<"Gia ve: "<<giaVe<<endl;
    }


};

class VeVip :public Ve{
public:
    void nhap(int loaiVe){
        Ve::nhap(loaiVe);
        this->giaVe = 4000000;
    }
};

class VeThuong : public Ve{
private:
    int giaDinhVuThem;
    int soDichVuThem;
public:
    VeThuong(){
        this->giaDinhVuThem = 0;
        this->soDichVuThem = 0;
    }
    void nhap(int loaiVe){
        Ve::nhap(loaiVe);
        cout<<"Nhap so dinh vu chon them"<<endl;
        cin>>soDichVuThem;
        this->giaDinhVuThem = soDichVuThem*600000;
        this->giaVe = 1800000 + this->giaDinhVuThem;
    }
    int getSoDichVuThem(){
        return soDichVuThem;
    }
};

class VeTap : public Ve{
private:
    int soGioTap;
public:
    VeTap(){
        this->soGioTap = 1;
    }
    void nhap(int loaiVe){
        Ve::nhap(loaiVe);
        cout<<"Nhap so gio tap"<<endl;
        cin>>soGioTap;
        this->giaVe = this->soGioTap*1700000;
    }
};

class QuanLy{
private:
    vector<Ve*> danhSachVeDaBan;
    int soVeDaBan;
    int tongTienVeNguoiMoiTapChoi;
public:
    void nhapVe(){
        int loaiVe;
        cout<<"Nhap so luong ve da ban"<<endl;
        cin>>soVeDaBan;
        for (int i = 0; i< soVeDaBan; i++){
            cout<<"Nhap loai ve: 1: Ve Vip -  2: Ve Thuong  - 3: Ve Tap "<<endl;
            Ve* ve;
            cin>>loaiVe;
            switch (loaiVe)
            {
            case 1:
                ve = new VeVip;
                break;
            case 2:
                ve = new VeThuong;
                break;
            case 3:
                ve = new VeTap;
                break;
            default:
                break;
            }
            ve->nhap(loaiVe);
            danhSachVeDaBan.push_back(ve);
        }
        
    }

    void tinhTongSoTienDaBanChoNguoiMoiTapChoi(){
        tongTienVeNguoiMoiTapChoi = 0;
        cout<<"Tong so tien da ban cho nguoi moi tap choi: "<<endl;
        for (int i = 0; i< soVeDaBan; i ++){
            if (danhSachVeDaBan[i]->getLoaiVe() == 3){
                tongTienVeNguoiMoiTapChoi += danhSachVeDaBan[i]->getGiaVe();
            }
        }
        cout<<tongTienVeNguoiMoiTapChoi<<endl;
    }

    void trungBinhDichVuChonthem(){
        int tongDichVuThem = 0;
        int soVeThuong = 0;
        for (int i= 0; i < soVeDaBan; i++){
            if (danhSachVeDaBan[i]->getLoaiVe() == 2){
                soVeThuong++;
                tongDichVuThem+= danhSachVeDaBan[i]->getSoDichVuThem();
            }
        }  
        cout<<"Trung binh moi ve thuong khach hang se chon them: "
        <<tongDichVuThem/soVeThuong<<" dich vu."<<endl; 
    }

    void timVeThuongDaBanCoMenhGiaCaoNhat(){
        int menhGiaMax = 0;
        Ve* veThuongMax;
           for (int i= 0; i < soVeDaBan; i++){
            if (danhSachVeDaBan[i]->getLoaiVe() == 2){
                if (danhSachVeDaBan[i]->getGiaVe() > menhGiaMax){
                    menhGiaMax = danhSachVeDaBan[i]->getGiaVe();
                    veThuongMax = danhSachVeDaBan[i];
                }
            }
        }  
        cout<<"Ve thuong co menh gia cao nhat: "<<endl;
        veThuongMax->xuat();
    }



};

int main(){
    QuanLy veDaBan;
    veDaBan.nhapVe();
    veDaBan.tinhTongSoTienDaBanChoNguoiMoiTapChoi();
    veDaBan.trungBinhDichVuChonthem();
    veDaBan.timVeThuongDaBanCoMenhGiaCaoNhat();
    return 0;
}