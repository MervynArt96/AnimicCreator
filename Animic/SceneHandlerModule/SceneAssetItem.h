#pragma once

#include <QListWidgetItem>
#include "CanvasModule/AnimicScene.h"

struct VideoAsset
{
	QUrl path;
	QPointF pos;

};

struct ImageAsset
{
	QUrl path;
	QPointF pos;
};

struct AudioAsset
{
	QUrl path;

};

struct DialogueAsset
{
	QPointF pos;
	qreal playbackSpeed;
};


class SceneAssetItem : public QListWidgetItem
{

public:
	SceneAssetItem(QString ,QListWidget*);
	~SceneAssetItem();

	/*
	QList<VideoAsset> getVideoList();
	QList<ImageAsset> getImageList();
	QList<AudioAsset> getAudioList();
	QList<DialogueAsset> getDialogueList();

	AnimicScene* getScene();
	*/
	enum AssetType
	{
		Video,Image,
		Audio,Dialogue
	};

private:

	struct AssetList
	{
		QList<VideoAsset> videoList;
		QList<ImageAsset> imageList;
		QList<AudioAsset> audioList;
		QList<DialogueAsset> dialogueList;
	};

	AnimicScene* scene;

public slots:

	void onObjectInserted(AssetType, QUrl);
	void onObjectRemoved(AssetType, QUrl);

};
