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
		qDebug() << "Finding New Item";
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
		qDebug() << "Emitting FoundNew Max";
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
		if (triggerToBeInserted == 0)					
		{
			for (QUrl url : mimedata->urls())
			{
				TwoWayTrigger* trigger = new TwoWayTrigger(this, &url);
				trigger->setPos(event->scenePos());
				this->addItem(trigger);
				emit triggerInserted();

				//connect(trigger->getPlayer(), SIGNAL(durationChanged(qint64)), this, SLOT(onTriggerLoaded(qint64)));

				pauseAll();
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
		}
		else if (triggerToBeInserted == 2)
		{
			//OneWayTrigger* trigger = new OneWayTrigger(this, &url);
			//trigger->setPos(event->scenePos());
			//this->addItem(trigger);

			//temp = trigger->getPlayer();
			//connect(trigger->getPlayer(), SIGNAL(durationChanged(qint64)), this, SLOT(onVideoLoaded(qint64)));

			pauseAll();
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
			qDebug() << "Playing";
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
	qDebug() << "Trigger Loaded";
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
			//TMTrigger->playMedia();
		}
		else if (OWTrigger != nullptr)
		{
			//OWTrigger->playMedia();
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
			//TMTrigger->pauseMedia();
		}
		else if (OWTrigger != nullptr)
		{
			//OWTrigger->pauseMedia();
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
			//TMTrigger->stopMedia();
		}
		else if (OWTrigger != nullptr)
		{
			//OWTrigger->stopMedia();
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

		qDebug() << "TWTrigger: " << TWTrigger;
		//qDebug() << "TMTrigger: " << TMTrigger;
		//qDebug() << "OWTrigger: " << OWTrigger;

		if (TWTrigger != nullptr)
		{
			TWTrigger->setVisible(true);
			TWTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
		}
		else if (TMTrigger != nullptr)
		{
			//TMTrigger->setVisible(true);
			//TMTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
		}
		else if (OWTrigger != nullptr)
		{
			//OWTrigger->setVisible(true);
			//OWTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
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
			qDebug() << "Inside For Loop";
			if (TWTrigger != nullptr)
			{
				qDebug() << "Within TW";
				TWTrigger->setVisible(true);
				TWTrigger->setFlag(QGraphicsVideoItem::ItemIsMovable, false);
				TWTrigger->setFlag(QGraphicsVideoItem::ItemIsSelectable, false);
				TMTrigger->setFlag(QGraphicsVideoItem::ItemIsFocusable);
				TWTrigger->setActiveTrigger(true);
				TWTrigger->setFocus();

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
			/*else if (TMTrigger != nullptr)
			{
				qDebug() << "Within TM";
				TMTrigger->setVisible(true);
				TMTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
				//TMTrigger->setActiveTrigger(true);


				//TMTrigger->playMedia();

				return;
			}
			else if (OWTrigger != nullptr)
			{
				qDebug() << "Within OW";
				OWTrigger->setVisible(true);
				OWTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
				//OWTrigger->setActiveTrigger(true);

				//OWTrigger->playMedia();

				return;
			}
			*/
		}
		qDebug() << "No Trigger Found, Terminating Scene";
		onLastScene();	//if can't find a single trigger, terminate early.
	}
}

void AnimicScene::deactivateTrigger()
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
			TMTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
			//TMTrigger->setActiveTrigger(false);
			return;
		}
		else if (OWTrigger != nullptr)
		{
			OWTrigger->setVisible(true);
			OWTrigger->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
			//OWTrigger->setActiveTrigger(false);
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


void AnimicScene::onNextScene(AnimicScene* sc)
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
			TWTrigger->setActiveTrigger(false);
			TWTrigger->stopMedia();
			disconnect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &AnimicScene::onLastScene);
			disconnect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &AnimicScene::onNextScene);
			disconnect(TWTrigger, &TwoWayTrigger::sendAltScene, this, &AnimicScene::onNextScene);
			disconnect(TWTrigger, &TwoWayTrigger::sendAltScene, this, &AnimicScene::onLastScene);
		}
		else if (TMTrigger != nullptr)
		{
			//TMTrigger->setActiveTrigger(false);
		}
		else if (OWTrigger != nullptr)
		{
			//OWTrigger->setActiveTrigger(false);
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

	//emit lastScene();
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
