#include <iostream>
//framework ver0.1 2022-06-20
using namespace std;

struct AAA //  구조체는 기본이 public이다
{
	int Number = 0;
};


class BBB // class 는 private가 기본이다.
{
private: //-> c에서는 사용할순 없ㄷ음.
	int m_iNumber;

public:
	void Initialize(){m_iNumber = 0;	}
	//** 데이터를 사용하는 것은 가능하지만 수정은 불가.
	int GetNumber() { return m_iNumber; }

	//** 데이터를 수정하는 것은 가능하지만 참조는 불가.
	void SetNumber(int _Number)	{ m_iNumber = _Number;	}
};

class CCC// class 는 private가 기본이다.
{
private: //-> c에서는 사용할순 없ㄷ음.
	int m_iNumber;

public:
	void Initialize() { m_iNumber = 100; }
	//** 데이터를 사용하는 것은 가능하지만 수정은 불가.
	int GetNumber() { return m_iNumber; }

	//** 데이터를 수정하는 것은 가능하지만 참조는 불가.
	void SetNumber(int _Number) { m_iNumber = _Number; }
};


int main(void)
{
	AAA a;
	a.Number;

	BBB b;
	// b.Number 바로 사용할 수 없음.
	b.Initialize();
	b.SetNumber(10);
	cout << b.GetNumber() << endl;

	CCC c;
	// b.Number 바로 사용할 수 없음.
	c.Initialize();
	cout << c.GetNumber() << endl;


	return 0;
}
/*
// C++ 5가지
// 클레스
// ** 1. 정보은닉
	공개된 데이터는 누구나 수정 가능한 데이터다
// ** 2. 캡슐화
	각각의 데이터와 기능이 나눠져 있다.
// ** 3. 추상화
	포괄적인 의미
// ** 4. 상속
// ** 5. 다형성
모든 객체는 클레스가 될수 있지만
모든 클레스는 객체가 될 수 있다. (추상 클레스가 존재하기 떄문에 )
*/
