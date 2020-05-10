#pragma once
#include "stdafx.h"
#include "VideoProperties.h"

VideoProperties::VideoProperties(QWidget *parent): QWidget(parent)
{
	QGridLayout* baseLayout = new QGridLayout();

	//QSpacerItem* spacer = new QSpacerItem(20, 20);

	baseLayout->addWidget(nameLabel, 0 , 0); baseLayout->addWidget(nameText, 0, 1);
	baseLayout->addWidget(posXLabel, 1, 0); baseLayout->addWidget(posXEdit, 1, 1);
	baseLayout->addWidget(posYLabel, 2, 0); baseLayout->addWidget(posYEdit, 2, 1);
	baseLayout->addWidget(scaleXLabel, 3, 0); baseLayout->addWidget(scaleXEdit, 3, 1);
	baseLayout->addWidget(scaleYLabel, 4, 0); baseLayout->addWidget(scaleYEdit, 4, 1);
	baseLayout->addWidget(urlLabel, 5, 0); baseLayout->addWidget(urlEdit, 5, 1);
	baseLayout->addWidget(muteSwitch, 6, 0);

	setLayout(baseLayout);

	connectComponent();
}

VideoProperties::~VideoProperties()
{

}

void VideoProperties::connectComponent()
{
	if(obj != nullptr)
	{
		connect(obj, SIGNAL(xChanged()), posXEdit, SLOT(setText()));
		connect(obj, SIGNAL(yChanged()), posYEdit, SLOT(setText()));

		//connect(obj, SIGNAL(scaleChanged()), posXEdit, SLOT(setText()));

		//connect ui to obj
		//connect obj to ui

	}
}

void VideoProperties::onFocusChanged(VideoObject* target)
{
	obj = target;
	
	posXEdit->setText(QString::number(obj->scenePos().x()));
	posYEdit->setText(QString::number(obj->scenePos().y()));

	//scale here

	urlEdit->setText(obj->getVideoPath());

	connectComponent();
}

void VideoProperties::onSizeXChanged()
{

}

void VideoProperties::onSizeYChanged()
{

}

void VideoProperties::onScaleXChanged() 
{

}

void VideoProperties::onScaleYChanged()
{

}
