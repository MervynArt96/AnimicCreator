#pragma once

#include <QListWidget>

class SceneListWidget : public QListWidget
{
	Q_OBJECT

public:
	SceneListWidget(QWidget *parent);
	~SceneListWidget();

	void mousePressEvent(QMouseEvent* event);
	void mouseDoubleClickEvent(QMouseEvent* event);


};
