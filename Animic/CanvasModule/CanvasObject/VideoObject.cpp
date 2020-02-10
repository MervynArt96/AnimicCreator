#include "stdafx.h"
#include "VideoObject.h"

VideoObject::VideoObject(QObject *parent, QString path)
{
	if (QFile::exists(path))
	{
		videoPath = path;
		player = new QMediaPlayer();
		this->setFlag(QGraphicsVideoItem::ItemIsMovable);
		player->setMedia(QUrl::fromLocalFile(path));
		player->setVideoOutput(this);
		pixmapFrame = new QPixmap();
		drawBoundingRect();
	}
}

VideoObject::VideoObject(QString path)
{
	if (QFile::exists(path))
	{
		videoPath = path;
		player = new QMediaPlayer();
		this->setFlag(QGraphicsVideoItem::ItemIsMovable);
		player->setMedia(QUrl::fromLocalFile(path));
		player->setVideoOutput(this);
		player->play();
		pixmapFrame = new QPixmap();
		drawBoundingRect();
	}
}

VideoObject::~VideoObject()
{
	delete player;
}

QString VideoObject::getVideoPath()
{
	return videoPath;
}

QMediaPlayer* VideoObject::getPlayer()
{
	return player;
}

QRectF VideoObject::boundingRect()
{
	qreal penWidth = 1;
	return QRectF(10, 10 ,50, 50);
}

void VideoObject::drawBoundingRect()
{
	QPainter* painter = new QPainter();
	painter->setPen(Qt::Key_Blue);
	painter->drawRect(boundingRect());
}

/*
void VideoObject::mousePressEvent(QGraphicsSceneMouseEvent* event) 
{

}

void VideoObject::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{

}

void VideoObject::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{

}

void VideoObject::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{

}

void VideoObject::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{

}

void VideoObject::hoverMoveEvent(QGraphicsSceneHoverEvent* event)
{

}

void VideoObject::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{

}

bool VideoObject::mousePosOnHandles(QPointF pos)
{
	return false;
}
*/