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



	Temp.DOT_Image.push_back((char*)"EEEEEEEEEEEEEEEEEEEEEE  XXXXXXX       XXXXXXX  IIIIIIIIII  TTTTTTTTTTTTTTTTTTTTTTT");
	Temp.DOT_Image.push_back((char*)"E::::::::::::::::::::E  X:::::X       X:::::X  I::::::::I  T:::::::::::::::::::::T");
	Temp.DOT_Image.push_back((char*)"E::::::::::::::::::::E  X:::::X       X:::::X  I::::::::I  T:::::::::::::::::::::T");
	Temp.DOT_Image.push_back((char*)"EE::::::EEEEEEEEE::::E  X::::::X     X::::::X  II::::::II  T:::::TT:::::::TT:::::T");
	Temp.DOT_Image.push_back((char*)"  E:::::E       EEEEEE  XXX:::::X   X:::::XXX    I::::I    TTTTTT  T:::::T  TTTTTT");
	Temp.DOT_Image.push_back((char*)"  E:::::E                  X:::::X X:::::X       I::::I            T:::::T        ");
	Temp.DOT_Image.push_back((char*)"  E::::::EEEEEEEEEE         X:::::X:::::X        I::::I            T:::::T        ");
	Temp.DOT_Image.push_back((char*)"  E:::::::::::::::E          X:::::::::X         I::::I            T:::::T        ");
	Temp.DOT_Image.push_back((char*)"  E:::::::::::::::E          X:::::::::X         I::::I            T:::::T        ");
	Temp.DOT_Image.push_back((char*)"  E::::::EEEEEEEEEE         X:::::X:::::X        I::::I            T:::::T        ");
	Temp.DOT_Image.push_back((char*)"  E:::::E                  X:::::X X:::::X       I::::I            T:::::T        ");
	Temp.DOT_Image.push_back((char*)"  E:::::E       EEEEEE  XXX:::::X   X:::::XXX    I::::I            T:::::T        ");
	Temp.DOT_Image.push_back((char*)"EE::::::EEEEEEEE:::::E  X::::::X     X::::::X  II::::::II        TT:::::::TT      ");
	Temp.DOT_Image.push_back((char*)"E::::::::::::::::::::E  X:::::X       X:::::X  I::::::::I        T:::::::::T      ");
	Temp.DOT_Image.push_back((char*)"E::::::::::::::::::::E  X:::::X       X:::::X  I::::::::I        T:::::::::T      ");
	Temp.DOT_Image.push_back((char*)"EEEEEEEEEEEEEEEEEEEEEE  XXXXXXX       XXXXXXX  IIIIIIIIII        TTTTTTTTTTT      ");
	Temp.Color = 15;
	Image_Size = strlen(Temp.DOT_Image.front());
	Temp.Data.Position = Vector3((float)(InGameConsole_WidthSize - Image_Size) * 0.5f, (float)(ConsoleHeightSize - Temp.DOT_Image.size()) * 0.5f , 0);
	m_vecTextureImage.push_back(Temp);

	Temp.DOT_Image = Make_Box(Temp.DOT_Image.size());
	Temp.Color = 15;
	Image_Size = strlen(Temp.DOT_Image.front());
	Temp.Data.Position = Vector3((float)(InGameConsole_WidthSize - Image_Size) * 0.5f, (float)(ConsoleHeightSize - Temp.DOT_Image.size()) * 0.5f, 0);
	m_vecBoxImage.push_back(Temp);
	Temp.DOT_Image.clear();

	

	Temp.DOT_Image.clear();
	Temp.DOT_Image.push_back((char*)"   SSSSSSSSSSSSS   TTTTTTTTTTTTTTTTTTTTT        A               GGGGGGGGGGG EEEEEEEEEEEEE   1111111   ");
	Temp.DOT_Image.push_back((char*)" SS:::::::::::::S  T:::::::::::::::::::T       A:A            GG::::::::::G E:::::::::::E  1::::::1   ");
	Temp.DOT_Image.push_back((char*)"S:::S     SSSSSSS  T:::::TT:::::TT:::::T      A:::A         G:::GGGGGG::::G EE:::EEEEE::E 111:::::1   ");
	Temp.DOT_Image.push_back((char*)"S:::S              TTTTTT  T:::T  TTTTTT     A:::::A       G:::G     GGGGGG   E::E    EEE    1::::1   ");
	Temp.DOT_Image.push_back((char*)"S:::S                      T:::T            A:::A:::A     G:::G               E::E           1::::1   ");
	Temp.DOT_Image.push_back((char*)" S::SSSS                   T:::T           A:::A A:::A    G:::G               E:::EEEEE      1::::1   ");
	Temp.DOT_Image.push_back((char*)"  S:::::SSSSS              T:::T          A:::A   A:::A   G:::G    GGGGGGGG   E:::::::E      1::::l   ");
	Temp.DOT_Image.push_back((char*)"     SSSSSS::::S           T:::T         A:::AAAAAAA:::A  G:::G    GGG::::G   E:::EEEEE      1::::l   ");
	Temp.DOT_Image.push_back((char*)"          S:::::S          T:::T        A:::::::::::::::A G:::G      G::::G   E::E           1::::l   ");
	Temp.DOT_Image.push_back((char*)"          S:::::S          T:::T       A:::AAAAAAAAAAA:::A G:::G     G::::G   E::E    EEE    1::::l   ");
	Temp.DOT_Image.push_back((char*)"SSSSS     S:::::S        TT:::::TT    A:::A           A:::A G:::GGGGGG::::G EE:::EEEEE::E 111::::::111");
	Temp.DOT_Image.push_back((char*)"S::::SSSSSS:::::S        T:::::::T   A::::             ::::A G::::::::::::G E:::::::::::E 1::::::::::1");
	Temp.DOT_Image.push_back((char*)" SSSSSSSSSSSSS           TTTTTTTTT  AAAAA               AAAAA   GGGGG  GGGG EEEEEEEEEEEEE 111111111111");
	Temp.Color = 15;
	Image_Size = strlen(Temp.DOT_Image.front());
	Temp.Data.Position = Vector3((float)(InGameConsole_WidthSize - Image_Size) * 0.5f, (float)(ConsoleHeightSize - Temp.DOT_Image.size()) * 0.5f - 8, 1);
	m_vecTextureImage.push_back(Temp);

	Temp.DOT_Image = Make_Box(Temp.DOT_Image.size());
	Temp.Color = 15;
	Image_Size = strlen(Temp.DOT_Image.front());
	Temp.Data.Position = Vector3((float)(InGameConsole_WidthSize - Image_Size) * 0.5f, (float)(ConsoleHeightSize - Temp.DOT_Image.size()) * 0.5f - 8, 1);
	m_vecBoxImage.push_back(Temp);
	Temp.DOT_Image.clear();


	Temp.DOT_Image.push_back((char*)"   SSSSSSSSSS  TTTTTTTTTTTTTTTTTTTTT         A                 GGGGGGGGGGGGG EEEEEEEEEEEEE  2222222222    ");
	Temp.DOT_Image.push_back((char*)" SS::::::::::S T:::::::::::::::::::T        A:A             GGG::::::::::::G E:::::::::::E 2::::::::::22  ");
	Temp.DOT_Image.push_back((char*)"S:::S    SSSSS T:::::TT:::::TT:::::T       A:::A         G:::::GGGGGGGG::::G EE::::EEEEE:E 22222    2:::2 ");
	Temp.DOT_Image.push_back((char*)"S:::S          TTTTTT  T:::T  TTTTTT      A:::::A       G:::::G       GGGGGG   E:::E   EEE          2:::2 ");
	Temp.DOT_Image.push_back((char*)"S:::S                  T:::T             A:::A:::A     G:::::G                 E:::E                2:::2 ");
	Temp.DOT_Image.push_back((char*)" S::SSSS               T:::T            A:::A A:::A    G:::::G                 E::::EEEEE        2222::2  ");
	Temp.DOT_Image.push_back((char*)"  S:::::SSS            T:::T           A:::A   A:::A   G:::::G    GGGGGGGGGG   E::::::::E    2222::::22   ");
	Temp.DOT_Image.push_back((char*)"     SSSSS::S          T:::T          A:::AAAAAAA:::A  G:::::G    GGGGG::::G   E::::EEEEE   2:::2222      ");
	Temp.DOT_Image.push_back((char*)"         S:::S         T:::T         A:::::::::::::::A G:::::G        G::::G   E:::E       2:::2          ");
	Temp.DOT_Image.push_back((char*)"         S:::S         T:::T        A::AAAAAAAAAAAAA::A G:::::G       G::::G   E:::E   EEE 2:::2          ");
	Temp.DOT_Image.push_back((char*)"SSSSS    S:::S       TT:::::TT     A::A             A::A G:::::GGGGGGGG::::G EE::::EEEE::E 2:::2     22222");
	Temp.DOT_Image.push_back((char*)"S::::SSSSS:::S       T:::::::T    A:::               :::A GG:::::::::::::::G E:::::::::::E 2::::22222::::2");
	Temp.DOT_Image.push_back((char*)" SSSSSSSSSS          TTTTTTTTT  AAAAAA                AAAAA    GGGGGG   GGGG EEEEEEEEEEEEE 222222222222222");
	Temp.Color = 15;
	Image_Size = strlen(Temp.DOT_Image.front());
	Temp.Data.Position = Vector3((float)(InGameConsole_WidthSize - Image_Size) * 0.5f, (float)(ConsoleHeightSize - Temp.DOT_Image.size()) * 0.5f - 13, 2);
	m_vecTextureImage.push_back(Temp);

	Temp.DOT_Image = Make_Box(Temp.DOT_Image.size());
	Temp.Color = 15;
	Image_Size = strlen(Temp.DOT_Image.front());
	Temp.Data.Position = Vector3((float)(InGameConsole_WidthSize - Image_Size) * 0.5f , (float)(ConsoleHeightSize - Temp.DOT_Image.size()) * 0.5f - 13, 2);
	m_vecBoxImage.push_back(Temp);
	Temp.DOT_Image.clear();

	
	Temp.DOT_Image.push_back((char*)"   SSSSSSSSSSS  TTTTTTTTTTTTTTTTTTTTT         A                  GGGGGGGGGGGG EEEEEEEEEEEEEE  33333333  ");
	Temp.DOT_Image.push_back((char*)"S:::SSSSSS::::S T:::::::::::::::::::T        A:A            GG:::::::::::::G E::::::::::::E 3::::33::::3");
	Temp.DOT_Image.push_back((char*)"S:::S     SSSSS T:::::TT:::::TT:::::T       A:::A          G::::GGGGGGGG:::G EE::::EEEEE::E 33333  3:::3");
	Temp.DOT_Image.push_back((char*)"S:::S           TTTTTT  T:::T  TTTTTT      A:::::A        G::::G       GGGGG   E:::E   EEEE        3:::3");
	Temp.DOT_Image.push_back((char*)"S:::S                   T:::T             A:::A:::A      G::::G                E:::E               3:::3");
	Temp.DOT_Image.push_back((char*)" S::SSSS                T:::T            A:::A A:::A     G::::G                E::::EEEEE     33333:::3 ");
	Temp.DOT_Image.push_back((char*)"  S:::::SSSS            T:::T           A:::A   A:::A    G::::G    GGGGGGGGG   E:::::::::     3::::::3  ");
	Temp.DOT_Image.push_back((char*)"   SS:::::::S           T:::T          A:::A     A:::A   G::::G    G:::::::G   E:::::::::     33333:::3 ");
	Temp.DOT_Image.push_back((char*)"     SSSSSS::S          T:::T         A:::AAAAAAAAA:::A  G::::G    GGGGG:::G   E::::EEEEE          3:::3");
	Temp.DOT_Image.push_back((char*)"          S:::S         T:::T        A:::::::::::::::::A G::::G        G:::G   E:::E               3:::3");
	Temp.DOT_Image.push_back((char*)"          S:::S         T:::T       A:::AAAAAAAAAAAAA:::A G::::G       G:::G   E:::E   EEEE        3:::3");
	Temp.DOT_Image.push_back((char*)"SSSSS     S:::S       TT:::::TT    A:::A             A:::A G::::GGGGGGGG:::G EE::::EEEE:::E 33333  3:::3");
	Temp.DOT_Image.push_back((char*)"S::::SSSSSS:::S       T:::::::T   A:::A               A:::A GG:::::::::::::G E::::::::::::E 3::::33::::3");
	Temp.DOT_Image.push_back((char*)" SSSSSSSSSSS          TTTTTTTTT  AAAAA                 AAAAA    GGGGGG   GGG EEEEEEEEEEEEEE  33333333   ");
	Temp.Color = 15;
	Image_Size = strlen(Temp.DOT_Image.front());
	Temp.Data.Position = Vector3((float)(InGameConsole_WidthSize - Image_Size) * 0.5f, (float)(ConsoleHeightSize - Temp.DOT_Image.size()) * 0.5f - 15, 3);
	m_vecTextureImage.push_back(Temp);

	Temp.DOT_Image = Make_Box(Temp.DOT_Image.size());
	Temp.Color = 15;
	Image_Size = strlen(Temp.DOT_Image.front());
	Temp.Data.Position = Vector3((float)(InGameConsole_WidthSize - Image_Size) * 0.5f, (float)(ConsoleHeightSize - Temp.DOT_Image.size()) * 0.5f - 15, 3);
	m_vecBoxImage.push_back(Temp);
	Temp.DOT_Image.clear();

	

	m_iSelectStage = 0;
}

int StageMenuInterface::Update()
{
	DWORD Key = InputManager::GetInstance()->GetKey();
	if (Key & KEY_DOWN && m_vecBoxImage.front().Data.Position.z != 0)
	{
		
		for (int i = 0; i < m_vecBoxImage.size(); ++i)
		{
			Location_Check(m_vecBoxImage[i].Data.Position, IMAGE_MOVE_DIRECTION::DOWN);
			Location_Check(m_vecTextureImage[i].Data.Position, IMAGE_MOVE_DIRECTION::DOWN);
		}
	}
	else if (Key & KEY_UP && m_vecBoxImage.back().Data.Position.z != 0) // 여기서 조건 예외 조건 걸어버리면 될거 같다.
	{
		for (int i = 0; i < m_vecBoxImage.size(); ++i)
		{
			Location_Check(m_vecBoxImage[i].Data.Position, IMAGE_MOVE_DIRECTION::UP);
			Location_Check(m_vecTextureImage[i].Data.Position, IMAGE_MOVE_DIRECTION::UP);
		}
	}
	return 0;
}

void StageMenuInterface::Render()
{
	for (int i = m_vecBoxImage.size() - 1; i >= 0; --i)
	{
		if (m_vecBoxImage[i].Data.Position.z > 0)
			ImageDraw(i);
	}
	for (int i = 0; i < m_vecBoxImage.size(); ++i)
	{
		if (m_vecBoxImage[i].Data.Position.z <0)
			ImageDraw(i);
	}
	for (int i = 0; i < m_vecBoxImage.size(); ++i)
	{
		if (m_vecBoxImage[i].Data.Position.z == 0)
			ImageDraw(i);
	}
}

void StageMenuInterface::Location_Check(Vector3& _Position , IMAGE_MOVE_DIRECTION Check)
{
	// 예외 처리 하자 
	if (Check == IMAGE_MOVE_DIRECTION::UP)
	{
		if (_Position.z == 0 || _Position.z == 1)
			_Position.y += 8;
		else if (_Position.z == 2 || _Position.z == -1)
			_Position.y += 5;
		else if (_Position.z == 3 || _Position.z == -2)
			_Position.y += 2;

		--_Position.z;

	}
	else if (Check == IMAGE_MOVE_DIRECTION::DOWN)
	{
		if (_Position.z == 0 || _Position.z == -1)
			_Position.y -= 8;
		else if (_Position.z == 1 || _Position.z == -2)
			_Position.y -= 5;
		else if (_Position.z == 2 || _Position.z == -3)
			_Position.y -= 2;
		
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

void StageMenuInterface::Release()
{
	m_vecTextureImage.clear();
	m_vecBoxImage.clear();
}