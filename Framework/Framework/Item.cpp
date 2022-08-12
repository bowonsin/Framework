#include "Item.h"
#include "CursorManager.h"

void Item::Input_Image()
{
	ch_Buffer.clear();
	ch_Buffer.push_back((char*)":             +:.");
	ch_Buffer.push_back((char*)"@@+++#@%*@@%#@*+");
	ch_Buffer.push_back((char*)" .@@@%#***%@@*=");
	ch_Buffer.push_back((char*)" *@@*+++++=+@*:.");
	ch_Buffer.push_back((char*)" *@+++++++==@%*");
	ch_Buffer.push_back((char*)" *@++++++==@@@@.");
	ch_Buffer.push_back((char*)"  @@*+=+*#%@@@%");
	ch_Buffer.push_back((char*)"+@%#*+#####+.%%#.");
	ch_Buffer.push_back((char*)"=+.            .");

}

int Item::Console_Out_Check()
{
	if (TransInfo.Position.x >= InGameConsole_WidthSize + 1)
		return BUFFER_OVER;
	else if (TransInfo.Position.x <= 0)
		return BUFFER_OVER;
	if (TransInfo.Position.y >= (float)ConsoleHeightSize)
		return BUFFER_OVER;
	else if (TransInfo.Position.y <= 0)
		return BUFFER_OVER;

	return 0;
}

Item::Item() {  }
Item::Item(Transform _Info) {}
Item::~Item() { Release(); }

Object* Item::Initialize(string _Key)
{
	strKey = _Key;
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(1,0,0);

	Input_Image();
	TransInfo.Scale = Vector3 ((float)strlen(ch_Buffer[0]),ch_Buffer.size());
    return this;
}

int Item::Update()
{
	TransInfo.Position.x -= TransInfo.Direction.x;

	return Console_Out_Check();
}

void Item::Render()
{
	for (int i = 0; i < ch_Buffer.size(); ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			ch_Buffer[i], 15);
	}
}

void Item::Release()
{
}

void Item::LifeCheck(){}