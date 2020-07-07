#pragma once
#include <QRectF>
#include <QVector>
#include <QPolygonF>
#include <QLineF>
#include <QGraphicsSceneEvent>
#include "CanvasModule/CanvasObject/RectHandle.h"
#include <QPainter>
#include <QGraphicsItem>
#include <QSettings>
#include <QVariant>


class BaseObject    //base class that adds handles to a graphics object. Everything is inline, so no .cpp file
{

public:

    inline BaseObject();
    inline void createHandles();

protected:

    virtual void mousePressEvent(QGraphicsSceneMouseEvent*) = 0;      //pure virtual functions for user input events
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent*) = 0;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent*) = 0;
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent*) = 0;

    //virtual QVariant itemChange(QGraphicsItem::GraphicsItemChange, const QVariant) = 0;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) = 0;

    //virtual QRectF boundingRect() const = 0;

    QList<RectHandle*> handleList;
    QRectF objectRect;
    QPointF origin;

    RectHandle* currentHandle;

private:

    QLineF RotationLine;
    QPolygonF m_AngleHandle;

}; 
//Class ending_______________________________________________________________________________________________________


BaseObject::BaseObject() {};

void BaseObject::createHandles()
{
    QSettings settings;
    int size = settings.value("drawing/handleSize", 10).toInt();        //default size for the handle

    origin = this->objectRect.center();                                                 //create initial position to place the handles
    QPointF left(objectRect.left() + 5, objectRect.top() + (objectRect.height() / 2));
    QPointF right(objectRect.right() - 5, objectRect.top() + objectRect.height() / 2);
    QPointF top(objectRect.left() + objectRect.width() / 2, objectRect.top() + 5);
    QPointF bottom(objectRect.left() + objectRect.width() / 2, objectRect.bottom() - 5);
    QPointF rotate(top.x(), top.y() - 50);

    handleList.append(new RectHandle(objectRect.topLeft() + QPointF(5,5), size, HandleShape::RectangleShape, HandleType::TopLeft));         // create a new handle and add to list
    handleList.append(new RectHandle(objectRect.topRight() + QPointF(-5, 5), size, HandleShape::RectangleShape, HandleType::TopRight));
    handleList.append(new RectHandle(objectRect.bottomLeft() + QPointF(5, -5), size, HandleShape::RectangleShape, HandleType::BtmLeft));
    handleList.append(new RectHandle(objectRect.bottomRight() + QPointF(-5, -5), size, HandleShape::RectangleShape, HandleType::BtmRight));

    //handleList.append(new RectHandle(rotate, size, HandleShape::CircleShape, HandleType::Rotation));      //implementation issue
    //handleList.append(new RectHandle(origin, size, HandleShape::CircleShape, HandleType::Origin));

    //handleList.append(new RectHandle(top, size, HandleShape::RectangleShape, HandleType::Top));           //not needed
    //handleList.append(new RectHandle(left, size, HandleShape::RectangleShape, HandleType::MidLeft));
    //handleList.append(new RectHandle(right, size, HandleShape::RectangleShape, HandleType::MidRight));
    //handleList.append(new RectHandle(bottom, size, HandleShape::RectangleShape, HandleType::Btm));
}


