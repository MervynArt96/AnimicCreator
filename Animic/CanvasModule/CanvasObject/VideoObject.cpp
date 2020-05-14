#include "stdafx.h"
#include "VideoObject.h"


VideoObject::VideoObject(QObject* parent, QUrl* filePath)
{
	if (QFile::exists(filePath->path()))
	{
		videoPath = filePath;
		player = new QMediaPlayer();
        this->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
        this->setAcceptHoverEvents(true);
		player->setMedia(QUrl::fromLocalFile(filePath->path()));
		player->setVideoOutput(this);
        player->play();
		//pixmapFrame = new QPixmap();
        this->currentHandle = nullptr;   
        qDebug() << player->error();
	}
    else
    {
        qDebug() << "File Not Found";
    }
}

VideoObject::~VideoObject()
{
	delete player;
}

QString VideoObject::getVideoPath()
{
	return videoPath->path();
}

QMediaPlayer* VideoObject::getPlayer()
{
	return player;
}

void VideoObject::playMedia()
{
    //if(!player->NoMedia)
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


/*
QRectF VideoObject::boundingRect() 
{
    return QRectF(0, 0, 200, 200);
}*/


void VideoObject::setPixmap(QPixmap* pixmap) //might not need
{
	this->pixmapFrame = pixmap;
}


void VideoObject::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (!init)
    {
        this->objectRect = boundingRect();
        createHandles();
    }

	if (event->buttons() == Qt::LeftButton)
    {
        mousePos = event->pos();
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
        qDebug() << "Right Click";
        //open context menu here
    
    }
    QGraphicsVideoItem::mousePressEvent(event);
    //event->accept();
}

void VideoObject::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->buttons() == Qt::LeftButton && this->currentHandle != nullptr)
    {
        qreal sensitivity = 1;
        qreal dirX = 1.15;
        qreal dirY = 1.15;
        QPointF deltaPos = event->pos() - mousePos;

        if (deltaPos.x() < 0)
            dirX = 0.9;
        if (deltaPos.y() < 0)
            dirY = 0.9;

        dirX *= sensitivity;
        dirY *= sensitivity;

        mousePos = event->pos();
        QTransform transform = this->transform();

        if (this->currentHandle->getHandleType() == HandleType::MidLeft)
        {
            this->setTransform(this->transform().scale(dirX, 1));
        }
        else if (this->currentHandle->getHandleType() == HandleType::MidRight)
        {
            this->setTransform(this->transform().scale(dirX, 1));
        }
        else if (this->currentHandle->getHandleType() == HandleType::Top)
        {
            this->setTransform(this->transform().scale(1, dirY));
        }
        else if (this->currentHandle->getHandleType() == HandleType::Btm)
        {
            this->setTransform(this->transform().scale(1, dirY));
        }
        else if (this->currentHandle->getHandleType() == HandleType::TopLeft)
        {
            this->setTransform(this->transform().scale(dirX, dirY));
        }
        else if (this->currentHandle->getHandleType() == HandleType::TopRight)
        {
            this->setTransform(this->transform().scale(dirX, dirY));
        }
        else if (this->currentHandle->getHandleType() == HandleType::BtmLeft)
        {
            this->setTransform(this->transform().scale(dirX, dirY));

        }
        else if (this->currentHandle->getHandleType() == HandleType::BtmRight)
        {
            this->setTransform(this->transform().scale(dirX, dirY));
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

    if (showRect)
    {
        QGraphicsVideoItem::paint(painter, option, widget);

        painter->setRenderHint(QPainter::Antialiasing, true);

        if (this->isSelected())
        {
            if (this->isDrawRect)
            {
                QPen pen(QColor::fromRgb(80, 80, 250));
                painter->setPen(pen);
                painter->drawRect(boundingRect());

                //painter->drawRect(QRectF(boundingRect().left() - 5, boundingRect().top() - 5, boundingRect().right() + 10, boundingRect().bottom() - 20));
            }

            QPointF p1;
            QPointF p2;
            for (RectHandle* handle : handleList)
            {
                if (handle->getHandleType() == HandleType::Rotation)
                {
                    p1 = handle->getPosition();
                }
                else if (handle->getHandleType() == HandleType::Top)
                {
                    p2 = handle->getPosition();
                }

                if (handle->getHandleShape() == HandleShape::RectangleShape)
                {
                    painter->drawRect(handle->boundingRect());
                }
                else if (handle->getHandleShape() == HandleShape::CircleShape)
                {
                    painter->drawEllipse(handle->boundingRect());
                }
            }

            painter->drawLine(p1, p2);
            painter->drawPoint(this->origin);
        }

        scene()->update();
    }
}

void VideoObject::onFocused()
{
    showRect = true;
}

void VideoObject::onFocusExit()
{
    showRect = false;
}