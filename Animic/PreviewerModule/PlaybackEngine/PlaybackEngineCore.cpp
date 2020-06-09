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
	entry = findEntryScene();
	if (entry != nullptr)
	{
		emit playNextScene(entry);
		emit disableSpace();
	}
	else
	{
		emit terminatePreview();
	}
}

void PlaybackEngineCore::onNextScene(AnimicScene* sc)
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
