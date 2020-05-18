#pragma once

#include <QGraphicsVideoItem>
#include <QMediaPlayer>
#include <QMediaPlaylist>;
#include <CanvasModule\AnimicScene.h>
#include "StitchingModule/Triggers/BaseTrigger.h"

class TwoWayTrigger : public QGraphicsVideoItem, public BaseTrigger
{
	Q_OBJECT

public:

	TwoWayTrigger(QObject *parent, QUrl*);
	~TwoWayTrigger();

	AnimicScene* getDefaultScene();
	AnimicScene* getAltScene();

	QString getName();
	void setName(QString);

	QMediaPlayer* getPlayer();
	QMediaPlaylist* getPlayList();

	void playMedia();
	void pauseMedia();
	void stopMedia();

	void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
	enum { Type = UserType + 101 };

	inline int type() const { return Type; }

	void mousePressEvent(QGraphicsSceneMouseEvent*) override;      //user input events
	void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;
	void hoverMoveEvent(QGraphicsSceneHoverEvent*) override;

	void createHandles();

private:

	QList<RectHandle*> handleList;
	QRectF objectRect;
	QPointF origin;

	RectHandle* currentHandle;

	QLineF RotationLine;
	QPolygonF m_AngleHandle;

	bool showRect = true;

	QPointF mousePos;
	bool init = false;

private:

	AnimicScene* sceneDefault = nullptr;
	AnimicScene* sceneAlt = nullptr;

	QMediaPlaylist* playList = nullptr;
	QMediaPlayer* player = nullptr;
	QUrl* videoPath = nullptr;

	QString name = "TwoWayTrigger1";

	bool persist = true;

public slots:

	void onFocused();
	void onFocusExit();

	void disableRect();
	void enableRect();
	
	void toggleLoop();

	void onUrlChanged();
};
