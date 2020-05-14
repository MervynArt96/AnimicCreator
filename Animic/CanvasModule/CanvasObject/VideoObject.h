#pragma once
#include <QGraphicsVideoItem>
#include "CanvasModule/CanvasObject/BaseObject.h"
#include <QMediaPlayer>
#include <QFile>
#include <QPixmap>
#include <QGraphicsItem>

class VideoObject : public QGraphicsVideoItem, public BaseObject
{
	Q_OBJECT

public:

	VideoObject(QObject*, QUrl*);
	~VideoObject();

	QString getVideoPath();
	QMediaPlayer* getPlayer();

	//QRectF boundingRect();
	
	void setPixmap(QPixmap*);
	void playMedia();
	void pauseMedia();
	void stopMedia();
	void toggleMute();

	void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);// override;
	enum { Type = UserType + 1 };

	inline int type() const { return Type;}


protected:
	void mousePressEvent(QGraphicsSceneMouseEvent*) override;      //user input events
	void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;
	void hoverMoveEvent(QGraphicsSceneHoverEvent*) override;
	//bool mousePosOnHandles(QPointF) override;
	//QVariant itemChange(QGraphicsItem::GraphicsItemChange, const QVariant) override;
	
private:

	QUrl* videoPath;
	QMediaPlayer* player = nullptr;
	QMediaPlaylist* playList = nullptr;
	QPixmap* pixmapFrame = nullptr;

	QPointF mousePos;
	bool init = false;

	qreal oriSizeX;
	qreal oriSizeY;

	bool showRect = true;

signals:

	void scaleChanged();

public slots:

	void onFocused();	
	void onFocusExit();

	//void onPosXChanged(); void onPosYChanged();
	//scale change
	//url change

};