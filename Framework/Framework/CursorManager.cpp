#include "CursorManager.h"

CursorManager::CursorManager() :BufferIndex(0){}
CursorManager::~CursorManager() { DestoryBuffer(); }

CursorManager* CursorManager::Instance = nullptr;

void CursorManager::CreateBuffer(const int& _Width, const int& _Height)
{
	// ** 커서 설정
	CONSOLE_CURSOR_INFO Cursor;


	Cursor.bVisible = FALSE;	// ** 커서를 안보이게함
	Cursor.dwSize = 1;			// ** 커서의 사이즈 설정

	COORD Size = {(SHORT)_Width, (SHORT)_Height}; // ** 생성할때 쓸 사이즈 설정
	SMALL_RECT rect = { (SHORT)0,(SHORT)0,(SHORT)_Width,(SHORT)_Height }; // ** Rect 는 버퍼 사이즈로 

	for (int i = 0; i < 2; ++i) // ** 텍스트 문서 
	{
		// ** 버퍼 생성
		hBuffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

		// ** 버퍼 사이즈 설정
		SetConsoleScreenBufferSize(hBuffer[i], Size);

		// * 버퍼가 포함될 윈도우 사이즈 설정
		SetConsoleWindowInfo(hBuffer[i], TRUE, &rect);

		// ** 커서 샛팅
		SetConsoleCursorInfo(hBuffer[i], &Cursor);

	}

}

void CursorManager::WriteBuffer(float _x, float _y, char* _str, int _Color)
{
	DWORD dw;

	COORD CurSorPosition = { (SHORT) _x, (SHORT) _y };

	SetConsoleCursorPosition(hBuffer[BufferIndex], CurSorPosition);

	// 텍스트 색 변경
	SetColor(_Color);

	// 버퍼에 쓰기
	WriteFile(hBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void CursorManager::WriteBuffer(Vector3 _Position, char* _str, int _Color)
{
	DWORD dw;

	COORD CurSorPosition = { (SHORT)_Position.x, (SHORT)_Position.y };

	SetConsoleCursorPosition(hBuffer[BufferIndex], CurSorPosition);
	SetColor(_Color);


	// 버퍼에 쓰기
	WriteFile(hBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void CursorManager::FlippingBuffer()
{
	SetConsoleActiveScreenBuffer(hBuffer[BufferIndex]);
	BufferIndex = !BufferIndex;


	ClearBuffer();
}

void CursorManager::ClearBuffer()
{
	DWORD dw;

	COORD Coord = { 0, 0};

	FillConsoleOutputCharacter(hBuffer[BufferIndex], ' ', ConsoleWidthSize * ConsoleHeightSize, Coord, &dw);

}

void CursorManager::DestoryBuffer()
{

	for (int i = 0; i < 2; ++i)
		CloseHandle(hBuffer[i]);

}

void CursorManager::SetColor(int _Color)
{
}


