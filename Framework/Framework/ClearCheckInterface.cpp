#include "ClearCheckInterface.h"
#include "CursorManager.h"

ClearCheckInterface::ClearCheckInterface() :m_iStart(0),m_iEnd(0){}
ClearCheckInterface::~ClearCheckInterface() {}

void ClearCheckInterface::Initialize()
{
	Image_Transform_Data StartImage;

	StartImage.DOT_Image.push_back((char*)"          _____                    _____                    _____                    _____           ");
	StartImage.DOT_Image.push_back((char*)"         /\    \                  /\    \                  /\    \                  /\    \          ");
	StartImage.DOT_Image.push_back((char*)"        /::\    \                /::\    \                /::\____\                /::\    \         ");
	StartImage.DOT_Image.push_back((char*)"       /::::\    \              /::::\    \              /::::|   |               /::::\    \        ");
	StartImage.DOT_Image.push_back((char*)"      /::::::\    \            /::::::\    \            /:::::|   |              /::::::\    \       ");
	StartImage.DOT_Image.push_back((char*)"     /:::/\:::\    \          /:::/\:::\    \          /::::::|   |             /:::/\:::\    \      ");
	StartImage.DOT_Image.push_back((char*)"    /:::/  \:::\    \        /:::/__\:::\    \        /:::/|::|   |            /:::/__\:::\    \     ");
	StartImage.DOT_Image.push_back((char*)"   /:::/    \:::\    \      /::::\   \:::\    \      /:::/ |::|   |           /::::\   \:::\    \    ");
	StartImage.DOT_Image.push_back((char*)"  /:::/    / \:::\    \    /::::::\   \:::\    \    /:::/  |::|___|______    /::::::\   \:::\    \   ");
	StartImage.DOT_Image.push_back((char*)" /:::/    /   \:::\ ___\  /:::/\:::\   \:::\    \  /:::/   |::::::::\    \  /:::/\:::\   \:::\    \  ");
	StartImage.DOT_Image.push_back((char*)"/:::/____/  ___\:::|    |/:::/  \:::\   \:::\____\/:::/    |:::::::::\____\/:::/__\:::\   \:::\____\ ");
	StartImage.DOT_Image.push_back((char*)"\:::\    \ /\  /:::|____|\::/    \:::\  /:::/    /\::/    / ~~~~~/:::/    /\:::\   \:::\   \::/    / ");
	StartImage.DOT_Image.push_back((char*)" \:::\    /::\ \::/    /  \/____/ \:::\/:::/    /  \/____/      /:::/    /  \:::\   \:::\   \/____/  ");
	StartImage.DOT_Image.push_back((char*)"  \:::\   \:::\ \/____/            \::::::/    /               /:::/    /    \:::\   \:::\    \      ");
	StartImage.DOT_Image.push_back((char*)"   \:::\   \:::\____\               \::::/    /               /:::/    /      \:::\   \:::\____\     ");
	StartImage.DOT_Image.push_back((char*)"    \:::\  /:::/    /               /:::/    /               /:::/    /        \:::\   \::/    /     ");
	StartImage.DOT_Image.push_back((char*)"     \:::\/:::/    /               /:::/    /               /:::/    /          \:::\   \/____/      ");
	StartImage.DOT_Image.push_back((char*)"      \::::::/    /               /:::/    /               /:::/    /            \:::\    \          ");
	StartImage.DOT_Image.push_back((char*)"       \::::/    /               /:::/    /               /:::/    /              \:::\____\         ");
	StartImage.DOT_Image.push_back((char*)"        \::/____/                \::/    /                \::/    /                \::/    /         ");
	StartImage.DOT_Image.push_back((char*)"                                  \/____/                  \/____/                  \/____/          ");
	StartImage.Data.Position = Vector3((float)(InGameConsole_WidthSize * 0.5f - 65) + PlayerDataInfoSize, (float)(ConsoleHeightSize * 0.5f - 23));
	StartImage.Color = 12;
	m_vecTextureImage.push_back(StartImage);
	StartImage.DOT_Image.clear();

	StartImage.DOT_Image.push_back((char*)"         _______                   _____                    _____                    _____          ");
	StartImage.DOT_Image.push_back((char*)"        /::\    \                 /\    \                  /\    \                  /\    \         ");
	StartImage.DOT_Image.push_back((char*)"       /::::\    \               /::\____\                /::\    \                /::\    \        ");
	StartImage.DOT_Image.push_back((char*)"      /::::::\    \             /:::/    /               /::::\    \              /::::\    \       ");
	StartImage.DOT_Image.push_back((char*)"     /::::::::\    \           /:::/    /               /::::::\    \            /::::::\    \      ");
	StartImage.DOT_Image.push_back((char*)"    /:::/~~\:::\    \         /:::/    /               /:::/\:::\    \          /:::/\:::\    \     ");
	StartImage.DOT_Image.push_back((char*)"   /:::/    \:::\    \       /:::/____/               /:::/__\:::\    \        /:::/__\:::\    \    ");
	StartImage.DOT_Image.push_back((char*)"  /:::/    / \:::\    \      |::|    |               /::::\   \:::\    \      /::::\   \:::\    \   ");
	StartImage.DOT_Image.push_back((char*)" /:::/____/   \:::\____\     |::|    |     _____    /::::::\   \:::\    \    /::::::\   \:::\    \  ");
	StartImage.DOT_Image.push_back((char*)"|:::|    |     |:::|    |    |::|    |    /\    \  /:::/\:::\   \:::\    \  /:::/\:::\   \:::\____\ ");
	StartImage.DOT_Image.push_back((char*)"|:::|____|     |:::|    |    |::|    |   /::\____\/:::/__\:::\   \:::\____\/:::/  \:::\   \:::|    |");
	StartImage.DOT_Image.push_back((char*)" \:::\    \   /:::/    /     |::|    |  /:::/    /\:::\   \:::\   \::/    /\::/   |::::\  /:::|____|");
	StartImage.DOT_Image.push_back((char*)"  \:::\    \ /:::/    /      |::|    | /:::/    /  \:::\   \:::\   \/____/  \/____|:::::\/:::/    / ");
	StartImage.DOT_Image.push_back((char*)"   \:::\    /:::/    /       |::|____|/:::/    /    \:::\   \:::\    \            |:::::::::/    /  ");
	StartImage.DOT_Image.push_back((char*)"    \:::\__/:::/    /        |:::::::::::/    /      \:::\   \:::\____\           |::|\::::/    /   ");
	StartImage.DOT_Image.push_back((char*)"     \::::::::/    /         \::::::::::/____/        \:::\   \::/    /           |::| \::/____/    ");
	StartImage.DOT_Image.push_back((char*)"      \::::::/    /           ~~~~~~~~~~               \:::\   \/____/            |::|  ~|          ");
	StartImage.DOT_Image.push_back((char*)"       \::::/    /                                      \:::\    \                |::|   |          ");
	StartImage.DOT_Image.push_back((char*)"        \::/____/                                        \:::\____\               \::|   |          ");
	StartImage.DOT_Image.push_back((char*)"         ~~                                               \::/    /                \:|   |          ");
	StartImage.DOT_Image.push_back((char*)"                                                           \/____/                  \|___|          ");
	StartImage.Data.Position = Vector3((float)(InGameConsole_WidthSize * 0.5f - 65) + PlayerDataInfoSize, (float)(ConsoleHeightSize * 0.5f - 8));
	StartImage.Color = 12;
	m_vecTextureImage.push_back(StartImage);
	StartImage.DOT_Image.clear();

	StartImage.DOT_Image.push_back((char*)"          _____                    _____                    _____                    _____            ");
	StartImage.DOT_Image.push_back((char*)"         /\    \                  /\    \                  /\    \                  /\    \           ");
	StartImage.DOT_Image.push_back((char*)"        /::\    \                /::\    \                /::\____\                /::\    \          ");
	StartImage.DOT_Image.push_back((char*)"       /::::\    \              /::::\    \              /::::|   |               /::::\    \         ");
	StartImage.DOT_Image.push_back((char*)"      /::::::\    \            /::::::\    \            /:::::|   |              /::::::\    \        ");
	StartImage.DOT_Image.push_back((char*)"     /:::/\:::\    \          /:::/\:::\    \          /::::::|   |             /:::/\:::\    \       ");
	StartImage.DOT_Image.push_back((char*)"    /:::/  \:::\    \        /:::/__\:::\    \        /:::/|::|   |            /:::/__\:::\    \      ");
	StartImage.DOT_Image.push_back((char*)"   /:::/    \:::\    \      /::::\   \:::\    \      /:::/ |::|   |           /::::\   \:::\    \     ");
	StartImage.DOT_Image.push_back((char*)"  /:::/    / \:::\    \    /::::::\   \:::\    \    /:::/  |::|___|______    /::::::\   \:::\    \    ");
	StartImage.DOT_Image.push_back((char*)" /:::/    /   \:::\ ___\  /:::/\:::\   \:::\    \  /:::/   |::::::::\    \  /:::/\:::\   \:::\    \   ");
	StartImage.DOT_Image.push_back((char*)"/:::/____/  ___\:::|    |/:::/  \:::\   \:::\____\/:::/    |:::::::::\____\/:::/__\:::\   \:::\____\ |");
	StartImage.DOT_Image.push_back((char*)"\:::\    \ /\  /:::|____|\::/    \:::\  /:::/    /\::/    / ~~~~~/:::/    /\:::\   \:::\   \::/    / |");
	StartImage.DOT_Image.push_back((char*)" \:::\    /::\ \::/    /  \/____/ \:::\/:::/    /  \/____/      /:::/    /  \:::\   \:::\   \/____/   ");
	StartImage.DOT_Image.push_back((char*)"  \:::\   \:::\ \/____/            \::::::/    /               /:::/    /    \:::\   \:::\    \       ");
	StartImage.DOT_Image.push_back((char*)"   \:::\   \:::\____\               \::::/    /               /:::/    /      \:::\   \:::\____\      ");
	StartImage.DOT_Image.push_back((char*)"    \:::\  /:::/    /               /:::/    /               /:::/    /        \:::\   \::/    /      ");
	StartImage.DOT_Image.push_back((char*)"     \:::\/:::/    /               /:::/    /               /:::/    /          \:::\   \/____/       ");
	StartImage.DOT_Image.push_back((char*)"      \::::::/    /               /:::/    /               /:::/    /            \:::\    \           ");
	StartImage.DOT_Image.push_back((char*)"       \::::/    /               /:::/    /               /:::/    /              \:::\____\          ");
	StartImage.DOT_Image.push_back((char*)"        \::/____/                \::/    /                \::/    /                \::/    /          ");
	StartImage.DOT_Image.push_back((char*)"                                  \/____/                  \/____/                  \/____/           ");
	StartImage.Data.Position = Vector3((float)(InGameConsole_WidthSize * 0.5f -50) + PlayerDataInfoSize, (float)(ConsoleHeightSize * 0.5f - 20));
	StartImage.Color = 10;
	m_vecTextureImage.push_back(StartImage);
	StartImage.DOT_Image.clear();


	StartImage.DOT_Image.push_back((char*)"          _____                    _____            _____                    _____                    _____          ");
	StartImage.DOT_Image.push_back((char*)"         /\    \                  /\    \          /\    \                  /\    \                  /\    \         ");
	StartImage.DOT_Image.push_back((char*)"        /::\    \                /::\____\        /::\    \                /::\    \                /::\    \        ");
	StartImage.DOT_Image.push_back((char*)"       /::::\    \              /:::/    /       /::::\    \              /::::\    \              /::::\    \       ");
	StartImage.DOT_Image.push_back((char*)"      /::::::\    \            /:::/    /       /::::::\    \            /::::::\    \            /::::::\    \      ");
	StartImage.DOT_Image.push_back((char*)"     /:::/\:::\    \          /:::/    /       /:::/\:::\    \          /:::/\:::\    \          /:::/\:::\    \     ");
	StartImage.DOT_Image.push_back((char*)"    /:::/  \:::\    \        /:::/    /       /:::/__\:::\    \        /:::/__\:::\    \        /:::/__\:::\    \    ");
	StartImage.DOT_Image.push_back((char*)"   /:::/    \:::\    \      /:::/    /       /::::\   \:::\    \      /::::\   \:::\    \      /::::\   \:::\    \   ");
	StartImage.DOT_Image.push_back((char*)"  /:::/    / \:::\    \    /:::/    /       /::::::\   \:::\    \    /::::::\   \:::\    \    /::::::\   \:::\    \  ");
	StartImage.DOT_Image.push_back((char*)" /:::/    /   \:::\    \  /:::/    /       /:::/\:::\   \:::\    \  /:::/\:::\   \:::\    \  /:::/\:::\   \:::\____\ ");
	StartImage.DOT_Image.push_back((char*)"/:::/____/     \:::\____\/:::/____/       /:::/__\:::\   \:::\____\/:::/  \:::\   \:::\____\/:::/  \:::\   \:::|    |");
	StartImage.DOT_Image.push_back((char*)"\:::\    \      \::/    /\:::\    \       \:::\   \:::\   \::/    /\::/    \:::\  /:::/    /\::/   |::::\  /:::|____|");
	StartImage.DOT_Image.push_back((char*)" \:::\    \      \/____/  \:::\    \       \:::\   \:::\   \/____/  \/____/ \:::\/:::/    /  \/____|:::::\/:::/    / ");
	StartImage.DOT_Image.push_back((char*)"  \:::\    \               \:::\    \       \:::\   \:::\    \               \::::::/    /         |:::::::::/    /  ");
	StartImage.DOT_Image.push_back((char*)"   \:::\    \               \:::\    \       \:::\   \:::\____\               \::::/    /          |::|\::::/    /   ");
	StartImage.DOT_Image.push_back((char*)"    \:::\    \               \:::\    \       \:::\   \::/    /               /:::/    /           |::| \::/____/    ");
	StartImage.DOT_Image.push_back((char*)"     \:::\    \               \:::\    \       \:::\   \/____/               /:::/    /            |::|  ~|          ");
	StartImage.DOT_Image.push_back((char*)"      \:::\    \               \:::\    \       \:::\    \                  /:::/    /             |::|   |          ");
	StartImage.DOT_Image.push_back((char*)"       \:::\____\               \:::\____\       \:::\____\                /:::/    /              \::|   |          ");
	StartImage.DOT_Image.push_back((char*)"        \::/    /                \::/    /        \::/    /                \::/    /                \:|   |          ");
	StartImage.DOT_Image.push_back((char*)"         \/____/                  \/____/          \/____/                  \/____/                  \|___|          ");
	StartImage.Data.Position = Vector3((float)(InGameConsole_WidthSize * 0.5f - 50) + PlayerDataInfoSize, (float)(ConsoleHeightSize * 0.5f + 3 ));
	StartImage.Color = 10;
	m_vecTextureImage.push_back(StartImage);
	StartImage.DOT_Image.clear();

	m_iEnd = 0;
}

int ClearCheckInterface::Update()
{
    return 0;
}

void ClearCheckInterface::Render()
{
	if (m_iEnd != 0)
	{
		for (int i = m_iStart; i <= m_iEnd; ++i)
			UserInterface::ImageDraw(i);
	}
}

void ClearCheckInterface::Release()
{
	m_vecTextureImage.clear();
}

void ClearCheckInterface::OverCheck(bool Check)
{
	if (Check)
	{
		m_iStart = 0;
		m_iEnd = 1;
	}
	else
	{
		m_iStart = 2;
		m_iEnd = 3;
	}
}

vector<char*> ClearCheckInterface::Make_Box(int Font_Size)
{
    return vector<char*>();
}


