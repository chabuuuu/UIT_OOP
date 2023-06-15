#include<iostream>
#include<vector>
using namespace std;
static float giaGocTriTatCa = 0;

class Clothes{
protected:
    string name;
    float price;
    string producer;
    string type;
public:
    virtual void nhapThongTin() {
        cin>>name;
        cin>>price;
        cin>>producer;
    }
    virtual void updateGia() = 0;
    float getPrice(){
        return price;
    }
    string getType(){
        return type;
    }
    virtual float addBuff(float rawPrice) = 0;
    void xuat(){
        cout<<name<<price<<type<<endl;
    }

};



//Quan
class Paint :public Clothes{
protected:
    float length;
public:
    Paint(){
        this->type = "paint";
    }
     void nhapThongTin(){
        Clothes::nhapThongTin();
        cin>>length;
    }
    float addBuff(float rawPrice){
        return giaGocTriTatCa;
    }

};

class Jean : public Paint{

public:
void updateGia(){
    price = price*0.8;
    giaGocTriTatCa += price;
}

};

class Kaki: public Paint{
public:
void updateGia(){
    price = 1.5*price;
    giaGocTriTatCa += price;
}

};

//Ao

class Ao: public Clothes {
protected:
    string color;
public:
    Ao(){
        this->type = "ao";
    }
    virtual void nhapThongTin(){
        Clothes::nhapThongTin();
        cin>>color;
    }
      float addBuff(float rawPrice){
        return giaGocTriTatCa;
    }
};

class AoTayNgan : public Ao {
private:
bool coAo;
public:
    void nhapThongTin(){
        Ao::nhapThongTin();
        cin>>coAo;
    }
void updateGia(){
giaGocTriTatCa+= price;
}
};

class AoTayDai : public Ao
{
private:
   float lenghtOngTay; 
public:
    void nhapThongTin(){
        Ao::nhapThongTin();
        cin>>lenghtOngTay;
    }
void updateGia(){
giaGocTriTatCa += price;
}  
};

//Mu

class Mu : public Clothes{
protected:

    int level;
public:
    Mu(){
        this->type = "mu";
    }
    void nhapThongTin(){
        Clothes::nhapThongTin();
        cin>>level;
    }
  

};

class MuSat : public Mu{

public:
void updateGia(){
price = 0;
}
float addBuff(float rawPrice){
    return giaGocTriTatCa;
}
};

class MuBac : public Mu {

public:
void updateGia(){
giaGocTriTatCa += price;
}
float addBuff(float rawPrice){

    
    return rawPrice*1.5 + giaGocTriTatCa - rawPrice;
}
};
class MuVang: public Mu{

public:
void updateGia(){
giaGocTriTatCa += price;
}
float addBuff(float rawPrice){
return rawPrice*3 + giaGocTriTatCa - rawPrice;
}


};



class Human {
private:
    int nVatPham;
    vector<Clothes*> listClothes;
    float giaTriMu = 0;
    

public:
    void nhapVatPham(){  
        cin>>nVatPham;
        if (nVatPham == 0){
            cout<<"0";
            return;
        }
        Clothes* clothes;
        int type;
        for (int i = 0 ; i < nVatPham; i ++){


        
            cin>>type; 

           switch (type)
           {
           case 1:
            clothes = new Jean;
            clothes->nhapThongTin();
            break;
           case 2:
            clothes = new Kaki;
            clothes->nhapThongTin();
            break;
           case 3:
           clothes = new AoTayNgan;
            clothes->nhapThongTin();
            break;
            case 4:
           clothes = new AoTayDai;
            clothes->nhapThongTin();
            break;
            case 5:
           clothes = new MuSat;
            clothes->nhapThongTin();
            break;
            case 6:
           clothes = new MuBac;
            clothes->nhapThongTin();
            giaTriMu += clothes->getPrice();
            break;
            case 7:
            clothes = new MuVang;
            clothes->nhapThongTin();
            giaTriMu += clothes->getPrice();
            break;

           default:
           clothes = NULL;
            break;
           }
           clothes->updateGia();
           listClothes.push_back(clothes);
        }
        
    }

    void calBuff(){
        if (nVatPham != 0){
            float giaTriTruMu = giaGocTriTatCa - giaTriMu;
         float max = listClothes[0]->addBuff(giaTriTruMu);
        for (int i = 0; i <nVatPham; i ++){
            if (listClothes[i]->getType() == "mu"){       
                if (listClothes[i]->addBuff(giaTriTruMu) > max){
                    max = listClothes[i]->addBuff(giaTriTruMu);
                } 
            }
        }
        
        cout<<max;
        }

         
    }


};




int main(){
    Human sori;
    sori.nhapVatPham();
    sori.calBuff();
    return 0;
}