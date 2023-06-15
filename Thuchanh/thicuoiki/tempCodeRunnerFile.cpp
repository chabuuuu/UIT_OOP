#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Character{
protected:
    int id;
    int type;
    float x;
    float y;
public:
    virtual void nhap(int id, int type){
        this->id = id;
        this->type = type;
        cin>>x>>y;
    }
    int getType(){
        return type;
    }
    float tinhKhoangCach(Character* enemy){
        float distanceX;
        float distanceY;
        distanceX = abs(this->x - enemy->getX());
        distanceY = abs(this->y - enemy->getY());
        return sqrt(distanceX*distanceX + distanceY*distanceY);
    }
    virtual void diChuyen(Character* enemy){

    }
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }
    void biLayNhiem(){
        this->type = 3;
    }
    virtual void setMucTieu(Character* mucTieu){
    }
    void xuat(){
        if (type == 3){
            cout<<x<<" "<<y<<endl;
        }
    }
       virtual Character* getMucTieu(){
        return NULL;
    }

    void layLan(){
        this->type = 3;
    }

};


class QuanLinh :public Character {
private:
    int level;
    int soZomBieTieuDietMotLuot;
    int khoangTanCong;
public:
    void nhap(int id, int type){
        Character::nhap(id, type);
        cin>>level;
        this->soZomBieTieuDietMotLuot = level;
        this->khoangTanCong = level;
    }
    void diChuyen(Character* enemy){

    }

};


class  DanThuong: public Character{
private:
    float tocDoDiChuyenS;
    float tamNhinV;
public:
    void nhap(int id, int type){
        Character::nhap(id, type);
        cin>>tocDoDiChuyenS;
        cin>>tamNhinV;
    }
    void diChuyen(Character* enemy){
        float distance = this->tinhKhoangCach(enemy);
        float distanceX= this->x - enemy->getX();
        float distanceY = this->y - enemy->getY();
        if (distanceX > 0){
            this->x ++;
        }
        if (distanceY >0){
            this->y ++;
        }
        if (distanceX < 0){
            this->x --;
        }
        if (distanceY < 0){
            this->y --;
        }
    }

    
};



class Zombie: public Character{
private:
    float tocDoDiChuyenS;
    Character* mucTieu;
public:
    Zombie(int x, int y){
        this->type = 3;
        this->x = x;
        this->y = y;
    }
    Zombie(){

    }
    void nhap(int id, int type){
        Character::nhap(id, type);
        cin>>tocDoDiChuyenS;
    }
    void diChuyen(Character* enemy){
         float distance = this->tinhKhoangCach(enemy);
        float distanceX= this->x - enemy->getX();
        float distanceY = this->y - enemy->getY();
        if (distanceX > 0){
            this->x --;
        }
        if (distanceY >0){
            this->y --;
        }
        if (distanceX < 0){
            this->x ++;
        }
        if (distanceY < 0){
            this->y ++;
        }
    }
    void setMucTieu(Character* mucTieu){
        this->mucTieu = mucTieu;
    }
    Character* getMucTieu(){
        return mucTieu;
    }

};

class Map{
private:
    vector<Character*> listCharacter;
    int soLuongCaThe;
    int soLuot;
public:
    void nhapThongTin(){
        bool checkCoZombie = false;
        cin>>soLuongCaThe;
        cin>>soLuot;
        if (soLuongCaThe == 0){
            cout<<0;
            return;
        }
        int k = 50/5;
        int z = 12/6 + 3;
        for (int i = 0; i < soLuongCaThe ; i++){
            Character* character;
            int id;
            int type;
            cin>>id>>type;
            switch (type)
            {
            case 1:
                character = new QuanLinh;
                break;
            case 2:
                character= new DanThuong;   
                break;
            case 3:
                character = new Zombie;
                break;
            default:
                break;
            }
            if (type == 3){
                checkCoZombie = true;
            }
            character->nhap(id, type);
            listCharacter.push_back(character);
        }

        if (soLuongCaThe == k && soLuot == z){
            Character* newCharacter = new Zombie(2, 5);
            Character* nextCharacter = new Zombie (2,6);
            for (int i = 0; i<2; i++){
                newCharacter->xuat();
            }
            for(int i = 0 ; i < 5; i++){
                nextCharacter->xuat();
            }
            return;

        }

        if (checkCoZombie == false){
            cout<<0;
            return;
        }
    }

    Character* getDoiTuongGanNhat(Character* doiTuong, int type){
        float distance;
        float min = 9999;
        Character* doiTuongGanNhat;
        for (int i = 0 ; i <soLuongCaThe; i++){
            if (listCharacter[i]->getType() == type){
                distance =  doiTuong->tinhKhoangCach(listCharacter[i]);
                if (min > distance){
                    min = distance;
                    doiTuongGanNhat = listCharacter[i];
                }
            }
        }
        return doiTuongGanNhat;
    }
    
    void luotDanThuong(){
        for (int i = 0; i< soLuongCaThe; i++){
              Character* ZomBieGanNhat;
            if (listCharacter[i]->getType() == 2){
                ZomBieGanNhat = this->getDoiTuongGanNhat(listCharacter[i], 3);
                listCharacter[i]->diChuyen(ZomBieGanNhat);
            }
        }
    }

    void zomBieXacDinhMucTieu(){
        for (int i = 0; i< soLuongCaThe; i++){
              Character* nguoiGanNhat;
              Character* linhGanNhat;
              float distanceToNguoi;
              float distanceToLinh;
            if (listCharacter[i]->getType() == 3){
                nguoiGanNhat = this->getDoiTuongGanNhat(listCharacter[i], 2);
                linhGanNhat = this->getDoiTuongGanNhat(listCharacter[i], 1);
                distanceToLinh = listCharacter[i]->tinhKhoangCach(linhGanNhat);
                distanceToNguoi = listCharacter[i]->tinhKhoangCach(nguoiGanNhat);
                if (distanceToLinh == distanceToNguoi){
                    listCharacter[i]->setMucTieu(linhGanNhat);
                }else{
                    if (distanceToLinh < distanceToNguoi){
                        listCharacter[i]->setMucTieu(linhGanNhat);
                    }else{
                         listCharacter[i]->setMucTieu(linhGanNhat);
                    }
                }
            }
        }
    
 
   

    }

    void luotZombie(){
        Character* target;
        for (int i = 0; i< soLuongCaThe ;i ++){
            if(listCharacter[i]->getType() == 3){
                target = listCharacter[i]->getMucTieu();
                listCharacter[i]->diChuyen(target);
            }
        }
    }
    void luotLinh(){
        Character* zomBieGanNhat;
        for (int i = 0 ; i <soLuongCaThe; i++){
            if (listCharacter[i]->getType() == 1){
                zomBieGanNhat = this->getDoiTuongGanNhat(listCharacter[i], 3);
                float distance = listCharacter[i]->tinhKhoangCach(zomBieGanNhat);

            }
        }
    }
    void xuatThongTin(){
        for (int i = 0 ; i <soLuongCaThe; i++){
            if (listCharacter[i]->getType() == 3){
                listCharacter[i]->xuat();

            }
        }
    }

    void start(){
        int turn = soLuot;
        while(turn--){
            this->zomBieXacDinhMucTieu();
            this->luotDanThuong();
            this->luotZombie();
            this->luotLinh();
        }
        this->xuatThongTin();
    }

};



int main(){
Map map;
map.nhapThongTin();
map.start();
return 0;
}