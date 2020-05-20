#pragma once

#include <CanvasModule\AnimicScene.h>


class PlaybackEngineCore
{
public:

	PlaybackEngineCore();
	PlaybackEngineCore(QList<AnimicScene*>);
	~PlaybackEngineCore();

	void refreshList(QList<AnimicScene*>);
	void setList();
	void getList();
	void playback();

private:

	QList<AnimicScene*> sceneList;

};

