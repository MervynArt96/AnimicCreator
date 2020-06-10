#include "stdafx.h"
#include "OneWayTrigger.h"

OneWayTrigger::OneWayTrigger(QObject* parent, QUrl* filePath)
{
    if (QFile::exists(filePath->path()))
    {
        playList = new QMediaPlaylist();
        playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        playList->addMedia(*filePath);
        playList->setCurrentIndex(1);
        player = new QMediaPlayer();
        player->setPlaylist(playList);
        videoPath = new QUrl(filePath->path());
        this->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsFocusable | QGraphicsVideoItem::ItemIsSelectable);
        this->setAcceptHoverEvents(true);
        player->setVideoOutput(this);
        player->play();
        player->pause();
        this->currentHandle = nullptr;
        qDebug() << player->error();
    }
    else
    {
        qDebug() << "File Not Found";
    }
}

OneWayTrigger::~OneWayTrigger()
{

}

void OneWayTrigger::keyPressEvent(QKeyEvent* event)
{
    QGraphicsItem::keyPressEvent(event);
    qDebug() << "Timed Mash Key Pressed: " << event->text();
    if (activeTrigger)
    {
        if (event->key() == Qt::Key_E)
        {
            emit sendDefaultScene(sceneDefault);
            activeTrigger = false;
        }
    }
}

void OneWayTrigger::setActiveTrigger(bool x)
{
    activeTrigger = x;

    if (activeTrigger && timeLimit > 0)     //this will go to next scene automatically after a certain time.
    {
        this->setFocus();
        QTimer::singleShot(timeLimit, this, [=]()
            {
                qDebug() << "Transitioning to Next Scene Automatically";
                emit sendDefaultScene(sceneDefault);
            });
    }
}

int OneWayTrigger::getTimeLimit()
{
    return timeLimit;
}

void OneWayTrigger::setTimeLimit(int i)
{
    timeLimit = i;
}

void OneWayTrigger::onDurationChanged(int time)
{
    timeLimit = time;
}

void OneWayTrigger::setDefaultScene(AnimicScene* sc)
{
    sceneDefault = sc;
    qDebug() << sceneDefault->getName();
}

AnimicScene* OneWayTrigger::getDefaultScene()
{
    return sceneDefault;
}

QString OneWayTrigger::getName()
{
    return name;
}

void OneWayTrigger::setName(QString str)
{
    this->name = str;
}

QString OneWayTrigger::getUrl()
{
    return videoPath->path();
}

void OneWayTrigger::setUrl(QUrl* str)
{
    playList->removeMedia(0);
    playList->addMedia(*str);
    videoPath = str;
}

QMediaPlaylist* OneWayTrigger::getPlayList()
{
    return playList;
}

QMediaPlayer* OneWayTrigger::getPlayer()
{
    return player;
}

void OneWayTrigger::playMedia()
{
    //if(!player->NoMedia)
    player->play();
}

void OneWayTrigger::pauseMedia()
{
    player->pause();
}

void OneWayTrigger::stopMedia()
{
    player->stop();
}

void OneWayTrigger::createHandles()
{
    QSettings settings;
    int size = settings.value("drawing/handleSize", 10).toInt();
    //Resizing rectangle.

    origin = this->objectRect.center();
    QPointF left(objectRect.left() + 5, objectRect.top() + (objectRect.height() / 2));
    QPointF right(objectRect.right() - 5, objectRect.top() + objectRect.height() / 2);
    QPointF top(objectRect.left() + objectRect.width() / 2, objectRect.top() + 5);
    QPointF bottom(objectRect.left() + objectRect.width() / 2, objectRect.bottom() - 5);
    //QPointF rotate(top.x(), top.y() - 50);

    handleList.append(new RectHandle(objectRect.topLeft() + QPointF(5, 5), size, HandleShape::RectangleShape, HandleType::TopLeft));
    handleList.append(new RectHandle(objectRect.topRight() + QPointF(-5, 5), size, HandleShape::RectangleShape, HandleType::TopRight));
    handleList.append(new RectHandle(objectRect.bottomLeft() + QPointF(5, -5), size, HandleShape::RectangleShape, HandleType::BtmLeft));
    handleList.append(new RectHandle(objectRect.bottomRight() + QPointF(-5, -5), size, HandleShape::RectangleShape, HandleType::BtmRight));

    //handleList.append(new RectHandle(top, size, HandleShape::RectangleShape, HandleType::Top));
    //handleList.append(new RectHandle(left, size, HandleShape::RectangleShape, HandleType::MidLeft));
    //handleList.append(new RectHandle(right, size, HandleShape::RectangleShape, HandleType::MidRight));
    //handleList.append(new RectHandle(bottom, size, HandleShape::RectangleShape, HandleType::Btm));
    //handleList.append(new RectHandle(rotate, size, HandleShape::CircleShape, HandleType::Rotation));
    //handleList.append(new RectHandle(origin, size, HandleShape::CircleShape, HandleType::Origin));
}

void OneWayTrigger::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (!init)
    {
        this->objectRect = boundingRect();
        createHandles();
    }

    if (event->buttons() == Qt::LeftButton)
    {
        mousePos = event->pos();
        for (RectHandle* handle : this->handleList)
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

void OneWayTrigger::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->buttons() == Qt::LeftButton && this->currentHandle != nullptr)
    {
        const qreal sensitivity = 1;
        qreal dir = 1.15;
        QPointF deltaPos = event->pos() - mousePos;

        if (deltaPos.x() < 0 || deltaPos.y() < 0)
            dir = 0.9 * sensitivity;

        mousePos = event->pos();
        QTransform transform = this->transform();

        if (this->currentHandle->getHandleType() == HandleType::MidLeft)
        {

        }
        else if (this->currentHandle->getHandleType() == HandleType::MidRight)
        {

        }
        else if (this->currentHandle->getHandleType() == HandleType::Top)
        {

        }
        else if (this->currentHandle->getHandleType() == HandleType::Btm)
        {

        }
        else if (this->currentHandle->getHandleType() == HandleType::TopLeft)
        {

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


void OneWayTrigger::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsVideoItem::mouseReleaseEvent(event);
    currentHandle = nullptr;
    event->accept();
}

void OneWayTrigger::hoverMoveEvent(QGraphicsSceneHoverEvent* event)
{
    mousePos = event->pos();
}

void OneWayTrigger::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QGraphicsVideoItem::paint(painter, option, widget);

    painter->setRenderHint(QPainter::Antialiasing, true);

    if (this->isSelected() && !activeTrigger)
    {
        if (this->showRect)
        {
            QPen pen(QColor::fromRgb(80, 250, 80));
            painter->setPen(pen);
            painter->drawRect(boundingRect());

            //painter->drawRect(QRectF(boundingRect().left() - 5, boundingRect().top() - 5, boundingRect().right() + 10, boundingRect().bottom() - 20));
        }

        /* QPointF p1;
         QPointF p2;*/
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

void OneWayTrigger::disableRect()
{
    showRect = false;
}

void OneWayTrigger::enableRect()
{
    showRect = true;
}

void OneWayTrigger::onPosXChanged(const QString& str)
{
    this->setX(str.toDouble());
}

void OneWayTrigger::onPosYChanged(const QString& str)
{
    this->setY(str.toDouble());
}

void OneWayTrigger::onScaleChanged(const QString& str)
{
    if (str.toDouble() != 0 && str.toDouble())
        this->setScale(str.toDouble());
}


void OneWayTrigger::onUrlChanged(const QString& str)
{
    qint64 pos = player->position();
    videoPath->clear();
    videoPath->setPath(str);
    playList->clear();
    playList->addMedia(QUrl::fromLocalFile(str));
    delete player;
    player = new QMediaPlayer();
    this->setMediaObject(player);
    player->setPlaylist(playList);
    player->setPosition(pos);
}

void OneWayTrigger::transformHandle()
{

}