#include "stdafx.h"
#include "AnimicView.h"

AnimicView::AnimicView(QWidget* parent): QGraphicsView(parent)
{
    this->viewport()->installEventFilter(this);
    this->setMouseTracking(true);
    modifiers = Qt::ControlModifier;
    zoom_factor_base = 1.0015;
}

AnimicView::~AnimicView()
{

}


void AnimicView::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        qDebug() << "Space";
    }
}

void AnimicView::gentle_zoom(double factor) 
{
    this->scale(factor, factor);
    this->centerOn(target_scene_pos);
    QPointF delta_viewport_pos = target_viewport_pos - QPointF(this->viewport()->width() / 2.0, this->viewport()->height() / 2.0);
    QPointF viewport_center = this->mapFromScene(target_scene_pos) - delta_viewport_pos;
    this->centerOn(this->mapToScene(viewport_center.toPoint()));
    emit zoomed();
}

void AnimicView::set_modifiers(Qt::KeyboardModifiers modifiers) 
{
    modifiers = modifiers;
}

void AnimicView::set_zoom_factor_base(double value) 
{
    zoom_factor_base = value;
}

bool AnimicView::eventFilter(QObject* object, QEvent* event)
{
    Q_UNUSED(object)

    if (event->type() == QEvent::MouseMove) 
    {
        QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);
        QPointF delta = target_viewport_pos - mouse_event->pos();
        if (qAbs(delta.x()) > 5 || qAbs(delta.y()) > 5) 
        {
            target_viewport_pos = mouse_event->pos();
            target_scene_pos = this->mapToScene(mouse_event->pos());
        }
    }
    else if (event->type() == QEvent::Wheel) 
    {
        QWheelEvent* wheel_event = static_cast<QWheelEvent*>(event);
        if (QApplication::keyboardModifiers() == modifiers && wheel_event->orientation() == Qt::Vertical)
        {
            if (1) //scale between range
            {
                double angle = wheel_event->angleDelta().y();
                double factor = qPow(zoom_factor_base, angle);
                gentle_zoom(factor);
                return true;
            }
        }
    }
    return false;
}

