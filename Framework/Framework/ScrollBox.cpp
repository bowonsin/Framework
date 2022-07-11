#include "ScrollBox.h"
#include "CursorManager.h"
#include "InputManager.h"

ScrollBox::ScrollBox() {}
ScrollBox::ScrollBox(Transform _info) {}
ScrollBox::~ScrollBox() {}

void ScrollBox::Initialize()
{

    strKey = "ScrollBox";

	TextureList.push_back("忙式式式式式式式式式式忖");
	TextureList.push_back("弛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛弛");
	TextureList.push_back("弛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛弛");
	TextureList.push_back(" ㄞ���� ��������ㄞ��′��");
	TextureList.push_back("��﹛﹛﹛﹛﹛﹛﹛�� -戎��");
	TextureList.push_back(" ′_______________′__ㄞ");


	TransInfo.Position = Vector3((float)(120/2), 5.0f);
	TransInfo.Rotation = Vector3(0.0f, .0f);
	TransInfo.Scale = Vector3(14.0f, 6.0f);

}

int ScrollBox::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	auto iter = TextureList.begin();
	++iter;

	if (dwKey & KEY_CTRL)
	{
		TextureList.insert(iter, "|﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛|");
		++TransInfo.Scale.y;
	}
    return 0;
}

void ScrollBox::Render()
{
	
}

void ScrollBox::Release()
{
}


