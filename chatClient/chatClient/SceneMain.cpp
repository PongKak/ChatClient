#include "stdafx.h"
#include "SceneMain.h"



SceneMain::SceneMain(HWND hWnd,HDC memoryDC,HINSTANCE hInstance)
	:m_hWnd(hWnd),
	m_memoryDC(memoryDC),
	m_hInstance(hInstance)
{
	m_CurrentScene = CurrentScene::MainScene;
	Init();
}


SceneMain::~SceneMain()
{
	
}

void SceneMain::DrawScene()
{


}

void SceneMain::Init()
{

	m_Main = CreateWindow(TEXT("MainScene"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 0, 800, 600, m_hWnd, (HMENU)menu::login::MAIN, m_hInstance, NULL);

	CreateWindow(TEXT("button"), NULL, WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 200, 150, 400, 150, m_Main, NULL, m_hInstance, NULL);



	m_EditID = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 300, 200, 100, 25, m_Main, (HMENU)menu::login::EDITID, m_hInstance, NULL);
	m_EditPASSWORD = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 300, 230, 100, 25, m_Main, (HMENU)menu::login::EDITPASSWORD, m_hInstance, NULL);

	CreateWindow(TEXT("button"), TEXT("LOGIN"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 450, 200, 80, 60, m_Main, (HMENU)menu::login::LOGIN, m_hInstance, NULL);


	ShowWindow(m_Main, SW_SHOWMINNOACTIVE);
}

int SceneMain::Update()
{
	ShowWindow(m_Main, SW_SHOWMAXIMIZED);



	DrawScene();

	GetWindowText(m_EditID, m_ID, sizeof(m_ID));
	GetWindowText(m_EditPASSWORD, m_PASSWORD, sizeof(m_PASSWORD));
	return 0;
}
