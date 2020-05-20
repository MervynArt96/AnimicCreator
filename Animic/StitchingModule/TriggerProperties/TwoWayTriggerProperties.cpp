#include "stdafx.h"
#include "TwoWayTriggerProperties.h"

TwoWayTriggerProperties::TwoWayTriggerProperties(QWidget *parent): QWidget(parent)
{

	connect(nameEdit, &QLineEdit::textChanged, this, &onChangeName);



}

TwoWayTriggerProperties::~TwoWayTriggerProperties()
{
}

void TwoWayTriggerProperties::changeName(QString str)
{
	nameEdit->setText(str);
	trigger->setName(str);
}

void TwoWayTriggerProperties::changePosX(qreal val)
{
	posXEdit->setText(QString::number(val));
	trigger->setX(val);
}

void TwoWayTriggerProperties::changePosY(qreal val)
{
	posYEdit->setText(QString::number(val));
	trigger->setY(val);
}

void TwoWayTriggerProperties::changeScale(qreal val)
{
	scaleEdit->setText(QString::number(val));
	// TBD
}

void TwoWayTriggerProperties::changeUrl(QString str)
{
	urlEdit->setText(str);
	trigger->setUrl(QUrl(str));
}

void TwoWayTriggerProperties::onChangeName(QString)
{

}

void TwoWayTriggerProperties::onChangePosX(qreal)
{

}

void TwoWayTriggerProperties::onChangePosY(qreal)
{

}

void TwoWayTriggerProperties::onChangeScale(qreal)
{

}

void TwoWayTriggerProperties::onChangeUrl(QString)
{

}

void TwoWayTriggerProperties::onChangeTrigger(TwoWayTrigger* tr)
{

}
