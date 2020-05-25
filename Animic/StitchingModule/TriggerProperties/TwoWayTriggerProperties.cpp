#include "stdafx.h"
#include "TwoWayTriggerProperties.h"

TwoWayTriggerProperties::TwoWayTriggerProperties(QWidget *parent): QWidget(parent)
{
	
}

TwoWayTriggerProperties::~TwoWayTriggerProperties()
{

}

void TwoWayTriggerProperties::onChangeScene()
{
	
}

void TwoWayTriggerProperties::onChangeName(QString str)
{
	nameEdit->setText(str);
	if (trigger != nullptr)
		trigger->setName(str);
}

void TwoWayTriggerProperties::onChangePosX(qreal val)
{
	posXEdit->setText(QString::number(val));
	if (trigger != nullptr)
		trigger->setX(val);
}

void TwoWayTriggerProperties::onChangePosY(qreal val)
{
	posYEdit->setText(QString::number(val));
	if (trigger != nullptr)
		trigger->setY(val);
}

void TwoWayTriggerProperties::onChangeScale(qreal val)
{
	scaleEdit->setText(QString::number(val));
	// TBD
}

void TwoWayTriggerProperties::onChangeUrl(QUrl url)
{
	urlEdit->setText(url.toString());
	if (trigger != nullptr)
		trigger->setUrl(&url);
}

void TwoWayTriggerProperties::onChangeUrl(QString str)
{
	urlEdit->setText(str);
	if (trigger != nullptr)
		trigger->setUrl(&QUrl(str));
}


void TwoWayTriggerProperties::onChangeTrigger(TwoWayTrigger* tr)
{
	trigger = tr;
	connectTrigger();
}

void TwoWayTriggerProperties::onToggleLoop()
{
	if (trigger != nullptr)
		trigger->toggleLoop();
}


void TwoWayTriggerProperties::connectTrigger(TwoWayTrigger* tr)
{
	//connect(nameEdit, &QLineEdit::textChanged, trigger, change name);
	//connect(posXEdit, textChanged, trigger, changePosX)

	//connect(urlEdit, textChanged, trigger, changeUrl)

	//connect trigger, position change, this, onchangePos
	//connect trigger, scale change, this, onscaleChange
	//connect 
}

void TwoWayTriggerProperties::connectTrigger()
{
	if (trigger != nullptr)
	{
		connect(nameEdit, &QLineEdit::textChanged, trigger, &TwoWayTrigger::setName);
		//connect(posXEdit, textChanged, trigger, changePosX)

		//connect(urlEdit, textChanged, trigger, changeUrl)

		//connect trigger, position change, this, onchangePos
		//connect trigger, scale change, this, onscaleChange
		connect(loopToggle, &QCheckBox::stateChanged, trigger, &TwoWayTrigger::toggleLoop);
	}
}
