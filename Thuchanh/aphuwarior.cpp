#include <vector>
#include <iostream>

using namespace std;

class Vukhi {
public:
    float SatThuong;

    int LuotSuDung;

    Vukhi() {
        SatThuong = 0;
        LuotSuDung = 0;
    }

    virtual void Nhap() {
        cin >> SatThuong;
        cin >> LuotSuDung;
    }


        virtual bool HetLuot() = 0;
        virtual float Damage() = 0;



};

class Dao : public Vukhi {
public:
    float ChieuDai;

    Dao() {

        
        ChieuDai = 0;
    }

    void Nhap() {
        Vukhi::Nhap();
        cin >> ChieuDai;
    }

    float Damage() {
        LuotSuDung--;
        return SatThuong * ChieuDai;
    }

    bool HetLuot() {
        return LuotSuDung <= 0;
    }
};

class Cung : public Vukhi {
public:
    int slMuiTen;

    Cung() {
        slMuiTen = 0;
    }

    void Nhap() {
        Vukhi::Nhap();
        cin >> slMuiTen;
    }

    float Damage() {
        LuotSuDung = LuotSuDung - 2;
        return SatThuong * slMuiTen / 2;
    }

    bool HetLuot() {
        return LuotSuDung <= 0;
    }
};

class TayKhong : public Vukhi {
public:
    void Nhap() {}

    float Damage() {
        return SatThuong;
    }

    bool HetLuot() {
        return false;
    }
};

class APhu {
public:
    float HP;
    int n;
    vector<Vukhi*> vukhi;

    APhu() {
        n = 0;
        HP = 0;
    }

    void Nhap() {
        cin >> HP;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            Vukhi* temp;

            switch (x) {
            case 1:
                temp = new Dao;
                break;
            case 2:
                temp = new Cung;
                break;
            default:
                temp = NULL;
                break;
            }

            if (temp != NULL) {
                temp->Nhap();
                vukhi.push_back(temp);
            }
        }
    }

    bool Die() {
        return HP <= 0;
    }
};

class ThuDu {
public:
    float SatThuong;
    float HP;

    ThuDu() {
        SatThuong = HP = 0;
    }

    virtual void Nhap() {
        cin >> HP;
        cin >> SatThuong;
    }

    virtual float Damage() = 0;
    virtual bool Die() = 0;
};

class Ho : public ThuDu {
public:
    void Nhap() {
        ThuDu::Nhap();
    }

    float Damage() {
        return SatThuong * 15 / 10;
    }

    bool Die() {
        return HP <= 0;
    }
};

class BoTot : public ThuDu {
public:
    int SoLuotChiuDanh;

    BoTot() {
        SoLuotChiuDanh = 1;
    }

    void Nhap() {
        ThuDu::Nhap();
        cin >> SoLuotChiuDanh;
    }

    float Damage() {
        return SatThuong;
    }

    bool Die() {
        SoLuotChiuDanh--;
        return HP <= 0 || 
        SoLuotChiuDanh <= 0;
    }
};


class TranChien {
protected:
    APhu A;
    int m;
    vector<ThuDu*> danhsach;

public:
    TranChien() {
        m = 0;
    }

    void Nhap() {
        A.Nhap();
        cin >> m;

        for (int i = 0; i < m; i++) {
            ThuDu* temp;
            int x;
            cin >> x;

            switch (x) {
            case 1:
                temp = new BoTot();
                break;
            case 2:
                temp = new Ho();
                break;
            default:
                temp = NULL;
                break;
            }

            if (temp != NULL) {
                temp->Nhap();
                danhsach.push_back(temp);
            }
        }
    }

    void Xuat() {
        if (!A.Die()) {
            cout << "A Phu chien thang, hp con lai: " << A.HP << ", so vu khi con lai: " << A.n;
        }
        else {
            cout << "A Phu that bai, so thu du con lai: " << m;
        }
    }

    int KiemTra() {
        if (m == 1) {
            Xuat();
            return 1;
        }
        return 0;
    }

    void Chien() {
        float HPGoc = A.HP;

        while (!A.Die() && !danhsach.empty()) {
            if (!A.vukhi.empty()) {
                danhsach[0]->HP -= A.vukhi[0]->Damage();

                if (A.vukhi[0]->HetLuot()) {
                    A.vukhi.erase(A.vukhi.begin());
                    A.n--;
                }
            }

            if (A.vukhi.empty()) {
                danhsach[0]->HP -= HPGoc * 1 / 10;
                A.HP -= HPGoc * 1 / 10;

                if (A.Die()) {
                    Xuat();
                    return;
                }
            }

            if (!danhsach[0]->Die()) {
                A.HP -= danhsach[0]->Damage();
            }
            else {
                danhsach.erase(danhsach.begin());
                m--;

                if (danhsach.empty()) {
                    Xuat();
                    return;
                }
            }

            if (A.Die()) {
                Xuat();
                return;
            }
        }

        Xuat();
    }
};

int main() {
    TranChien T;

    T.Nhap();

    if (T.KiemTra() == 1) {
        return 0;
    }

    T.Chien();
    return 0;
}
