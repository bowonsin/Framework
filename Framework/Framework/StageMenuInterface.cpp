#include "StageMenuInterface.h"
#include "CursorManager.h"
#include "InputManager.h"

StageMenuInterface::StageMenuInterface() :m_iSelectStage(0){}
StageMenuInterface::StageMenuInterface(Transform _info) : m_iSelectStage(0) {}
StageMenuInterface::~StageMenuInterface() { Release(); }

void StageMenuInterface::Initialize()
{
	Image_Transform_Data Temp;
	int Image_Size = 0;

	

	Temp.DOT_Image.clear();
	Temp.DOT_Image.push_back((char*)"   SSSSSSSSSSSSS   TTTTTTTTTTTTTTTTTTTTT        AAA               GGGGGGGGGGG EEEEEEEEEEEEE   1111111   ");
	Temp.DOT_Image.push_back((char*)" SS:::::::::::::S  T:::::::::::::::::::T       A:::A            GG::::::::::G E:::::::::::E  1::::::1   ");
	Temp.DOT_Image.push_back((char*)"S:::S     SSSSSSS  T:::::TT:::::TT:::::T      A:::::A         G:::GGGGGG::::G EE:::EEEEE::E 111:::::1   ");
	Temp.DOT_Image.push_back((char*)"S:::S              TTTTTT  T:::T  TTTTTT     A:::::::A       G:::G     GGGGGG   E::E    EEE    1::::1   ");
	Temp.DOT_Image.push_back((char*)"S:::S                      T:::T            A::::A::::A     G:::G               E::E           1::::1   ");
	Temp.DOT_Image.push_back((char*)" S::SSSS                   T:::T           A::::A A::::A    G:::G               E:::EEEEE      1::::1   ");
	Temp.DOT_Image.push_back((char*)"  S:::::SSSSS              T:::T          A::::A   A::::A   G:::G    GGGGGGGG   E:::::::E      1::::l   ");
	Temp.DOT_Image.push_back((char*)"     SSSSSS::::S           T:::T         A::::AAAAAAA::::A  G:::G    GGG::::G   E:::EEEEE      1::::l   ");
	Temp.DOT_Image.push_back((char*)"          S:::::S          T:::T        A:::::::::::::::::A G:::G      G::::G   E::E           1::::l   ");
	Temp.DOT_Image.push_back((char*)"          S:::::S          T:::T       A::::AAAAAAAAAAA::::A G:::G     G::::G   E::E    EEE    1::::l   ");
	Temp.DOT_Image.push_back((char*)"SSSSS     S:::::S        TT:::::TT    A::::A           A::::A G:::GGGGGG::::G EE:::EEEEE::E 111::::::111");
	Temp.DOT_Image.push_back((char*)"S::::SSSSSS:::::S        T:::::::T   A:::::             :::::A G::::::::::::G E:::::::::::E 1::::::::::1");
	Temp.DOT_Image.push_back((char*)" SSSSSSSSSSSSS           TTTTTTTTT  AAAAAA               AAAAAA   GGGGG  GGGG EEEEEEEEEEEEE 111111111111");
	Temp.Color = 15;
	Image_Size = strlen(Temp.DOT_Image.front());
	Temp.Data.Position = Vector3((float)(ConsoleWidthSize - Image_Size) * 0.5f, (float)(ConsoleHeightSize - Temp.DOT_Image.size()) * 0.5f, 0);
	TextureImage.push_back(Temp);

	Temp.DOT_Image = Make_Box(Temp.DOT_Image.size());
	Temp.Color = 15;
	Image_Size = strlen(Temp.DOT_Image.front());
	Temp.Data.Position = Vector3((float)(ConsoleWidthSize - Image_Size) * 0.5f, (float)(ConsoleHeightSize - Temp.DOT_Image.size()) * 0.5f, 0);
	BoxImage.push_back(Temp);
	Temp.DOT_Image.clear();


	Temp.DOT_Image.push_back((char*)"   SSSSSSSSSS  TTTTTTTTTTTTTTTTTTTTT         AAA                 GGGGGGGGGGGGG EEEEEEEEEEEEE  2222222222    ");
	Temp.DOT_Image.push_back((char*)" SS::::::::::S T:::::::::::::::::::T        A:::A             GGG::::::::::::G E:::::::::::E 2::::::::::22  ");
	Temp.DOT_Image.push_back((char*)"S:::S    SSSSS T:::::TT:::::TT:::::T       A:::::A         G:::::GGGGGGGG::::G EE::::EEEEE:E 22222    2:::2 ");
	Temp.DOT_Image.push_back((char*)"S:::S          TTTTTT  T:::T  TTTTTT      A:::::::A       G:::::G       GGGGGG   E:::E   EEE          2:::2 ");
	Temp.DOT_Image.push_back((char*)"S:::S                  T:::T             A:::A:::::A     G:::::G                 E:::E                2:::2 ");
	Temp.DOT_Image.push_back((char*)" S::SSSS               T:::T            A:::A A:::::A    G:::::G                 E::::EEEEE        2222::2  ");
	Temp.DOT_Image.push_back((char*)"  S:::::SSS            T:::T           A:::A   A:::::A   G:::::G    GGGGGGGGGG   E::::::::E    2222::::22   ");
	Temp.DOT_Image.push_back((char*)"     SSSSS::S          T:::T          A:::AAAAAAA:::::A  G:::::G    GGGGG::::G   E::::EEEEE   2:::2222      ");
	Temp.DOT_Image.push_back((char*)"         S:::S         T:::T         A:::::::::::::::::A G:::::G        G::::G   E:::E       2:::2          ");
	Temp.DOT_Image.push_back((char*)"         S:::S         T:::T        A::AAAAAAAAAAAAA::::A G:::::G       G::::G   E:::E   EEE 2:::2          ");
	Temp.DOT_Image.push_back((char*)"SSSSS    S:::S       TT:::::TT     A::A             A::::A G:::::GGGGGGGG::::G EE::::EEEE::E 2:::2     22222");
	Temp.DOT_Image.push_back((char*)"S::::SSSSS:::S       T:::::::T    A:::               :::::A GG:::::::::::::::G E:::::::::::E 2::::22222::::2");
	Temp.DOT_Image.push_back((char*)" SSSSSSSSSS          TTTTTTTTT  AAAAAA                AAAAAAA    GGGGGG   GGGG EEEEEEEEEEEEE 222222222222222");
	Temp.Color = 15;
	Image_Size = strlen(Temp.DOT_Image.front());
	Temp.Data.Position = Vector3((float)(ConsoleWidthSize - Image_Size) * 0.5f, (float)(ConsoleHeightSize - Temp.DOT_Image.size()) * 0.5f - 8, 1);
	TextureImage.push_back(Temp);

	Temp.DOT_Image = Make_Box(Temp.DOT_Image.size());
	Temp.Color = 15;
	Image_Size = strlen(Temp.DOT_Image.front());
	Temp.Data.Position = Vector3((float)(ConsoleWidthSize - Image_Size) * 0.5f , (float)(ConsoleHeightSize - Temp.DOT_Image.size()) * 0.5f - 8, 1);
	BoxImage.push_back(Temp);


	m_iSelectStage = 0;
}

int StageMenuInterface::Update()
{
	DWORD Key = InputManager::GetInstance()->GetKey();
	if (Key & KEY_UP)
	{
		for (int i = 0; i < BoxImage.size(); ++i)
		{
			Location_Check(BoxImage[i].Data.Position, UP_DOWN::UP);
			Location_Check(TextureImage[i].Data.Position, UP_DOWN::UP);
		}
	}
	else if (Key & KEY_DOWN) // 여기서 조건 예외 조건 걸어버리면 될거 같다.
	{
		for (int i = 0; i < BoxImage.size(); ++i)
		{
			Location_Check(BoxImage[i].Data.Position, UP_DOWN::DOWN);
			Location_Check(TextureImage[i].Data.Position, UP_DOWN::DOWN);
		}
	}
	return 0;
}

void StageMenuInterface::Render()
{
	int Check = Z_Count_Check();

	bool Cycle = true;
	while (Cycle)
	{
		
		for (int i = 0; i < BoxImage.size(); ++i)
		{
			
			if (Check == BoxImage[i].Data.Position.z || -Check == BoxImage[i].Data.Position.z)
			{
				

				ImageDraw(i);

				if (Check == 0)
					Cycle = false;
				--Check;
			}
		}
	}
	
}

int StageMenuInterface::Z_Count_Check()
{
	int Big = 0;
	int Small = 0;
	for (int i = 0; i < BoxImage.size(); ++i)
	{
		if (Big<= BoxImage[i].Data.Position.z)
			Big= BoxImage[i].Data.Position.z;

		if (Small >= BoxImage[i].Data.Position.z)
			Small = BoxImage[i].Data.Position.z;

	}
	if (Big > -Small)
		return Big;
	else
		return -Small;
}

void StageMenuInterface::Location_Check(Vector3& _Position , UP_DOWN Check)
{
	if (Check == UP_DOWN::DOWN)
	{
		if (_Position.z == 0 || _Position.z == 1)
		{
			--_Position.z;
			_Position.y -= 8;
		}
		else if (_Position.z == 2 || _Position.z == -1)
		{
			--_Position.z;
			_Position.y -= 5;
		}
		else if (_Position.z == 3 || _Position.z == -2)
		{
			--_Position.z;
			_Position.y -= 2;
		}
		else
			--_Position.z;
	}
	else if (Check == UP_DOWN::UP)
	{
		if (_Position.z == 0 || _Position.z == 1)
		{
			++_Position.z;
			_Position.y += 8;
		}
		else if (_Position.z == 2 || _Position.z == -1)
		{
			++_Position.z;
			_Position.y += 5;
		}
		else if (_Position.z == 3 || _Position.z == -2)
		{
			++_Position.z;
			_Position.y += 2;
		}
		else
			++_Position.z;
	}
}



vector<char*> StageMenuInterface::Make_Box(int Font_Size)
{
	vector<char*> Temp;
	Temp.push_back((char*)"------------------------------------------------------------------------------------------------------------------");
	Temp.push_back((char*)":                                                                                                               ,~");
	for (int i = 0 ; i < Font_Size + 3; ++i)
		Temp.push_back((char*)"*                                                                                                               -;");
	Temp.push_back((char*)"=$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$:");
	return Temp;
}

void StageMenuInterface::ImageDraw(int order)
{
	for (int j = 0; j < BoxImage[order].DOT_Image.size(); ++j)
	{
		CursorManager::GetInstance()->WriteBuffer(
			BoxImage[order].Data.Position.x,
			BoxImage[order].Data.Position.y + j,
			BoxImage[order].DOT_Image[j], BoxImage[order].Color);
	}

	for (int j = 0; j < TextureImage[order].DOT_Image.size(); ++j)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TextureImage[order].Data.Position.x,
			TextureImage[order].Data.Position.y + j,
			TextureImage[order].DOT_Image[j], TextureImage[order].Color);
	}
}
           
void StageMenuInterface::Release()
{
	TextureImage.clear();
	BoxImage.clear();
}