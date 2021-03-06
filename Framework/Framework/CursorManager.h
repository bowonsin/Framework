#pragma once
#include "Headers.h"

class CursorManager
{
private:
	static CursorManager* Instance;

public:
	static CursorManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new CursorManager;

		return Instance;
	}
private:
	
	int BufferIndex;	// ** 버퍼의 인덱스 접근을 위한 변수 
	HANDLE hBuffer[2];	// ** 2개의 버퍼

public:
	void CreateBuffer(const int& _Width, const int& _Height);	// ** 버퍼를 생성
	void WriteBuffer(float _x, float _y, char* _str, int _Color = 15);	// ** 그리기 버퍼
	void WriteBuffer(float _x, float _y, int _Value, int _Color = 15);	// ** 그리기 버퍼
	void WriteBuffer(Vector3 _Position, char* _str, int _Color = 15);	// ** 그리기 버퍼
	void WriteBuffer(Vector3 _Position, int _Value, int _Color = 15);
	void FlippingBuffer();	// ** 버퍼 전환
	void ClearBuffer();		// ** 그려진 내용 삭제
	void DestoryBuffer();	// ** 버퍼 해제
	void SetColor(int _Color);
	void Draw(float _x, float _y, string str);
private:
	CursorManager();
public:
	~CursorManager();
};

