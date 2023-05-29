#include <iostream>
using namespace std;

class Animal {
protected:
    int quantity;
    int milk;
    int tong;

public:
    Animal() {
        quantity = 0;
        milk = 0;
    }

    void setQuantity(int q) {
        quantity = q;
    }
    void setTong(int t) {
        tong = tong + t;
    }
     void setTongLucDau() {
        tong = quantity;
    }
    int getTong(){
        return tong;
    }

    int getQuantity() {
        return quantity;
    }

    int getMilk() {
        return milk;
    }

    virtual void produceMilk() = 0;
};

class Cow : public Animal {
public:
    void produceMilk() {
        milk += quantity * 10;
    }
};

class Sheep : public Animal {
public:
    void produceMilk() {
        milk += quantity * 5;
    }
};

class Goat : public Animal {
public:
    void produceMilk() {
        milk += quantity * 8;
    }
};

class Rabbit : public Animal {
public:
    void produceMilk() {
        // Rabbits do not produce milk
    }
};

int main() {
    Cow bo;
    Sheep cuu;
    Goat de;
    Rabbit tho;

    int boQuantity, cuuQuantity, deQuantity, thoQuantity;
    cin >> boQuantity >> cuuQuantity >> deQuantity >> thoQuantity;

    bo.setQuantity(boQuantity);
    cuu.setQuantity(cuuQuantity);
    de.setQuantity(deQuantity);
    tho.setQuantity(thoQuantity);

    bo.setTongLucDau();
    cuu.setTongLucDau();
    de.setTongLucDau();
    tho.setTongLucDau();
    int numRounds;
    cin >> numRounds;
    int cuuCon, boCon, deCon, thoCon;
    for (int i = 1; i <= numRounds; i++) {
        bo.produceMilk();
        cuu.produceMilk();
        de.produceMilk();
        tho.produceMilk();

         boCon = bo.getQuantity() / 2;
         cuuCon = cuu.getQuantity()/ 2;
         deCon = de.getQuantity() / 2;
         thoCon = tho.getQuantity() / 2;
            // bo.setQuantity(bo.getQuantity() + bo.getQuantity() / 2);
            // cout<<bo.getQuantity()<<endl;
            // cuu.setQuantity(cuu.getQuantity() + cuu.getMilk() / 10);
            // de.setQuantity(de.getQuantity() + de.getMilk() / 16);

             bo.setTong(boCon) ;
                cuu.setTong(cuuCon);
                de.setTong(deCon);
       

        if(i>1) {
            tho.setQuantity(tho.getQuantity() + thoCon);
            
            }

        if(i%4==0) {
            bo.setQuantity( bo.getQuantity() + boCon);
           cuu.setQuantity( cuu.getQuantity() + cuuCon);
           de.setQuantity( de.getQuantity() + deCon);
        }
        
    }

    cout << "Bo: " << bo.getTong() << "," << bo.getMilk() << endl;
    cout << "Cuu: " << cuu.getTong() << "," << cuu.getMilk() << endl;
    cout << "De: " << de.getTong() << "," << de.getMilk() << endl;
    cout << "Tho: " << tho.getQuantity() << "," << tho.getMilk() << endl;

    return 0;
}
