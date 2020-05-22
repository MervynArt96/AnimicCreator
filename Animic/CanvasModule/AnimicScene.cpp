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

VideoObject* AnimicScene::selectedItem()
{
	QList<QGraphicsItem*> itemList = QGraphicsScene::selectedItems();

	for (QGraphicsItem* item : itemList)
	{
		VideoObject* obj = qgraphicsitem_cast<VideoObject*>(item);
		if (obj != nullptr)
		{
			return obj;
		}
	}
	return nullptr;
}

TwoWayTrigger* AnimicScene::selectedTWTrigger()
{
	QList<QGraphicsItem*> itemList = QGraphicsScene::selectedItems();
	for (QGraphicsItem* item : itemList)
	{
		TwoWayTrigger* obj = qgraphicsitem_cast<TwoWayTrigger*>(item);
		if (obj != nullptr)
		{
			return obj;
		}
	}
	return nullptr;

}

TimedMashTrigger* AnimicScene::selectedTMTrigger()
{
	QList<QGraphicsItem*> itemList = QGraphicsScene::selectedItems();
	for (QGraphicsItem* item : itemList)
	{
		TimedMashTrigger* obj = qgraphicsitem_cast<TimedMashTrigger*>(item);
		if (obj != nullptr)
		{
			return obj;
		}
	}
	return nullptr;
}

OneWayTrigger* AnimicScene::selectedOWTrigger()
{
	QList<QGraphicsItem*> itemList = QGraphicsScene::selectedItems();
	for (QGraphicsItem* item : itemList)
	{
		OneWayTrigger* obj = qgraphicsitem_cast<OneWayTrigger*>(item);
		if (obj != nullptr)
		{
			return obj;
		}
	}
	return nullptr;
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

	if (dynamic_cast<AssetHandler*>(event->source()))
	{
		for (QUrl url : mimedata->urls())
		{
			VideoObject* video = new VideoObject(this, &url);
			video->setPos(event->scenePos());
			this->addItem(video);

			temp = video->getPlayer();
			connect(video->getPlayer(), SIGNAL(durationChanged(qint64)), this, SLOT(onVideoLoaded(qint64)));

			pauseAll();
		}
	}
	else if (dynamic_cast<TriggerAssetHandler*>(event->source()))
	{
		qDebug() << "Dropping from trigger asset";
		if (triggerToBeInserted == 0)					//button toggle for different trigger type
		{
			for (QUrl url : mimedata->urls())
			{
				TwoWayTrigger* trigger = new TwoWayTrigger(this, &url);
				trigger->setPos(event->scenePos());
				this->addItem(trigger);

				//temp = trigger->getPlayer();
				connect(trigger->getPlayer(), SIGNAL(durationChanged(qint64)), this, SLOT(onVideoLoaded(qint64)));

				pauseAll();
				triggerToBeInserted = -1;
			}
		}
		else if (triggerToBeInserted == 1)
		{
			//TimedMashTrigger* trigger = new TimedMashTrigger(this, &url);
			//trigger->setPos(event->scenePos());
			//this->addItem(trigger);

			//temp = trigger->getPlayer();
			//connect(trigger->getPlayer(), SIGNAL(durationChanged(qint64)), this, SLOT(onVideoLoaded(qint64)));

			pauseAll();
			triggerToBeInserted = -1;
		}
		else if (triggerToBeInserted == 2)
		{
			//OneWayTrigger* trigger = new OneWayTrigger(this, &url);
			//trigger->setPos(event->scenePos());
			//this->addItem(trigger);

			//temp = trigger->getPlayer();
			//connect(trigger->getPlayer(), SIGNAL(durationChanged(qint64)), this, SLOT(onVideoLoaded(qint64)));

			pauseAll();
			triggerToBeInserted = -1;
		}
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
	}
}

void AnimicScene::onVideoLoaded(qint64 length)
{
	if (length > maxDuration)
	{
		maxDuration = length;
		max = temp;
	}
	emit objectInserted(maxDuration);
	disconnect(temp, SIGNAL(durationChanged(qint64), this, SLOT(onVideoLoaded(qint64))));
}

void AnimicScene::onTriggerLoaded(qint64 length)
{
	emit objectInserted(maxDuration);
	disconnect(temp, SIGNAL(durationChanged(qint64), this, SLOT(onVideoLoaded(qint64))));
}

void AnimicScene::onEndOfMedia()
{
	activateTrigger();
}

bool AnimicScene::checkForTrigger()
{
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		TwoWayTrigger* TWTrigger = qgraphicsitem_cast<TwoWayTrigger*>(item);
		TimedMashTrigger* TMTrigger = qgraphicsitem_cast<TimedMashTrigger*>(item);
		OneWayTrigger* OWTrigger = qgraphicsitem_cast<OneWayTrigger*>(item);

		if (TWTrigger != nullptr || TMTrigger != nullptr)
		{

		}
		else if (TMTrigger != nullptr)
		{

		}
		else if (OWTrigger != nullptr)
		{
			OWTrigger->setVisible(true);
			OWTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
		}
	}
}

QGraphicsItem* AnimicScene::getTrigger()
{
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		VideoObject* obj = qgraphicsitem_cast<VideoObject*>(item);

		if (obj == nullptr)
		{
			return item;
		}
	}
}

void AnimicScene::enableTrigger()
{
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		VideoObject* obj = qgraphicsitem_cast<VideoObject*>(item);

		if (obj == nullptr)
		{
			item->setVisible(true);
			item->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
		}
	}
}

void AnimicScene::disableTrigger()
{
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		VideoObject* obj = qgraphicsitem_cast<VideoObject*>(item);

		if (obj == nullptr)
		{
			item->setVisible(false);
			item->setFlags(item->flags().setFlag(QGraphicsVideoItem::ItemIsMovable, false)
				.setFlag(QGraphicsVideoItem::ItemIsFocusable, false)
				.setFlag(QGraphicsVideoItem::ItemIsSelectable, false));
		}
	}
}

void AnimicScene::activateTrigger()
{
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		TwoWayTrigger* TWTrigger = qgraphicsitem_cast<TwoWayTrigger*>(item);
		TimedMashTrigger* TMTrigger = qgraphicsitem_cast<TimedMashTrigger*>(item);
		OneWayTrigger* OWTrigger = qgraphicsitem_cast<OneWayTrigger*>(item);

		if (TWTrigger != nullptr)
		{
			TWTrigger->setVisible(true);
			TWTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
			TWTrigger->setActiveTrigger(true);

			//play trigger
			if (TWTrigger->getDefaultScene() == nullptr && TWTrigger->getAltScene() == nullptr)
			{
				connect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &lastScene);
				connect(TWTrigger, &TwoWayTrigger::sendAltScene, this, &lastScene);
			}
			else
			connect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &nextScene);
			connect(TWTrigger, &TwoWayTrigger::sendAltScene, this, &nextScene);

			return;
		}
		else if(TMTrigger != nullptr)
		{
			TMTrigger->setVisible(true);
			TMTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
			//TMTrigger->setActiveTrigger(true);
			return;
		}
		else if(OWTrigger != nullptr)
		{
			OWTrigger->setVisible(true);
			OWTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
			//OWTrigger->setActiveTrigger(true);
		}
	}
}

void AnimicScene::nextScene(AnimicScene*)
{

}

void AnimicScene::lastScene()
{

}

void AnimicScene::playThrough()
{
	playAll();
	if(max != nullptr)
		connect(max, &QMediaPlayer::mediaStatusChanged, this, &activateTrigger);
}
