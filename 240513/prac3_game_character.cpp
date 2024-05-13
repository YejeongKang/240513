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

	// �⺻ ������
	Character(string c_name) : name(c_name), level(0), item_num(0) {}

	// �޼ҵ� ����
	void setName(string c_name); // ���� 1 �̸� ����
	void accelLevel(); // ���� 2 ������ 
	void pickupItem(); // ���� 3 ������ �ݱ�
	void useItem(); // ���� 4 ������ ���
	
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

void Character::setName(string c_name) { // ���� 1 �̸� ����

	this->name = c_name;
};

void Character::accelLevel() { // ���� 2 ������ (level + 1)

	this->level = level++;
}; 

void Character::pickupItem() { // ���� 3 ������ �ݱ� (item_num + 1)
	
	this->item_num++;
}; 

void Character::useItem() { // ���� 4 ������ ��� (item_num - 1)
	
	this->item_num--;
}; 


int main() {
	string c_name;
	int manipulating; // ĳ���͸� ��� �������� �޴� case ����
	
	cout << "����� ĳ������ �̸��� �Է��Ͻÿ�. : ";
	cin >> c_name;

	// ��ü ���� 
	Character GameSet(c_name);

	// ����ڰ� ���� ���Ḧ ���ϱ�(0 �Է�) ������ ������ �Է¹ޱ�
	while (1) {
		
		cout << endl << "� ������ �����Ͻðڽ��ϱ�? (0 ����): ";
		/*<< "1) �̸� ����" << endl
		<< "2) level up" << endl
		<< "3) item �Ĺ�!" << endl
		<< "4) item ���" << endl
		<< "5) �̸�, level, item ���" << endl
		<< "0) ���� ����" << endl*/

		cin >> manipulating;

		switch (manipulating) {

		case 1:

			cout << "�� �̸��� �Է����ּ��� : ";

			cin >> c_name;

			// �̸� �����ϴ� �Լ� ȣ��
			GameSet.setName(c_name);

			// �̸� ��ȯ���ִ� �Լ� ȣ���ؼ� ����� �̸� Ȯ��
			cout << endl << "�̸��� ����Ǿ����ϴ�." << endl << "new name : " << GameSet.getName() << endl;

			break;

		case 2:
			
			GameSet.accelLevel();
			
			cout << "Level Up !!!" << endl;

			break;

		case 3:

			GameSet.pickupItem();

			cout << "�������� ������ϴ�! " << endl << "���� ������ ���� : " << 
				GameSet.getItemNum() << endl;

			break;

		case 4:

			GameSet.useItem();

			cout << "�������� ����߽��ϴ�!" << endl << "���� ������ ���� : " <<
				GameSet.getItemNum() << endl;;
			
			break;

		case 5:

			cout << "�̸� : " << GameSet.getName() << endl
			<< "���� : " << GameSet.getLevel() << endl
			<< "���� ������ ���� : " << GameSet.getItemNum() << endl;

			break;
	
		case 0:

			cout << "������ �����մϴ�." << endl;

			return 0;

			break;
		}
	}



	return 0;
}

