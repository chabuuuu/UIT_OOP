#include <iostream>
#include <vector>

using namespace std;

class Sung {


protected:
    string tenSung;
    int dan, kichThuocDan;

    float satThuongCoBan, tocDoBan, thoiGianNapDan;

public:


    Sung(string ten, 
    int soDan, 
    int kichThuoc, 

    float satThuong, 
    float tocDo) {

        kichThuocDan = kichThuoc;
        
        satThuongCoBan = satThuong;
        
        tocDoBan = tocDo;
        tenSung = ten;
        
        thoiGianNapDan = 2.0;
        dan = soDan;
    }
    
    virtual int getKichThuoc() {

        return kichThuocDan;
    }
    
    virtual int getDan() {
        return dan;
    }
    
    virtual float getSatThuong(float doHaoMon) {
        return doHaoMon * satThuongCoBan;
    }

    virtual float getTocDoBan(float doHaoMon) {
        if (doHaoMon > 0 && doHaoMon < 1) {
            return tocDoBan / 2; 
        }
            
        return tocDoBan; 
    }

    virtual float getThoiGianNapDan() {
        return thoiGianNapDan;
    }

    virtual float getTongSatThuong(float doHaoMon, double dan) {

        if (dan > int(dan)) { 
            
            dan = int(dan) + 1; 
            }
        else 
        { 
            dan = dan; 
        }
        int temp;


        int tongDan = getKichThuoc() * getDan();

        temp = ((dan - (2 * getTocDoBan(doHaoMon))) / getDan());
        dan = dan - (getThoiGianNapDan() * temp * getTocDoBan(doHaoMon));
        if (dan > tongDan) 
        { 
            dan = tongDan; 
        }
        else { 
            dan = dan; 
        }

        return dan * getSatThuong(doHaoMon) ;
    }

    virtual string getTenSung() {
        return tenSung;
    }
    virtual ~Sung() {}
};

class SungNgan : public Sung {
public:
    SungNgan(string ten, 
    int dan, 
    int kichThuoc, 
    float satThuong, 
    float tocDo) : Sung(ten, dan, kichThuoc, satThuong, tocDo) {}
};

class SungTruong : public Sung {
    float satThuongSkin;

public:
    SungTruong(string ten, 
    int dan, 
    int kichThuoc, 
    float satThuong, 
    float tocDo, 
    float skin) : Sung(ten, dan, kichThuoc, satThuong, tocDo) {
        satThuongSkin = skin;
    }

    float getSatThuong(float doHaoMon) {
        return (doHaoMon * satThuongCoBan) + satThuongSkin;
    }
};

class SungBanTia : public Sung {
public:
    SungBanTia(string ten, int dan, int kichThuoc, float satThuong, float tocDo) : Sung(ten, dan, kichThuoc, satThuong, tocDo) {}

    float getTocDoBan(float doHaoMon) {
        if (doHaoMon > 0 && doHaoMon < 1)
            return (1 / ((1 / (tocDoBan / 2)) + 1));
        return (1 / ((1 / tocDoBan) + 1));
    }
};

int main() {
    int soSung;
    cin >> soSung;
    int loai, kichThuoc;
    float doHaoMon, satThuongPhu;
    vector<Sung*> sung;
    vector<float> listHaoMon; 
    for (int i = 0; i < soSung; i++) {
        cin >> loai >> kichThuoc >> doHaoMon;
        listHaoMon.push_back(doHaoMon); 

        Sung* sungTmp;
        switch (loai) {
            case 1:
                sungTmp = new SungNgan("G18", 12, kichThuoc, 2.0, 1.0);
                break;
            case 2:
                sungTmp = new SungNgan("M500", 5, kichThuoc, 4.0, 0.5);
                break;
            case 3:
                cin >> satThuongPhu;
                sungTmp = new SungTruong("MP40", 20, kichThuoc, 3.0, 5.0, satThuongPhu);
                break;
            case 4:
                cin >> satThuongPhu;
                sungTmp = new SungTruong("AK", 30, kichThuoc, 5.0, 1.0, satThuongPhu);
                break;
            case 5:
                sungTmp = new SungBanTia("SVD", 10, kichThuoc, 5.0, 0.5);
                break;
            case 6:
                sungTmp = new SungBanTia("AWM", 5, kichThuoc, 10.0, 0.5);
                break;    
            default:
                delete sungTmp;
                continue;
        }

        sung.push_back(sungTmp);
    }
    
    float tongThoiGian;

    cin >> tongThoiGian;

    for (int i = 0; i < sung.size(); i++) {
        Sung* sungTmp = sung[i];
        float doHaoMon = listHaoMon[i];  
        float satThuong = 
        sungTmp->getTongSatThuong(doHaoMon, 
        tongThoiGian * sungTmp->getTocDoBan(doHaoMon));

        
        cout << sungTmp->getTenSung() << ": " << satThuong << endl;

        delete sungTmp;
    }

    return 0;
}
