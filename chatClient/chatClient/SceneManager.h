#pragma once

class ClientScene;

class SceneManager
{
public:
	SceneManager(HWND,HDC,HINSTANCE);
	~SceneManager();


	void update();
	void DeleteScene();
	void SelectCurrentScene();
	void ChangeScene(CurrentScene);

	ClientScene* m_pCurrentScene;
	ClientScene* m_pMainScene;
	ClientScene* m_pChannelScene;
	ClientScene* m_pLobbyScene;



private:


	HWND m_hWnd;
	HDC m_memoryDC;
	HINSTANCE m_hInstance;
	CurrentScene m_SceneNum;


};

