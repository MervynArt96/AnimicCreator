#pragma once
#include <QGraphicsVideoItem>
#include "CanvasModule/CanvasObject/BaseObject.h"
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <QFile>
#include <QPixmap>

class VideoObject : public QGraphicsVideoItem//, public BaseObject
{
	Q_OBJECT

public:
	VideoObject(QObject* parent, QString);
	VideoObject(QString);
	~VideoObject();

	QString getVideoPath();
	QMediaPlayer* getPlayer();

	QRectF boundingRect();
	void drawBoundingRect();
	
	/*
	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;      //user input events
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
	void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
	void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;
	void hoverMoveEvent(QGraphicsSceneHoverEvent* event) override;
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseDragMoveEvent(QGraphicsSceneMouseEvent*) override;
	bool mousePosOnHandles(QPointF pos) override;
	*/

private:

	QString videoPath;
	QMediaPlayer* player;
	QPixmap* pixmapFrame;

public slots:

	//void onScrubEnter();
	//void onScrubExit();

	//void onFocused();
	//void onFocusExit();

	//void onDurationChanged();
	//void onSourceChanged();

};