#pragma once

#include "TimelineModule/Timeline.h"
#include "CanvasModule/CanvasObject/VideoObject.h"

class AnimicScene : public QGraphicsScene
{
	Q_OBJECT

public:

	AnimicScene();
	~AnimicScene();

protected:

	QString mimeType();

	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent* event);
	void dragLeaveEvent(QGraphicsSceneDragDropEvent* event);
	void dropEvent(QGraphicsSceneDragDropEvent* event);
	void dragMoveEvent(QGraphicsSceneDragDropEvent* event);

private:




};

