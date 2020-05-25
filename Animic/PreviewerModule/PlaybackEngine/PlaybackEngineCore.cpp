#include "stdafx.h"
#include "PlaybackEngineCore.h"

PlaybackEngineCore::PlaybackEngineCore()
{

}

PlaybackEngineCore::PlaybackEngineCore(QList<AnimicScene*> list)
{
	sceneList = list;
}

PlaybackEngineCore::~PlaybackEngineCore()
{

}

void PlaybackEngineCore::refreshList(QList<AnimicScene*> list)
{
	sceneList.clear();
	sceneList = list;
}

void PlaybackEngineCore::setList(QList<AnimicScene*> list)
{
	sceneList = list;
}

QList<AnimicScene*> PlaybackEngineCore::getList()
{
	return sceneList;
}

void PlaybackEngineCore::playback()
{
	//event loop?
	for (AnimicScene* scene : sceneList)
	{
		//connect(scene, &AnimicScene::nextScene, this, &onNextScene);
	}
}

void PlaybackEngineCore::onNextScene(AnimicScene* sc)
{
	emit playNextScene(sc);
}