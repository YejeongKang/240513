// prac3_game_character 파일 분리 전

#include <iostream>
#include <string>

using namespace std;

class Character {

private:
	string name;
	int level;
	int item_num;

public:
	Character() {}

	// 기본 생성자
	Character(string c_name) : name(c_name), level(0), item_num(0) {}

	// 메소드 선언
	void setName(string c_name); // 조작 1 이름 변경
	void accelLevel(); // 조작 2 레벨업 
	void pickupItem(); // 조작 3 아이템 줍기
	void useItem(); // 조작 4 아이템 사용

	string getName() {
		return name;
	};

	int getLevel() {
		return level;
	};

	int getItemNum() {
		return item_num;
	};
};

void Character::setName(string c_name) { // 조작 1 이름 변경

	this->name = c_name;
};

void Character::accelLevel() { // 조작 2 레벨업 (level + 1)

	this->level = level++;
};

void Character::pickupItem() { // 조작 3 아이템 줍기 (item_num + 1)

	this->item_num++;
};

void Character::useItem() { // 조작 4 아이템 사용 (item_num - 1)

	this->item_num--;
};


int main() {

	/*int num = 5;

	Character* players = new Character[num];

	players[3].setName("james");

	cout << players[3].getName();*/

	string c_name;
	int manipulating; // 캐릭터를 어떻게 조작할지 받는 case 변수

	cout << "사용할 캐릭터의 이름을 입력하시오. : ";
	cin >> c_name;

	// 개체 생성 
	Character GameSet(c_name);

	// 사용자가 게임 종료를 원하기(0 입력) 전까지 동작을 입력받기
	while (1) {

		cout << endl << "어떤 동작을 실행하시겠습니까? (0 종료): ";
		/*<< "1) 이름 변경" << endl
		<< "2) level up" << endl
		<< "3) item 파밍!" << endl
		<< "4) item 사용" << endl
		<< "5) 이름, level, item 출력" << endl
		<< "0) 게임 종료" << endl*/

		cin >> manipulating;

		switch (manipulating) {

		case 1:

			cout << "새 이름을 입력해주세요 : ";

			cin >> c_name;

			// 이름 변경하는 함수 호출
			GameSet.setName(c_name);

			// 이름 반환해주는 함수 호출해서 변경된 이름 확인
			cout << endl << "이름이 변경되었습니다." << endl << "new name : " << GameSet.getName() << endl;

			break;

		case 2:

			GameSet.accelLevel();

			cout << "Level Up !!!" << endl;

			break;

		case 3:

			GameSet.pickupItem();

			cout << "아이템을 얻었습니다! " << endl << "현재 아이템 개수 : " <<
				GameSet.getItemNum() << endl;

			break;

		case 4:

			GameSet.useItem();

			cout << "아이템을 사용했습니다!" << endl << "현재 아이템 개수 : " <<
				GameSet.getItemNum() << endl;;

			break;

		case 5:

			cout << "이름 : " << GameSet.getName() << endl
				<< "레벨 : " << GameSet.getLevel() << endl
				<< "현재 아이템 개수 : " << GameSet.getItemNum() << endl;

			break;

		case 0:

			cout << "게임을 종료합니다." << endl;

			return 0;

			break;
		}
	}



	return 0;
}