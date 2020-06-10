#pragma once

#include <QGraphicsVideoItem>
#include <CanvasModule\AnimicScene.h>

class OneWayTrigger : public QGraphicsVideoItem
{
	Q_OBJECT

public:
	OneWayTrigger(QObject *parent, QUrl* filePath);
	~OneWayTrigger();

	AnimicScene* getDefaultScene();

	QString getName();
	void setName(QString);

	QString getUrl();
	void setUrl(QUrl*);

	int getTimeLimit();
	void setTimeLimit(int i);

	QMediaPlayer* getPlayer();
	QMediaPlaylist* getPlayList();

	void setActiveTrigger(bool);

	void playMedia();
	void pauseMedia();
	void stopMedia();

	void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
	enum { Type = UserType + 103 };

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

	QMediaPlaylist* playList = nullptr;
	QMediaPlayer* player = nullptr;
	QUrl* videoPath = nullptr;

	QString name = "OneWayTrigger";

	bool activeTrigger = false;

	int timeLimit = 3000;

signals:

	void sendDefaultScene(AnimicScene*);

public slots:

	void disableRect();
	void enableRect();

	void onDurationChanged(int);

	void onPosXChanged(const QString&); void onPosYChanged(const QString&);
	void onScaleChanged(const QString&);
	void onUrlChanged(const QString&);

	void setDefaultScene(AnimicScene* sc);

};
