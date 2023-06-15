#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Character{
protected:
    string ten;
    float HP;
    float ATK;
    float DEF;
    int type;
    static int soThanhVienNhanLoai;
    static int soThanhVienDevil;
public:
    virtual void ajust(){
    }
    virtual void nhap(int type){
        this->type = type;
        cin>>ten>>HP>>ATK>>DEF;
    }
    void atack(Character* enemy){
        if (enemy->DEF > ATK ){
            return;
        }
        enemy->HP = enemy->HP -  (ATK - enemy->DEF);
    }
    bool daChet(){
        if (HP <= 0){
            return true;
        }else{
            return false;
        }
    }
    float getHP(){
        return HP;
    }
    void xuat(){
        cout<<ten<<" "<<HP<<endl;
    }
};

class NhanLoai : public Character{
protected:
    string jobClass;
    void nhap(int type){
        Character::nhap(type);
        cin>>jobClass;
        soThanhVienNhanLoai++;
    }

};

class Human : public NhanLoai{

public:
void ajust(){

}
};

class Elf : public NhanLoai{

public:
    void ajust(){
        DEF = DEF*50/100 + DEF;
    }
};

class BanNhan : public Character{
private:
    string racialClass;

public:
    void nhap(int type){
        Character::nhap(type);
            cin>>racialClass;
        }
    
    
};

class Orc : public BanNhan{
public:
    void ajust(){
        HP= HP*50/100 + HP;
    }

};

class Goblin : public BanNhan{
public:
    void ajust(){
        ATK = ATK*10/100 + ATK;
    }
};

class DiHinh : public Character{
public:
    void nhap(int type){
        Character::nhap(type);
    }
};

class Vampire : public DiHinh{
public:
    void ajust(){
        HP = HP*10/100*soThanhVienNhanLoai + HP;
    }
};

class Devil : public DiHinh{
    public:

Devil(){
    soThanhVienDevil ++;
}
    void ajust(){
        ATK= ATK*10/100*soThanhVienDevil + ATK;
        DEF = DEF*10/100*soThanhVienDevil + DEF;
    }
};

class Boss : public Character{

};


bool compareHP(Character* a, Character*b){
    return (a->getHP() < b->getHP());
}

class Guild{
private:
    vector<Character*> listCharacter;
    int soLuongThanhVien;
public:

void nhapThanhVien(){
    int loai;
    Character* character;
    cin>>soLuongThanhVien;
    for (int i = 0 ;i < soLuongThanhVien; i++){
        cin>>loai;
        switch (loai)
        {
        case 1:
            character = new Human;
            break;
        case 2:
            character = new Elf;
            break;
        case 3:
            character = new Orc;
            break;
        case 4:
            character = new Goblin;
            break;
        case 5:
            character = new Vampire;
            break;
        case 6:
            character = new Devil;
            break;
        default:
            break;
        }
        character->nhap(loai);
        character->ajust();
        listCharacter.push_back(character);
    }
    
}

int getThanhVienItMauNhat(){
    float minHp  = 99999;
    int thanhVienItMauNhat;
    for (int i = 0 ; i < soLuongThanhVien; i++){
        if (listCharacter[i]->daChet() == false){
           if (minHp > listCharacter[i]->getHP()){
            minHp = listCharacter[i]->getHP();
            thanhVienItMauNhat = i;
           }
        }
    }
    return thanhVienItMauNhat;
}


void guildAtack(Character* boss){
    for (int i = 0; i < soLuongThanhVien; i++){
         if (listCharacter[i]->daChet() == false){
            listCharacter[i]->atack(boss);
         }
    }
}
void bossAtack ( Character* boss){
    bool daDanh[100] = {false};
    int thanhVienItMauNhat;
    if (boss->daChet() == false){
        for (int i = 0; i < soLuongThanhVien; i++){
            thanhVienItMauNhat = this->getThanhVienItMauNhat();
         if (listCharacter[thanhVienItMauNhat]->daChet() == false && 
         daDanh[thanhVienItMauNhat] == false){
            daDanh[thanhVienItMauNhat] = true;
            boss->atack(listCharacter[thanhVienItMauNhat]);
            return; //o day
         }
    }
    }
}
bool conSong(){
    int nguoiConSong = 0;
    for (int i = 0 ; i < soLuongThanhVien; i++){
        if (listCharacter[i]->daChet() == false){
            nguoiConSong++;
        }
    }
    if (nguoiConSong > 0 ){
        return true;
    }else{
        return false;
    }
}

void xuatNguoiConSong(){
       sort(listCharacter.begin(), listCharacter.end(), compareHP);
       for (int i = 0 ; i < soLuongThanhVien; i++){
        if (listCharacter[i]->daChet() == false){
            listCharacter[i]->xuat();
        }
       }
}

};

class Raid {
private:
    Guild guild;
    Character* boss;
public:
    void nhapThanhVienGuild(){
        guild.nhapThanhVien();
    }
    void nhapThongTinBoss(){
        boss = new Boss;
        boss->nhap(7);
    }
    void startBattle(){
        int numberLuot = 0;
        while (guild.conSong() == true && boss->daChet() == false){
            if (numberLuot > 100){
                boss->xuat();
                return;
            }
            numberLuot++;
        guild.guildAtack(boss);
        if (boss->daChet() == true){
            break;
        }
        guild.bossAtack(boss);

        }
    if (guild.conSong() == true){
        guild.xuatNguoiConSong();
        return;
    }
    boss->xuat();
    }

};


int Character::soThanhVienNhanLoai = 0;
int Character::soThanhVienDevil = 0;



int main(){
Raid raid;
raid.nhapThanhVienGuild();
raid.nhapThongTinBoss();
raid.startBattle();
}