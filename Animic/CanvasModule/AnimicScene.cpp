#include "stdafx.h"
#include "AnimicScene.h"
#include <StitchingModule/Triggers/TwoWayTrigger.h>
#include <StitchingModule/Triggers/TimedMashTrigger.h>
#include <StitchingModule/Triggers/OneWayTrigger.h>

AnimicScene::AnimicScene()
{
	bgmList = new QMediaPlaylist();		//for bgm, not used at all, wrong concept and should be removed entirely in the future
	bgmPlayer = new QMediaPlayer();
	bgmPlayer->setPlaylist(bgmList);
}

AnimicScene::~AnimicScene()
{
	delete bgmList;	//to be removed
	delete bgmPlayer;
}

QString AnimicScene::getName()
{
	return name;	//scene name for display purposes
}

void AnimicScene::setName(QString k)
{
	name = k;
	emit nameChanged(k);
}


VideoObject* AnimicScene::selectedItem()	//get selected video object
{
	QList<QGraphicsItem*> itemList = QGraphicsScene::selectedItems();

	for (QGraphicsItem* item : itemList)
	{
		VideoObject* obj = qgraphicsitem_cast<VideoObject*>(item);		//cast qt provided QGraphicsItem to custom VideoObject, returns nullptr if no conversion available
		if (obj != nullptr)
		{
			return obj;
		}
	}
	return nullptr;
}

void AnimicScene::onDeleteItem()	//for safe deletion
{
	QList<QGraphicsItem*> itemList = QGraphicsScene::selectedItems();

	for (int i = 0; i < itemList.size(); i++)
	{
		emit deletingVideo();													//prepare the system for safe deletion
		VideoObject* obj = qgraphicsitem_cast<VideoObject*>(itemList.at(i));
		if(obj != nullptr)
		{
			if (max == obj->getPlayer())		//check for the video player that holds the long duration video
			{
				max = nullptr;		
				maxDuration = 0;
			}
			removeItem(obj);			//remove video object from scene
			delete(obj);				//delete videoObject and free memory
		}
	}
	QList<QGraphicsItem*> list = QGraphicsScene::items();

	qint64 tempDuration = 0;
	bool found = false;

	for (int i = 0; i < list.size(); i++)									//find a new maximum duration for the timeline 
	{
		VideoObject* obj = qgraphicsitem_cast<VideoObject*>(list.at(i));
		if (obj != nullptr)
		{
			if (obj->getPlayer()->duration() > tempDuration)		//find the largest value of duration
			{
				found = true;
				max = obj->getPlayer();
				maxDuration = obj->getPlayer()->duration();	//get duration from media player
				tempDuration = maxDuration;
			}
		}
	}
	if (found == true)
	{
		emit foundNewMax(maxDuration);		//set the timeline slider maximum here
	}
	else emit foundNewMax(0);
}

void AnimicScene::onDeleteTrigger()	//safe deletion of triggers, not working yet, will crash
{
	QList<QGraphicsItem*> itemList = QGraphicsScene::selectedItems();

	for (int i = 0; i < itemList.size(); i++)
	{
		emit deletingVideo();
		TwoWayTrigger* tw = qgraphicsitem_cast<TwoWayTrigger*>(itemList.at(i));
		TimedMashTrigger* tm = qgraphicsitem_cast<TimedMashTrigger*>(itemList.at(i));
		OneWayTrigger* ow = qgraphicsitem_cast<OneWayTrigger*>(itemList.at(i));
		if (tw != nullptr)		//for two way trigger
		{
			if (max == tw->getPlayer())
			{
				max = nullptr;
				maxDuration = 0;
			}
			removeItem(tw);
			delete(tw);
			acceptTrigger = true;
		}
		else if (tm != nullptr)	//for timed mash trigger
		{
			if (max == tm->getPlayer())
			{
				max = nullptr;
				maxDuration = 0;
			}
			removeItem(tm);
			delete(tm);
			acceptTrigger = true;
		}
		else if (ow != nullptr) // for one way trigger
		{
			if (max == ow->getPlayer())
			{
				max = nullptr;
				maxDuration = 0;
			}
			removeItem(ow);
			delete(ow);
			acceptTrigger = true;
		}
	}
}

QString AnimicScene::mimeType()
{
	return QString("text/uri-list");
}

void AnimicScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mousePressEvent(event);
}

void AnimicScene::dragEnterEvent(QGraphicsSceneDragDropEvent* event)	// to accept drag and drop from asset list widgets 
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

	if (dynamic_cast<AssetHandler*>(event->source()))	//if source is NORMAL VIDEO asset List Widget
	{
		for (QUrl url : mimedata->urls())
		{
			VideoObject* video = new VideoObject(this, &url);	//create a new video object here and add to this scene
			video->setPos(event->scenePos());
			this->addItem(video);

			temp = video->getPlayer();			//get reference to the video player
			connect(video->getPlayer(), SIGNAL(durationChanged(qint64)), this, SLOT(onVideoLoaded(qint64)));	// this is to get the correct video duration
			
			pauseAll();	// pause all video object in the scene
		}
	}
	else if (dynamic_cast<TriggerAssetHandler*>(event->source())) //if source is TRIGGER Asset List Widget
	{
		if (acceptTrigger) //to ensure only 1 trigger is present in each scene, may require a different implementation approach in the future
		{
			for (QUrl url : mimedata->urls())
			{
				if (triggerToBeInserted == 0)
				{
					TwoWayTrigger* trigger = new TwoWayTrigger(this, &url);	//creates a trigger here and add to scene
					trigger->setPos(event->scenePos());
					this->addItem(trigger);
					emit triggerInserted();		//to connect with other UI components such as timeline slider in stitching dialog, trigger properties, etc.
					acceptTrigger = false;
					trigger->setZValue(100);	//set z value to as high as possible to always show on top of the normal videos 
					pauseAll();
					return;
				}
				else if (triggerToBeInserted == 1)	//refer above
				{
					TimedMashTrigger* trigger = new TimedMashTrigger(this, &url);
					trigger->setPos(event->scenePos());
					this->addItem(trigger);
					emit triggerInserted();
					acceptTrigger = false;
					trigger->setZValue(100);
					pauseAll();
					return;
				}
				else if (triggerToBeInserted == 2)	//refer above
				{
					OneWayTrigger* trigger = new OneWayTrigger(this, &url);
					trigger->setPos(event->scenePos());
					this->addItem(trigger);
					emit triggerInserted();
					acceptTrigger = false;
					trigger->setZValue(100);
					pauseAll();
					return;
				}
			}
		}
		else
		{
			qDebug() << "Another Trigger Is Found";	// currently scene cannot accpet more than 1 trigger
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

void AnimicScene::playAll()	//play all video object in the scene
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

void AnimicScene::pauseAll()	// pause all video object in the scene
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

void AnimicScene::stopAll()	//stop all
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

void AnimicScene::disableObjectDragging()	//make video object unable to be moved, selected or focussed 
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

void AnimicScene::enableObjectDragging()	//refer above
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

void AnimicScene::disconnectObject()	//disconnect all signals that a video object emits
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

void AnimicScene::disconnectScene()	//disconnect all signals that this scene emits 
{
	this->disconnect();
}


void AnimicScene::setVideoFrameTime(int pos)	// jump directly to this frame when user release the timeline slider
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

QMediaPlayer* AnimicScene::getMaxPlayer()	//get the media player that has the longest duration video
{
	return max;
}

void AnimicScene::onVideoLoaded(qint64 length)	// this is to get the correct video duraiton for the timeline slider 
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

bool AnimicScene::checkForTrigger()	//this is not needed in latest build, initially thinking to use to check if a trigger is present
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

int AnimicScene::getTriggerType() //0 = Two way trigger , 1 = Timed mash trigger, 2 = One way trigger
{
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)	//return what type of trigger is in the scene
	{
		TwoWayTrigger* TWTrigger = qgraphicsitem_cast<TwoWayTrigger*>(item);
		TimedMashTrigger* TMTrigger = qgraphicsitem_cast<TimedMashTrigger*>(item);
		OneWayTrigger* OWTrigger = qgraphicsitem_cast<OneWayTrigger*>(item);

		if (TWTrigger != nullptr)
		{
			return 0;
		}
		else if (TMTrigger != nullptr)
		{
			return 1;
		}
		else if (OWTrigger != nullptr)
		{
			return 2;
		}
	}
	return -1;	//-1 = no trigger flag
}

QGraphicsItem* AnimicScene::getTrigger()	//return trigger in the scene
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

void AnimicScene::playTrigger()	//play trigger
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
			return;		// this return statement ensures only the first trigger is affected
		}
		else if (TMTrigger != nullptr)
		{
			TMTrigger->playMedia();
			return;
		}
		else if (OWTrigger != nullptr)
		{
			OWTrigger->playMedia();
			return;
		}
	}
}

void AnimicScene::pauseTrigger() //pause trigger
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
			return;		
		}
		else if (TMTrigger != nullptr)
		{
			TMTrigger->pauseMedia();
			return;
		}
		else if (OWTrigger != nullptr)
		{
			OWTrigger->pauseMedia();
			return;
		}
	}
}

void AnimicScene::stopTrigger() //stop trigger
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
			return;
		}
		else if (TMTrigger != nullptr)
		{
			TMTrigger->stopMedia();
			return;
		}
		else if (OWTrigger != nullptr)
		{
			OWTrigger->stopMedia();
			return;
		}
	}
}

void AnimicScene::enableTrigger()	//enable trigger = edit mode for triggers 
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

void AnimicScene::disableTrigger()	//refer above
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
			TWTrigger->setVisible(false);
			TWTrigger->setFlag(QGraphicsVideoItem::ItemIsMovable, false);
			TWTrigger->setFlag(QGraphicsVideoItem::ItemIsSelectable, false);
			TWTrigger->setFlag(QGraphicsVideoItem::ItemIsFocusable, false);
		}
		else if (TMTrigger != nullptr)
		{
			TMTrigger->stopMedia();
			TMTrigger->setVisible(false);
			TMTrigger->setFlag(QGraphicsVideoItem::ItemIsMovable, false);
			TMTrigger->setFlag(QGraphicsVideoItem::ItemIsSelectable, false);
			TMTrigger->setFlag(QGraphicsVideoItem::ItemIsFocusable, false);
		}
		else if (OWTrigger != nullptr)
		{
			OWTrigger->stopMedia();
			OWTrigger->setVisible(false);
			OWTrigger->setFlag(QGraphicsVideoItem::ItemIsMovable, false);
			OWTrigger->setFlag(QGraphicsVideoItem::ItemIsSelectable, false);
			OWTrigger->setFlag(QGraphicsVideoItem::ItemIsFocusable, false);
		}
	}
}

void AnimicScene::resetTriggerNextScene(AnimicScene* sc)		//Remove pointer to a scene that is about to be deleted
{
	QList<QGraphicsItem*> allItems = items();	

	for (QGraphicsItem* item : allItems)
	{
		TwoWayTrigger* TWTrigger = qgraphicsitem_cast<TwoWayTrigger*>(item);
		TimedMashTrigger* TMTrigger = qgraphicsitem_cast<TimedMashTrigger*>(item);
		OneWayTrigger* OWTrigger = qgraphicsitem_cast<OneWayTrigger*>(item);

		if (TWTrigger != nullptr)
		{
			TWTrigger->resetNextScenes(sc);
		}
		else if (TMTrigger != nullptr)
		{
			TMTrigger->resetNextScenes(sc);
		}
		else if (OWTrigger != nullptr)
		{
			OWTrigger->resetScene(sc);
		}
	}
}

void AnimicScene::activateTrigger(QMediaPlayer::MediaStatus status)	//active trigger = preview mode, trigger will react to the user input 
{
	if (status == QMediaPlayer::EndOfMedia) 
	{
		playbackMode = true;
		QList<QGraphicsItem*> allItems = items();
		engageLoopVideo();							//add the placeholder video into all videoobject's playlist

		for (QGraphicsItem* item : allItems)
		{
			TwoWayTrigger* TWTrigger = qgraphicsitem_cast<TwoWayTrigger*>(item);
			TimedMashTrigger* TMTrigger = qgraphicsitem_cast<TimedMashTrigger*>(item);
			OneWayTrigger* OWTrigger = qgraphicsitem_cast<OneWayTrigger*>(item);

			if (TWTrigger != nullptr)	//if found two way trigger
			{
				TWTrigger->setVisible(true);
				TWTrigger->setActiveTrigger(true);			//activate trigger here
				TWTrigger->setFlag(QGraphicsVideoItem::ItemIsMovable, false);	
				TWTrigger->setFlag(QGraphicsVideoItem::ItemIsSelectable, false);
				TWTrigger->setFlag(QGraphicsVideoItem::ItemIsFocusable);

				if (TWTrigger->getDefaultScene() == nullptr)
				{
					connect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &AnimicScene::onLastScene);	// if the default next scene is empty, end the preview
				}
				else connect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &AnimicScene::onNextScene); //else go to the next designated scene

				if (TWTrigger->getAltScene() == nullptr)
				{
					connect(TWTrigger, &TwoWayTrigger::sendAltScene, this, &AnimicScene::onLastScene);	// if the alternate next scene is empty, end the preview
				}
				else connect(TWTrigger, &TwoWayTrigger::sendAltScene, this, &AnimicScene::onNextScene); //else go to the next designated scene

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
					connect(TMTrigger, &TimedMashTrigger::sendDefaultScene, this, &AnimicScene::onLastScene); //refer above
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
					connect(OWTrigger, &OneWayTrigger::sendDefaultScene, this, &AnimicScene::onLastScene); //refer above
				}
				else connect(OWTrigger, &OneWayTrigger::sendDefaultScene, this, &AnimicScene::onNextScene);

				OWTrigger->playMedia();

				return;
			}
		}
		qDebug() << "No Trigger Found, Terminating Scene";
		onLastScene();	//if can't find any trigger, terminate early.
	}
}

void AnimicScene::deactivateTrigger()		//going back to stitching dialog from preview mode, change all triggers to edit mode
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
			disconnect(TWTrigger, &TwoWayTrigger::sendDefaultScene, this, &AnimicScene::onLastScene);		//disconnect the trigger from user input  
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
	if(items().count() == 0)	// if empty scene, then ignore and end preview early
	{	
		emit lastScene();	
		return;	//exit function
	}

	playAll();		//start playing all videos in the scene
	if(max != nullptr)
		connect(max, &QMediaPlayer::mediaStatusChanged, this, &AnimicScene::activateTrigger);	//activate the trigger onces the longest duration video finish playing
}

void AnimicScene::switchTriggerType(int i)
{
	triggerToBeInserted = i;	// control what type of trigger to be inserted by referring to which check box is ticked 
}

bool AnimicScene::isEntry()
{
	return entryScene;		// is this the first scene in the list?
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


void AnimicScene::onNextScene(AnimicScene* sc)		//returns the next scene to be played 
{
	stopAll();	//stop current scene
	disengageLoopingVideo();	//reset all video objects
	playbackMode = false;	
	QList<QGraphicsItem*> allItems = items();

	for (QGraphicsItem* item : allItems)	//reset the trigger
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
	emit nextScene(sc); //returns the next scene here
}

void AnimicScene::onLastScene()	//preview termination here
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

	for (QGraphicsItem* item : allItems)		//add placeholder video to each videoObject
	{
		VideoObject* obj = qgraphicsitem_cast<VideoObject*>(item);
		if (obj != nullptr)
		{
			obj->setFlag(QGraphicsVideoItem::ItemIsMovable, false);
			obj->setFlag(QGraphicsVideoItem::ItemIsSelectable, false);
			obj->setFlag(QGraphicsVideoItem::ItemIsFocusable, false);
			obj->addLoop();
		}
	}
}

void AnimicScene::disengageLoopingVideo()
{
	QList<QGraphicsItem*> allItems = items();		//refer above
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

void AnimicScene::disconnectMax()		//disconnect all signal that the mediaplayer with the longest duration video will emit
{
	disconnect(max, nullptr, this, nullptr);
}

void AnimicScene::onSetEntry(bool x)	//set this as the first scene, controlled from a check box in properties widget
{
	entryScene = x;
}
