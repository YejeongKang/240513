#include "Character.h"
#include "myFunc.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
using namespace findData;

/* 기능 추가 */ // ~현재진행
// 예외 처리 (아이템 사용/구매/판매) ~ㅇㅋ
// 필드 추가 (체력, 돈) ~ㅇㅋ
// 메소드 추가 (아이템 구매/판매, 공격, 전멸, 자결) 아이템까지만 ~ㅇㅋ
// 기능 추가 (객체 선택, 레벨 업하면 체력 증가, 돈 많거나 스탯 쌓으면 레벨 업, 체력 0 되면 소멸) ~체력 ㄴㄴ


int main() {

	int idx;
	int manipulating; // 캐릭터를 어떻게 조작할지 받는 case 변수
	int damagedIDX;
	string c_name; // 사용자가 사용하고자 하는 캐릭터 이름 
	string status; // Login 화면에서 벗어나지 않았으면 ON, OFF 시 게임 종료
	vector<Character> players; // 사용자가 지금껏 등록한 계정(인스턴스)을 담아두는 벡터
	

	while (1) {
		status = "ON";

		std::cout << "[HOST] 사용할 캐릭터의 이름을 입력하시오. (0 입력 시 종료) : ";
		std::cin >> c_name;

		if (c_name == "0")
		{
			break;
		}

		else {
			// players 명단의 몇 번 인덱스에 c_name이 있는지 확인(회원가입 되어있는지 확인 후 접속)
			idx = getIndex(c_name, players);

			if (idx != -1) {

				// 계정이 존재함, 로그인한 계정의 정보 출력해주기
				players[idx].prtInfo();
			}
			else { // 계정이 없기 때문에 인스턴스를 새로 만듬.(변수 이름 NA)
				Character NA(c_name);

				cout << "계정 생성!" << endl;

				// 값 비교를 하기 위해 벡터에 인스턴스 추가.
				players.push_back(NA);

				// 벡터의 마지막에 넣었기 때문에.
				// switch 문에서 접근하기 위해 인덱스 기록
				idx = players.size() - 1;
			}
		}

		// 사용자가 게임 종료를 원하기(0 입력) 전까지 동작을 입력받기
		while (status == "ON") {

			cout << endl << "[HOST] 어떤 동작을 실행하시겠습니까? (0 종료): ";
			/*<< "1) 이름 변경" << endl
			<< "2) level up" << endl
			<< "3) item 파밍!" << endl
			<< "4) item 사용" << endl
			<< "5) 이름, level, item 출력" << endl
			<< "0) 게임 종료" << endl*/

			cin >> manipulating;

			switch (manipulating) {

			case 1:

				// players 명단에 이름이 있는지 확인하고 인덱스 받아오기
				idx = getIndex(c_name, players);

				cout << "새 이름을 입력해주세요 : ";

				cin >> c_name;

				players[idx].setName(c_name);

				// 이름 변경하는 함수 호출
				players[idx].setName(c_name);

				// 이름 반환해주는 함수 호출해서 변경된 이름 확인
				cout << endl << "이름이 변경되었습니다." << endl << "new name : " << players[idx].getName() << endl << endl;

				break;

			case 2:

				players[idx].accelLevel();

				break;

			case 3:

				players[idx].pickupItem();

				cout << "현재 아이템 개수 : " <<	players[idx].getItemNum() << endl << endl;

				break;

			case 4:

				// 예외 처리(아이템이 없으면 사용하지 못함)
				if (players[idx].getItemNum() > 0) {

					players[idx].useItem();

					cout << "현재 아이템 개수 : " << players[idx].getItemNum() << endl << endl;;

				}
				else {
					cout << "사용할 아이템이 없습니다!" << endl << endl;
				}

				break;
				
			case 5:

				players[idx].buyItem();

				cout << "현재 아이템 개수 : " << players[idx].getItemNum() << endl
					<< "현재 보유한 돈 : " << players[idx].getMoney() << endl << endl;

				break;

			case 6:

				players[idx].sellItem();

				cout  << "현재 아이템 개수 : " << players[idx].getItemNum() << endl
					<< "현재 보유한 돈 : " << players[idx].getMoney() << endl << endl;

				break;

			case 7:
				cout << "공격할 캐릭터의 이름을 입력해주세요. : ";
				cin >> c_name;

				damagedIDX = getIndex(c_name, players);

				players[idx].attack(damagedIDX,players);
				
				cout << "[NOTICE] " << players[damagedIDX].getName() << "이(가) 공격받았습니다 !!! HP 50 감소 !!!";

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

				// players 명단 출력
				cout << "[현재 접속 중인 플레이어]" << endl;

				for (Character player : players) {

					cout << player.getName() << " " << endl;
				}
				cout << endl << endl;
				break;

			case 0:
				 
				cout << "게임을 종료합니다." << endl;

				status = "OFF";

				break;

			default:

				cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;

				break;
			}
		}
	}
}

