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

	AnimicScene(QListWidget*);
	AnimicScene();
	~AnimicScene();

	QString getName();
	void setName(QString);

	QGraphicsItem* getTrigger();
	QMediaPlayer* getMaxPlayer();

	VideoObject* selectedItem();
	//TwoWayTrigger* selectedTWTrigger();
	//TimedMashTrigger* selectedTMTrigger();
	//OneWayTrigger* selectedOWTrigger();

	void playThrough();

protected:

	QString mimeType();

	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent* event);
	void dragLeaveEvent(QGraphicsSceneDragDropEvent* event);
	void dropEvent(QGraphicsSceneDragDropEvent* event);
	void dragMoveEvent(QGraphicsSceneDragDropEvent* event);

	qint64 maxDuration = 0;

private:

	QString name = "Scene ";
	QListWidget* sceneList;

	QMediaPlaylist* bgmList = nullptr;
	QMediaPlayer* bgmPlayer = nullptr;

	QMediaPlayer* temp = nullptr;	//temp holder for video object/ trigger media player
	QMediaPlayer* max = nullptr;

	int triggerToBeInserted = 0; // null = -1, TW = 0, TM = 1, OW = 2

	bool checkForTrigger();

	/*QMediaPlaylist* bgmLoopList = nullptr;
	QMediaPlayer* bgmLoopPlayer = nullptr;
	*/

signals:

	void objectInserted(qint64);
	void subscribeTimeline(QMediaPlayer*); 
	void unscubscribeTimeline();
	void nextScene(AnimicScene*);
	void lastScene();

	void triggerInserted();

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

	void onEndOfMedia();

	void enableTrigger();
	void disableTrigger();
	void activateTrigger();

	void playTrigger();
	void pauseTrigger();
	void stopTrigger();

	void switchTriggerType(int);
};