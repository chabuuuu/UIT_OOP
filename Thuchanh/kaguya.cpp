#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std;


class BestFriend {
private:
    string name;
    int age;
    string phone;

public:
    BestFriend(string name, int age, string phone) {
        this->name = name;
        this->age = age;
        this->phone = phone;
    }

    float getTimeSpent() {
        return 5;  
    }

    void printInfo() {
        cout << "Ten: " << name << ", tuoi: " << age << ", so dien thoai: " << phone << endl;
    }
    string getName(){
        return name;
    }
};


class BoyFriend {
private:
    string name;
    int age;
    int income;

public:
    BoyFriend(string name, int age, int income) {
        this->name = name;
        this->age = age;
        this->income = income;
    }

    float getTimeSpent() {
        return 5 * income / 10000000.0;  
    }

    void printInfo() {
        cout << "Ten: " << name << ", tuoi: " << age << ", thu nhap: " << income << "d" << endl;
    }
    string getName(){
        return name;
    }
};


class OtherBoy {
private:
    string name;
    int age;
    float attractiveness;

public:
    OtherBoy(string name, int age, float attractiveness) {
        this->name = name;
        this->age = age;
        this->attractiveness = attractiveness;
    }

    float getTimeSpent(int totalFriends) {
        return attractiveness * 20 / totalFriends;  
    }

    void printInfo() {
        string level;
        if (attractiveness >= 0.7)
            level = "cao";
        else if (attractiveness >= 0.4)
            level = "trung binh";
        else
            level = "thap";

        cout << "Ten: " << name << ", tuoi: " << age << ", do thu hut: " << level << endl;
    }
    string getName(){
        return name;
    }
};

int main() {
    int n;
    cin >> n;

    vector<BestFriend> bestFriends;
    vector<BoyFriend> boyFriends;
    vector<OtherBoy> otherBoys;
    queue<string> names;

    for (int i = 0; i < n; i++) {
        int type;
        string name;
        int age;

        cin >> type >> name >> age;

        if (type == 1) {
            string phone;
            cin >> phone;
            bestFriends.push_back(BestFriend(name, age, phone));
            names.push(name);
        } else if (type == 2) {
            int income;
            cin >> income;
            boyFriends.push_back(BoyFriend(name, age, income));
            names.push(name);
        } else if (type == 3) {
            double attractiveness;
            cin >> attractiveness;
            otherBoys.push_back(OtherBoy(name, age, attractiveness));
            names.push(name);
        }
    }

  
    float timeSpentBestFriend = 0;
    float timeSpentBoyFriend = 0;
    float timeSpentOtherBoy = 0;

    for (auto& it : bestFriends){
         timeSpentBestFriend += it.getTimeSpent();
    }
  

    for ( auto& it : boyFriends)
        timeSpentBoyFriend += it.getTimeSpent();

  
    for ( auto& it : otherBoys)
        timeSpentOtherBoy += it.getTimeSpent(n);

  
    cout << "Thong ke:" << endl;
    if (timeSpentBestFriend != 0){
        cout << "-Thoi gian cho ban than: " << timeSpentBestFriend << " h" << endl;
    }
     if (timeSpentBoyFriend != 0){
            cout << "-Thoi gian cho ban trai: " << timeSpentBoyFriend << " h" << endl;
     }
     if (timeSpentOtherBoy != 0){
            cout << "-Thoi gian cho ban trai khac: " << timeSpentOtherBoy << " h" << endl;
     }



 
    vector<pair<string, float>> importantFriends;

    for ( auto& it : bestFriends)
        importantFriends.push_back(make_pair(it.getName(), it.getTimeSpent()));

    for ( auto& it : boyFriends)
        importantFriends.push_back(make_pair(it.getName(), it.getTimeSpent()));

    for ( auto& it : otherBoys)
        importantFriends.push_back(make_pair(it.getName(), it.getTimeSpent(n) ));


    sort(importantFriends.begin(), importantFriends.end(), [](const pair<string, float>& a, const pair<string, float>& b) {
        return a.second > b.second;
    });


    cout << "Nguoi ban quan trong nhat:" << endl;

   
    while (names.empty() != true){

        for (const auto& it : importantFriends) {

        if (it.first == names.front()){
            names.pop();
        if (it.second == importantFriends[0].second) {
          
            for ( auto& object : bestFriends) {
                if (object.getName() == it.first) {
                    object.printInfo();
                    break;
                }
            }

            for ( auto& boyFriend : boyFriends) {
                if (boyFriend.getName() == it.first) {
                    boyFriend.printInfo();
                    break;
                }
            }

            for ( auto& otherBoy : otherBoys) {
                if (otherBoy.getName() == it.first) {
                    otherBoy.printInfo();
                    break;
                }
            }
        } else {
            break;
        }

        break;
        }


    }



    }

    return 0;
}
