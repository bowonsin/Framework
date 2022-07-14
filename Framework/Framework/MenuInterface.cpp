#include "MenuInterface.h"
#include "CursorManager.h"
#include "InputManager.h"

MenuInterface::MenuInterface():m_iSelectMenu(0) {}
MenuInterface::MenuInterface(Transform _info) {}
MenuInterface::~MenuInterface() { Release(); }

void MenuInterface::Initialize()
{
	m_iSelectMenu = 0;	

	Image_Transform_Data MenuImage; 
	float x_Standard = (float)(ConsoleWidthSize * 0.5f);
	float y_Standard = (float)(ConsoleHeightSize * 0.5f);

	MenuImage.DOT_Image = make_box();
	MenuImage.Data.Position = Vector3(x_Standard - 50.0f,y_Standard - 14.0f);
	MenuImage.Color = 12;
	BoxImage.push_back(MenuImage);
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
	MenuImage.Data.Position = Vector3(x_Standard - 46.0f, y_Standard - 10.0f);
	MenuImage.Color = 12;
	TextureImage.push_back(MenuImage);
	MenuImage.DOT_Image.clear();

	MenuImage.DOT_Image = make_box();
	MenuImage.Data.Position = Vector3(x_Standard - 20.0f, y_Standard - 16.0f);
	MenuImage.Color = 9;
	BoxImage.push_back(MenuImage);
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
	MenuImage.Data.Position = Vector3(x_Standard - 17.0f, y_Standard - 7.0f);
	MenuImage.Color = 9;
	TextureImage.push_back(MenuImage);
	MenuImage.DOT_Image.clear();

	

	//MenuImage.DOT_Image = make_box();
	//MenuImage.Color = 14;
	//MenuImage.Data.Position = Vector3((float)(ConsoleWidthSize * 0.5 - 5), (float)(ConsoleHeightSize * 0.5f - 14));
	//LogoImage.push_back(MenuImage);
}

vector<char*> MenuInterface::make_box()
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




int MenuInterface::Update()
{
	DWORD Key = InputManager::GetInstance()->GetKey();

	if (m_iSelectMenu <= 0 && (Key & KEY_RIGHT))
		++m_iSelectMenu;
	else if (m_iSelectMenu >= 1 && (Key & KEY_LEFT)) // menu 개수가 늘어 날 수록 정수값 늘리기
		--m_iSelectMenu;
	
	return 0;
}

void MenuInterface::Render()
{
	if (m_iSelectMenu == 0 )
	{
		for (int i = BoxImage.size() - 1; i >= 0; --i)
			ImageDrawing(i);
	}
	else
	{
		for (int i = 0 ;  i < BoxImage.size(); ++i )
			ImageDrawing(i);
	}
}
void MenuInterface::ImageDrawing(int Order)
{
	for (int j = 0; j < BoxImage[Order].DOT_Image.size(); ++j)
	{
		CursorManager::GetInstance()->WriteBuffer(
			BoxImage[Order].Data.Position.x,
			BoxImage[Order].Data.Position.y + j,
			BoxImage[Order].DOT_Image[j], BoxImage[Order].Color);
	}

	for (int j = 0; j < TextureImage[Order].DOT_Image.size(); ++j)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TextureImage[Order].Data.Position.x,
			TextureImage[Order].Data.Position.y + j,
			TextureImage[Order].DOT_Image[j], TextureImage[Order].Color);
	}
}

void MenuInterface::Release()
{
}