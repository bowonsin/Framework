#include "MainUpdate.h"
#include "Headers.h"

int main(void)
{
	system("title ȫ�浿 - ���Ӹ�");

	system("mode con cols= 120 line=30"); //  �ܼ�â 120  30 ���� ����
	

	MainUpdate Main;
	Main.Initialize();
	
	ULONGLONG Time = GetTickCount64();// 1/ 1000;
	while (true)
	{
		if (Time + 50 < GetTickCount64()) //Time + 50 < GetTickCount64() 0.05 �� + 
		{
			Time = GetTickCount64();
			system("cls");
			Main.Update();
			Main.Render();

		}
	}
	

	return 0;
}

#pragma region C++ �����Ѱ�
// C++ 5����

// ** 1. ��������
/*
//������ �����ʹ� ������ ���� ������ �����ʹ�
struct AAA //  ����ü�� �⺻�� public�̴�
{
	int Number = 0;
};


class BBB // class �� private�� �⺻�̴�.
{
private: //-> c������ ����Ҽ� ������.
	int m_iNumber;

public:
	void Initialize(){m_iNumber = 0;	}
	//** �����͸� ����ϴ� ���� ���������� ������ �Ұ�.
	int GetNumber() { return m_iNumber; }

	//** �����͸� �����ϴ� ���� ���������� ������ �Ұ�.
	void SetNumber(int _Number)	{ m_iNumber = _Number;	}
};

class CCC// class �� private�� �⺻�̴�.
{
private: //-> c������ ����Ҽ� ������.
	int m_iNumber;

public:
	void Initialize() { m_iNumber = 100; }
	//** �����͸� ����ϴ� ���� ���������� ������ �Ұ�.
	int GetNumber() { return m_iNumber; }

	//** �����͸� �����ϴ� ���� ���������� ������ �Ұ�.
	void SetNumber(int _Number) { m_iNumber = _Number; }
};

*/

// ** 2. ĸ��ȭ
/*
	//������ �����Ϳ� ����� ������ �ִ�.
	// �����Ϳ� ����� �Ѱ��� �������� ����ϴ� ��
*/

// ** 3. �߻�ȭ
/*
	��ü�� �������� �ʴ� �߻����� Ŭ������ �߻� Ŭ���� ��� �Ѵ�.
	��) ���, �л�, ���� ���� ����� Ư������ �ʴ� ��� ( �߻����� ���) 
	��) ȫ�浿�� �л��̴�. ��� ȫ�浿 �̶�� Ư�� ����� �����Ƿ�,
		�߻��� ���·� �� �� ����.
*/

// ** 4. ���
/*
class Parent
{
	// ���� ���� Ű����
private:
	// ** �ڱ� �ڽŸ� ��� ����

protected:
	// ** ��Ӱ��� ������ ���� . ���� Ŭ���� ���Ұ�. �ܺ� ��� �Ұ�.

public:
	// ** ������ ����
	int m_Number;

};

class Child : public Parent
{
};
*/

// ** 5. ������
/*
//		�پ��� ���·� ������ �� �ִ�.
//��� ��ü�� Ŭ������ �ɼ� ������
//��� Ŭ������ ��ü�� �� �� �ִ�. (�߻� Ŭ������ �����ϱ� ������ )
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
	//((Child*)d)->Initialize(); // �θ��� ���¿��� �ڽ��� �Լ� �Ǵ� ���� ���� ���ؼ� ���
	//((Child*)d)->Output(); //
	*/

//** 6. namespace 
/*
// ������ ������ �����Ͽ� ������ �̸��� �Լ��� ����� �� �ֵ��� ��.
//void Parent::Output() //Ŭ������ �̸��� ����ͼ� public�� �ִ� �Լ��� ����´�.
//{ cout << m_Number << endl; } 
namespace AAA
{
	void Output(){cout << "ȫ�浿" << endl;}
}
namespace BBB
{
	void Output() { cout << "�Ӳ���" << endl; }
}

using AAA::Output;
*/

// ** 7. ������ , ���� ������
/*
class Object
{
private:
public:
	int Number;
	char* Name;
	// ** ����ڰ� ȣ������ �ʾƵ� ������ ȣ���.
	// ** Ŭ���� ������ ���� ȣ��..
	Object()
	{
		//cout << "������" << endl;
	};

	// ** ����ڰ� ȣ�� �ϴ� ������ ȣ���.
	// ** ���ް��� ������ �ڷ����� ���� ������(�ڵ�)���� ȣ�� ��.
	Object(int _Number)
	{
		cout << "���� ������ int" << endl;
		Number = _Number;
	};
	Object(float _Number)
	{
		cout << "���� ������ float" << endl;
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

	// ** Ŭ������ �����Ǳ� ����.
	~Object()
	{
		//cout << "�Ҹ���" << endl;
	};
};
//Object o = Object ();
	// Object o; �� ������ ����
	// �� Object o(10) �̳� Object o = Object(10) �� ����
	Object o1;
	o1.Number = 10;
	o1.Name = (char*)"ȫ�浿";

	Object o2 = Object(o1);

	o1.Name = (char*)"�Ӳ���";


	cout << o2.Number << endl;
	cout << o2.Name<< endl;
*/
// ** 8. �������� ���� ����-> �̰Ŵ� �� �ڼ��� �˾ƺ���

// ** 9. �����ε� & �������̵�
/*
	�����ε��� ���� �����ڿ� ���� 
	�Ű� ������ ���¿� ������ �޶������ ���� �̸����� ���� �� �ִ�.

	�������̵��� ��Ӱ� ����ؼ�
	�θ� Ŭ�������� ���Ǵ� �Լ��� �̸��� ������ �ڽ� Ŭ������ ���� ����Ѵ�.
*/

// ���ƺ���
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

	virtual Object* Clone() = 0; // Clone �� �ٽ��ѹ� Ȯ���ϰ� ����ϱ�
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

	 ���� �ϳ� Ȯ���� �ۺ���
	 main()
	tagInfo Info;

	Info.Number = 10;
	prototypeObject["Player"] = new Player(Info);

	Object* pProtoObj= GetObject("Player");
	Object* pPlayer = nullptr;

	if (pProtoObj != nullptr)
		pPlayer = pProtoObj;
*/

// ** 10.������ �����ε� 
/* -- ������ ������ github Ȯ�� �غ���
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
	Object(tagInfo _tag) :m_tag(_tag) {} //���� ������
	~Object() {};
};

*/

// ** 11. ������ (����) & ĸ��ȭ 
/*
	1. * ������ , & �ּҹ�ȯ ������
	2. �����ͺ��� ��� [�����Ҵ�]
	3. Ŭ���� & ����ü�� .(��) �ƴϸ� ->(ȭ��ǥ)�� ����
	Parent* pParent = new Child;
	(  ���� ����  )   ( �� ���� )  

	4. [�����Ҵ�] �ߵ��� �ݵ�� [�Ҵ� ����]
*/

// ** �ζ��� �Լ� 
/*
	���� ���� �� �� �ֵ��� �����Ѵ�.
	Ŭ���� �Լ��� cpp�ȿ� ���� .h�� �ִ� �Լ���
	class �̸�
	{
		�Լ� ()
		{
		}
		�̷��� �Ǿ������� �ζ��� �Լ��� ���Եȴ�.
	}
*/

// ** const 
/*
	const ����� Ű�d,
	void setnumber(const int& _Number){ m_Number = _Number;}���� 
	_Number ���� ��ü�ǰų� ���� ���� ���ƾ� �ϴ� ��쿡 const ���� ����Ѵ�.
	������ �ڵ� �۾��� ���� �ش޶�� �ϴ� ǥ�� ���� const �� ����ϴ� �� ���� �ִ�

	int GetNumber()	{return m_Number;}
	�� �Լ����� return m_Number �� ���� �ǵ��� ����� �ϸ�
	int Getnumber() const{return m_Number;} �� ����ص� �ȴ�.
	const <= ���ȭ Ű����

*/

// ** & ������ ��� �ñ�
/*
	& ������ ���� �����ڷ� ���ɶ� �ּ� ��ȯ�����ڷ� ��� �ȴ�.
	���۷��� ������ -> ������ Ÿ�Կ� �پ��ִ�. ( C++ ���� ���� ������ �� ��� ) 
	���۷��� Ű���带 ����� ������ const Ű���带 ����ϴ°� ��ü���̴�.
	void setnumber(const int& _Number){ m_Number = _Number;} -> �̰�� 

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
//Ŭ������ ������ Ŭ���� �̸��� ��
// �Լ� �� ������ �Լ� ���� ���̸� �ȴ�.
//A* a = Temp<A>::Func();
template <typename T>
class Temp
{
public:
	// �ڷ����� ������ �Ű������̴�.
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