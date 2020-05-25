#include "stdafx.h"
#include "AnimicScene.h"
#include <StitchingModule/Triggers/TwoWayTrigger.h>
#include <StitchingModule/Triggers/TimedMashTrigger.h>
#include <StitchingModule/Triggers/OneWayTrigger.h>

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
		if (triggerToBeInserted == 0)					
		{
			for (QUrl url : mimedata->urls())
			{
				TwoWayTrigger* trigger = new TwoWayTrigger(this, &url);
				trigger->setPos(event->scenePos());
				this->addItem(trigger);

				//temp = trigger->getPlayer();
				connect(trigger->getPlayer(), SIGNAL(durationChanged(qint64)), this, SLOT(onTriggerLoaded(qint64)));

				pauseAll();
				//triggerToBeInserted = -1;
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
			//triggerToBeInserted = -1;
		}
		else if (triggerToBeInserted == 2)
		{
			//OneWayTrigger* trigger = new OneWayTrigger(this, &url);
			//trigger->setPos(event->scenePos());
			//this->addItem(trigger);

			//temp = trigger->getPlayer();
			//connect(trigger->getPlayer(), SIGNAL(durationChanged(qint64)), this, SLOT(onVideoLoaded(qint64)));

			pauseAll();
			//triggerToBeInserted = -1;
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
	qDebug() << "Disabling Object Dragging";
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

void AnimicScene::disconnectObject()
{
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		VideoObject* videoObj = qgraphicsitem_cast<VideoObject*>(item);
		if (videoObj != nullptr)
		{
			disconnect(videoObj);
		}
	}
}

void AnimicScene::disconnectScene()
{
	this->disconnect();
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

QMediaPlayer* AnimicScene::getMaxPlayer()
{
	return max;
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

			return true;
		}
		else if (TMTrigger != nullptr)
		{
			return true;
		}
		else if (OWTrigger != nullptr)
		{
			OWTrigger->setVisible(true);
			OWTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
			return true;
		}
	}
	return false;
}

QGraphicsItem* AnimicScene::getTrigger()
{
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		TwoWayTrigger* TWTrigger = qgraphicsitem_cast<TwoWayTrigger*>(item);
		TimedMashTrigger* TMTrigger = qgraphicsitem_cast<TimedMashTrigger*>(item);
		OneWayTrigger* OWTrigger = qgraphicsitem_cast<OneWayTrigger*>(item);

		if (TWTrigger != nullptr)
		{
			return TWTrigger;
		}
		else if (TMTrigger != nullptr)
		{
			return TMTrigger;
		}
		else if (OWTrigger != nullptr)
		{
			return OWTrigger;
		}
	}
	return nullptr;
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
			if (TWTrigger->getDefaultScene() == nullptr)
			{
				connect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &AnimicScene::lastScene);
			}
			else connect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &AnimicScene::nextScene);

			if (TWTrigger->getAltScene() == nullptr)
			{
				connect(TWTrigger, &TwoWayTrigger::sendAltScene, this, &AnimicScene::lastScene);
			}
			else connect(TWTrigger, &TwoWayTrigger::sendAltScene, this, &AnimicScene::nextScene);

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

void AnimicScene::playThrough()
{
	playAll();
	if(max != nullptr)
		connect(max, &QMediaPlayer::mediaStatusChanged, this, &AnimicScene::activateTrigger);
}

void AnimicScene::switchTriggerType(int i)
{
	qDebug() << "Trigger Type: " << triggerToBeInserted;
	triggerToBeInserted = i;
}