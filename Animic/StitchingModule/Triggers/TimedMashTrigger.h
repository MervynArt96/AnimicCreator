#pragma once

#include <QGraphicsVideoItem>
#include <QMediaPlayer>
#include <QMediaPlaylist>;
#include "CanvasModule/CanvasObject/RectHandle.h"
#include <CanvasModule/AnimicScene.h>


class TimedMashTrigger : public QGraphicsVideoItem
{
	Q_OBJECT

public:
	TimedMashTrigger(QObject *parent, QUrl* filePath);
	~TimedMashTrigger();

	AnimicScene* getDefaultScene();
	AnimicScene* getAltScene();

	QString getName();
	void setName(QString);

	QString getUrl();
	void setUrl(QUrl*);

	int getTimeLimit();
	void setTimeLimit(int i);

	int getKeyMax();
	void setKeyMax(int i);

	QMediaPlayer* getPlayer();
	QMediaPlaylist* getPlayList();

	void setActiveTrigger(bool);

	void playMedia();
	void pauseMedia();
	void stopMedia();

	void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
	enum { Type = UserType + 102 };

	inline int type() const { return Type; }

	void keyPressEvent(QKeyEvent*) override;

	void mousePressEvent(QGraphicsSceneMouseEvent*) override;      //user input events
	void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;
	void hoverMoveEvent(QGraphicsSceneHoverEvent*) override;

	void createHandles();
	void transformHandle();

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

	QString name = "TimedMashTrigger";

	bool activeTrigger = false;

	int keyPressCount = 0;
	int keyMax = 3;
	int timeLimit = 3000;

signals:

	void sendDefaultScene(AnimicScene*);
	void sendAltScene(AnimicScene*);

public slots:

	void disableRect();
	void enableRect();

	void onKeyMaxChanged(int);
	void onDurationChanged(int);
		
	void onPosXChanged(const QString&); void onPosYChanged(const QString&);
	void onScaleChanged(const QString&);
	void onUrlChanged(const QString&);

	void setDefaultScene(AnimicScene* sc);
	void setAltScene(AnimicScene* sc);
};
