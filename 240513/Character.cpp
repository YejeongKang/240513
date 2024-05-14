#include "Character.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Character::setName(string c_name) { // 조작 1) 이름 변경

	this->name = c_name;
};

void Character::accelLevel() { // 조작 2) 레벨업 (level + 1)

	level = level++;

	HP += 10;

	cout << "Level Up !!!" << endl << endl;

};

void Character::pickupItem() { // 조작 3) 아이템 줍기 (item_num + 1)

	item_num++;

	cout << "아이템을 얻었습니다! " << endl;
};

void Character::useItem() { // 조작 4) 아이템 사용 (item_num - 1)

	item_num--;

	cout << "아이템을 사용했습니다!" << endl;
};


void Character::buyItem() { // 조작 5) 아이템 구매

	if (money >= 100) {

		item_num++;

		money -= 100;

		cout << "아이템을 구매했습니다! " << endl;
	}
	else {

		cout << "머니가 부족합니다. 아이템을 구매하지 못했습니다." << endl;
	}
};

void Character::sellItem() { // 조작 6) 아이템 판매
	char res;

	if (item_num > 0) {

		item_num--;

		money += 100;

		cout << "아이템을 판매했습니다! " << endl;
	}
	else {

		cout << "아이템을 판매하지 못했습니다. " << endl;
	}

	if (money >= 1000) {

		cout << "1000 머니를 지불하고 캐릭터를 강화하시겠습니까? (Y/N 입력): ";
		cin >> res;

		if (res == 'Y') {
		
			accelLevel();// level++
			money -= 1000;
		}
		else {}
	}
};

void Character::attack(int idx, vector<Character> vec) { // 조작 7) 공격

	// 나와 공격 대상의 매치 수 모두 1 증가, 상대 체력 50 감소
	match++;

	// 현재 체력이 50이 안넘으면, 공격당한 후 죽음.
	if (vec[idx].HP >= 50) {
	
		vec[idx].HP -= 50;
	}
	else {
		cout << vec[idx].getName() << "플레이어가 사망했습니다. 흑흑" << endl;

		vec.erase(vec.begin() + idx, vec.begin() + idx + 1);

	}


	vec[idx].match++;

	// 매치 수가 10씩 증가할 때마다 레벨 업
	if (match > 0 && match%10 == 0) {

		accelLevel();
	}

	if (vec[idx].match > 0 && vec[idx].match % 10 == 0) {

		accelLevel();
	}
};

void Character::eliminateAll(int idx, vector<Character> vec) { // 조작 8) 전멸

	if (level >= 100) {

		// vec[idx], 즉 본인 빼고 벡터에서 다 제거

		vec.erase(vec.begin(), vec.begin() + idx);

		vec.erase(vec.begin() + idx + 1, vec.begin());

		cout << "적을 모두 전멸시켰습니다. 새로운 적을 찾으세요.";
	}
	else {
		cout << "레벨 100 이상만 실행할 수 있는 공격입니다. 렙 키워오셈요." << endl;
	}
};

void Character::selfDestructed(int idx, vector<Character> vec) { // 조작 9) 자결

	// 벡터에서 본인을 제거
	cout << vec[idx].getName() << "플레이어가 자결했습니다. 흑흑" << endl;

	vec.erase(vec.begin() + idx, vec.begin() + idx + 1);

};

void Character::prtInfo() { // 조작 10) 캐릭터의 모든 정보 출력

	cout << "이름 : " << name << endl
		<< "레벨 : " << level << endl
		<< "현재 아이템 개수 : " << item_num << endl
		<< "현재 체력 : " << HP << endl
		<< "현재 매치 수 : " << match << endl
		<< "보유한 자금 : " << money << endl;
}
