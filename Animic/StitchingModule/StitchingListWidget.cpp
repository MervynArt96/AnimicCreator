#include "stdafx.h"
#include "StitchingListWidget.h"

StitchingListWidget::StitchingListWidget(QWidget *parent) : QListWidget(parent)
{

}

StitchingListWidget::~StitchingListWidget()
{

}

void StitchingListWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		
	}
}
