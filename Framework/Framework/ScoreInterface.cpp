#include "ScoreInterface.h"
#include "CursorManager.h"

ScoreInterface::ScoreInterface() {}
ScoreInterface::~ScoreInterface() { Release(); }

void ScoreInterface::Initialize()
{
	Image_Transform_Data InputImage;
	InputImage.DOT_Image = Make_Box(20);
	InputImage.Color = 15;
	InputImage.Data.Position = Vector3(InGameConsole_WidthSize - 1,0);
	m_vecBoxImage.push_back(InputImage);
	InputImage.DOT_Image.clear();

	InputImage.DOT_Image = Make_Box(10);
	InputImage.Color = 15;
	InputImage.Data.Position = Vector3(0 , 0);
	m_vecBoxImage.push_back(InputImage);

}

int ScoreInterface::Update()
{
	return 0;
}

void ScoreInterface::Render()
{
	for (int Box_Count = 0; Box_Count < m_vecBoxImage.size(); ++Box_Count)
	{
		ImageDraw(Box_Count);
	}
}

void ScoreInterface::Release()
{
	m_vecBoxImage.clear();
	m_vecTextureImage.clear();
}

vector<char*> ScoreInterface::Make_Box(int Box_Size)
{
	vector<char*> BoxImage;
	switch (Box_Size)
	{
	case 20:
		BoxImage.push_back((char*)"忙式式式式式式式式式式式式式忖");
		for (int i = 0; i < ConsoleHeightSize - 2; ++i)
			BoxImage.push_back((char*)"弛                          弛");
		BoxImage.push_back((char*)"戌式式式式式式式式式式式式式戎");
		break;
	case 10:
		BoxImage.push_back((char*)"忙式式式式式式式式忖");
		for (int i = 0; i < ConsoleHeightSize - 2; ++i)
			BoxImage.push_back((char*)"弛                弛");
		BoxImage.push_back((char*)"戌式式式式式式式式戎");
		break;
	}
	return BoxImage;
}

