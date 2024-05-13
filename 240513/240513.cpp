#include <iostream>
#include <string>

using namespace std;

class Rectangle {

private:
	float m_width = 0;
	float m_height = 0;

public:
	Rectangle() {}

	// 기본 생성자
	Rectangle(float w, float h) : m_width(w), m_height(h) {}

	// 복사 생성자
	Rectangle(const Rectangle& copy);

	float area(); // 클래스 내부에 선언만 해둠.

	float getWidth() {
		return m_width;
	}

	float getHeight() {
		return m_height;
	}

	void setWidth(float width) {

		this->m_width = width;
	}

	void setHeight(float height) {

		this->m_height = height;
	}

};

float Rectangle::area()
{
	return m_width * m_height;
}

int main() {
	float width, height;

	Rectangle Rec(1, 2);

	cout << "넓이는 : " << Rec.area() << endl; // 넓이

	cout << "사각형의 가로와 세로 길이를 입력하시오. (띄어쓰기로 구분): ";
	cin >> width >> height;

	Rec.setWidth(width);

	Rec.setHeight(height);

	cout << "넓이는 : " << Rec.area() << endl
		<< "가로 세로 길이는 : " << Rec.getWidth() << " " << Rec.getHeight();


	return 0;
}