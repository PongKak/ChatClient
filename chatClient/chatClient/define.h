#pragma once


namespace menu
{
	enum class sceneState
	{
		SCENE_MAIN,
		SCENE_CHANNEL,
		SCENE_LOBBY,
	};

	enum class login
	{
		MAIN = 101,
		LOGIN,
		CANSLE,
		EDITID,
		EDITPASSWORD,

	};

	enum class channel
	{
		MAIN = 101,
		LOGOUT,
		LIST,
		JOIN,
	};

	enum class lobby
	{
		MAIN = 101,
		LOGOUT,
		CHANNELOUT,

	};

}


enum class CurrentScene {
	MainScene,
	ChannelScene,
	LobbyScene,
};