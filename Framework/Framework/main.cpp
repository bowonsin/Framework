#include <iostream>
//framework ver0.1 2022-06-20
using namespace std;

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


int main(void)
{
	AAA a;
	a.Number;

	BBB b;
	// b.Number �ٷ� ����� �� ����.
	b.Initialize();
	b.SetNumber(10);
	cout << b.GetNumber() << endl;

	CCC c;
	// b.Number �ٷ� ����� �� ����.
	c.Initialize();
	cout << c.GetNumber() << endl;


	return 0;
}
/*
// C++ 5����
// Ŭ����
// ** 1. ��������
	������ �����ʹ� ������ ���� ������ �����ʹ�
// ** 2. ĸ��ȭ
	������ �����Ϳ� ����� ������ �ִ�.
// ** 3. �߻�ȭ
	�������� �ǹ�
// ** 4. ���
// ** 5. ������
��� ��ü�� Ŭ������ �ɼ� ������
��� Ŭ������ ��ü�� �� �� �ִ�. (�߻� Ŭ������ �����ϱ� ������ )
*/
