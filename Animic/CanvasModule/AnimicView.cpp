#include "stdafx.h"
#include "AnimicView.h"

AnimicView::AnimicView(QWidget* parent, int md): QGraphicsView(parent)  //custom viewport to hold scenes
{
    mode = md;                                      //mode determine if the input key will affect the video object, used to distinguish preview mode and edit mode
    this->viewport()->installEventFilter(this);     
    this->setMouseTracking(true);                   //track mouse movement
    setDragMode(QGraphicsView::NoDrag);             // wont support drag to create a selection box 
    modifiers = Qt::ControlModifier;                // ctrl key modifier for zooming
    zoom_factor_base = 1.0015;                      
    this->setFocusPolicy(Qt::ClickFocus);           //requires mouse click focus on the viewport before reacting to user input
}

AnimicView::~AnimicView()
{

}

void AnimicView::setAnimicScene(AnimicScene* sc)    
{
    QGraphicsView::setScene(sc);
    emit sceneChanged(sc);
}


void AnimicView::keyPressEvent(QKeyEvent* event) // accept key press input from user
{
    QGraphicsView::keyPressEvent(event);    //calling inherrited function to get the default behaviour

    if (mode == 0) // edit mode
    {
        if (event->key() == Qt::Key_Space && !event->isAutoRepeat())    //to achieve press and hold space scenario
        {
            setDragMode(QGraphicsView::ScrollHandDrag);                         //can drag the viewport around by holding down space and mouse drag
            AnimicScene* scene = dynamic_cast<AnimicScene*>(this->scene());     

            if (scene != nullptr)
            {
                scene->disableObjectDragging();         //disable video object dragging in this scenario
            }
        }
    }
    else if (mode == 1) //preview mode
    {
        if (event->key() == Qt::Key_Space && !event->isAutoRepeat())    //start preview by pressing on space
        {
            emit startPreview();
        }
    }
}

void AnimicView::keyReleaseEvent(QKeyEvent* event) 
{
    if (event->key() == Qt::Key_Space && !event->isAutoRepeat())        //reset scene to normal behaviour after releasing space
    {
        setDragMode(QGraphicsView::NoDrag);
        AnimicScene* scene = dynamic_cast<AnimicScene*>(this->scene());

        if (scene != nullptr)
        {
            scene->enableObjectDragging();
        }
    }
}

void AnimicView::gentle_zoom(double factor)     //zoom in and out algorithm with ctrl + mouse wheel
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
                qDebug() << this->transform();
            }
        }
    }
    return false;
}
