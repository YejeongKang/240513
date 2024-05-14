#include "Character.h"
#include "myFunc.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
using namespace findData;

/* ��� �߰� */ // ~��������
// ���� ó�� (������ ���/����/�Ǹ�) ~����
// �ʵ� �߰� (ü��, ��) ~����
// �޼ҵ� �߰� (������ ����/�Ǹ�, ����, ����, �ڰ�) �����۱����� ~����
// ��� �߰� (��ü ����, ���� ���ϸ� ü�� ����, �� ���ų� ���� ������ ���� ��, ü�� 0 �Ǹ� �Ҹ�) ~ü�� ����


int main() {

	int idx;
	int manipulating; // ĳ���͸� ��� �������� �޴� case ����
	int damagedIDX;
	string c_name; // ����ڰ� ����ϰ��� �ϴ� ĳ���� �̸� 
	string status; // Login ȭ�鿡�� ����� �ʾ����� ON, OFF �� ���� ����
	vector<Character> players; // ����ڰ� ���ݲ� ����� ����(�ν��Ͻ�)�� ��Ƶδ� ����
	

	while (1) {
		status = "ON";

		std::cout << "[HOST] ����� ĳ������ �̸��� �Է��Ͻÿ�. (0 �Է� �� ����) : ";
		std::cin >> c_name;

		if (c_name == "0")
		{
			break;
		}

		else {
			// players ����� �� �� �ε����� c_name�� �ִ��� Ȯ��(ȸ������ �Ǿ��ִ��� Ȯ�� �� ����)
			idx = getIndex(c_name, players);

			if (idx != -1) {

				// ������ ������, �α����� ������ ���� ������ֱ�
				players[idx].prtInfo();
			}
			else { // ������ ���� ������ �ν��Ͻ��� ���� ����.(���� �̸� NA)
				Character NA(c_name);

				cout << "���� ����!" << endl;

				// �� �񱳸� �ϱ� ���� ���Ϳ� �ν��Ͻ� �߰�.
				players.push_back(NA);

				// ������ �������� �־��� ������.
				// switch ������ �����ϱ� ���� �ε��� ���
				idx = players.size() - 1;
			}
		}

		// ����ڰ� ���� ���Ḧ ���ϱ�(0 �Է�) ������ ������ �Է¹ޱ�
		while (status == "ON") {

			cout << endl << "[HOST] � ������ �����Ͻðڽ��ϱ�? (0 ����): ";
			/*<< "1) �̸� ����" << endl
			<< "2) level up" << endl
			<< "3) item �Ĺ�!" << endl
			<< "4) item ���" << endl
			<< "5) �̸�, level, item ���" << endl
			<< "0) ���� ����" << endl*/

			cin >> manipulating;

			switch (manipulating) {

			case 1:

				// players ��ܿ� �̸��� �ִ��� Ȯ���ϰ� �ε��� �޾ƿ���
				idx = getIndex(c_name, players);

				cout << "�� �̸��� �Է����ּ��� : ";

				cin >> c_name;

				players[idx].setName(c_name);

				// �̸� �����ϴ� �Լ� ȣ��
				players[idx].setName(c_name);

				// �̸� ��ȯ���ִ� �Լ� ȣ���ؼ� ����� �̸� Ȯ��
				cout << endl << "�̸��� ����Ǿ����ϴ�." << endl << "new name : " << players[idx].getName() << endl << endl;

				break;

			case 2:

				players[idx].accelLevel();

				break;

			case 3:

				players[idx].pickupItem();

				cout << "���� ������ ���� : " <<	players[idx].getItemNum() << endl << endl;

				break;

			case 4:

				// ���� ó��(�������� ������ ������� ����)
				if (players[idx].getItemNum() > 0) {

					players[idx].useItem();

					cout << "���� ������ ���� : " << players[idx].getItemNum() << endl << endl;;

				}
				else {
					cout << "����� �������� �����ϴ�!" << endl << endl;
				}

				break;
				
			case 5:

				players[idx].buyItem();

				cout << "���� ������ ���� : " << players[idx].getItemNum() << endl
					<< "���� ������ �� : " << players[idx].getMoney() << endl << endl;

				break;

			case 6:

				players[idx].sellItem();

				cout  << "���� ������ ���� : " << players[idx].getItemNum() << endl
					<< "���� ������ �� : " << players[idx].getMoney() << endl << endl;

				break;

			case 7:
				cout << "������ ĳ������ �̸��� �Է����ּ���. : ";
				cin >> c_name;

				damagedIDX = getIndex(c_name, players);

				players[idx].attack(damagedIDX,players);
				
				cout << "[NOTICE] " << players[damagedIDX].getName() << "��(��) ���ݹ޾ҽ��ϴ� !!! HP 50 ���� !!!";

				break;

			case 8:

				players[idx].eliminateAll(idx, players);

				break;

			case 9:

				players[idx].selfDestructed(idx, players);

				break;

			case 10:

				players[idx].prtInfo();

				break;

			case 11:

				// players ��� ���
				cout << "[���� ���� ���� �÷��̾�]" << endl;

				for (Character player : players) {

					cout << player.getName() << " " << endl;
				}
				cout << endl << endl;
				break;

			case 0:
				 
				cout << "������ �����մϴ�." << endl;

				status = "OFF";

				break;

			default:

				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;

				break;
			}
		}
	}
}

