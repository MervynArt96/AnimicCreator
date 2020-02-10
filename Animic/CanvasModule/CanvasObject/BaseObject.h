#pragma once
#include <QRectF>
#include <QVector>
#include <QPolygonF>
#include <QLineF>
#include <QGraphicsSceneEvent>

enum RectHandle
{
	TopLeft,Top,TopRight,
	MidLeft,Mid,MidRight,
	BtmLeft,Btm,BtmRight,
	Rotation
};

class BaseObject
{
public:

    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) = 0;      //user input events
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) = 0;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) = 0;
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* event) = 0;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) = 0;
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent* event) = 0;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) = 0;
    virtual void mouseDragMoveEvent(QGraphicsSceneMouseEvent* event) = 0;
    virtual bool mousePosOnHandles(QPointF pos) = 0;

private:

    QRectF boundingRect;
    //QRectF oriRect;
    QVector<QRectF> handlelist;
    QLineF RotationLine;
    QPolygonF m_AngleHandle;

    double angle;

    bool isResizing;
    bool mousePressed;

    RectHandle handle;

};

