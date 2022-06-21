#include "Child.h"
#include "Bullet.h"

class AAA
{
protected:
	string m_str = "AAA";
public:
	void Output() { cout << m_str<< endl; }

};
class BBB : public AAA
{
private:
	string m_str = "BBB";
public:
	void Initialize() { m_str = "BBB"; }
	void Output() { cout << m_str<< endl; }

};
class CCC : public AAA
{
private:
	//string m_str = "AAA";

public:
	void Initialize() { m_str = "CCC"; }
	void Output() { cout << m_str << endl; }

};

const int ID_Child = 0;
const int ID_Bullet = 1;

int main(void)
{

	Parent* p[2];
	p[ID_Child] = new Child;
	p[ID_Bullet] = new Bullet;

	for (int i = 0; i < 2; ++i)
	{
		p[i]->Initialize();
		p[i]->Output();
	}

	return 0;
}
#pragma region C++
// C++ 5가지
// 클레스
// ** 1. 정보은닉
	//공개된 데이터는 누구나 수정 가능한 데이터다
/*
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
*/
// ** 2. 캡슐화
	//각각의 데이터와 기능이 나눠져 있다.
	// 데이터와 기능을 한곳에 묶음으로 사용하는 것
// ** 3. 추상화
//		객체가 존재하지 않는 추상적인 클래스를 추상 클래스 라고 한다.
//		예) 사람, 학생, 군인 등의 대상이 특정되지 않는 경우 ( 추상적인 경우) 
//		예) 홍길동은 학생이다. 라면 홍길동 이라는 특정 대상이 있으므로,
//			추상적 형태로 볼 수 없음.

// ** 4. 상속
// 상속
/*
class Parent
{
	// 접근 범위 키워드
private:
	// ** 자기 자신만 사용 가능

protected:
	// ** 상속간의 공개된 상태 . 비상속 클레스 사용불가. 외부 사용 불가.

public:
	// ** 공개된 상태
	int m_Number;

};

class Child : public Parent
{
};
*/

// ** 5. 다형성
//		다양한 형태로 존재할 수 있다.

/*
//모든 객체는 클레스가 될수 있지만
//모든 클레스는 객체가 될 수 있다. (추상 클레스가 존재하기 떄문에 )
	Parent* p[2];

	const int c = 0;
	const int b = 1;

	p[c] = new Child;
	p[b] = new Bullet;

	for (int i = 0; i < 2; ++i)
	{
		p[i]->Initialize();
		p[i]->Output();
	}

	//Parent* d = new Child;
	//((Child*)d)->Initialize(); // 부모의 형태에서 자식의 함수 또는 값을 쓰기 위해서 사용
	//((Child*)d)->Output(); //
	*/

//** 6. namespace 

// 별도의 영역을 지정하여 동일한 이름의 함수를 사용할 수 있도록 함.
//void Parent::Output() //클레스의 이름을 끌어와서 public에 있는 함수를 끌어온다.
//{ cout << m_Number << endl; } 
/*
namespace AAA
{
	void Output(){cout << "홍길동" << endl;}
}
namespace BBB
{
	void Output() { cout << "임꺽정" << endl; }
}

using AAA::Output;
*/

// ** 7. 생성자 , 복사 생성자
#pragma endregion 
