#include "MenuInterface.h"
#include "CursorManager.h"

MenuInterface::MenuInterface() {}
MenuInterface::MenuInterface(Transform _info) {}
MenuInterface::~MenuInterface() { Release(); }

void MenuInterface::Initialize()
{

	Image_Transform_Data StartImage;


	StartImage.DOT_Image.push_back((char*)"; @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	StartImage.DOT_Image.push_back((char*)"; ................................................................, #");
	for (int i = 0 ; i < 30; ++i)
		StartImage.DOT_Image.push_back((char*)";                                                                   #");
	StartImage.DOT_Image.push_back((char*)"; ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: @");
	StartImage.Data.Position = Vector3((float)(ConsoleWidthSize * 0.5f - 65), (float)(ConsoleHeightSize * 0.5f - 6));
	StartImage.Color = 12;
	LogoImage.push_back(StartImage);
	StartImage.DOT_Image.clear();

	StartImage.DOT_Image.push_back((char*)"; @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	StartImage.DOT_Image.push_back((char*)"; ................................................................, #");
	for (int i = 0; i < 30; ++i)
		StartImage.DOT_Image.push_back((char*)";                                                                   #");
	StartImage.DOT_Image.push_back((char*)"; ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::; @");
	StartImage.Data.Position = Vector3((float)(ConsoleWidthSize * 0.5f - 35), (float)(ConsoleHeightSize * 0.5f - 14));
	StartImage.Color = 9;
	LogoImage.push_back(StartImage);
	StartImage.DOT_Image.clear();

	StartImage.DOT_Image.push_back((char*)"; @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	StartImage.DOT_Image.push_back((char*)"; ................................................................, #");
	for (int i = 0; i < 30; ++i)
		StartImage.DOT_Image.push_back((char*)";                                                                   #");
	StartImage.DOT_Image.push_back((char*)"; ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::; @");
	StartImage.Color = 14;
	StartImage.Data.Position = Vector3((float)(ConsoleWidthSize * 0.5 - 5), (float)(ConsoleHeightSize * 0.5f - 24));
	LogoImage.push_back(StartImage);
}

int MenuInterface::Update()
{
	return 0;
}

void MenuInterface::Render()
{
	for (int i = 0; i < LogoImage.size(); ++i)
	{
		for (int j = 0; j < LogoImage[i].DOT_Image.size(); ++j)
		{
			CursorManager::GetInstance()->WriteBuffer(
				LogoImage[i].Data.Position.x,
				LogoImage[i].Data.Position.y + j,
				LogoImage[i].DOT_Image[j], LogoImage[i].Color);
		}
	}
}

void MenuInterface::Release()
{
}


