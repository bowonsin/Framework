#pragma once
#include "Headers.h"
class Parent
{

	// ���� ���� Ű����
private:
	// ** �ڱ� �ڽŸ� ��� ����

protected:
	// ** ��Ӱ��� ������ ���� . ���� Ŭ���� ���Ұ�. �ܺ� ��� �Ұ�.
	int m_Number = 0;

public:

	void Update()
	{

	}
	
	virtual void Initialize() = 0;
	// ** ������ ����
	virtual void Output() = 0;

	// ** [virtual ] = �����Լ� 
	// ** [= 0] : virtual �Լ����� ���� �� �ִ�.
	// ** �Լ��� ���� [= 0] ���̰� �Ǹ� [���� ���� �Լ�] �� �ȴ�.
	
	// ** [���� ���� �Լ�]
	// ** virtual  �Լ��� �Լ��� ��ü(����) �� ���� �� ����Ѵ�.

	// ** virtual �Լ��� ����ϴ� ����?
	// ** ���� �����Լ� ��� ���� �˻�

};

