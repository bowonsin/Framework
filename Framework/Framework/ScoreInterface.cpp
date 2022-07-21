#include "ScoreInterface.h"
#include "CursorManager.h"

ScoreInterface::ScoreInterface() {}
ScoreInterface::~ScoreInterface() {}

void ScoreInterface::Initialize()
{
	Image_Transform_Data InputImage;
	InputImage.DOT_Image = Make_Box(NULL);
	InputImage.Color = 15;
	InputImage.Data.Position = Vector3(InGameConsole_WidthSize - 1,0);
	m_vecBoxImage.push_back(InputImage);

}

int ScoreInterface::Update()
{
	return 0;
}

void ScoreInterface::Render()
{
	for (int i = 0; i < m_vecBoxImage.front().DOT_Image.size(); ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			m_vecBoxImage.front().Data.Position.x,
			m_vecBoxImage.front().Data.Position.y + i,
			m_vecBoxImage.front().DOT_Image[i], m_vecBoxImage.front().Color
		);
	}
}

void ScoreInterface::Release()
{
	m_vecBoxImage.clear();
	m_vecTextureImage.clear();
}

vector<char*> ScoreInterface::Make_Box(int Font_Size)
{
	vector<char*> BoxImage;
	BoxImage.push_back((char*)"忙式式式式式式式式式式式式式式式式式式忖");
	for (int i = 0; i < ConsoleHeightSize - 2; ++i)
		BoxImage.push_back((char*)"弛                                    弛");
	BoxImage.push_back((char*)"戌式式式式式式式式式式式式式式式式式式戎");
	
	return BoxImage;
}
