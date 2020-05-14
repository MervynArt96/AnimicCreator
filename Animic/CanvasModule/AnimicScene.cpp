#include "stdafx.h"
#include "AnimicScene.h"

AnimicScene::AnimicScene(QListWidget* list)
{
	sceneList = list;
	bgmList = new QMediaPlaylist();
	bgmPlayer = new QMediaPlayer();
	bgmPlayer->setPlaylist(bgmList);
}

AnimicScene::AnimicScene()
{
	bgmList = new QMediaPlaylist();
	bgmPlayer = new QMediaPlayer();
	bgmPlayer->setPlaylist(bgmList);
}

AnimicScene::~AnimicScene()
{
	delete bgmList;
	delete bgmPlayer;
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		VideoObject* videoObj = qgraphicsitem_cast<VideoObject*>(item);
		if (videoObj != nullptr)
		{
			delete videoObj;
		}
	}
}

QString AnimicScene::getName()
{
	return name;
}

void AnimicScene::setName(QString k)
{
	name = k;
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

		temp = video->getPlayer();
		connect(video->getPlayer(), SIGNAL(durationChanged(qint64)), this, SLOT(onVideoLoaded(qint64)));

		pauseAll();
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

void AnimicScene::playAll()
{
	bool found = false;
	bool first = false;
	QList<QGraphicsItem*> allItems = items();

	for(QGraphicsItem * item : allItems)
	{
		VideoObject* videoObj = qgraphicsitem_cast<VideoObject*>(item);
		if (videoObj != nullptr)
		{
			videoObj->playMedia();
			found = true;
			if(videoObj->getPlayer()->duration() >= maxDuration)
			{
				temp = videoObj->getPlayer();
				temp->setNotifyInterval(50);
			}
		}
		else return;

		if (found && !first)
		{
			emit subscribeTimeline(temp);
			found = false;
			first = true;
		}
	}

	bgmPlayer->play();
}

void AnimicScene::pauseAll()
{
	QList<QGraphicsItem*> allItems = items();

	for(QGraphicsItem* item : allItems)
	{
		VideoObject* videoObj = qgraphicsitem_cast<VideoObject*>(item);
		if (videoObj != nullptr)
		{
			videoObj->pauseMedia();
		}
		else return;
	}
	bgmPlayer->pause();
}

void AnimicScene::stopAll()
{
	QList<QGraphicsItem*> allItems = items();

	for(QGraphicsItem * item : allItems)
	{
		VideoObject* videoObj = qgraphicsitem_cast<VideoObject*>(item);
		if (videoObj != nullptr)
		{
			videoObj->stopMedia();
		}
		else return;
	}
	bgmPlayer->stop();
}

void AnimicScene::disableObjectDragging()
{
	QList<QGraphicsItem*> allItems = items();

	for(QGraphicsItem * item : allItems)
	{
		VideoObject* videoObj = qgraphicsitem_cast<VideoObject*>(item);
		if (videoObj != nullptr)
		{
			videoObj->setFlag(QGraphicsVideoItem::ItemIsMovable, false);
			videoObj->setFlag(QGraphicsVideoItem::ItemIsSelectable, false);
			videoObj->setFlag(QGraphicsVideoItem::ItemIsFocusable, false);
		}
		else return;
	}
}

void AnimicScene::enableObjectDragging()
{
	QList<QGraphicsItem*> allItems = items();

	for(QGraphicsItem * item : allItems)
	{
		VideoObject* videoObj = qgraphicsitem_cast<VideoObject*>(item);
		if (videoObj != nullptr)
		{
			videoObj->setFlag(QGraphicsVideoItem::ItemIsMovable, true);
			videoObj->setFlag(QGraphicsVideoItem::ItemIsSelectable, true);
			videoObj->setFlag(QGraphicsVideoItem::ItemIsFocusable, true);
		}
		else return;
	}
}

void AnimicScene::setVideoFrameTime(int pos)
{
	QList<QGraphicsItem*> allItems = items();

	for(QGraphicsItem * item : allItems)
	{
		VideoObject* videoObj = qgraphicsitem_cast<VideoObject*>(item);
		if (videoObj != nullptr)
		{
			videoObj->getPlayer()->setPosition(pos);
		}
		else return;
	}
}

void AnimicScene::onVideoLoaded(qint64 length)
{
	if (length > maxDuration)
	{
		maxDuration = length;
	}
	emit objectInserted(maxDuration);
	disconnect(temp, SIGNAL(durationChanged(qint64), this, SLOT(onVideoLoaded(qint64))));
}

