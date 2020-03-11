#include "stdafx.h"
#include "SceneListWidget.h"

SceneListWidget::SceneListWidget(QWidget *parent) : QListWidget(parent)
{

}

SceneListWidget::~SceneListWidget()
{

}

void SceneListWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::RightButton)
	{
		qDebug() << "Right Click";
		//open menu
	}
}

void SceneListWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		qDebug() << "Double Click";
	}
}


