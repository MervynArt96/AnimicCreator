#include "stdafx.h"
#include "AnimicScene.h"
#include <StitchingModule/Triggers/TwoWayTrigger.h>
#include <StitchingModule/Triggers/TimedMashTrigger.h>
#include <StitchingModule/Triggers/OneWayTrigger.h>

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
	emit nameChanged(k);
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

void AnimicScene::onDeleteItem()
{
	QList<QGraphicsItem*> itemList = QGraphicsScene::selectedItems();

	for (int i = 0; i < itemList.size(); i++)
	{
		emit deletingVideo();
		VideoObject* obj = qgraphicsitem_cast<VideoObject*>(itemList.at(i));
		if(obj != nullptr)
		{
			if (max == obj->getPlayer())
			{
				max = nullptr;
				maxDuration = 0;
			}
		}
		removeItem(itemList.at(i));
		delete(itemList.at(i));
	}
	QList<QGraphicsItem*> list = QGraphicsScene::items();

	qint64 tempDuration = 0;
	bool found = false;


	for (int i = 0; i < list.size(); i++)
	{
		VideoObject* obj = qgraphicsitem_cast<VideoObject*>(list.at(i));
		if (obj != nullptr)
		{
			if (obj->getPlayer()->duration() > tempDuration)
			{
				qDebug() << obj;
				found = true;
				max = obj->getPlayer();
				maxDuration = obj->getPlayer()->duration();
				tempDuration = maxDuration;
			}
		}
	}
	if (found == true)
	{
		emit foundNewMax(maxDuration);
	}
	else emit foundNewMax(0);
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
		for (QUrl url : mimedata->urls())
		{
			if (triggerToBeInserted == 0)
			{
				TwoWayTrigger* trigger = new TwoWayTrigger(this, &url);
				trigger->setPos(event->scenePos());
				this->addItem(trigger);
				emit triggerInserted();

				pauseAll();
				return;
			}
			else if (triggerToBeInserted == 1)
			{
				TimedMashTrigger* trigger = new TimedMashTrigger(this, &url);
				trigger->setPos(event->scenePos());
				this->addItem(trigger);
				emit triggerInserted();

				pauseAll();
				return;
			}
			else if (triggerToBeInserted == 2)
			{
				OneWayTrigger* trigger = new OneWayTrigger(this, &url);
				trigger->setPos(event->scenePos());
				this->addItem(trigger);
				emit triggerInserted();

				pauseAll();
				return;
			}
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
	emit triggerInserted();
	disconnect(temp, SIGNAL(durationChanged(qint64), this, SLOT(onTriggerLoaded(qint64))));
}

bool AnimicScene::checkForTrigger()	//might skip
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

	if(playbackMode)		//when previewing and can't find trigger
		emit lastScene();		//end preview early

	return nullptr;
}

void AnimicScene::playTrigger()
{
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		TwoWayTrigger* TWTrigger = qgraphicsitem_cast<TwoWayTrigger*>(item);
		TimedMashTrigger* TMTrigger = qgraphicsitem_cast<TimedMashTrigger*>(item);
		OneWayTrigger* OWTrigger = qgraphicsitem_cast<OneWayTrigger*>(item);

		if (TWTrigger != nullptr)
		{
			TWTrigger->playMedia();
		}
		else if (TMTrigger != nullptr)
		{
			TMTrigger->playMedia();
		}
		else if (OWTrigger != nullptr)
		{
			OWTrigger->playMedia();
		}
	}
}

void AnimicScene::pauseTrigger()
{
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		TwoWayTrigger* TWTrigger = qgraphicsitem_cast<TwoWayTrigger*>(item);
		TimedMashTrigger* TMTrigger = qgraphicsitem_cast<TimedMashTrigger*>(item);
		OneWayTrigger* OWTrigger = qgraphicsitem_cast<OneWayTrigger*>(item);

		if (TWTrigger != nullptr)
		{
			TWTrigger->pauseMedia();
		}
		else if (TMTrigger != nullptr)
		{
			TMTrigger->pauseMedia();
		}
		else if (OWTrigger != nullptr)
		{
			OWTrigger->pauseMedia();
		}
	}
}

void AnimicScene::stopTrigger()
{
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		TwoWayTrigger* TWTrigger = qgraphicsitem_cast<TwoWayTrigger*>(item);
		TimedMashTrigger* TMTrigger = qgraphicsitem_cast<TimedMashTrigger*>(item);
		OneWayTrigger* OWTrigger = qgraphicsitem_cast<OneWayTrigger*>(item);

		if (TWTrigger != nullptr)
		{
			TWTrigger->stopMedia();
		}
		else if (TMTrigger != nullptr)
		{
			TMTrigger->stopMedia();
		}
		else if (OWTrigger != nullptr)
		{
			OWTrigger->stopMedia();
		}
	}
}


void AnimicScene::enableTrigger()
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
		}
		else if (TMTrigger != nullptr)
		{
			TMTrigger->setVisible(true);
			TMTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
		}
		else if (OWTrigger != nullptr)
		{
			OWTrigger->setVisible(true);
			OWTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
		}
	}
}

void AnimicScene::disableTrigger()
{
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		TwoWayTrigger* TWTrigger = qgraphicsitem_cast<TwoWayTrigger*>(item);
		TimedMashTrigger* TMTrigger = qgraphicsitem_cast<TimedMashTrigger*>(item);
		OneWayTrigger* OWTrigger = qgraphicsitem_cast<OneWayTrigger*>(item);

		if (TWTrigger != nullptr)
		{
			qDebug() << "Stopping Trigger, removing visibility";
			TWTrigger->stopMedia();
			TWTrigger->setVisible(false);
			TWTrigger->setFlag(QGraphicsVideoItem::ItemIsMovable, false);
			TWTrigger->setFlag(QGraphicsVideoItem::ItemIsSelectable, false);
			TWTrigger->setFlag(QGraphicsVideoItem::ItemIsFocusable, false);
		}
		else if (TMTrigger != nullptr)
		{

		}
		else if (OWTrigger != nullptr)
		{

		}
	}
}

void AnimicScene::activateTrigger(QMediaPlayer::MediaStatus status)
{
	if (status == QMediaPlayer::EndOfMedia) 
	{
		playbackMode = true;
		QList<QGraphicsItem*> allItems = items();
		engageLoopVideo();

		for (QGraphicsItem* item : allItems)
		{
			TwoWayTrigger* TWTrigger = qgraphicsitem_cast<TwoWayTrigger*>(item);
			TimedMashTrigger* TMTrigger = qgraphicsitem_cast<TimedMashTrigger*>(item);
			OneWayTrigger* OWTrigger = qgraphicsitem_cast<OneWayTrigger*>(item);

			if (TWTrigger != nullptr)
			{
				TWTrigger->setVisible(true);
				TWTrigger->setActiveTrigger(true);
				TWTrigger->setFlag(QGraphicsVideoItem::ItemIsMovable, false);
				TWTrigger->setFlag(QGraphicsVideoItem::ItemIsSelectable, false);
				TWTrigger->setFlag(QGraphicsVideoItem::ItemIsFocusable);

				if (TWTrigger->getDefaultScene() == nullptr)
				{
					connect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &AnimicScene::onLastScene);
				}
				else connect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &AnimicScene::onNextScene);

				if (TWTrigger->getAltScene() == nullptr)
				{
					connect(TWTrigger, &TwoWayTrigger::sendAltScene, this, &AnimicScene::onLastScene);
				}
				else connect(TWTrigger, &TwoWayTrigger::sendAltScene, this, &AnimicScene::onNextScene);

				TWTrigger->playMedia();

				return;
			}
			else if (TMTrigger != nullptr)
			{
				TMTrigger->setVisible(true);
				TMTrigger->setActiveTrigger(true);
				TMTrigger->setFlag(QGraphicsVideoItem::ItemIsMovable, false);
				TMTrigger->setFlag(QGraphicsVideoItem::ItemIsSelectable, false);
				TMTrigger->setFlag(QGraphicsVideoItem::ItemIsFocusable);
				
				if (TMTrigger->getDefaultScene() == nullptr)
				{
					connect(TMTrigger, &TimedMashTrigger::sendDefaultScene, this, &AnimicScene::onLastScene);
				}
				else connect(TMTrigger, &TimedMashTrigger::sendDefaultScene, this, &AnimicScene::onNextScene);

				if (TMTrigger->getAltScene() == nullptr)
				{
					connect(TMTrigger, &TimedMashTrigger::sendAltScene, this, &AnimicScene::onLastScene);
				}
				else connect(TMTrigger, &TimedMashTrigger::sendAltScene, this, &AnimicScene::onNextScene);

				TMTrigger->playMedia();

				return;
			}
			
			else if (OWTrigger != nullptr)
			{
				OWTrigger->setVisible(true);
				OWTrigger->setActiveTrigger(true);
				OWTrigger->setFlag(QGraphicsVideoItem::ItemIsMovable, false);
				OWTrigger->setFlag(QGraphicsVideoItem::ItemIsSelectable, false);
				OWTrigger->setFlag(QGraphicsVideoItem::ItemIsFocusable);
				
				if (OWTrigger->getDefaultScene() == nullptr)
				{
					connect(OWTrigger, &OneWayTrigger::sendDefaultScene, this, &AnimicScene::onLastScene);
				}
				else connect(OWTrigger, &OneWayTrigger::sendDefaultScene, this, &AnimicScene::onNextScene);

				OWTrigger->playMedia();

				return;
			}
							/*
							else if() More Trigger Type to be Added Here......
							{
			
							}
			
							*/
		}
		qDebug() << "No Trigger Found, Terminating Scene";
		onLastScene();	//if can't find a single trigger, terminate early.
	}
}

void AnimicScene::deactivateTrigger()		//going back to stitching dialog
{
	playbackMode = false;
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		TwoWayTrigger* TWTrigger = qgraphicsitem_cast<TwoWayTrigger*>(item);
		TimedMashTrigger* TMTrigger = qgraphicsitem_cast<TimedMashTrigger*>(item);
		OneWayTrigger* OWTrigger = qgraphicsitem_cast<OneWayTrigger*>(item);

		if (TWTrigger != nullptr)
		{
			TWTrigger->setVisible(true);
			TWTrigger->setActiveTrigger(false);
			TWTrigger->stopMedia();
			TWTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
			disconnect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &AnimicScene::onLastScene);
			disconnect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &AnimicScene::onNextScene);
			disconnect(TWTrigger, &TwoWayTrigger::sendAltScene, this, &AnimicScene::onNextScene);
			disconnect(TWTrigger, &TwoWayTrigger::sendAltScene, this, &AnimicScene::onLastScene);

			return;
		}
		else if (TMTrigger != nullptr)
		{
			TMTrigger->setVisible(true);
			TMTrigger->setActiveTrigger(false);
			TMTrigger->stopMedia();
			TMTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
			disconnect(TMTrigger, &TimedMashTrigger::sendDefaultScene, this, &AnimicScene::onLastScene);
			disconnect(TMTrigger, &TimedMashTrigger::sendDefaultScene, this, &AnimicScene::onNextScene);
			disconnect(TMTrigger, &TimedMashTrigger::sendAltScene, this, &AnimicScene::onNextScene);
			disconnect(TMTrigger, &TimedMashTrigger::sendAltScene, this, &AnimicScene::onLastScene);

			return;
		}
		else if (OWTrigger != nullptr)
		{
			OWTrigger->stopMedia();
			OWTrigger->setVisible(true);
			OWTrigger->setActiveTrigger(false);
			OWTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
			disconnect(OWTrigger, &OneWayTrigger::sendDefaultScene, this, &AnimicScene::onLastScene);
			disconnect(OWTrigger, &OneWayTrigger::sendDefaultScene, this, &AnimicScene::onNextScene);
			
		}
	}
}


void AnimicScene::playThrough()
{
	if(items().count() == 0)	// if empty scene then ignore, and send terminate signal
	{	
		emit lastScene();
		return;
	}

	playAll();
	if(max != nullptr)
		connect(max, &QMediaPlayer::mediaStatusChanged, this, &AnimicScene::activateTrigger);
}

void AnimicScene::switchTriggerType(int i)
{
	triggerToBeInserted = i;
}

bool AnimicScene::isEntry()
{
	return entryScene;
}
void AnimicScene::setEntry(bool x)
{
	entryScene = x;
}

bool AnimicScene::getPlaybackMode()
{
	return playbackMode;
}

void AnimicScene::setPlaybackMode(bool x)
{
	playbackMode = x;
}


void AnimicScene::onNextScene(AnimicScene* sc)		//only used during playback mode
{
	stopAll();
	disengageLoopingVideo();
	playbackMode = false;
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		TwoWayTrigger* TWTrigger = qgraphicsitem_cast<TwoWayTrigger*>(item);
		TimedMashTrigger* TMTrigger = qgraphicsitem_cast<TimedMashTrigger*>(item);
		OneWayTrigger* OWTrigger = qgraphicsitem_cast<OneWayTrigger*>(item);

		if (TWTrigger != nullptr)
		{
			TWTrigger->stopMedia();
			disconnect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &AnimicScene::onLastScene);
			disconnect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &AnimicScene::onNextScene);
			disconnect(TWTrigger, &TwoWayTrigger::sendAltScene, this, &AnimicScene::onNextScene);
			disconnect(TWTrigger, &TwoWayTrigger::sendAltScene, this, &AnimicScene::onLastScene);
		}
		else if (TMTrigger != nullptr)
		{
			TMTrigger->stopMedia();
			disconnect(TMTrigger, &TimedMashTrigger::sendDefaultScene, this, &AnimicScene::onLastScene);
			disconnect(TMTrigger, &TimedMashTrigger::sendDefaultScene, this, &AnimicScene::onNextScene);
			disconnect(TMTrigger, &TimedMashTrigger::sendAltScene, this, &AnimicScene::onNextScene);
			disconnect(TMTrigger, &TimedMashTrigger::sendAltScene, this, &AnimicScene::onLastScene);
		}
		else if (OWTrigger != nullptr)
		{
			OWTrigger->stopMedia();
			disconnect(OWTrigger, &OneWayTrigger::sendDefaultScene, this, &AnimicScene::onLastScene);
			disconnect(OWTrigger, &OneWayTrigger::sendDefaultScene, this, &AnimicScene::onNextScene);
		}
	}
	disconnectMax();
	emit nextScene(sc);
}

void AnimicScene::onLastScene()
{
	playbackMode = false;
	stopAll();
	disengageLoopingVideo();
	deactivateTrigger();
	disconnectMax();
	emit lastScene();
}

void AnimicScene::resetScene()
{
	playbackMode = false;
	deactivateTrigger();
	stopAll();
	
}

void AnimicScene::engageLoopVideo()
{
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)
	{
		VideoObject* obj = qgraphicsitem_cast<VideoObject*>(item);
		if (obj != nullptr)
		{
			obj->addLoop();
		}
	}
}

void AnimicScene::disengageLoopingVideo()
{
	QList<QGraphicsItem*> allItems = items();
	qDebug() << "Inside Disengage Loop";
	for (QGraphicsItem* item : allItems)
	{
		VideoObject* obj = qgraphicsitem_cast<VideoObject*>(item);
		if (obj != nullptr)
		{
			qDebug() << "Removing Loop";
			obj->removeLoop();
		}
	}
}

void AnimicScene::disconnectMax()
{
	disconnect(max, nullptr, this, nullptr);
}

void AnimicScene::onSetEntry(bool x)
{
	qDebug() << "Toggling Scene";
	entryScene = x;
}
