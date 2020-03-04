#pragma once
#include <QGraphicsPixmapItem>
//#include "CanvasModule/CanvasObject/BaseObject.h"

class ImageObject : public QGraphicsPixmapItem//, public BaseObject
{

public:
	ImageObject(QObject *parent, QUrl*);
	~ImageObject();

	//void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

protected:

	//void mousePressEvent(QGraphicsSceneMouseEvent*) override;      //user input events
	//void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;
	//void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;
	//void hoverMoveEvent(QGraphicsSceneHoverEvent*) override;
	
private:

	QUrl* imagePath;

	QPointF mousePos;
	bool init = false;

public slots:

	/*void onSliderChange();
	void onSliderEnter();
	void onSliderExit();
	void onDurationChanged();*/

};