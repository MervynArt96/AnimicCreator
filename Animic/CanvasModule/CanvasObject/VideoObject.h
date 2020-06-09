#pragma once
#include <QGraphicsVideoItem>
#include "CanvasModule/CanvasObject/BaseObject.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

class VideoObject : public QGraphicsVideoItem, public BaseObject
{
	Q_OBJECT

public:

	VideoObject(QObject*, QUrl*);
	~VideoObject();

	QString getVideoPath();
	QString getLoopPath();

	QMediaPlayer* getPlayer();
	QMediaPlaylist* getPlayList();

	void VideoObject::contextMenuEvent(QGraphicsSceneContextMenuEvent* event) override;

	//QRectF boundingRect();
	void playMedia();
	void pauseMedia();
	void stopMedia();
	void toggleMute();

	void setName(QString);
	QString getName();

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
	QUrl* loopPath;
	QBuffer* loopBuffer;
	QBuffer* mainBuffer;
	QMediaPlayer* player = nullptr;
	QMediaPlaylist* playList = nullptr;

	QString name = "Video Layer";

	QPointF mousePos;
	bool init = false;

	//qreal oriSizeX = 0;
	//qreal oriSizeY = 0;

	bool showRect = true;

signals:

	void scaleChanged();

public slots:

	void onFocused();	
	void onFocusExit();

	void disableRect();
	void enableRect();

	void onPosXChanged(const QString&); void onPosYChanged(const QString&);
	void onScaleChanged(const QString&);
	void onUrlChanged(const QString&);
	void onLoopPathChanged(const QString& str);

	void addLoop();
	void removeLoop();
	void switchPlayMode(int index);
};