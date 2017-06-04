#include "stdafx.h"
#include "SceneChannel.h"



SceneChannel::SceneChannel(HWND hWnd, HDC memoryDC, HINSTANCE hInstance)
	:m_hWnd(hWnd),
	m_memoryDC(memoryDC),
	m_hInstance(hInstance)
{

	m_CurrentScene = CurrentScene::ChannelScene;
	Init();
}


SceneChannel::~SceneChannel()
{

}

void SceneChannel::DrawScene()
{
	
}

void SceneChannel::Init()
{
	m_Main = CreateWindow(TEXT("ChannelScene"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 0, 800, 600, m_hWnd, (HMENU)menu::login::MAIN, m_hInstance, NULL);

	m_ChannelList = CreateWindow(TEXT("listbox"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL, 100, 100, 400, 300, m_Main, (HMENU)menu::channel::LIST, m_hInstance, NULL);




	CreateWindow(TEXT("button"), TEXT("LogOut"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 650, 50, 80, 60, m_Main, (HMENU)menu::channel::LOGOUT, m_hInstance, NULL);
	CreateWindow(TEXT("button"), TEXT("Join"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 550, 50, 80, 60, m_Main, (HMENU)menu::channel::JOIN, m_hInstance, NULL);




	ShowWindow(m_Main, SW_SHOWMINNOACTIVE);
}

int SceneChannel::Update()
{

	DrawScene();


	ShowWindow(m_Main, SW_SHOWMAXIMIZED);
	return 0;
}
