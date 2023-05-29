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
    Alpha(string macpu)
        : CPU(macpu, "Alpha", "Black", 2, 1.8, 200) {}
};

class Beta : public CPU {
public:
    Beta(string macpu)
        : CPU(macpu, "Beta", "Black", 4, 2.46, 400) {}
};

class Gamma : public CPU {
public:
    Gamma(string macpu)
        : CPU(macpu, "Gamma", "White", 4, 2.6, 600) {}
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
    HD(string maManHinh, string hangSX)
        : ManHinh(maManHinh, hangSX, "HD", 200) {}
};

class FullHD : public ManHinh {
protected:
    bool chongLoa;

public:
    FullHD(bool chongLoa , string maManHinh, string hangSX)
        : ManHinh(maManHinh, hangSX, "FullHD", chongLoa ? 500 : 300), chongLoa(chongLoa) {}

    void display() {
        ManHinh::display();
        cout  << (chongLoa ? "Co" : "Khong") << endl;
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
    Vo(string ma, string loai, string hang, string mauSac, double giaNhap)
        : ma(ma), loai(loai), hang(hang), mauSac(mauSac), giaNhap(giaNhap) {}

    virtual void display() {
        cout << "Vo smartphone: " << ma << " " << loai << " " << hang << " "  << mauSac<<" "<< giaNhap << endl;
    }

    double getGiaNhap() {
        return giaNhap;
    }
};

class VoNhom : public Vo {
public:
    VoNhom(string maVo, string mauVo)
        : Vo(maVo, "Nhom", "Black", mauVo, 400) {}
};

class VoNhua : public Vo {
public:
    VoNhua(string maVo, string mauVo)
        : Vo(maVo, "Nhua", "White", mauVo, 200) {}
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
    
    cin >> n;

    Smartphone** smartphones = new Smartphone*[n];

    for (int i = 0; i < n; i++) {
        int dong;
       
        cin >> dong;

        string ma, maCPU, hangManHinh, doPhanGiai, loaiVo, maVo, mauSac, maManHinh;
        int loaiCPU, soCore;
        double xungNhip;


        cin >> ma;
        cin >> loaiCPU;
        cin >> maCPU;
        cin >> maManHinh;
        cin >> hangManHinh;
        cin >> doPhanGiai;
        cin >> loaiVo;
        cin >> maVo;
        cin >> mauSac;

        CPU* cpu;
        if (loaiCPU == 1)
            cpu = new Alpha(maCPU);
        else if (loaiCPU == 2)
            cpu = new Beta(maCPU);
        else if (loaiCPU == 3)
            cpu = new Gamma(maCPU);

        ManHinh* manHinh;
        if (doPhanGiai == "1")
            manHinh = new HD(maManHinh, hangManHinh);
        else if (doPhanGiai == "2") {
            bool chongLoa;
            cin >> chongLoa;
            manHinh = new FullHD(chongLoa, maManHinh, hangManHinh);
        }

        Vo* vo;
        if (loaiVo == "1"){
            if (mauSac == "1")
                mauSac = "Do";
            else if (mauSac == "2")
                mauSac = "Den";
            else if (mauSac == "3")
                mauSac = "Xanh";
            vo = new VoNhom(maVo, mauSac);
        }
        
            
        else if (loaiVo == "2") {
            if (mauSac == "1")
                mauSac = "Do";
            else if (mauSac == "2")
                mauSac = "Den";
            else if (mauSac == "3")
                mauSac = "Xanh";

            vo = new VoNhua(maVo, mauSac);
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
