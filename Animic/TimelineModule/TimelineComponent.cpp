#include "stdafx.h"
#include "TimelineComponent.h"

#include <QQuickPaintedItem>
#include <QPainter>
#include <QPalette>

class TimelinePlayhead : public QQuickPaintedItem
{
    void paint(QPainter* painter)
    {
        QPainterPath path;
        path.moveTo(width(), 0);
        path.lineTo(width() / 2.0, height());
        path.lineTo(0, 0);
        QPalette p;
        painter->fillPath(path, p.color(QPalette::WindowText));
    }
    
};

class TimelineTriangle : public QQuickPaintedItem
{
public:
    TimelineTriangle()
    {
        setAntialiasing(QPainter::Antialiasing);
    }
    void paint(QPainter* painter)
    {
        QPainterPath path;
        path.moveTo(0, 0);
        path.lineTo(width(), 0);
        path.lineTo(0, height());
        painter->fillPath(path, Qt::black);
    }
};

class TimelineWaveform : public QQuickPaintedItem
{


};