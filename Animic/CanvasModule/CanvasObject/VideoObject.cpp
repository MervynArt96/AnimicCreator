#include "stdafx.h"
#include "VideoObject.h"
#include <CanvasModule\AnimicScene.h>

VideoObject::VideoObject(QObject* parent, QUrl* filePath)   // the graphic object that renders the video
{
    videoPath = new QUrl();             //path of the video
    loopPath = new QUrl();              //path of the placeholder video, placeholder video is the video that will be played when waiting for user input
    playList = new QMediaPlaylist();    //playlist to switch between normal video and placeholder video
    player = new QMediaPlayer();        //player that plays video buffer
    loopBuffer = new QBuffer();         //buffer that holds the video data in RAM
    mainBuffer = new QBuffer();         

	if (QFile::exists(filePath->path()))
	{
        videoPath->setUrl(filePath->path());    // initialize video path for reference later, might be redundant
        player->setPlaylist(playList);          // assign player to play from this list
        this->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
        this->setAcceptHoverEvents(true);   
		player->setVideoOutput(this);       //player will render to this video object
        player->play();                     //this to get the first frame displayed or else it will show a black image.
        player->pause();                    // ^^
        this->currentHandle = nullptr;      // no handle is selected at first

        QFile file(filePath->path());       //open the file based on the given url
        file.open(QIODevice::ReadOnly);
        QByteArray* ba = new QByteArray();   
        ba->append(file.readAll());         //read the file into RAM
        mainBuffer->setBuffer(ba);          //assign byte array as buffer
        mainBuffer->open(QIODevice::ReadOnly);  //to eep a copy of the media for instant playback, no buffering required later on
        mainBuffer->reset();    //set buffer pointer back to the beginning

        player->setMedia(QMediaContent(), mainBuffer);  //set buffer as the media
        file.close();
	}
    else
    {
        qDebug() << "File Not Found";   //need more varification check on this
    }
}

VideoObject::~VideoObject()
{
    delete player;              //delete pointer and free memory, not calling delete will cause dangling pointers and memory leak
    delete mainBuffer;
    delete loopBuffer;
    delete playList;
    delete videoPath;
    delete loopPath;
}

void VideoObject::contextMenuEvent(QGraphicsSceneContextMenuEvent* event)   //right click menu
{
    QMenu menu;                                                     
    QAction* removeAction = menu.addAction("Remove Item");
    connect(removeAction, &QAction::triggered, qobject_cast<AnimicScene*>(scene()), &AnimicScene::onDeleteItem);    //connect the action button to delete functionalities
    QAction* selectedAction = menu.exec(event->screenPos());    //open the menu at the cursor location
}


QString VideoObject::getVideoPath()
{
	return videoPath->path();
}

QString VideoObject::getLoopPath()
{
    return loopPath->path();
}

QMediaPlayer* VideoObject::getPlayer()
{
	return player;
}

QMediaPlaylist* VideoObject::getPlayList()
{
    return playList;
}

void VideoObject::playMedia()
{
    player->play();
}

void VideoObject::pauseMedia()
{
    player->pause();
}

void VideoObject::stopMedia()
{
    player->stop();
}

void VideoObject::toggleMute()
{
    player->isMuted() ? player->setMuted(false) : player->setMuted(true); //mute or unmute video, not used currently
}

void VideoObject::setName(QString str)
{
    name = str;
}

QString VideoObject::getName()
{
    return name;
}

/*
QRectF VideoObject::boundingRect() 
{

}
*/

void VideoObject::mousePressEvent(QGraphicsSceneMouseEvent* event)  
{
    if (!init)
    {
        this->objectRect = boundingRect();      //initialize handles if haven't
        createHandles();
    }

	if (event->buttons() == Qt::LeftButton)
    {
        mousePos = event->scenePos();
		for(RectHandle* handle : this->handleList)  // change to for loop in future
        {
            if (handle->boundingRect().contains(event->pos()))
            {
                this->currentHandle = handle;       // if the user click on a handle, set that handle as the current handle
                break;
            }
            else this->currentHandle = nullptr;
		}
	}
    else if (event->button() == Qt::RightButton)
    {
        
        
    
    }
    QGraphicsVideoItem::mousePressEvent(event);
    //event->accept();
}

void VideoObject::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->buttons() == Qt::LeftButton && this->currentHandle != nullptr)       //move handle to scale object
    {
        //qreal sensitivity = 0.1;
        qreal dir = 1.0001;
        QPointF deltaPos = event->scenePos() - mousePos;

        qDebug() << deltaPos;

        if (deltaPos.x() <= 0 || deltaPos.y() <= 0)     //scaling amount calculations
        {
            //sensitivity = 1;
            dir = 0.0099;
        }

        QTransform transform = this->transform();   //get the transform (position, scale, rotation, etc. )of the object

        mousePos = event->scenePos();

        /*
        if (this->currentHandle->getHandleType() == HandleType::MidLeft)    //mid left till btm handle is not used
        {
            this->setTransform(this->transform().scale(dir, 1));
        }
        else if (this->currentHandle->getHandleType() == HandleType::MidRight)
        {
            this->setTransform(this->transform().scale(dir, 1));
        }
        else if (this->currentHandle->getHandleType() == HandleType::Top)
        {
            this->setTransform(this->transform().scale(1, dir));
        }
        else if (this->currentHandle->getHandleType() == HandleType::Btm)
        {
            this->setTransform(this->transform().scale(1, dir));
        }
        else 
            */
        if (this->currentHandle->getHandleType() == HandleType::TopLeft)
        {
            //use bounding rect, to be implemented in the future
        }
        else if (this->currentHandle->getHandleType() == HandleType::TopRight)
        {

        }
        else if (this->currentHandle->getHandleType() == HandleType::BtmLeft)
        {

        }
        else if (this->currentHandle->getHandleType() == HandleType::BtmRight)
        {

        }
        else if (this->currentHandle->getHandleType() == HandleType::Rotation)  //not used, not sure about implementation method
        {
            this->setTransform(QTransform().translate(origin.x(), origin.y()).rotate(-QLineF(event->scenePos(),
               mapToScene(origin)).angle() + QLineF(event->lastScenePos(), mapToScene(origin)).angle()).translate(-origin.x(), -origin.y()), true);
        }
        else if (this->currentHandle->getHandleType() == HandleType::Origin)    //not used, werid duplication of origin handle bug
        {
            this->currentHandle->setPosition(event->pos());
            this->transformOriginPoint() = event->pos();
            this->origin = currentHandle->getPosition();
        }
        
    }
    else if (!this->currentHandle)
    {
        QGraphicsVideoItem::mouseMoveEvent(event);  // just simply move the object if no handle is selected
    }
}


void VideoObject::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    QGraphicsVideoItem::mouseReleaseEvent(event);      
    currentHandle = nullptr;                 //reset handle
    event->accept();
}

void VideoObject::hoverMoveEvent(QGraphicsSceneHoverEvent* event)
{
    mousePos = event->pos();
}

/*QVariant VideoObject::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant value)
{
    if (change == GraphicsItemChange::ItemPositionChange) {
        QPointF newPos = value.toPointF();
        QSettings settings;
        int gridSize = settings.value("drawing/gridSize").toInt();
        bool gridEnabled = settings.value("drawing/gridEnabled").toBool();

        QPointF newPos = value.toPointF();
        if (gridEnabled) {
            if ((int)newPos.x() % gridSize != 0) {
                int x = (int)newPos.x() - (int)newPos.x() % gridSize;
                newPos.setX(x);
            }
            if ((int)newPos.y() % gridSize != 0) {
                int y = (int)newPos.y() - (int)newPos.y() % gridSize;
                newPos.setY(y);
            }
        }
        
        return newPos;
    }
    
    return BaseObject::itemChange(change, value);
}*/


void VideoObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) // to render the object and the handle
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QGraphicsVideoItem::paint(painter, option, widget); //draw object here

    painter->setRenderHint(QPainter::Antialiasing, true);

    if (this->isSelected())     //draw handles here
    {
        if (this->showRect)
        {
            QPen pen(QColor::fromRgb(80, 80, 250));
            painter->setPen(pen);
            painter->drawRect(boundingRect());

            //painter->drawRect(QRectF(boundingRect().left() - 5, boundingRect().top() - 5, boundingRect().right() + 10, boundingRect().bottom() - 20));
        }

        //QPointF p1;
        //QPointF p2;
        for (RectHandle* handle : handleList)
        {
            /*if (handle->getHandleType() == HandleType::Rotation)
            {
                p1 = handle->getPosition();
            }
            else if (handle->getHandleType() == HandleType::Top)
            {
                p2 = handle->getPosition();
            }*/

            if (handle->getHandleShape() == HandleShape::RectangleShape)
            {
                painter->drawRect(handle->boundingRect());
            }
            else if (handle->getHandleShape() == HandleShape::CircleShape)
            {
                painter->drawEllipse(handle->boundingRect());
            }
        }

        //painter->drawLine(p1, p2);
        //painter->drawPoint(this->origin);
    }

    scene()->update();
}

void VideoObject::onFocused()  
{

}

void VideoObject::onFocusExit()
{
    
}

void VideoObject::disableRect()
{
    showRect = false;
}

void VideoObject::enableRect()
{
    showRect = true;
}


void VideoObject::onPosXChanged(const QString& str) //change properties of the object when corresponding text field has changed text
{
    this->setX(str.toDouble());
}

void VideoObject::onPosYChanged(const QString& str) // refer above
{
    this->setY(str.toDouble());
}

void VideoObject::onScaleChanged(const QString& str) // refer above
{
    if(str.toDouble() != 0 && str.toDouble())
        this->setScale(str.toDouble());
}


void VideoObject::onUrlChanged(const QString& str) // refer above
{
    if (QFile::exists(str))
    {
        qint64 pos = player->position();
        videoPath->clear();
        videoPath->setPath(str);
        //playList->clear();
        //playList->addMedia(QUrl::fromLocalFile(str));
        //delete player;
        //player = new QMediaPlayer();
        //this->setMediaObject(player);

        QFile file(str);
        file.open(QIODevice::ReadOnly);
        QByteArray* ba = new QByteArray();
        ba->append(file.readAll());

        mainBuffer->setBuffer(ba);
        mainBuffer->open(QIODevice::ReadOnly);  //keep a copy of the media
        mainBuffer->reset();
        player->setPosition(pos);
        player->setMedia(QMediaContent(), mainBuffer);
    }
}

void VideoObject::onLoopPathChanged(const QString& str) // refer above
{
    if (QFile::exists(str)) 
    {
        loopPath->setPath(str);
        QFile file(str);
        file.open(QIODevice::ReadOnly);
        QByteArray* ba = new QByteArray();
        ba->append(file.readAll());

        loopBuffer->setBuffer(ba);
        loopBuffer->open(QIODevice::ReadOnly);  //keep a copy of the media
        loopBuffer->reset();
    }
}

void VideoObject::addLoop() // add the placeholder video into playlist, used only in preview mode
{
    if (loopPath->path() != "") 
    {
        switchPlayMode(1);
        player->setMedia(QMediaContent(), loopBuffer);
        player->play();
    }
    else
    {
        qDebug() << "No loop video";
    }
}

void VideoObject::switchPlayMode(int index) //for preview mode, change to loop current video 
{
    if (index == 0)
    {
        playList->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    }
    else if (index == 1)
    {
        playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    }
}

void VideoObject::removeLoop()  //remove placeholder video from the playlist, return to normal playback mode for editing 
{
    player->setMedia(QMediaContent(), mainBuffer);
    player->stop();
    switchPlayMode(0);
}