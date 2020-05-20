#pragma once

#include <QGraphicsView>
#include "CanvasModule/AnimicScene.h"

class AnimicView : public QGraphicsView
{
	Q_OBJECT

public:
	AnimicView(QWidget*);
    ~AnimicView();
    void gentle_zoom(double factor);
    void set_modifiers(Qt::KeyboardModifiers modifiers);
    void set_zoom_factor_base(double value);

    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent* event);

    void setAnimicScene(AnimicScene*);

private:

    Qt::KeyboardModifiers modifiers;
    double zoom_factor_base;
    QPointF target_scene_pos, target_viewport_pos;
    bool eventFilter(QObject* object, QEvent* event);
    int lowerLimit = 0.5;
    int upperLimit = 0.5;

signals:
    
    void zoomed();
    void sceneChanged(AnimicScene*);

public slots:


};
