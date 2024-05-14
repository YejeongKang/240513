#include "Character.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Character::setName(string c_name) { // ���� 1) �̸� ����

	this->name = c_name;
};

void Character::accelLevel() { // ���� 2) ������ (level + 1)

	level = level++;

	HP += 10;

	cout << "Level Up !!!" << endl << endl;

};

void Character::pickupItem() { // ���� 3) ������ �ݱ� (item_num + 1)

	item_num++;

	cout << "�������� ������ϴ�! " << endl;
};

void Character::useItem() { // ���� 4) ������ ��� (item_num - 1)

	item_num--;

	cout << "�������� ����߽��ϴ�!" << endl;
};


void Character::buyItem() { // ���� 5) ������ ����

	if (money >= 100) {

		item_num++;

		money -= 100;

		cout << "�������� �����߽��ϴ�! " << endl;
	}
	else {

		cout << "�Ӵϰ� �����մϴ�. �������� �������� ���߽��ϴ�." << endl;
	}
};

void Character::sellItem() { // ���� 6) ������ �Ǹ�
	char res;

	if (item_num > 0) {

		item_num--;

		money += 100;

		cout << "�������� �Ǹ��߽��ϴ�! " << endl;
	}
	else {

		cout << "�������� �Ǹ����� ���߽��ϴ�. " << endl;
	}

	if (money >= 1000) {

		cout << "1000 �Ӵϸ� �����ϰ� ĳ���͸� ��ȭ�Ͻðڽ��ϱ�? (Y/N �Է�): ";
		cin >> res;

		if (res == 'Y') {
		
			accelLevel();// level++
			money -= 1000;
		}
		else {}
	}
};

void Character::attack(int idx, vector<Character> vec) { // ���� 7) ����

	// ���� ���� ����� ��ġ �� ��� 1 ����, ��� ü�� 50 ����
	match++;

	// ���� ü���� 50�� �ȳ�����, ���ݴ��� �� ����.
	if (vec[idx].HP >= 50) {
	
		vec[idx].HP -= 50;
	}
	else {
		cout << vec[idx].getName() << "�÷��̾ ����߽��ϴ�. ����" << endl;

		vec.erase(vec.begin() + idx, vec.begin() + idx + 1);

	}


	vec[idx].match++;

	// ��ġ ���� 10�� ������ ������ ���� ��
	if (match > 0 && match%10 == 0) {

		accelLevel();
	}

	if (vec[idx].match > 0 && vec[idx].match % 10 == 0) {

		accelLevel();
	}
};

void Character::eliminateAll(int idx, vector<Character> vec) { // ���� 8) ����

	if (level >= 100) {

		// vec[idx], �� ���� ���� ���Ϳ��� �� ����

		vec.erase(vec.begin(), vec.begin() + idx);

		vec.erase(vec.begin() + idx + 1, vec.begin());

		cout << "���� ��� ������׽��ϴ�. ���ο� ���� ã������.";
	}
	else {
		cout << "���� 100 �̻� ������ �� �ִ� �����Դϴ�. �� Ű��������." << endl;
	}
};

void Character::selfDestructed(int idx, vector<Character> vec) { // ���� 9) �ڰ�

	// ���Ϳ��� ������ ����
	cout << vec[idx].getName() << "�÷��̾ �ڰ��߽��ϴ�. ����" << endl;

	vec.erase(vec.begin() + idx, vec.begin() + idx + 1);

};

void Character::prtInfo() { // ���� 10) ĳ������ ��� ���� ���

	cout << "�̸� : " << name << endl
		<< "���� : " << level << endl
		<< "���� ������ ���� : " << item_num << endl
		<< "���� ü�� : " << HP << endl
		<< "���� ��ġ �� : " << match << endl
		<< "������ �ڱ� : " << money << endl;
}
