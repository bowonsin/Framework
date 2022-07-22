#include "LogoInterface.h"
#include "CursorManager.h"

LogoInterface::LogoInterface() {}
LogoInterface::LogoInterface(Transform _info) {}
LogoInterface::~LogoInterface() { Release(); }



void LogoInterface::Initialize()
{
	Image_Transform_Data StartImage;
	
	
	StartImage.DOT_Image.push_back((char*)":'######::'########:'##::::'##:'##:::'##::::'########:::::'###::::'########:::'#######::'########::'####:'##::::'##::'######::");
	StartImage.DOT_Image.push_back((char*)"'##... ##: ##.....::. ##::'##::. ##:'##::::: ##.... ##:::'## ##::: ##.... ##:'##.... ##: ##.... ##:. ##:: ##:::: ##:'##... ##:");
	StartImage.DOT_Image.push_back((char*)" ##:::..:: ##::::::::. ##'##::::. ####:::::: ##:::: ##::'##:. ##:: ##:::: ##: ##:::: ##: ##:::: ##:: ##:: ##:::: ##: ##:::..::");
	StartImage.DOT_Image.push_back((char*)". ######:: ######:::::. ###::::::. ##::::::: ########::'##:::. ##: ########:: ##:::: ##: ##:::: ##:: ##:: ##:::: ##:. ######::");
	StartImage.DOT_Image.push_back((char*)":..... ##: ##...:::::: ## ##:::::: ##::::::: ##.....::: #########: ##.. ##::: ##:::: ##: ##:::: ##:: ##:: ##:::: ##::..... ##:");
	StartImage.DOT_Image.push_back((char*)"'##::: ##: ##:::::::: ##:. ##::::: ##::::::: ##:::::::: ##.... ##: ##::. ##:: ##:::: ##: ##:::: ##:: ##:: ##:::: ##:'##::: ##:");
	StartImage.DOT_Image.push_back((char*)". ######:: ########: ##:::. ##:::: ##::::::: ##:::::::: ##:::: ##: ##:::. ##:. #######:: ########::'####:. #######::. ######::");
	StartImage.DOT_Image.push_back((char*)":......:::........::..:::::..:::::..::::::::..:::::::::..:::::..::..:::::..:::.......:::........:::....:::.......::::......:::");
	StartImage.Data.Position = Vector3((float)(InGameConsole_WidthSize * 0.5f - 65) + PlayerDataInfoSize, (float)(ConsoleHeightSize * 0.5f - 23));
	StartImage.Color = 12;
	m_vecTextureImage.push_back(StartImage);
	StartImage.DOT_Image.clear();

	StartImage.DOT_Image.push_back((char*)"  /$$$$$$  /$$$$$$$$ /$$$$$$  /$$$$$$$  /$$$$$$$$");
	StartImage.DOT_Image.push_back((char*)" /$$__  $$|__  $$__//$$__  $$| $$__  $$|__  $$__/");
	StartImage.DOT_Image.push_back((char*)"| $$   __/   | $$  | $$    $$| $$    $$   | $$   ");
	StartImage.DOT_Image.push_back((char*)"|  $$$$$$    | $$  | $$$$$$$$| $$$$$$$/   | $$   ");
	StartImage.DOT_Image.push_back((char*)"  ____  $$   | $$  | $$__  $$| $$__  $$   | $$   ");
	StartImage.DOT_Image.push_back((char*)" /$$    $$   | $$  | $$  | $$| $$    $$   | $$   ");
	StartImage.DOT_Image.push_back((char*)"|  $$$$$$/   | $$  | $$  | $$| $$  | $$   | $$   ");
	StartImage.DOT_Image.push_back((char*)" \______/    |__/  |__/  |__/|__/  |__/   |__/   ");
	StartImage.Data.Position = Vector3((float)(InGameConsole_WidthSize * 0.5f - 30) + PlayerDataInfoSize, (float)(ConsoleHeightSize* 0.5f - 8));
	StartImage.Color = 9;
	m_vecTextureImage.push_back(StartImage);
	StartImage.DOT_Image.clear();

	StartImage.DOT_Image.push_back((char*)"               _______   _______   ________   ______    ______         __  ________  __    __  ________  ________  _______    __               ");
	StartImage.DOT_Image.push_back((char*)"              /         /         /          /         /              /  |/        |/     /  |/        |/        |/          /  |              ");
	StartImage.DOT_Image.push_back((char*)"              $$$$$$$  |$$$$$$$  |$$$$$$$$/ /$$$$$$  |/$$$$$$  |      $$/ $$$$$$$$/ $$    $$ |$$$$$$$$/ $$$$$$$$/ $$$$$$$  | $$/               ");
	StartImage.DOT_Image.push_back((char*)" ______       $$ |__$$ |$$ |__$$ |$$ |__    $$  __$$/ $$  __$$/       $/  $$ |__    $$$   $$ |   $$ |   $$ |__    $$ |__$$ | $/         ______ ");
	StartImage.DOT_Image.push_back((char*)"/      |      $$    $$/ $$    $$< $$    |   $$        $$                  $$    |   $$$$  $$ |   $$ |   $$    |   $$    $$<           /      |");
	StartImage.DOT_Image.push_back((char*)"$$$$$$/       $$$$$$$/  $$$$$$$  |$$$$$/     $$$$$$  | $$$$$$  |          $$$$$/    $$ $$ $$ |   $$ |   $$$$$/    $$$$$$$  |          $$$$$$/ ");
	StartImage.DOT_Image.push_back((char*)"              $$ |      $$ |  $$ |$$ |_____ /   __$$ |/   __$$ |          $$ |_____ $$ |$$$$ |   $$ |   $$ |_____ $$ |  $$ |                  ");
	StartImage.DOT_Image.push_back((char*)"              $$ |      $$ |  $$ |$$       |$$    $$/ $$    $$/           $$       |$$ | $$$ |   $$ |   $$       |$$ |  $$ |                  ");
	StartImage.DOT_Image.push_back((char*)"              $$/       $$/   $$/ $$$$$$$$/  $$$$$$/   $$$$$$/            $$$$$$$$/ $$/   $$/    $$/    $$$$$$$$/ $$/   $$/                   ");
	StartImage.Color = 14;
	StartImage.Data.Position = Vector3((float)(InGameConsole_WidthSize * 0.5 - 75) + PlayerDataInfoSize, (float)(ConsoleHeightSize * 0.5f + StartImage.DOT_Image.size()));
	m_vecTextureImage.push_back(StartImage);

}

int LogoInterface::Update()
{
	return 0;
}

void LogoInterface::Render()
{

	for (int i = 0; i < m_vecTextureImage.size(); ++i)
		ImageDraw(i);
}

void LogoInterface::Release()
{
	m_vecTextureImage.clear();
}

vector<char*> LogoInterface::Make_Box()
{
	return vector<char*>();
}

