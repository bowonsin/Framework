#include "ScrollBox.h"
#include "CursorManager.h"
#include "InputManager.h"

ScrollBox::ScrollBox() {}
ScrollBox::ScrollBox(Transform _info) {}
ScrollBox::~ScrollBox() {}

void ScrollBox::Initialize()
{

    strKey = "ScrollBox";

	//TextureVector.push_back((char*)"忙式式式式式式式式式式忖");
	//TextureVector.push_back((char*)"弛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛弛");
	//TextureVector.push_back((char*)"弛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛弛");
	//TextureVector.push_back((char*)" ㄞ���� ��������ㄞ��′��");
	//TextureVector.push_back((char*)"��﹛﹛﹛﹛﹛﹛﹛�� -戎��");
	//TextureVector.push_back((char*)" ′_______________′__ㄞ");
	//
	//
	//TransInfo.Position = Vector3((float)(120/2), 5.0f);
	//TransInfo.Rotation = Vector3(0.0f, .0f);
	//TransInfo.Scale = Vector3(14.0f, 6.0f);

}

int ScrollBox::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	//
	//auto iter = TextureVector.begin();
	//++iter;
	//
	//if (dwKey & KEY_CTRL)
	//{
	//	TextureVector.insert(iter, (char*)"|﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛|");
	//	++TransInfo.Scale.y;
	//}
    return 0;
}

void ScrollBox::Render()
{
	
}

void ScrollBox::Release()
{
}


