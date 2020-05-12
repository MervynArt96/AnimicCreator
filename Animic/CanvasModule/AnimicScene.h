#pragma once

#include "CanvasModule/CanvasObject/VideoObject.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

class AnimicScene : public QGraphicsScene
{
	Q_OBJECT

public:

	AnimicScene(QListWidget*);
	~AnimicScene();

protected:

	QString mimeType();

	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent* event);
	void dragLeaveEvent(QGraphicsSceneDragDropEvent* event);
	void dropEvent(QGraphicsSceneDragDropEvent* event);
	void dragMoveEvent(QGraphicsSceneDragDropEvent* event);

	qint64 maxDuration = 0;

private:

	//QList<VideoObject*> videoList;
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
};

