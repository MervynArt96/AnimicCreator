#pragma once

#include "CanvasModule/CanvasObject/VideoObject.h"
#include "CanvasModule/CanvasObject/ImageObject.h"
#include "CanvasModule/CanvasObject/AudioObject.h"
#include "CanvasModule/CanvasObject/DialogueObject.h"

enum SceneType
{
	AutoScene,
	SingleButtonScene,
	MashButtonScene,
	HoldButtonScene,
	TimeLimitedScene,
	TwoWayScene,
	MultiWayScene
};

class AnimicScene : public QGraphicsScene
{
	Q_OBJECT

public:

	AnimicScene(QListWidget*);
	~AnimicScene();

protected:

	QString mimeType();

	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent* event);
	void dragLeaveEvent(QGraphicsSceneDragDropEvent* event);
	void dropEvent(QGraphicsSceneDragDropEvent* event);
	void dragMoveEvent(QGraphicsSceneDragDropEvent* event);

	void keyPressEvent(QKeyEvent* event);

private:

	//QList<VideoObject*> videoList;

	QListWidget* sceneList;

signals:

	void objectInserted();


};

