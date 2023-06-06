#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Gun {
protected:
    string name;
    int ammoSize;
    float baseDamage;
    float fireRate;
    float reloadTime;
    int ammoCount;
    float weardown;
    
    

public:
    Gun(string name, int ammoSize, float baseDamage, float fireRate, int ammoCount, float weardown)
        : name(name), ammoSize(ammoSize), baseDamage(baseDamage), fireRate(fireRate), reloadTime(2.0), ammoCount(ammoCount), weardown(weardown) {}

    virtual ~Gun() {}

    virtual float calculateDamage(float wearDown) {
        float damage = baseDamage *  wearDown;
      
        return damage;
    }

    virtual float calculateFireRate(float wearDown) {
        float modifiedFireRate = fireRate /2;
        return modifiedFireRate;
    }
    
    float getwearDown(){
        return weardown;
    }

    float calculateTotalDamage(float wearDown, int shootingTime) {
        float damage = calculateDamage(wearDown);
      
        float newFireRate;
        if (wearDown != 1){
             newFireRate = calculateFireRate(wearDown);
             
        }else{
             newFireRate = fireRate;
        }
        
        int time = shootingTime;
        int soBangDan = ammoSize;
        int soDanCoTheBan = ammoCount*ammoSize;
        // bool check = true;
      
        float soDanBan = 0;
        while (time > 0 && soBangDan > 0){
            if (newFireRate*time < ammoCount ){
                
                soDanBan = soDanBan + newFireRate*(float)time ;
                soDanCoTheBan = soDanCoTheBan - soDanBan;
                soBangDan--;
               
                return damage * round(soDanBan);
            }


             for (int i  = 1; i<= time ; i++){
            if (newFireRate*i > ammoCount){
                

                soDanBan = soDanBan + newFireRate*(i);
                soDanCoTheBan = soDanCoTheBan - soDanBan;
                soBangDan--;
               
                time = time - i - 2;
                
                break;
            }
        }

        }
        
       
        return damage * round(soDanBan);
    }

    virtual string getName() {
        return name;
    }
};

class ShortGun : public Gun {
public:
    ShortGun(string name, int ammoSize, float baseDamage, float fireRate, int ammoCount, float weardown)
        : Gun(name, ammoSize, baseDamage, fireRate, ammoCount, weardown) {}

    float calculateFireRate(float wearDown) {
        float modifiedFireRate = fireRate /2;
        return modifiedFireRate;
    }
     float calculateDamage(float wearDown) {
        float damage = baseDamage * wearDown ;
        return damage;
    }
};

class SniperGun : public Gun {
public:
    SniperGun(string name, int ammoSize, float baseDamage, float fireRate, int ammoCount, float weardown)
        : Gun(name, ammoSize, baseDamage, fireRate, ammoCount, weardown) {
            reloadTime += ammoSize;
        }

    float calculateDamage(float wearDown) {
        float damage = baseDamage * wearDown ;
        return damage;
    }

    float calculateFireRate(float wearDown) {
        float modifiedFireRate = fireRate / 2;
        return modifiedFireRate;
    }
};

class AssaultRifle : public Gun {
public:
    AssaultRifle(string name, int ammoSize, float baseDamage, float fireRate, int ammoCount, float weardown)
        : Gun(name, ammoSize, baseDamage, fireRate, ammoCount, weardown) {}

    float calculateDamage(float wearDown) {
        float damage = baseDamage;
    
        return damage;
    }
    float calculateFireRate(float wearDown) {
        float modifiedFireRate = fireRate / 2;
        return modifiedFireRate;
    }
};

class Player {
private:
    vector<Gun*> guns;

public:
    ~Player() {
        for (auto gun : guns) {
            delete gun;
        }
        guns.clear();
    }

    void addGun(Gun* gun) {
        guns.push_back(gun);
    }

    float calculateTotalDamage(float wearDown, int shootingTime) {
        float totalDamage = 0.0;
        for (auto gun : guns) {
            totalDamage += gun->calculateTotalDamage(wearDown, shootingTime);
        }
        return totalDamage;
    }
    vector<Gun*> getGuns(){
        return guns;
    }
};

int main() {
    int n;
    cin >> n;

    Player player;

    for (int i = 0; i < n; i++) {
        int gunType, ammoSize, ammoCount;
        float wearDown, baseDamage, fireRate, bonus;
        cin >> gunType >> ammoSize >> wearDown;
       
        Gun* gun;
        float extraDamage;
        
        // if (gunType == 3 || gunType == 4) {
        //     float extraDamage;
        //     cin >> extraDamage;
        //     baseDamage = baseDamage*wearDown + extraDamage;
        // }
        switch (gunType) {
            case 1:
                baseDamage = 2.0;
                fireRate = 1.0;
                ammoCount = 12;
                gun = new ShortGun("G18", ammoSize, baseDamage, fireRate, ammoCount, wearDown);
                break;
            case 2:
                baseDamage = 4.0;
                fireRate = 0.5;
                ammoCount = 5;
                gun = new ShortGun("M500", ammoSize, baseDamage, fireRate, ammoCount, wearDown);
                break;
            case 3:
                baseDamage = 3.0;
                fireRate = 5.0;
                ammoCount = 20;
              
            cin >> extraDamage;
            baseDamage = baseDamage*wearDown + extraDamage;
                gun = new AssaultRifle("MP40", ammoSize, baseDamage, fireRate, ammoCount, wearDown);
                break;
            case 4:
                baseDamage = 5.0;
                fireRate = 1.0;
                ammoCount = 30;
                
            cin >> extraDamage;
            baseDamage = baseDamage*wearDown + extraDamage;
                gun = new AssaultRifle("AK", ammoSize, baseDamage, fireRate, ammoCount, wearDown);
                break;
            case 5:
                baseDamage = 5.0;
                fireRate = 0.25;
                ammoCount = 10;
                gun = new SniperGun("SVD", ammoSize, baseDamage, fireRate, ammoCount, wearDown);
                break;
            case 6:
                baseDamage = 10.0;
                fireRate = 0.25;
                ammoCount = 5;
                gun = new SniperGun("AWM", ammoSize, baseDamage, fireRate, ammoCount, wearDown);
                break;
        }

        player.addGun(gun);

    }

    int shootingTime;
    cin >> shootingTime;

    for (auto gun : player.getGuns()) {
        float thisWearDown = gun->getwearDown();
        float totalDamage = gun->calculateTotalDamage(thisWearDown, shootingTime);
        cout << gun->getName() << ": " << totalDamage << endl;
    }

    return 0;
}
