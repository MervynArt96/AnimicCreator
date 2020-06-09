#include "stdafx.h"
#include "VideoObject.h"
#include <CanvasModule\AnimicScene.h>

VideoObject::VideoObject(QObject* parent, QUrl* filePath)
{
    videoPath = new QUrl();
    loopPath = new QUrl();
    playList = new QMediaPlaylist();
    player = new QMediaPlayer();
    loopBuffer = new QBuffer();
    mainBuffer = new QBuffer();

	if (QFile::exists(filePath->path()))
	{
        videoPath->setUrl(filePath->path());
        player->setPlaylist(playList);
        this->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
        this->setAcceptHoverEvents(true);
		player->setVideoOutput(this);
        player->play();
        player->pause();
        this->currentHandle = nullptr;   

        QFile file(filePath->path());
        file.open(QIODevice::ReadOnly);
        QByteArray* ba = new QByteArray();
        ba->append(file.readAll());
        mainBuffer->setBuffer(ba);
        mainBuffer->open(QIODevice::ReadOnly);  //keep a copy of the media
        mainBuffer->reset();

        player->setMedia(QMediaContent(), mainBuffer);
        connect(player, &QMediaPlayer::mediaStatusChanged, this, [=]()
            {
                //qDebug() << "Media Status:" << player->mediaStatus();
            });
        file.close();
	}
    else
    {
        qDebug() << "File Not Found";
    }
}

VideoObject::~VideoObject()
{
    qDebug() << "Freeing Memory";
    delete player;
    delete mainBuffer;
    delete loopBuffer;
    delete playList;
    delete videoPath;
    delete loopPath;
}

void VideoObject::contextMenuEvent(QGraphicsSceneContextMenuEvent* event)
{
    QMenu menu;
    QAction* removeAction = menu.addAction("Remove Item");
    connect(removeAction, &QAction::triggered, qobject_cast<AnimicScene*>(scene()), &AnimicScene::onDeleteItem);
    QAction* selectedAction = menu.exec(event->screenPos());
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
    qDebug() << player->mediaStatus();
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
    player->isMuted() ? player->setMuted(false) : player->setMuted(true); //toggle mute switch
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
        this->objectRect = boundingRect();
        createHandles();
    }

	if (event->buttons() == Qt::LeftButton)
    {
        mousePos = event->scenePos();
		for(RectHandle* handle : this->handleList)
        {
            if (handle->boundingRect().contains(event->pos()))
            {
                this->currentHandle = handle;
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
    if (event->buttons() == Qt::LeftButton && this->currentHandle != nullptr)
    {
        //qreal sensitivity = 0.1;
        qreal dir = 1.0001;
        QPointF deltaPos = event->scenePos() - mousePos;

        qDebug() << deltaPos;

        if (deltaPos.x() <= 0 || deltaPos.y() <= 0)
        {
            //sensitivity = 1;
            dir = 0.0099;
        }

        QTransform transform = this->transform();

        mousePos = event->scenePos();

        if (this->currentHandle->getHandleType() == HandleType::MidLeft)
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
        else if (this->currentHandle->getHandleType() == HandleType::TopLeft)
        {
            //use bounding rect
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
        else if (this->currentHandle->getHandleType() == HandleType::Rotation)
        {
            this->setTransform(QTransform().translate(origin.x(), origin.y()).rotate(-QLineF(event->scenePos(),
               mapToScene(origin)).angle() + QLineF(event->lastScenePos(), mapToScene(origin)).angle()).translate(-origin.x(), -origin.y()), true);
        }
        else if (this->currentHandle->getHandleType() == HandleType::Origin)
        {
            this->currentHandle->setPosition(event->pos());
            this->transformOriginPoint() = event->pos();
            this->origin = currentHandle->getPosition();
        }
        
    }
    else if (!this->currentHandle)
    {
        QGraphicsVideoItem::mouseMoveEvent(event);
    }
}


void VideoObject::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    QGraphicsVideoItem::mouseReleaseEvent(event);
    currentHandle = nullptr;
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


void VideoObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QGraphicsVideoItem::paint(painter, option, widget);

    painter->setRenderHint(QPainter::Antialiasing, true);

    if (this->isSelected())
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
    //connect to
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


void VideoObject::onPosXChanged(const QString& str)
{
    this->setX(str.toDouble());
}

void VideoObject::onPosYChanged(const QString& str)
{
    this->setY(str.toDouble());
}

void VideoObject::onScaleChanged(const QString& str)
{
    if(str.toDouble() != 0 && str.toDouble())
        this->setScale(str.toDouble());
}


void VideoObject::onUrlChanged(const QString& str)
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

void VideoObject::onLoopPathChanged(const QString& str)
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

void VideoObject::addLoop()
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

void VideoObject::switchPlayMode(int index)
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

void VideoObject::removeLoop()
{
    player->setMedia(QMediaContent(), mainBuffer);
    player->stop();
    switchPlayMode(0);
}