#include <iostream>
#include <string>
#include <vector>

#include "Character.h"
#include "MyFunc.h"

using namespace std;

namespace findData {

	// Ư�� ���ڿ��� �̸��� ��ġ�ϴ� �ν��Ͻ��� ������ �� ��° �ε����� �����ϴ��� ��ȯ���ִ� �Լ�
	int getIndex(string name, vector<Character> vec) {
		bool flag = false;

		for (int i = 0; i < vec.size(); i++) {
			if (vec[i].getName() == name) {
				flag = true;
				return i;
				//break;
			}
			else {}
		}		

		if (!flag) {
			return -1;
		}
	}
}