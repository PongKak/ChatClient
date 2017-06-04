#pragma once
class ClientScene
{
public:
	ClientScene() = default;
	virtual ~ClientScene() = default;

	virtual void DrawScene() = 0;
	virtual void Init() = 0;
	virtual int Update() = 0;


	HWND m_Main;
private:

};

