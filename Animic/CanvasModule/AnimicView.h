#pragma once

#include <QGraphicsView>

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

private:

    Qt::KeyboardModifiers modifiers;
    double zoom_factor_base;
    QPointF target_scene_pos, target_viewport_pos;
    bool eventFilter(QObject* object, QEvent* event);
    int lowerLimit = 0.5;
    int upperLimit = 0.5;

signals:
    void zoomed();


};
