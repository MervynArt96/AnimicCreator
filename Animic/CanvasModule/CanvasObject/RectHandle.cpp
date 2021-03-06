#include "stdafx.h"
#include "RectHandle.h"

RectHandle::RectHandle(QPointF pos, int size, HandleShape shape, HandleType type)	//the sqaure handles around a graphic object that is in focus
{
	this->position = pos;
	this->type = type;		//type of handle: scale, rotate, origin
	this->shape = shape;	// square, round
	this->size = size;
	this->handleRect.setRect(pos.x() - (size/2), pos.y() - (size/2), size, size);
}

RectHandle::~RectHandle()
{

}

int RectHandle::getSize()
{
	return size;
}

void RectHandle::setSize(int value)
{
	size = value;
}

HandleType RectHandle::getHandleType()
{
	return type;
}

void RectHandle::setHandleType(HandleType t)
{
	type = t;
}

HandleShape RectHandle::getHandleShape()
{
	return shape;
}

void RectHandle::setHandleShape(HandleShape s)
{
	shape = s;
}

void RectHandle::setPosition(QPointF pos)
{
	this->handleRect.setRect(pos.x() - size / 2, pos.y() - size / 2, size, size);
	position = pos;
}

QPointF RectHandle::getPosition()
{
	return this->position;
}

QRectF RectHandle::boundingRect() const
{
	return this->handleRect;
}
