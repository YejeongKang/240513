#include <string>
#include <vector>

using namespace std;

#pragma once


class Character {

private:
	string name;
	int level;
	int item_num;
	int HP;
	int match;
	int money;


public:
	Character() {}

	// �⺻ ������
	Character(string c_name) : name(c_name), level(0), item_num(0), HP(100), match(0), money(0) {}

	// �޼ҵ� ����
	void setName(string c_name); // ���� 1) �̸� ����
	void accelLevel(); // ���� 2) ������ 
	void pickupItem(); // ���� 3) ������ �ݱ�
	void useItem(); // ���� 4) ������ ���
	void buyItem(); // ���� 5) ������ ����
	void sellItem(); // ���� 6) ������ �Ǹ�
	void attack(int idx, vector<Character>& vec); // ���� 7) ����
	void eliminateAll(int idx, vector<Character>& vec); // ���� 8) ����
	void selfDestructed(int idx, vector<Character>& vec); // ���� 9) �ڰ�
	void prtInfo(); // ���� 10) ���� ���	
	void setHP(int hp);


	string getName() {
		return name;
	};

	int getLevel() {
		return level;
	};

	int getItemNum() {
		return item_num;
	};

	int getHP() {
		return HP;
	};

	int getMatch() {
		return match;
	};

	int getMoney() {
		return money;
	};
};
