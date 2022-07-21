#include "MenuInterface.h"
#include "CursorManager.h"
#include "InputManager.h"

MenuInterface::MenuInterface() {}
MenuInterface::MenuInterface(Transform _info) {}
MenuInterface::~MenuInterface() { Release(); }

void MenuInterface::Initialize()
{

	Image_Transform_Data MenuImage; 

	MenuImage.DOT_Image = Make_Box(NULL);
	float x_Standard = (float)(InGameConsole_WidthSize * 0.5f - strlen(MenuImage.DOT_Image.front())/2);
	float y_Standard = (float)(ConsoleHeightSize * 0.5f - MenuImage.DOT_Image.size()/2);
	
	MenuImage.Data.Position = Vector3(x_Standard ,y_Standard ,0);
	MenuImage.Color = 12;
	m_vecBoxImage.push_back(MenuImage);
	MenuImage.DOT_Image.clear();

	MenuImage.DOT_Image.push_back((char*)"                   ::::::::::: ::::    ::: ");
	MenuImage.DOT_Image.push_back((char*)"                       :+:     :+:+:   :+: ");
	MenuImage.DOT_Image.push_back((char*)"                       +:+     :+:+:+  +:+ ");
	MenuImage.DOT_Image.push_back((char*)"                       +#+     +#+ +:+ +#+ ");
	MenuImage.DOT_Image.push_back((char*)"                       +#+     +#+  +#+#+# ");
	MenuImage.DOT_Image.push_back((char*)"                       #+#     #+#   #+#+# ");
	MenuImage.DOT_Image.push_back((char*)"                   ########### ###    #### ");
	MenuImage.DOT_Image.push_back((char*)"");
	MenuImage.DOT_Image.push_back((char*)"");
	MenuImage.DOT_Image.push_back((char*)"        ::::::::      :::     ::::    ::::  ::::::::::");
	MenuImage.DOT_Image.push_back((char*)"       :+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:       ");
	MenuImage.DOT_Image.push_back((char*)"       +:+         +:+   +:+  +:+ +:+:+ +:+ +:+       ");
	MenuImage.DOT_Image.push_back((char*)"       :#:        +#++:++#++: +#+  +:+  +#+ +#++:++#  ");
	MenuImage.DOT_Image.push_back((char*)"       +#+  ++#+# +#+     +#+ +#+       +#+ +#+       ");
	MenuImage.DOT_Image.push_back((char*)"       #+#    #+# #+#     #+# #+#       #+# #+#       ");
	MenuImage.DOT_Image.push_back((char*)"        ########  ###     ### ###       ### ##########");
	MenuImage.DOT_Image.push_back((char*)"");
	MenuImage.DOT_Image.push_back((char*)"");
	MenuImage.DOT_Image.push_back((char*)"       :::::::::  :::              :::      :::   ::: ");
	MenuImage.DOT_Image.push_back((char*)"       :+:    :+: :+:            :+: :+:    :+:   :+: ");
	MenuImage.DOT_Image.push_back((char*)"       +:+    +:+ +:+           +:+   +:+    +:+ +:+  ");
	MenuImage.DOT_Image.push_back((char*)"       +#++:++#+  +#+          +#++:++#++:    +#++:   ");
	MenuImage.DOT_Image.push_back((char*)"       +#+        +#+          +#+     +#+     +#+    ");
	MenuImage.DOT_Image.push_back((char*)"       #+#        #+#          #+#     #+#     #+#    ");
	MenuImage.DOT_Image.push_back((char*)"       ###        ##########   ###     ###     ###    ");
	MenuImage.Data.Position = Vector3(x_Standard + 4, y_Standard + 4,0); // 기본 꺼 와 x 4 y 4 차이남
	MenuImage.Color = 12;
	m_vecTextureImage.push_back(MenuImage);
	MenuImage.DOT_Image.clear();

	MenuImage.DOT_Image = Make_Box(NULL);
	MenuImage.Data.Position = Vector3(x_Standard + 30, y_Standard , 1);
	MenuImage.Color = 9;
	m_vecBoxImage.push_back(MenuImage);
	MenuImage.DOT_Image.clear();

	MenuImage.DOT_Image.push_back((char*)"EEEEEEEEEEEEEEE XXXXXX       XXXXXX IIIIIIIIII TTTTTTTTTTTTTTTTT");
	MenuImage.DOT_Image.push_back((char*)"E:::::::::::::E X::::X       X::::X I::::::::I T:::::::::::::::T");
	MenuImage.DOT_Image.push_back((char*)"E:::::::::::::E X::::X       X::::X I::::::::I T:::::::::::::::T");
	MenuImage.DOT_Image.push_back((char*)"EE:::EEEEEE:::E X:::::X     X:::::X II::::::II T:::TT:::::TT:::T");
	MenuImage.DOT_Image.push_back((char*)"  E::E    EEEEE XXX::::X   X::::XXX   I::::I   TTTT  T:::T  TTTT");
	MenuImage.DOT_Image.push_back((char*)"  E::E             X::::X X::::X      I::::I         T:::T      ");
	MenuImage.DOT_Image.push_back((char*)"  E:::EEEEEE        :::::X:::::       I::::I         T:::T      ");
	MenuImage.DOT_Image.push_back((char*)"  E::::::::E        X:::::::::X       I::::I         T:::T      ");
	MenuImage.DOT_Image.push_back((char*)"  E::::::::E        X:::::::::X       I::::I         T:::T      ");
	MenuImage.DOT_Image.push_back((char*)"  E:::EEEEEE        :::::X:::::       I::::I         T:::T      ");
	MenuImage.DOT_Image.push_back((char*)"  E::E             X::::X X::::X      I::::I         T:::T      ");
	MenuImage.DOT_Image.push_back((char*)"  E::E    EEEEE XXX::::X   X::::XXX   I::::I         T:::T      ");
	MenuImage.DOT_Image.push_back((char*)"EE:::EEEEE::::E X:::::X     X:::::X II::::::II     TT:::::TT    ");
	MenuImage.DOT_Image.push_back((char*)"E:::::::::::::E X::::X       X::::X I::::::::I     T:::::::T    ");
	MenuImage.DOT_Image.push_back((char*)"E:::::::::::::E X::::X       X::::X I::::::::I     T:::::::T    ");
	MenuImage.DOT_Image.push_back((char*)"EEEEEEEEEEEEEEE XXXXXX       XXXXXX IIIIIIIIII     TTTTTTTTT    ");
	MenuImage.Data.Position = Vector3(x_Standard + 33, y_Standard + 9, 1);
	MenuImage.Color = 9;
	m_vecTextureImage.push_back(MenuImage);
	MenuImage.DOT_Image.clear();

}


int MenuInterface::Update()
{
	DWORD Key = InputManager::GetInstance()->GetKey();

	if (Key & KEY_RIGHT && m_vecBoxImage.back().Data.Position.z != 0)
	{
		for (int i = 0; i < m_vecBoxImage.size(); ++i)
		{
			LocationCheck(m_vecBoxImage[i].Data.Position, IMAGE_MOVE_DIRECTION::RIGHT);
			LocationCheck(m_vecTextureImage[i].Data.Position, IMAGE_MOVE_DIRECTION::RIGHT);
		}
	}
	else if (Key & KEY_LEFT && m_vecBoxImage.front().Data.Position.z != 0) // menu 개수가 늘어 날 수록 정수값 늘리기
	{
		for (int i = 0; i < m_vecBoxImage.size(); ++i)
		{
			LocationCheck(m_vecBoxImage[i].Data.Position, IMAGE_MOVE_DIRECTION::LEFT);
			LocationCheck(m_vecTextureImage[i].Data.Position, IMAGE_MOVE_DIRECTION::LEFT);
		}
	}
		
	return 0;
}

void MenuInterface::Render()
{
	for (int i = m_vecBoxImage.size() - 1; i >= 0; --i)
	{
		if (m_vecBoxImage[i].Data.Position.z > 0)
			ImageDraw(i);
	}
	for (int i = 0; i < m_vecBoxImage.size(); ++i)
	{
		if (m_vecBoxImage[i].Data.Position.z < 0)
			ImageDraw(i);
	}
	for (int i = 0; i < m_vecBoxImage.size(); ++i)
	{
		if (m_vecBoxImage[i].Data.Position.z == 0)
			ImageDraw(i);
	}
}

void MenuInterface::LocationCheck(Vector3& _Position, IMAGE_MOVE_DIRECTION Check)
{
	if (Check ==IMAGE_MOVE_DIRECTION::RIGHT)
	{
		if (_Position.z == 0 || _Position.z == 1)
			_Position.x -= 30;
		else if (_Position.z == -1 || _Position.z == 2)
			_Position.x -= 20;
		else if (_Position.z == -2 || _Position.z == 3)
			_Position.x -= 10;

		--_Position.z;

	}
	else if (Check== IMAGE_MOVE_DIRECTION::LEFT)
	{
		if (_Position.z == 0 || _Position.z == -1)
			_Position.x += 30;
		else if (_Position.z == 1 || _Position.z == -2)
			_Position.x += 20;
		else if (_Position.z == 2 || _Position.z == -3)
			_Position.x += 10;

		++_Position.z;
	}
}

vector<char*> MenuInterface::Make_Box(int Font_Size)
{
	char* box_front = (char*)"; @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	char* box_middle1 = (char*)"; ................................................................, #";
	char* box_middle2 = (char*)";                                                                   #";
	char* box_end = (char*)"; ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: @";

	vector<char*> Temp;
	Temp.push_back(box_front);
	Temp.push_back(box_middle1);
	for (int i = 0; i < 29; ++i)
		Temp.push_back(box_middle2);
	Temp.push_back(box_middle1);
	Temp.push_back(box_end);
	return Temp;
}
void MenuInterface::ImageDraw(int Order)
{
	for (int j = 0; j < m_vecBoxImage[Order].DOT_Image.size(); ++j)
	{
		CursorManager::GetInstance()->WriteBuffer(
			m_vecBoxImage[Order].Data.Position.x,
			m_vecBoxImage[Order].Data.Position.y + j,
			m_vecBoxImage[Order].DOT_Image[j], m_vecBoxImage[Order].Color);
	}

	for (int j = 0; j < m_vecTextureImage[Order].DOT_Image.size(); ++j)
	{
		CursorManager::GetInstance()->WriteBuffer(
			m_vecTextureImage[Order].Data.Position.x,
			m_vecTextureImage[Order].Data.Position.y + j,
			m_vecTextureImage[Order].DOT_Image[j], m_vecTextureImage[Order].Color);
	}
}

void MenuInterface::Release()
{
	m_vecTextureImage.clear();
	m_vecBoxImage.clear();
}