#include "MainUpdate.h"
#include "Headers.h"

int main(void)
{
	system("title 홍길동 - 게임명");

	system("mode con cols= 120 line=30"); //  콘솔창 120  30 으로 고정
	

	MainUpdate Main;
	Main.Initialize();
	
	ULONGLONG Time = GetTickCount64();// 1/ 1000;
	while (true)
	{
		if (Time + 50 < GetTickCount64()) //Time + 50 < GetTickCount64() 0.05 초 + 
		{
			Time = GetTickCount64();
			system("cls");
			Main.Update();
			Main.Render();

		}
	}
	

	return 0;
}

#pragma region C++ 볼만한거
// C++ 5가지

// ** 1. 정보은닉
/*
//공개된 데이터는 누구나 수정 가능한 데이터다
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
/*
	//각각의 데이터와 기능이 나눠져 있다.
	// 데이터와 기능을 한곳에 묶음으로 사용하는 것
*/

// ** 3. 추상화
/*
	객체가 존재하지 않는 추상적인 클래스를 추상 클래스 라고 한다.
	예) 사람, 학생, 군인 등의 대상이 특정되지 않는 경우 ( 추상적인 경우) 
	예) 홍길동은 학생이다. 라면 홍길동 이라는 특정 대상이 있으므로,
		추상적 형태로 볼 수 없음.
*/

// ** 4. 상속
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
/*
//		다양한 형태로 존재할 수 있다.
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
/*
// 별도의 영역을 지정하여 동일한 이름의 함수를 사용할 수 있도록 함.
//void Parent::Output() //클레스의 이름을 끌어와서 public에 있는 함수를 끌어온다.
//{ cout << m_Number << endl; } 
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
/*
class Object
{
private:
public:
	int Number;
	char* Name;
	// ** 사용자가 호출하지 않아도 스스로 호출됨.
	// ** 클레스 생성된 직후 호출..
	Object()
	{
		//cout << "생성자" << endl;
	};

	// ** 사용자가 호출 하는 시점에 호출됨.
	// ** 전달값의 개수와 자료형에 따라서 선택적(자동)으로 호출 됨.
	Object(int _Number)
	{
		cout << "복사 생성자 int" << endl;
		Number = _Number;
	};
	Object(float _Number)
	{
		cout << "복사 생성자 float" << endl;
		Number = (float)_Number;
	};
	Object(char* _Name)
	{
		Name= _Name;
	};

	Object(Object* Obj)
	{
		Name = Obj->Name;

		Name = new char[strlen(Obj->Name) + 1];
		Number = Obj-> Number;
	};

	// ** 클레스가 삭제되기 직전.
	~Object()
	{
		//cout << "소멸자" << endl;
	};
};
//Object o = Object ();
	// Object o; 는 위에와 같다
	// 즉 Object o(10) 이나 Object o = Object(10) 과 같다
	Object o1;
	o1.Number = 10;
	o1.Name = (char*)"홍길동";

	Object o2 = Object(o1);

	o1.Name = (char*)"임꺽정";


	cout << o2.Number << endl;
	cout << o2.Name<< endl;
*/
// ** 8. 깊은복사 앝은 복사-> 이거는 더 자세히 알아보기

// ** 9. 오버로딩 & 오버라이딩
/*
	오버로딩은 복사 생성자와 같고 
	매개 변수의 형태와 개수가 달라야지만 같은 이름으로 나눌 수 있다.

	오버라이딩은 상속과 비슷해서
	부모 클레스에서 사용되는 함수를 이름이 같으면 자식 클레스의 것을 사용한다.
*/

// 돌아보기
/*
struct tagInfo
{
	int Number;
};
class Object
{
protected:
	tagInfo m_Info;
public:
	Object() {};
	Object(tagInfo _info) : m_Info(_info) {}

	virtual Object* Clone() = 0; // Clone 을 다시한번 확인하고 기억하기
};

class Player: public Object
{
public:

	virtual Object* Clone() override{return new Player(*this);}

	void Output(){cout << m_Info.Number << endl;}
	Player(tagInfo _Info) :Object(_Info) {}
	Player() {};
	~Player() {};
};

map<string, Object*> prototypeObject;
Object* GetObject(string _Key);

Object* GetObject(string _Key)
{
	map<string, Object*>::iterator iter = prototypeObject.find(_Key);

	if (iter == prototypeObject.end())
		return nullptr;
	else
		return iter->second;
}

	 예제 하넌 확실히 퍼보기
	 main()
	tagInfo Info;

	Info.Number = 10;
	prototypeObject["Player"] = new Player(Info);

	Object* pProtoObj= GetObject("Player");
	Object* pPlayer = nullptr;

	if (pProtoObj != nullptr)
		pPlayer = pProtoObj;
*/

// ** 10.연산자 오버로딩 
/* -- 오류남 선생님 github 확인 해보기
main
{
	Object o1(tagInfo(10));
	Object o2(01);

	o2 += o1;
	++o2;
	o2.Output();
	
}

struct tagInfo
{
	int Number;

	tagInfo() {};
	tagInfo(int _Number): Number(_Number){};
	~tagInfo() {};
};
	
class Object
{
private:
	tagInfo m_tag;
public:
	Object& operator+=(const Object& _Obj);
	{
		m_tag.Number += _Obj.Info.Number;
		return this*;
	}
	Object& operator++();
	{
		m_tag.Number += 1;
		return this*;
	}

	void Output() { cout << m_tag.Number << endl; };
	Object() {};
	Object(tagInfo _tag) :m_tag(_tag) {} //복사 생성자
	~Object() {};
};

*/

// ** 11. 포인터 (복습) & 캡슐화 
/*
	1. * 데이터 , & 주소반환 연산자
	2. 포인터변수 라면 [동적할당]
	3. 클래스 & 구조체는 .(점) 아니면 ->(화살표)로 접근
	Parent* pParent = new Child;
	(  스택 영역  )   ( 힙 영역 )  

	4. [동적할당] 했따면 반드시 [할당 해제]
*/

// ** 인라인 함수 
/*
	먼저 실행 될 수 있도록 돕게한다.
	클레스 함수가 cpp안에 없고 .h에 있는 함수가
	class 이름
	{
		함수 ()
		{
		}
		이렇게 되어있으면 인라인 함수로 포함된다.
	}
*/

// ** const 
/*
	const 상수와 키웓,
	void setnumber(const int& _Number){ m_Number = _Number;}에서 
	_Number 값이 교체되거나 변경 되지 말아야 하는 경우에 const 값을 사용한다.
	협업시 코드 작업시 조심 해달라고 하는 표현 으로 const 를 사용하는 할 수도 있다

	int GetNumber()	{return m_Number;}
	이 함수에서 return m_Number 의 값을 건들지 말라고 하면
	int Getnumber() const{return m_Number;} 로 사용해두 된다.
	const <= 상수화 키워드

*/

// ** & 연산자 사용 시기
/*
	& 연산이 단항 연산자로 사양될때 주소 반환연산자로 사용 된다.
	레퍼런스 연산자 -> 데이터 타입에 붙어있다. ( C++ 에서 새로 나오게 된 기능 ) 
	레퍼런스 키워드를 사용할 때에는 const 키워드를 사용하는게 대체적이다.
	void setnumber(const int& _Number){ m_Number = _Number;} -> 이경우 

*/

#pragma endregion 

#pragma region SingleTon
// ** Singleton
/*
class Singleton
{
private:
	static Singleton * Instance;
	Singleton() {}
	Singleton() :Number(10) {}

	int Number;

public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Singleton;

		return Instance;
	}

	int GetNumber() const { return Number; }
	void SetNumber(const int& _Number) { Number = _Number; }

	~Singleton() {}
};
Singleton* Singleton::Instance = nullptr;
*/
#pragma endregion 

#pragma region input

// ** Input

/*
	

*/

#pragma endregion

/*
//클래스에 붙으면 클레스 이름의 끝
// 함수 에 부으면 함수 끝에 붙이면 된다.
//A* a = Temp<A>::Func();
template <typename T>
class Temp
{
public:
	// 자료형을 보내는 매개변수이다.
	//A* a = Temp::Func<A>();
	template <typename T1>
	static T* Func()
	{
		return new T;
	}
	static T* Func(int i)
	{
		return new T;
	}
	static T* Func(float i)
	{
		return new T;
	}

};
class B
{
public:
	int Number;
};

class A
{
public:
	int Number;
};
	A* a = Temp<A>::Func<B>();

	a->Number = 10;
	*/