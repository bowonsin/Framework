#include "UserInterface.h"
#include "CursorManager.h"
void UserInterface::ImageDraw(int Order)
{
	vector<Image_Transform_Data>::iterator Check = m_vecBoxImage.begin();
	if (Check != m_vecBoxImage.end())
	{
		for (int j = 0; j < m_vecBoxImage[Order].DOT_Image.size(); ++j)
		{
			CursorManager::GetInstance()->WriteBuffer(
				m_vecBoxImage[Order].Data.Position.x,
				m_vecBoxImage[Order].Data.Position.y + j,
				m_vecBoxImage[Order].DOT_Image[j], m_vecBoxImage[Order].Color);
		}
	}

	Check = m_vecTextureImage.begin();
	if (Check != m_vecTextureImage.end())
	{
		for (int j = 0; j < m_vecTextureImage[Order].DOT_Image.size(); ++j)
		{
			CursorManager::GetInstance()->WriteBuffer(
				m_vecTextureImage[Order].Data.Position.x,
				m_vecTextureImage[Order].Data.Position.y + j,
				m_vecTextureImage[Order].DOT_Image[j], m_vecTextureImage[Order].Color);
		}
	}
}

UserInterface::UserInterface()
{
}

UserInterface::UserInterface(Transform _info)
{
}

UserInterface::~UserInterface()
{
}
