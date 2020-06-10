#pragma once

#include "CanvasModule/CanvasObject/VideoObject.h"
#include "AssetHandlerModule/TriggerAssetHandler.h"
#include "AssetHandlerModule/AssetHandler.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

class AnimicScene : public QGraphicsScene
{
	Q_OBJECT

public:

	AnimicScene();
	~AnimicScene();

	QString getName();
	void setName(QString);

	QGraphicsItem* getTrigger();
	QMediaPlayer* getMaxPlayer();

	int getTriggerType();

	VideoObject* selectedItem();
	bool isEntry();
	void setEntry(bool);

	void playThrough();
	bool getPlaybackMode();
	void setPlaybackMode(bool);

	void engageLoopVideo();
	void disengageLoopingVideo();

protected:

	QString mimeType();

	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent* event);
	void dragLeaveEvent(QGraphicsSceneDragDropEvent* event);
	void dropEvent(QGraphicsSceneDragDropEvent* event);
	void dragMoveEvent(QGraphicsSceneDragDropEvent* event);

private:

	QString name = "Scene ";

	QMediaPlaylist* bgmList = nullptr;	//not used for now
	QMediaPlayer* bgmPlayer = nullptr;

	QMediaPlayer* temp = nullptr;	//temp holder for video object/ trigger media player
	QMediaPlayer* max = nullptr;
	qint64 maxDuration = 0;

	int triggerToBeInserted = 0; // null = -1, TW = 0, TM = 1, OW = 2

	bool entryScene = false;
	bool playbackMode = false;
	bool checkForTrigger();

	bool acceptTrigger = true;

signals:

	void objectInserted(qint64);
	void subscribeTimeline(QMediaPlayer*); 
	void unscubscribeTimeline();
	void nextScene(AnimicScene*);
	void lastScene();

	void deletingVideo();
	void triggerInserted();
	void foundNewMax(qint64);
	void nameChanged(QString);

public slots:

	void playAll();
	void pauseAll();
	void stopAll();

	void disableObjectDragging();
	void enableObjectDragging();

	void disconnectObject();
	void disconnectScene();

	void setVideoFrameTime(int);

	void onVideoLoaded(qint64);
	void onTriggerLoaded(qint64);

	void enableTrigger();
	void disableTrigger();
	void activateTrigger(QMediaPlayer::MediaStatus);
	void deactivateTrigger();

	void playTrigger();
	void pauseTrigger();
	void stopTrigger();
	void resetTriggerNextScene(AnimicScene* );

	void switchTriggerType(int);
	void resetScene();

	void onNextScene(AnimicScene*);
	void onLastScene();

	void onDeleteItem();
	void onDeleteTrigger();
	void disconnectMax();

	void onSetEntry(bool);

};