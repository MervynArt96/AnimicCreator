#pragma once
#include "stdafx.h"
#include "VideoProperties.h"

VideoProperties::VideoProperties(QWidget *parent): QWidget(parent)
{
	QGridLayout* baseLayout = new QGridLayout();

	baseLayout->addWidget(nameLabel, 0 , 0);
	baseLayout->addWidget(posXLabel, 1, 0); baseLayout->addWidget(posXEdit, 1, 1);
	baseLayout->addWidget(posYLabel, 2, 0); baseLayout->addWidget(posYEdit, 2, 1);
	baseLayout->addWidget(scaleLabel, 3, 0); baseLayout->addWidget(scaleEdit, 3, 1);
	baseLayout->addWidget(urlLabel, 4, 0); baseLayout->addWidget(urlEdit, 4, 1);
	baseLayout->addWidget(muteToggle, 5, 0);

	setLayout(baseLayout);
}

VideoProperties::~VideoProperties()
{

}

void VideoProperties::onFocusChanged(QGraphicsItem* target, QGraphicsItem* oldItem, Qt::FocusReason reason)
{
	qDebug() << target;
	qDebug() << oldItem;

	if (target != oldItem) 
	{
		VideoObject* old = qgraphicsitem_cast<VideoObject*>(oldItem);

		if (old != nullptr)
		{
			old->disconnect(posXEdit, nullptr, old, nullptr);		//this on -> cant change object pos from line edit, if off, object will disappear
			old->disconnect(posYEdit, nullptr, old, nullptr);
			old->disconnect(scaleEdit, nullptr, old, nullptr);	//this on -> cant change object pos from line edit, if off -> will scale all object
			//old->disconnect(old, nullptr, posXEdit, nullptr);
			//old->disconnect(old, nullptr, posYEdit, nullptr);
			//old->disconnect(old, nullptr, scaleEdit, nullptr);
		}

		VideoObject* obj = qgraphicsitem_cast<VideoObject*>(target);
		this->object = obj;

		if (obj != nullptr)
		{
			posXEdit->setText(QString::number(obj->scenePos().x()));
			posYEdit->setText(QString::number(obj->scenePos().y()));
			scaleEdit->setText(QString::number(obj->scale()));

			urlEdit->setText(obj->getVideoPath());
			muteToggle->setChecked(obj->getPlayer()->isMuted());

			qDebug() << "Setting Connection on Focus Change";
			connect(obj, &VideoObject::xChanged, this, &VideoProperties::onPositionXChanged);	//object change Line Edit
			connect(obj, &VideoObject::yChanged, this, &VideoProperties::onPositionYChanged);
			connect(obj, &VideoObject::scaleChanged, this, &VideoProperties::onScaleChanged);

			connect(posXEdit, &QLineEdit::textChanged, obj, &VideoObject::onPosXChanged, Qt::UniqueConnection);		//Line Edit change Object
			connect(posYEdit, &QLineEdit::textChanged, obj, &VideoObject::onPosYChanged, Qt::UniqueConnection);
			connect(scaleEdit, &QLineEdit::textChanged, obj, &VideoObject::onScaleChanged, Qt::UniqueConnection);
		}
	}
}

void VideoProperties::onPositionXChanged()
{
	if(object != nullptr)
		posXEdit->setText(QString::number(object->scenePos().x()));
}

void VideoProperties::onPositionYChanged()
{
	if (object != nullptr)
		posYEdit->setText(QString::number(object->scenePos().y()));
}

void VideoProperties::onScaleChanged() 
{
	if (object != nullptr)
		scaleEdit->setText(QString::number(object->scale()));
}