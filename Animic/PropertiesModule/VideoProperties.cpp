#pragma once
#include "stdafx.h"
#include "VideoProperties.h"

VideoProperties::VideoProperties(QWidget *parent): QWidget(parent)	// properties widget that controls and display properties of a selected 
{
	QGridLayout* baseLayout = new QGridLayout();

	baseLayout->addWidget(nameLabel, 0 , 0);
	baseLayout->addWidget(posXLabel, 1, 0); baseLayout->addWidget(posXEdit, 1, 1);		//position controls
	baseLayout->addWidget(posYLabel, 2, 0); baseLayout->addWidget(posYEdit, 2, 1);
	baseLayout->addWidget(scaleLabel, 3, 0); baseLayout->addWidget(scaleEdit, 3, 1);	//scale control
	baseLayout->addWidget(urlLabel, 4, 0); baseLayout->addWidget(urlEdit, 4, 1);		//url control
	baseLayout->addWidget(loopLabel, 5, 0); baseLayout->addWidget(loopEdit, 5, 1);		//placeholder url control
	baseLayout->addWidget(muteToggle, 6, 0);

	setLayout(baseLayout);
}

VideoProperties::~VideoProperties()
{

}

void VideoProperties::onSwitchScene()	//when user click on a different tab or close a tab
{
	disconnectWidgets();
}

void VideoProperties::resetItem()
{
	newItem = nullptr;
	clearProperties();
}

void VideoProperties::onFocusChanged(QGraphicsItem* target, QGraphicsItem* oldItem, Qt::FocusReason reason)	//when user click on a different video object or any other ui component
{
	if (target != nullptr)													//user click on something that is not a graphics object
	{
		VideoObject* old = qgraphicsitem_cast<VideoObject*>(oldItem);	
		if (old != nullptr)													//check if previously a graphics object is in focus
		{
			oldObject = old;												//disconnect the old object from being controlled
			disconnect(posXEdit, nullptr, old, nullptr);
			disconnect(posYEdit, nullptr, old, nullptr);
			disconnect(scaleEdit, nullptr, old, nullptr);
			disconnect(urlEdit, nullptr, old, nullptr);
			disconnect(loopEdit, nullptr, old, nullptr);
		}
		if (newItem != nullptr)												//local reference of the previous object
		{
			disconnect(posXEdit, nullptr, newItem, nullptr);
			disconnect(posYEdit, nullptr, newItem, nullptr);
			disconnect(scaleEdit, nullptr, newItem, nullptr);
			disconnect(urlEdit, nullptr, newItem, nullptr);
			disconnect(loopEdit, nullptr, newItem, nullptr);
		}

		VideoObject* obj = qgraphicsitem_cast<VideoObject*>(target);		// check if the newly clicked item is a video object

		if (obj != nullptr)
		{
			this->newItem = obj;
			posXEdit->setText(QString::number(obj->scenePos().x()));		//initialize the text fields
			posYEdit->setText(QString::number(obj->scenePos().y()));
			scaleEdit->setText(QString::number(obj->scale()));

			urlEdit->setText(obj->getVideoPath());
			loopEdit->setText(obj->getLoopPath());
			muteToggle->setChecked(obj->getPlayer()->isMuted());

			connect(obj, &VideoObject::xChanged, this, &VideoProperties::onPositionXChanged);	//allows object to change the text field
			connect(obj, &VideoObject::yChanged, this, &VideoProperties::onPositionYChanged);
			connect(obj, &VideoObject::scaleChanged, this, &VideoProperties::onScaleChanged);

			connect(posXEdit, &QLineEdit::textEdited, obj, &VideoObject::onPosXChanged);		//allow the text field to change the object
			connect(posYEdit, &QLineEdit::textEdited, obj, &VideoObject::onPosYChanged);		
			connect(scaleEdit, &QLineEdit::textEdited, obj, &VideoObject::onScaleChanged);
			connect(urlEdit, &QLineEdit::textChanged, obj, &VideoObject::onUrlChanged );
			connect(loopEdit, &QLineEdit::textChanged, obj, &VideoObject::onLoopPathChanged);
		}
	}
}

void VideoProperties::onPositionXChanged()
{
	if(newItem != nullptr)
		posXEdit->setText(QString::number(newItem->scenePos().x()));		//change the text field based on the change in the object position / scale
}

void VideoProperties::onPositionYChanged()
{
	if (newItem != nullptr)
		posYEdit->setText(QString::number(newItem->scenePos().y()));
}

void VideoProperties::onScaleChanged() 
{
	if (newItem != nullptr)
		scaleEdit->setText(QString::number(newItem->scale()));
}

void VideoProperties::clearProperties()
{
	posXEdit->setText(0);
	posYEdit->setText(0);
	scaleEdit->setText(0);
	urlEdit->setText("");
	loopEdit->setText("");
	muteToggle->setChecked(false);
}

void VideoProperties::disconnectWidgets()
{
	posXEdit->disconnect();
	posYEdit->disconnect();
	scaleEdit->disconnect();
	urlEdit->disconnect();
}