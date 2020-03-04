#pragma once

#include <QListWidgetItem>


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

	QList<VideoAsset> getVideoList();
	QList<ImageAsset> getImageList();
	QList<AudioAsset> getAudioList();
	QList<DialogueAsset> getDialogueList();

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

public slots:

	void onObjectInserted(AssetType, QUrl);
	void onObjectRemoved(AssetType, QUrl);

};
