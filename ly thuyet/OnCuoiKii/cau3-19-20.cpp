#include<iostream>
#include<vector>


using namespace std;

class Nguoi{
private:
string hoTen;
string CMND;
string diaChi;
int namSinh;
public:
void nhap(){
cin>>hoTen>>CMND>>diaChi>>namSinh;
}
void xuat(){
cout<<hoTen<<CMND<<diaChi<<namSinh;
}


};



class GiayChungNhan{
protected:
int soGiay;
Nguoi nguoiSoHuu;
int soThuaDat;
int soBanDo;
string diaChi;
float dienTich;
string ngayCap;
float donGia;
int loai;


public:
virtual void nhap(){
cin>>soGiay;
nguoiSoHuu.nhap();
cin>>soThuaDat>>soBanDo>>diaChi>>dienTich>>ngayCap>>donGia;
}
virtual void xuat(){
cout<<soGiay;
nguoiSoHuu.xuat();
cout<<soThuaDat<<soBanDo<<diaChi<<dienTich<<ngayCap<<donGia;
}
virtual bool DaHetHan(int namHienTai){return false;}
float TinhTien(){
return donGia*dienTich;
} 
int getLoai(){
return loai;
}


};
class DatNongNghiep : public GiayChungNhan{
private:
int thoiHan;
public:
void nhap(){
GiayChungNhan::nhap();
cin>>thoiHan;
}

void xuat(){
GiayChungNhan::xuat();
cout<<thoiHan<<endl;
}

bool DaHetHan(int namHienTai){
if (namHienTai <= thoiHan){
return false;
}
return true;
}
DatNongNghiep(){this->loai = 1;}
};


class DatPhiNongNghiep : public GiayChungNhan{
private:


public:
void nhap(){
GiayChungNhan::nhap();
}

void xuat(){
GiayChungNhan::xuat();
cout<<endl;
}

DatPhiNongNghiep(){this->loai = 2;}

};


class QuanLy{
private:
vector<GiayChungNhan*> listSoHong;
int soLuong;


public:
void nhapSoHong(){
cout<<"Nhap so luong:"<<endl;
cin>>soLuong;
for (int i = 0 ; i < soLuong;i ++){
GiayChungNhan* soHong;
int loai;
cout<<"Nhap loai dat: (1 - Dat Nong Nghiep, 2 - Dat Phi Nong Nghiep)"<<endl;
cin>>loai;
switch(loai){
	case 1:
	soHong = new DatNongNghiep;
	break;
	case 2:
	soHong = new DatPhiNongNghiep;
	break;
	default:
	break;
}
cout<<"Nhap lan luot So giay chung nhan, thong tin nguoi so huu (hoten, nam sinh, cmnd, dia chi), so thua dat, so to ban do, dia chi thua dat, dien tich, ngay cap, don gia thue, thoi han su dung (neu co)"<<endl;
soHong->nhap();



listSoHong.push_back(soHong);

}
}


void TinhTienThue(){
GiayChungNhan* maxThue;
float tienThueMax = 0;
for (int i = 0; i< soLuong; i++){
if (listSoHong[i]->TinhTien() > tienThueMax){
	tienThueMax = listSoHong[i]->TinhTien();
	maxThue = listSoHong[i];
}
cout<<"Thong tin Thua Dat co tien Thue phai dong nhieu nhat: "<<endl;
maxThue->xuat();

}
}

void xuatThuaDatHetHan(){
    int namHienTai;
    cout<<"Nhap Nam Hien Tai"<<endl;
    cin>>namHienTai;
for (int i = 0 ; i < soLuong; i ++){
if (listSoHong[i]->getLoai() == 1){
if (listSoHong[i]->DaHetHan(namHienTai) == true){
listSoHong[i]->xuat();
}
}
}
}


};


int main()
{
QuanLy soHong;
soHong.nhapSoHong();
soHong.TinhTienThue();
soHong.xuatThuaDatHetHan();
return 0;
}





