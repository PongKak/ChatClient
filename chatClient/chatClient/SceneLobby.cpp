#include "stdafx.h"
#include "SceneLobby.h"



SceneLobby::SceneLobby(HWND hWnd,HDC memoryDC,HINSTANCE hInstance)
	:m_hWnd(hWnd),
	m_memoryDC(memoryDC),
	m_hInstance(hInstance)
{
	m_CurrentScene = CurrentScene::LobbyScene;
	Init();
}


SceneLobby::~SceneLobby()
{
}

void SceneLobby::DrawScene()
{
}

void SceneLobby::Init()
{
	m_Main = CreateWindow(TEXT("ChannelScene"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 0, 800, 600, m_hWnd, (HMENU)menu::login::MAIN, m_hInstance, NULL);


	CreateWindow(TEXT("button"), TEXT("LogOut"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 650, 50, 80, 60, m_Main, (HMENU)menu::lobby::LOGOUT, m_hInstance, NULL);
	CreateWindow(TEXT("button"), TEXT("OUT"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 550, 50, 80, 60, m_Main, (HMENU)menu::lobby::CHANNELOUT, m_hInstance, NULL);

	ShowWindow(m_Main, SW_SHOWMINNOACTIVE);
}

int SceneLobby::Update()
{

	DrawScene();


	ShowWindow(m_Main, SW_SHOWMAXIMIZED);
	return 0;
}
