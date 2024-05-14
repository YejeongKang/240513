#include <iostream>
#include <string>
#include <vector>

#include "Character.h"
#include "MyFunc.h"

using namespace std;

namespace findData {

	// 특정 문자열과 이름이 일치하는 인스턴스가 벡터의 몇 번째 인덱스에 존재하는지 반환해주는 함수
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