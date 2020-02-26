#include "stdafx.h"
#include "AnimicScene.h"

AnimicScene::AnimicScene()
{
	
}

AnimicScene::~AnimicScene()
{

}

QString AnimicScene::mimeType()
{
	return QString("text/uri-list");
}


void AnimicScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mousePressEvent(event);
}

void AnimicScene::dragEnterEvent(QGraphicsSceneDragDropEvent* event)
{
	QGraphicsScene::dragEnterEvent(event);
	if (event->mimeData()->hasUrls())
	{
		event->acceptProposedAction();
	}
}

void AnimicScene::dropEvent(QGraphicsSceneDragDropEvent* event)
{

	const QMimeData* mimedata = event->mimeData();

	for (QUrl url : mimedata->urls())
	{
		VideoObject* video = new VideoObject(this , &url);
		this->addItem(video);
	}
	event->acceptProposedAction();

}

void AnimicScene::dragMoveEvent(QGraphicsSceneDragDropEvent* event)
{

}

void AnimicScene::dragLeaveEvent(QGraphicsSceneDragDropEvent* event)
{

}
