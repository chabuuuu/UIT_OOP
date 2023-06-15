#include <iostream>
#include <vector>

using namespace std;

class Gun {
protected:
    string gunName;
    int Bullet;
    int ammoSize;
    float baseDamage;
    float fireRate;
    float reloadTime;

public:
    Gun(string name, int bullet, int size, float damage, float rate) {
        gunName = name;
        ammoSize = size;
        baseDamage = damage;
        fireRate = rate;
        reloadTime = 2.0;
        Bullet=bullet;
    }
    
    virtual int getSize() {
        return ammoSize;
    }
    
    virtual int getBullet() {
        return Bullet;
    }
    
    virtual float getDamage(float erosion) {
        return erosion * baseDamage;
    }

    virtual float getFireRate(float erosion) {
        if (erosion > 0 && erosion < 1) 
        return fireRate / 2; 
        return fireRate; 
    }

    virtual float getReloadTime() {
        return reloadTime;
    }

    virtual float getTotalDamage(float erosion, double ammo) {
        if(ammo > int(ammo)) {ammo = int(ammo) + 1;}
        else {ammo = ammo;}
        int n;
        int totalBullet = getSize() * getBullet();
        n = ((ammo - (2 * getFireRate(erosion))) / getBullet());
        ammo = ammo - (getReloadTime()*n*getFireRate(erosion));
        if(ammo > totalBullet) {ammo = totalBullet;}
        else {ammo = ammo;}
        return getDamage(erosion) * ammo;
    }

    virtual string getGunName() {
        return gunName;
    }
    virtual ~Gun() {}
};

class ShortGun : public Gun {
public:
    ShortGun(string name, int bullet, int size, float damage, float rate) : Gun(name, bullet, size, damage, rate) {}
};

class Rifle : public Gun {
    float skinDamage;

public:
    Rifle(string name, int bullet, int size, float damage, float rate, float skin) : Gun(name, bullet, size, damage, rate) {
        skinDamage = skin;
    }

    float getDamage(float erosion) {
        return (erosion * baseDamage) + skinDamage;
    }
};

class Sniper : public Gun {
public:
    Sniper(string name, int bullet, int size, float damage, float rate) : Gun(name, bullet, size, damage, rate) {}

    float getFireRate(float erosion) {
        if(erosion > 0 && erosion < 1)
        return (1 / ((1 / (fireRate / 2)) + 1));
        return (1 / ((1 / fireRate) + 1));
    }

};

int main() {
    int numGuns;
    cin >> numGuns;
    int type, size;
    float erosion, extraDamage;
    vector<Gun*> guns;
    vector<float> erosions; 
    for (int i = 0; i < numGuns; i++) {
        cin >> type >> size >> erosion;
        erosions.push_back(erosion); 
        Gun* gun;
        switch (type) {
            case 1:
                gun = new ShortGun("G18", 12, size, 2.0, 1.0);
                break;
            case 2:
                gun = new ShortGun("M500", 5, size, 4.0, 0.5);
                break;
            case 3:
                cin >> extraDamage;
                gun = new Rifle("MP40", 20, size, 3.0, 5.0, extraDamage);
                break;
            case 4:
                cin >> extraDamage;
                gun = new Rifle("AK", 30, size, 5.0, 1.0, extraDamage);
                break;
            case 5:
                gun = new Sniper("SVD", 10, size, 5.0, 0.5);
                break;
            case 6:
                gun = new Sniper("AWM", 5, size, 10.0, 0.5);
                break;    
            default:
                delete gun;
                continue;
        }

        guns.push_back(gun);
    }
    
    float totalTime;
    cin >> totalTime;
    for (int i = 0; i < guns.size(); i++) {
        Gun* gun = guns[i];
        float erosion = erosions[i];  
        float damage = gun->getTotalDamage(erosion, totalTime * gun->getFireRate(erosion));
        cout << gun->getGunName() << ": " << damage << endl;

        delete gun;
    }

    return 0;
}