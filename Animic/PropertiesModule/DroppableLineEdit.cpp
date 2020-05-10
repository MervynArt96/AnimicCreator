#include "stdafx.h"
#include "DroppableLineEdit.h"

DroppableLineEdit::DroppableLineEdit(QWidget *parent): QLineEdit(parent)
{

}

DroppableLineEdit::DroppableLineEdit()
{

}

DroppableLineEdit::~DroppableLineEdit()
{

}


void DroppableLineEdit::dropEvent(QDropEvent* e)
{
	const QMimeData* data = e->mimeData();

	for(QUrl url : data->urls())
	{
		this->setText(url.toString());
	}

	emit urlChanged(data->urls());
}


void DroppableLineEdit::dragEnterEvent(QDragEnterEvent* e)
{
	const QMimeData* data = e->mimeData();

	if (data->hasUrls())
	{
		e->accept();
	}
}

void DroppableLineEdit::dragLeaveEvent(QDragLeaveEvent* e)
{

}

void DroppableLineEdit::dragMoveEvent(QDragMoveEvent* e)
{

}
