#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
using namespace std;

class NguonDien{
protected:
    float hieuSuat;
    float dienTaoRa;
    static float tongDien;
    static bool coKhaNangTichDien;
    static bool mangDienBiRa;
public:
    virtual void nhap(){
        cin>>hieuSuat;
    }
    virtual void tinhDienTaoRa(float tocDoGio , float gioHienTai , bool may ){
        return ;
    }
    void resetTongDienTaoRa(){
        tongDien = 0;
    }
    float getTongDien(){
        return tongDien;
    }
    bool getCoKhaNangTichDiem(){
        return coKhaNangTichDien;
    }
    void setDienBiRa(){
        dienTaoRa = true;
    }

};

class ThuyDien: public NguonDien{
private:
    int soToMay;
    bool tichNang;
public:
    void nhap(){
        NguonDien::nhap();
        cin>>soToMay>>tichNang;
        dienTaoRa = hieuSuat*soToMay;

        if (tichNang == true){
            coKhaNangTichDien = true;
        }
        //
        
    }

    void tinhDienTaoRa(float tocDoGio , float gioHienTai , bool may ){
        tongDien = tongDien + dienTaoRa;
        // cout<<"thuy dien: "<<dienTaoRa<<endl;
    }



};

class NhietDien: public NguonDien{
private:
    int soThan;
public:
    void nhap(){
        NguonDien::nhap();
        cin>>soThan;
        dienTaoRa = hieuSuat*soThan;
        //
    }

        void tinhDienTaoRa(float tocDoGio , float gioHienTai , bool may ){
        tongDien = tongDien + dienTaoRa;
        // cout<<"nhiet dien: "<<dienTaoRa<<endl;
    }
};

class DienGio : public NguonDien{
private:
    int soTuaBin;
    float tocDoGioToiDa;
public:
    void nhap(){
        NguonDien::nhap();
        cin>>soTuaBin>>tocDoGioToiDa;
        hieuSuat = soTuaBin*hieuSuat;
    }
    void tinhDienTaoRa(float tocDoGioHienTai , float gioHienTai , bool may ){
        if (mangDienBiRa != true){
        dienTaoRa = hieuSuat*tocDoGioHienTai/tocDoGioToiDa;
        // cout<<hieuSuat<<" "<<tocDoGioHienTai<<" "<<tocDoGioToiDa<<endl;
        tongDien = tongDien +  round(dienTaoRa);
        // cout<<"diengio: "<<dienTaoRa<<endl;
        }
    
    }

};

class DienMatTroi : public NguonDien{
private:
    float dienTichPin;
public:
    void nhap(){
        NguonDien::nhap();
        cin>>dienTichPin;

    }

    void tinhDienTaoRa(float tocDoGio , float gio , bool may ){
        if (mangDienBiRa != true){

               float dienThucTe;
        float dienLyThuyet = hieuSuat * dienTichPin;
        if (may == true){
            dienThucTe = 0;
             tongDien = tongDien + dienThucTe;
             return;

        }
        if (18 <= gio && gio <= 24 || gio >= 0 && gio <= 6){
            dienThucTe = 0;
        }
        if (11 <= gio && gio <= 13){
            dienThucTe = dienLyThuyet;
        }
        if (13 >= gio && gio <= 18){
            float giam = (gio - 13)*20/100;
            dienThucTe = dienLyThuyet - dienLyThuyet*giam;
        }
        if (6 <= gio && gio <= 11){
            float tang = (gio - 6)*20/100;
            dienThucTe = dienLyThuyet*tang;
        }

        tongDien = tongDien + dienThucTe;
        // cout<<"dien mat troi: "<<dienThucTe<<endl;
        }
     
    }

};

class SoGio{

    public:
    int gio;
    float tocDoGio;
    bool may;
    float tongCongSuatTieuThu;
    SoGio(){
        gio = 0;
        tocDoGio = 0;
        may = false;
        tongCongSuatTieuThu = 0;
    }   
    void nhap(){
        cin>>gio>>tocDoGio>>may>>tongCongSuatTieuThu;
    }
        
};

class MangDien{
private:
    vector<NguonDien*> listNguonDien;
    int soNguonDien;
    int soGio;
    int gio;
    float tocDoGio;
    bool may;
    float tongCongSuatTieuThu;
    float tongThu;
    float dienTichTru;
    vector<SoGio> listSoGio;
public:

    void nhapThongTin(){
            NguonDien* nguonDien;
            int loaiNguonDien;
            cin>>soNguonDien;
            for (int i = 0; i<soNguonDien; i++){
                cin>>loaiNguonDien;
                switch (loaiNguonDien)
                {
                case 1:
                    nguonDien = new ThuyDien;
                    break;
                case 2:
                    nguonDien = new NhietDien;
                    break;
                case 3:
                    nguonDien = new DienGio;
                    break;
                case 4:
                    nguonDien = new DienMatTroi;
                    break;
                default:
                    break;
                }   

                nguonDien->nhap();
                listNguonDien.push_back(nguonDien);
            }

            cin>>soGio;
            //tinhTongThu
           
            for (int i = 0; i <soGio; i++){
                SoGio sogio;
                sogio.nhap();
                listSoGio.push_back(sogio);
            }
            // cout<<setprecision(1000)<<tongThu;
    }

    float tinhTien(){
         tongThu = 0;
            float tongDien;
            float tongDienCu = 0;
            bool coTheHoatDong[100] = {true};
            for (int i = 0; i <soGio; i++){
                tongCongSuatTieuThu = listSoGio[i].tongCongSuatTieuThu;
                listNguonDien[0]->resetTongDienTaoRa();
                for (int k = 0 ; k < listNguonDien.size(); k++){
                    listNguonDien[k]->tinhDienTaoRa(listSoGio[i].tocDoGio, listSoGio[i].gio, listSoGio[i].may);
                }
                tongDien = listNguonDien[0]->getTongDien() + dienTichTru;
                // cout<<tongDien<<endl;
                if (tongDien > tongCongSuatTieuThu){
                    // cout<<"yes"<<tongCongSuatTieuThu<<endl;
                    tongThu+= (tongCongSuatTieuThu)*1000*3000;
                    dienTichTru = tongDien - tongCongSuatTieuThu;
                }
                if (tongDien < (tongCongSuatTieuThu*50/100) ){
                    // cout<<"yes"<<endl;
                    tongThu+=tongDien*1000*2000;
                }else{
                      if (tongDien < tongCongSuatTieuThu*80/100){
                    tongThu+=tongDien*1000*2500;
                }
                }
              
         


            }
            return tongThu;
    }
    
};

float NguonDien::tongDien = 0;
bool NguonDien::coKhaNangTichDien = false;
bool NguonDien::mangDienBiRa = false;


int main(){
    MangDien a;
    a.nhapThongTin();
    cout<<setprecision(1000)<<a.tinhTien();
}