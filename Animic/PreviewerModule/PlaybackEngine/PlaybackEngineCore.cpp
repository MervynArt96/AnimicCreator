#include "stdafx.h"
#include "PlaybackEngineCore.h"

PlaybackEngineCore::PlaybackEngineCore()	//contains preview playback logic
{

}

PlaybackEngineCore::PlaybackEngineCore(QList<AnimicScene*> list)	//get a reference list of all the scenes, during initialization
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

void PlaybackEngineCore::playback()	//starts the playback here
{
	entry = findEntryScene();	//get the first scene
	if (entry != nullptr)		// if found the first scene
	{
		emit playNextScene(entry);	//start playback
		emit disableSpace();		// space is used to start the playback, hence it is disabled to prevent user from starting the playback again when it is already running
	}
	else
	{
		emit terminatePreview();	//end preview playback
	}
}

void PlaybackEngineCore::onNextScene(AnimicScene* sc)	//play next scene
{
	emit playNextScene(sc);
}

AnimicScene* PlaybackEngineCore::findEntryScene()
{
	for (int i = 0; i < sceneList.count(); i++)
	{
		if (sceneList.at(i)->isEntry())
		{
			return sceneList.at(i);
		}
	}

	return nullptr;
}

void PlaybackEngineCore::onTerminate()
{
	emit terminatePreview();
}
