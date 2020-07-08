#include "stdafx.h"
#include "DroppableLineEdit.h"

DroppableLineEdit::DroppableLineEdit(QWidget *parent): QLineEdit(parent) // extension to QLineEdit, to accept drag and drop urls into the text field as string
{

}

DroppableLineEdit::DroppableLineEdit()
{

}

DroppableLineEdit::~DroppableLineEdit()
{

}


void DroppableLineEdit::dropEvent(QDropEvent* e)	// handle drop event
{
	const QMimeData* data = e->mimeData();

	for(QUrl url : data->urls())
	{
		this->setText(url.toString());	//set url as the text 
	}

	emit urlChanged(data->urls());	//signal that the url has changed and the video object should start buffering the video data
}


void DroppableLineEdit::dragEnterEvent(QDragEnterEvent* e)	//only accept mimedata with url in it
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
