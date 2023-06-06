#include <iostream>
using namespace std;
static float bossAttack = 0;
static float bossDefend = 0;
static int humanCount = 0;
static int devilCount = 0;
static float bossHP = 0;


class Guild {
protected:



	string name;


	float hp, attack, defend;

	string additionalInfo;

public:
	Guild() {


		name = ""; hp = 0; attack = 0; defend = 0; additionalInfo = "";
	}

	void setHP(float hp) {
		this->hp = hp;


        
	}

	float getHP() {
		return hp;
	}

	float getAttack() {
		return attack;
	}



	float getDefend() {
		return defend;
	}


	virtual void input() {
		cin >> name>>hp>>attack>>defend;
	}

	virtual void adjust() = 0;

	void display() {
		if (hp > 0)
			cout << name << " " << hp << endl;
	}
};

class Human : public Guild {
public:
	Human() {



    }
	void adjust() {


    }


	void input() {
		Guild::input();
		cin >> additionalInfo;


	}
};

class Elf : public Guild {
public:
	Elf() {}

	void adjust() {
		defend += (float)0.5 * defend;
	}

	void input() {
		Guild::input();
		cin >> additionalInfo;
	}
};

class Orc : public Guild {
public:
	Orc() {}

	void adjust() {
		hp += hp * (float)0.5;
	}

	void input() {
		Guild::input();
		cin >> additionalInfo;
	}
};

class Goblin : public Guild {
public:
	Goblin() {}

	void adjust() {


		attack = attack + attack *(float)0.1;

	}

	void input() {
		Guild::input();
		cin >> additionalInfo;
	}
};

class Vampire : public Guild {
public:
	Vampire() {}

	void adjust() {
		hp = hp + humanCount * (float)0.1 * hp;
	}

	void input() {
		Guild::input();
	}
};

class Devil : public Guild {
public:
	Devil() {}

	void adjust() {
		attack += devilCount * (float)0.1 * attack;
		defend += devilCount * (float)0.1 * defend;
	}

	void input() {
		Guild::input();
	}
};

class Overlord {
protected:
	Guild** guilds;
	int numGuilds;

public:
	void input() {
		cin >> numGuilds;
		guilds = new Guild*[numGuilds];
		int type;
		for (int i = 0; i < numGuilds; i++) {
			cin >> type;
			switch (type) {
			case 1:
				guilds[i] = new Human();
				humanCount++;
				break;
			case 2:
				guilds[i] = new Elf();
				humanCount++;
				break;
			case 3:
				guilds[i] = new Orc();
				break;
			case 4:
				guilds[i] = new Goblin();
				break;
			case 5:
				guilds[i] = new Vampire();
				break;
			case 6:
				guilds[i] = new Devil();
				devilCount++;
				break;
			}
			guilds[i]->input();
			guilds[i]->adjust();
		}
	}

	void display() {
		for (int i = 0; i < numGuilds; i++)
			guilds[i]->display();
	}

	void interchangeSort() {
		for (int i = 0; i < numGuilds - 1; i++) {
			for (int j = i + 1; j < numGuilds; j++) {
				if (guilds[i]->getHP() > guilds[j]->getHP())
					swap(guilds[i], guilds[j]);
			}
		}
	}

	bool checkAttack() {
		for (int i = 0; i < numGuilds; i++) {
			if (guilds[i]->getAttack() - bossAttack == 0 && guilds[i]->getDefend() - bossDefend == 0)
				return false;
		}
		return true;
	}

	int process() {
		if (!checkAttack())
			return 0;
		if (numGuilds == 0)
			return 0;
		while (true) {
			int turn = 0;
			
			interchangeSort();
			for (int i = 0; i < numGuilds; i++) {
				if (guilds[i]->getHP() <= 0)
					continue;
				if (guilds[i]->getAttack() - bossDefend > 0)
					bossHP -= guilds[i]->getAttack() - bossDefend;
			}
			if (bossHP < 0)
				return 1;

		
			for (int i = 0; i < numGuilds; i++) {
				if (guilds[i]->getHP() <= 0) {
					continue;
				}
				guilds[i]->setHP(guilds[i]->getHP() - (bossAttack - guilds[i]->getDefend()));
				break;
			}
			if (guilds[numGuilds - 1]->getHP() < 0)
				return 0;

			turn++;
			if (turn > 100)
				return -1;
		}
	}
};

int main() {
	Overlord a;
	a.input();
           










	string bossName;
	cin >> bossName>>bossHP>>bossAttack>>bossDefend;


	int result = a.process();

	if (result == 1)
		a.display();
	else if (result == -1)
		cout << bossName << " " << bossHP;
	else if (result == 0)
		cout << bossName << " " << bossHP;

	return 0;
}
