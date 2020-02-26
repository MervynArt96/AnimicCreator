#pragma once

#include <QRectF>

enum HandleType
{
	TopLeft, Top, TopRight,
	MidLeft, MidRight,
	BtmLeft, Btm, BtmRight,
	Rotation, Origin
};

enum HandleShape
{
	CircleShape,
	RectangleShape
};

class RectHandle
{

public:
	RectHandle(QPointF pos, int size, HandleShape shape, HandleType type);
	~RectHandle();

	int getSize();
	void setSize(int);

	HandleType getHandleType();
	void setHandleType(HandleType);
	HandleShape getHandleShape();
	void setHandleShape(HandleShape);
	void setPosition(QPointF);
	QPointF getPosition();

	QRectF boundingRect() const;

private:
	
	HandleType type;
	HandleShape shape;
	int size;
	QRectF handleRect;
	QPointF position;

};
