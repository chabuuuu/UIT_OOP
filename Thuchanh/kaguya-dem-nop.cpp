#include <iostream>
#include<vector>
using namespace std;
//cac bien tinh
static float thoi_gian_cho_nguoi_yeu = 0;
static float thoi_gian_cho_ban_nam_khac = 0;



static float thoi_gian_cho_ban_tan = 0;
static int _tong_so_ban = 0;

class Ban {

protected:

    float thoi_gian_da_tieu;
        string thong_tin_khac;
        string ten;
        int tuoi;
    
public:
    Ban() {
        tuoi = 0;
        ten = "";
        
    }
    float getThoiGianDaTieu() {
        return thoi_gian_da_tieu;
    }
    int getTuoi() {
        return tuoi;
    }

    string getTen() {
        return ten;
    }


    //
    virtual void thongTinKhac() = 0;
    virtual void nhap() {
        cin >> ten >> tuoi;
    }
    

    virtual void tinhThoiGianDaTieu() = 0;

    
};

class NguoiYeu : public Ban {
protected:

    int thu_nhap;
public:
    NguoiYeu() {
        thu_nhap = 0;
    }

    void nhap() {
        Ban::nhap();
        cin >> thu_nhap;
    }
    void tinhThoiGianDaTieu() {
        thoi_gian_da_tieu = 5 * thu_nhap / 10000000.0;
        thoi_gian_cho_nguoi_yeu += thoi_gian_da_tieu;
    }
    void thongTinKhac() {
        cout << ", thu nhập: " << thu_nhap << "đ";
    }

    
};

class BanThan : public Ban {
protected:
    //sodienthoai
    string so_dien_thoai;
public:
    BanThan() {
        so_dien_thoai = "";
    }

    //tinh thoi gian
    void tinhThoiGianDaTieu() {
        thoi_gian_da_tieu = 5;
        thoi_gian_cho_ban_tan += thoi_gian_da_tieu;
    }
    void nhap() {
        Ban::nhap();
        cin >> so_dien_thoai;
    }

    void thongTinKhac() {
        cout << ", so dien thoai: " << so_dien_thoai;
    }

    
};


class BanNamKhac : public Ban {
protected:
    string muc_do;
    float do_thu_hut;
    
public:
    BanNamKhac() {
        do_thu_hut = 0;
    }

    void nhap() {
        Ban::nhap();
        do {
            cin >> do_thu_hut;
        } while (do_thu_hut < 0 && do_thu_hut > 1);
    }

    void thongTinKhac() {
        if (do_thu_hut >= 0.7){
            cout << ", do thu hut: cao";
        }
            
        if (do_thu_hut >= 0.4 && do_thu_hut < 0.7){
            cout << ", do thu hut: trung binh";
        }
            
        if (do_thu_hut < 0.4){
 cout << ", do thu hut: thap";
        }
           
    }

    void tinhThoiGianDaTieu() {
        thoi_gian_da_tieu = do_thu_hut * 20.0 / _tong_so_ban;

        //thoi gian
        thoi_gian_cho_ban_nam_khac += thoi_gian_da_tieu;
    }
};

class Kaguya {
protected:
    Ban** danh_sach_ban;

    int tong_so_ban;
public:

    void nhap() {

        cin >> tong_so_ban;

        danh_sach_ban = new Ban*[tong_so_ban];

        int lua_chon;
        for (int i = 0; i < tong_so_ban; i++) {
            cin >> lua_chon;
            switch (lua_chon) {
                case 1:
                    danh_sach_ban[i] = new BanThan();
                    break;
                case 2:
                    danh_sach_ban[i] = new NguoiYeu();
                    break;
                case 3:
                    danh_sach_ban[i] = new BanNamKhac();
                    break;
            }

            danh_sach_ban[i]->nhap();
            _tong_so_ban++;
        }
    }   
    void xuat() {
        cout << "Thong ke:" << "\n";
        if (thoi_gian_cho_ban_tan > 0){
            cout << "- Thoi gian cho ban than: " << thoi_gian_cho_ban_tan << " h" << "\n";
        }
            
       
           
        if (thoi_gian_cho_ban_nam_khac > 0){
            cout << "- Thoi gian cho ban trai khac: " << thoi_gian_cho_ban_nam_khac << " h" << "\n";
        }



         if (thoi_gian_cho_nguoi_yeu > 0){
             cout << "- Thoi gian cho ban trai: " << thoi_gian_cho_nguoi_yeu << " h" << "\n";
        }
            
        cout << "Nguoi ban quan trong nhat:" << "\n";
    }

    void tinhThoiGianDaTieu() {
        for (int i = 0; 
        i < tong_so_ban; 
        i++)
            danh_sach_ban[i]->tinhThoiGianDaTieu();
    }

     void nguoiDaTieuThoiGianNhieuNhat() {
        for (int i = 0; i < tong_so_ban; i++) {
            if (danh_sach_ban[i]->getThoiGianDaTieu() == thoiGianDaTieuNhieuNhat()) {
                cout << "Ten: " << danh_sach_ban[i]->getTen() << ", tuoi: " << danh_sach_ban[i]->getTuoi();
                danh_sach_ban[i]->thongTinKhac();
                cout << "\n";
            }
        }
    }

    float thoiGianDaTieuNhieuNhat() {
        int vi_tri = 0;

        float thoi_gian = danh_sach_ban[0]->getThoiGianDaTieu();
        for (int i = 0; i < tong_so_ban; i++) {

            if (danh_sach_ban[i]->getThoiGianDaTieu() 
            > thoi_gian) {
                thoi_gian = danh_sach_ban[i]->getThoiGianDaTieu();
                
                vi_tri = i;
            }
        }
        return thoi_gian;
    }

   
};

int main() {
    Kaguya a;
    //nhap danh sach ban be
    a.nhap();


    a.tinhThoiGianDaTieu();
    //thong ke
    a.xuat();
    
    a.nguoiDaTieuThoiGianNhieuNhat();
    return 0;
}
