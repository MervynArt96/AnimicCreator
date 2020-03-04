#include "stdafx.h"
#include "AnimicScene.h"

AnimicScene::AnimicScene(QListWidget* list)
{
	sceneList = list;
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
		video->setPos(event->scenePos());
		this->addItem(video);

		emit objectInserted();
	}
	
	event->acceptProposedAction();

}

void AnimicScene::dragMoveEvent(QGraphicsSceneDragDropEvent* event)
{
	Q_UNUSED(event);
}

void AnimicScene::dragLeaveEvent(QGraphicsSceneDragDropEvent* event)
{
	Q_UNUSED(event);
}

void AnimicScene::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Space)
	{

		//for (VideoObject* item : );
		{
			
			
		}
	}
}