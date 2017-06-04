#include "stdafx.h"
#include "SceneManager.h"
#include "SceneMain.h"
#include "SceneChannel.h"
#include "SceneLobby.h"

SceneManager::SceneManager(HWND hWnd,HDC memoryDC,HINSTANCE hInstance)
	:m_hWnd(hWnd),
	m_memoryDC(memoryDC),
	m_hInstance(hInstance)
{
	m_pMainScene = new SceneMain(hWnd, memoryDC,hInstance);
	m_pChannelScene = new SceneChannel(hWnd, memoryDC,hInstance);
	m_pLobbyScene = new SceneLobby(hWnd, memoryDC, hInstance);
	m_SceneNum = CurrentScene::MainScene;
}


SceneManager::~SceneManager()
{
}

void SceneManager::update()
{
	SelectCurrentScene();
	m_pCurrentScene->Update();
}


void SceneManager::DeleteScene()
{
	m_pCurrentScene->~ClientScene();
}

void SceneManager::SelectCurrentScene()
{
	switch (m_SceneNum)
	{
		case CurrentScene::MainScene :
		{
			m_pCurrentScene = m_pMainScene;
			break;
		}
		case CurrentScene::ChannelScene : 
		{
			m_pCurrentScene = m_pChannelScene;
			break;
		}
		case CurrentScene::LobbyScene:
		{
			m_pCurrentScene = m_pLobbyScene;
			break;
		}
		default : 
		{
			break;
		}
	}
}

void SceneManager::ChangeScene(CurrentScene sceneNum)
{
	ShowWindow(m_pCurrentScene->m_Main, SW_SHOWMINNOACTIVE);
	//InvalidateRect(m_hWnd, NULL, FALSE);
	m_SceneNum = sceneNum;

}

