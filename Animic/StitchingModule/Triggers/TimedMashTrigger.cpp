#include "stdafx.h"
#include "TimedMashTrigger.h"

TimedMashTrigger::TimedMashTrigger(QObject* parent, QUrl* filePath) //same as video object but without placeholder video, has additional keypress event support
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
    }
    else
    {
        qDebug() << "File Not Found";
    }
}

TimedMashTrigger::~TimedMashTrigger()
{

}

void TimedMashTrigger::keyPressEvent(QKeyEvent* event)          //user required to mash the E key to go to the default scene
{
    QGraphicsItem::keyPressEvent(event);
    qDebug() << "Timed Mash Key Pressed: " << event->text();
    if (activeTrigger)
    {
        if (event->key() == Qt::Key_E)
        {
            keyPressCount++;                        // if key press reaches threshold play the next scene
            if (keyPressCount >= keyMax)
            {
                qDebug() << "Succeeded";
                emit sendDefaultScene(sceneDefault);
                activeTrigger = false;
            }
        }
    }
}

void TimedMashTrigger::setActiveTrigger(bool x)
{
    activeTrigger = x;

    if (activeTrigger)
    {
        keyPressCount = 0;
        this->setFocus();
        timer->singleShot(timeLimit, this, [=]()       //responsible to keep track of time, go to alternate scene if time is up
            {
                qDebug() << "Time's Up";
                emit sendAltScene(sceneAlt);
            });
    }
}

int TimedMashTrigger::getTimeLimit()
{
    return timeLimit;
}

void TimedMashTrigger::setTimeLimit(int i)
{
    timeLimit = i;
}

int TimedMashTrigger::getKeyMax()
{
    return keyMax;
}

void TimedMashTrigger::setKeyMax(int i)
{
    keyMax = i;
}

void TimedMashTrigger::setDefaultScene(AnimicScene* sc)
{
    sceneDefault = sc;
    qDebug() << "Default Scene: " <<sceneDefault->getName();
}

void TimedMashTrigger::setAltScene(AnimicScene* sc)
{
    sceneAlt = sc;
    qDebug() << "Alt Scene:" << sceneAlt->getName();
}

AnimicScene* TimedMashTrigger::getDefaultScene()
{
    return sceneDefault;
}

AnimicScene* TimedMashTrigger::getAltScene()
{
    return sceneAlt;
}

QString TimedMashTrigger::getName()
{
    return name;
}

void TimedMashTrigger::setName(QString str)
{
    this->name = str;
}

QString TimedMashTrigger::getUrl()
{
    return videoPath->path();
}

void TimedMashTrigger::setUrl(QUrl* str)
{
    playList->removeMedia(0);
    playList->addMedia(*str);
    videoPath = str;
}

QMediaPlaylist* TimedMashTrigger::getPlayList()
{
    return playList;
}

QMediaPlayer* TimedMashTrigger::getPlayer()
{
    return player;
}

void TimedMashTrigger::playMedia()
{
    //if(!player->NoMedia)
    player->play();
}

void TimedMashTrigger::pauseMedia()
{
    player->pause();
}

void TimedMashTrigger::stopMedia()
{
    player->stop();
}

void TimedMashTrigger::createHandles()
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

void TimedMashTrigger::mousePressEvent(QGraphicsSceneMouseEvent* event)
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

void TimedMashTrigger::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
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


void TimedMashTrigger::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsVideoItem::mouseReleaseEvent(event);
    currentHandle = nullptr;
    event->accept();
}

void TimedMashTrigger::hoverMoveEvent(QGraphicsSceneHoverEvent* event)
{
    mousePos = event->pos();
}

void TimedMashTrigger::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
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

void TimedMashTrigger::disableRect()
{
    showRect = false;
}

void TimedMashTrigger::enableRect()
{
    showRect = true;
}

void TimedMashTrigger::onKeyMaxChanged(const QString& i)
{
    keyMax = i.toInt();
    qDebug() << "Key MaX: " << keyMax;
}

void TimedMashTrigger::onTimeLimitChanged(const QString& time)
{
    timeLimit = time.toInt();
}

void TimedMashTrigger::onPosXChanged(const QString& str)
{
    this->setX(str.toDouble());
}

void TimedMashTrigger::onPosYChanged(const QString& str)
{
    this->setY(str.toDouble());
}

void TimedMashTrigger::onScaleChanged(const QString& str)
{
    if (str.toDouble() != 0 && str.toDouble())
        this->setScale(str.toDouble());
}


void TimedMashTrigger::onUrlChanged(const QString& str)
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

void TimedMashTrigger::transformHandle()
{

}

void TimedMashTrigger::contextMenuEvent(QGraphicsSceneContextMenuEvent* event)
{
    QMenu menu;
    QAction* removeAction = menu.addAction("Remove Item");
    connect(removeAction, &QAction::triggered, qobject_cast<AnimicScene*>(scene()), &AnimicScene::onDeleteTrigger);
    QAction* selectedAction = menu.exec(event->screenPos());
}

void TimedMashTrigger::resetNextScenes(AnimicScene* sc)
{
    if (sceneDefault == sc)
    {
        sceneDefault = nullptr;
    }

    if (sceneAlt == sc)
    {
        sceneAlt = nullptr;
    }
}