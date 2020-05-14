#pragma once

#include <QGraphicsVideoItem>
#include <QMediaPlayer>
#include <QMediaPlaylist>;
#include <CanvasModule\AnimicScene.h>

class TwoWayTrigger : public QGraphicsVideoItem
{
	Q_OBJECT

public:

	TwoWayTrigger(QObject *parent);
	~TwoWayTrigger();

private:

	AnimicScene* sceneDefault = nullptr;
	AnimicScene* sceneAlt = nullptr;

	QMediaPlaylist* playList = nullptr;
	QMediaPlayer* player = nullptr;
	QUrl* videoPath = nullptr;

	bool persist = true;
	bool loop = true;

};
