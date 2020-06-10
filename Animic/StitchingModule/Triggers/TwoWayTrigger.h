#pragma once

#include <QGraphicsVideoItem>
#include <QMediaPlayer>
#include <QMediaPlaylist>;
#include "CanvasModule/CanvasObject/RectHandle.h"
#include <CanvasModule/AnimicScene.h>

class TwoWayTrigger : public QGraphicsVideoItem
{
	Q_OBJECT

public:

	TwoWayTrigger(QObject *parent, QUrl*);
	~TwoWayTrigger();

	AnimicScene* getDefaultScene();
	AnimicScene* getAltScene();

	QString getName();
	void setName(QString);

	QString getUrl();
	void setUrl(QUrl*);

	QMediaPlayer* getPlayer();
	QMediaPlaylist* getPlayList();

	void setActiveTrigger(bool);

	void playMedia();
	void pauseMedia();
	void stopMedia();

	void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
	enum { Type = UserType + 101 };

	inline int type() const { return Type; }

	void keyPressEvent(QKeyEvent*) override;

	void mousePressEvent(QGraphicsSceneMouseEvent*) override;      //user input events
	void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;
	void hoverMoveEvent(QGraphicsSceneHoverEvent*) override;

	void createHandles();
	void transformHandle();

	void contextMenuEvent(QGraphicsSceneContextMenuEvent* event) override;

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

	AnimicScene* sceneDefault = nullptr;
	AnimicScene* sceneAlt = nullptr;

	QMediaPlaylist* playList = nullptr;
	QMediaPlayer* player = nullptr;
	QUrl* videoPath = nullptr;

	QString name = "TwoWayTrigger1";

	bool activeTrigger = false;

signals:
	
	void sendDefaultScene(AnimicScene*);
	void sendAltScene(AnimicScene*);

public slots:

	void disableRect();
	void enableRect();

	void onPosXChanged(const QString&); void onPosYChanged(const QString&);
	void onScaleChanged(const QString&);
	void onUrlChanged(const QString&);

	void setDefaultScene(AnimicScene* sc);
	void setAltScene(AnimicScene* sc);

	void resetNextScenes(AnimicScene*);
};
