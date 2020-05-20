#pragma once

#include "CanvasModule/CanvasObject/VideoObject.h"
#include "AssetHandlerModule/AssetHandler.h"
#include "AssetHandlerModule/TriggerAssetHandler.h"
#include <StitchingModule\Triggers\TwoWayTrigger.h>
#include <StitchingModule\Triggers\TimedMashTrigger.h>
#include <StitchingModule/Triggers/OneWayTrigger.h>
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
	void getTrigger();

	VideoObject* selectedItem();
	TwoWayTrigger* selectedTWTrigger();
	TimedMashTrigger* selectedTMTrigger();
	OneWayTrigger* selectedOWTrigger();

protected:

	QString mimeType();

	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent* event);
	void dragLeaveEvent(QGraphicsSceneDragDropEvent* event);
	void dropEvent(QGraphicsSceneDragDropEvent* event);
	void dragMoveEvent(QGraphicsSceneDragDropEvent* event);

	qint64 maxDuration = 0;

private:

	QString name = "Scene x";
	QListWidget* sceneList;

	QMediaPlaylist* bgmList = nullptr;
	QMediaPlayer* bgmPlayer = nullptr;

	QMediaPlayer* temp = nullptr;

	/*QMediaPlaylist* bgmLoopList = nullptr;
	QMediaPlayer* bgmLoopPlayer = nullptr;
	*/
signals:

	void objectInserted(qint64);
	void subscribeTimeline(QMediaPlayer*); 
	void unscubscribeTimeline();

public slots:

	void playAll();
	void pauseAll();
	void stopAll();

	void disableObjectDragging();
	void enableObjectDragging();

	void setVideoFrameTime(int);
	void onVideoLoaded(qint64);
	void onEndOfMedia();

	void enableTrigger();
	void disableTrigger();
	void playTrigger();
};