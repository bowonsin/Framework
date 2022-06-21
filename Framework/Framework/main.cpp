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
// C++ 5����
// Ŭ����
// ** 1. ��������
	//������ �����ʹ� ������ ���� ������ �����ʹ�
/*
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
	//������ �����Ϳ� ����� ������ �ִ�.
	// �����Ϳ� ����� �Ѱ��� �������� ����ϴ� ��
// ** 3. �߻�ȭ
//		��ü�� �������� �ʴ� �߻����� Ŭ������ �߻� Ŭ���� ��� �Ѵ�.
//		��) ���, �л�, ���� ���� ����� Ư������ �ʴ� ��� ( �߻����� ���) 
//		��) ȫ�浿�� �л��̴�. ��� ȫ�浿 �̶�� Ư�� ����� �����Ƿ�,
//			�߻��� ���·� �� �� ����.

// ** 4. ���
// ���
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
//		�پ��� ���·� ������ �� �ִ�.

/*
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

// ������ ������ �����Ͽ� ������ �̸��� �Լ��� ����� �� �ֵ��� ��.
//void Parent::Output() //Ŭ������ �̸��� ����ͼ� public�� �ִ� �Լ��� ����´�.
//{ cout << m_Number << endl; } 
/*
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
#pragma endregion 
