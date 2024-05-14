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

	// 기본 생성자
	Character(string c_name) : name(c_name), level(0), item_num(0), HP(100), match(0), money(0) {}

	// 메소드 선언
	void setName(string c_name); // 조작 1) 이름 변경
	void accelLevel(); // 조작 2) 레벨업 
	void pickupItem(); // 조작 3) 아이템 줍기
	void useItem(); // 조작 4) 아이템 사용
	void buyItem(); // 조작 5) 아이템 구매
	void sellItem(); // 조작 6) 아이템 판매
	void attack(int idx, vector<Character>& vec); // 조작 7) 공격
	void eliminateAll(int idx, vector<Character>& vec); // 조작 8) 전멸
	void selfDestructed(int idx, vector<Character>& vec); // 조작 9) 자결
	void prtInfo(); // 조작 10) 정보 출력	
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
