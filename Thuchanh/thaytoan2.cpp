#include <iostream>
#include <string>
using namespace std;

class CPU {
protected:
    string ma;
    string loai;
    string hang;
    int soCore;
    double xungNhip;
    double giaNhap;

public:
    CPU(string ma, string loai, string hang, int soCore, double xungNhip, double giaNhap)
        : ma(ma), loai(loai), hang(hang), soCore(soCore), xungNhip(xungNhip), giaNhap(giaNhap) {}

    virtual void display() {
        cout << "CPU: " << ma << " " << loai << " " << hang << " " << soCore << " " << xungNhip << " " << giaNhap << endl;
    }

    double getGiaNhap() {
        return giaNhap;
    }
};

class Alpha : public CPU {
public:
    Alpha()
        : CPU("CPU1", "Alpha", "Black", 2, 1.8, 200) {}
};

class Beta : public CPU {
public:
    Beta()
        : CPU("CPU2", "Beta", "Black", 4, 2.46, 400) {}
};

class Gamma : public CPU {
public:
    Gamma()
        : CPU("CPU3", "Gamma", "White", 4, 2.6, 600) {}
};

class ManHinh {
protected:
    string ma;
    string hang;
    string doPhanGiai;
    double giaNhap;

public:
    ManHinh(string ma, string hang, string doPhanGiai, double giaNhap)
        : ma(ma), hang(hang), doPhanGiai(doPhanGiai), giaNhap(giaNhap) {}

    virtual void display() {
        cout << "Man hinh: " << ma << " " << hang << " " << doPhanGiai << " " << giaNhap << endl;
    }

    double getGiaNhap() {
        return giaNhap;
    }
};

class HD : public ManHinh {
public:
    HD()
        : ManHinh("mh1", "ABC", "HD", 200) {}
};

class FullHD : public ManHinh {
protected:
    bool chongLoa;

public:
    FullHD(bool chongLoa = false)
        : ManHinh("mh2", "ABC", "FullHD", chongLoa ? 500 : 300), chongLoa(chongLoa) {}

    void display() {
        ManHinh::display();
        cout << "Chong loa: " << (chongLoa ? "Co" : "Khong") << endl;
    }
};

class Vo {
protected:
    string ma;
    string loai;
    string hang;
    double giaNhap;
    string mauSac;

public:
    Vo(string ma, string loai, string hang, double giaNhap, string mauSac)
        : ma(ma), loai(loai), hang(hang), giaNhap(giaNhap), mauSac(mauSac) {}

    virtual void display() {
        cout << "Vo smartphone: " << ma << " " << loai << " " << hang << " " << giaNhap << " " << mauSac << endl;
    }

    double getGiaNhap() {
        return giaNhap;
    }
};

class VoNhom : public Vo {
public:
    VoNhom()
        : Vo("v1", "Nhom", "Black", 400, "Do") {}
};

class VoNhua : public Vo {
public:
    VoNhua(string mauSac)
        : Vo("v2", "Nhua", "White", 200, mauSac) {}
};

class Smartphone {
protected:
    string ma;
    string dong;
    double giaBan;
    CPU* cpu;
    ManHinh* manHinh;
    Vo* vo;

public:
    Smartphone(string ma, string dong, CPU* cpu, ManHinh* manHinh, Vo* vo)
        : ma(ma), dong(dong), cpu(cpu), manHinh(manHinh), vo(vo) {
        giaBan = tinhGiaBan();
    }

    virtual void display() {
        cout << "Smartphone: " << ma << " " << dong << " " << giaBan << endl;
        cpu->display();
        manHinh->display();
        vo->display();
    }

    double tinhGiaBan() {
        double giaNhapCPU = cpu->getGiaNhap();
        double giaNhapManHinh = manHinh->getGiaNhap();
        double giaNhapVo = vo->getGiaNhap();
        double tongGiaNhap = giaNhapCPU + giaNhapManHinh + giaNhapVo;

        if (dong == "Venus")
            return tongGiaNhap * 1.3;
        else if (dong == "Mars")
            return tongGiaNhap * 1.5;
        else if (dong == "Jupiter")
            return tongGiaNhap * 1.8;
        
        return 0;
    }
};

int main() {
    int n;
    cout << "Nhap so luong smartphone: ";
    cin >> n;

    Smartphone** smartphones = new Smartphone*[n];

    for (int i = 0; i < n; i++) {
        int dong;
        cout << "Nhap thong tin smartphone thu " << i + 1 << endl;
        cout << "Dong smartphone (1 - dong Venus, 2 - dong Mars, 3 - dong Jupiter): ";
        cin >> dong;

        string ma, maCPU, hangCPU, doPhanGiai, loaiVo, maVo, mauSac;
        int loaiCPU, soCore;
        double xungNhip;

        cout << "Nhap ma so: ";
        cin >> ma;
        cout << "Loai CPU (1 - loai Alpha, 2 - loai Beta, 3 - loai Gamma): ";
        cin >> loaiCPU;
        cout << "Nhap ma CPU: ";
        cin >> maCPU;
        cout << "Man hinh:" << endl;
        cout << "Nhap ma man hinh: ";
        cin >> doPhanGiai;
        cout << "Hang san xuat: ";
        cin >> hangCPU;
        cout << "Do phan giai (1 - HD, 2 - FullHD): ";
        cin >> doPhanGiai;
        cout << "Loai vo smartphone (1 - loai nhom, 2 - loai nhua): ";
        cin >> loaiVo;
        cout << "Nhap ma vo: ";
        cin >> maVo;
        cout << "Mau vo (1 - do, 2 - den, 3 - xanh): ";
        cin >> mauSac;

        CPU* cpu;
        if (loaiCPU == 1)
            cpu = new Alpha();
        else if (loaiCPU == 2)
            cpu = new Beta();
        else if (loaiCPU == 3)
            cpu = new Gamma();

        ManHinh* manHinh;
        if (doPhanGiai == "1")
            manHinh = new HD();
        else if (doPhanGiai == "2") {
            bool chongLoa;
            cout << "FullHD co chong loa hay khong (1 - co, 0 - khong): ";
            cin >> chongLoa;
            manHinh = new FullHD(chongLoa);
        }

        Vo* vo;
        if (loaiVo == "1")
            vo = new VoNhom();
        else if (loaiVo == "2") {
            if (mauSac == "1")
                mauSac = "Do";
            else if (mauSac == "2")
                mauSac = "Den";
            else if (mauSac == "3")
                mauSac = "Xanh";

            vo = new VoNhua(mauSac);
        }

        Smartphone* smartphone;
        if (dong == 1)
            smartphone = new Smartphone(ma, "Venus", cpu, manHinh, vo);
        else if (dong == 2)
            smartphone = new Smartphone(ma, "Mars", cpu, manHinh, vo);
        else if (dong == 3)
            smartphone = new Smartphone(ma, "Jupiter", cpu, manHinh, vo);

        smartphones[i] = smartphone;
    }

    cout << endl << "Danh sach " << n << " smartphone:" << endl;
    for (int i = 0; i < n; i++) {
        smartphones[i]->display();
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete smartphones[i];
    }
    delete[] smartphones;

    return 0;
}
