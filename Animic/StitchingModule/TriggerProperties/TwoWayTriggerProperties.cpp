#include "stdafx.h"
#include "TwoWayTriggerProperties.h"

TwoWayTriggerProperties::TwoWayTriggerProperties(QWidget *parent): QWidget(parent)
{
	posXEdit = new QLineEdit();
	posYEdit = new QLineEdit();

	scaleEdit = new QLineEdit();
	urlEdit = new DroppableLineEdit();

	sceneDefaultLabel = new QLabel("Default Scene: ");
	sceneAltLabel = new QLabel("Alternate Scene: ");

	QComboBox* sceneDefaultComboBox = new QComboBox();
	QComboBox* sceneAltComboBox = new QComboBox();

	posXLabel = new QLabel("Position X: ");
	posYLabel = new QLabel("Position Y: ");

	urlLabel = new QLabel("URL: ");
	scaleLabel = new QLabel("Scale: ");

	loopToggle = new QCheckBox("Toggle Loop", nullptr);

	//set double invalidator for each line edit

	QGridLayout* layout = new QGridLayout();

	layout->addWidget(posXLabel, 0, 0); layout->addWidget(posXEdit, 0 ,1);
	layout->addWidget(posYLabel, 1, 0); layout->addWidget(posYEdit, 1, 1);
	layout->addWidget(urlLabel, 2, 0); layout->addWidget(urlEdit, 2, 1);
	layout->addWidget(sceneDefaultLabel, 3, 0); layout->addWidget(sceneDefaultComboBox, 3, 1);
	layout->addWidget(sceneAltLabel, 4, 0); layout->addWidget(sceneAltComboBox, 4, 1);
	layout->addWidget(loopToggle, 5, 0);

	this->setLayout(layout);
	//scale
}

TwoWayTriggerProperties::~TwoWayTriggerProperties()
{

}

void TwoWayTriggerProperties::onChangeScene(AnimicScene* sc)
{
	trigger = qgraphicsitem_cast<TwoWayTrigger*>(sc->getTrigger());
	if (trigger != nullptr)
	{
		//get trigger properties
		//connect trigger to line edits
		//connect line edits change signal to trigger slots
		//connect radio group to scene
	}
}

QComboBox* TwoWayTriggerProperties::getSceneDefaultComboBox()
{
	return sceneDefaultComboBox;
}

QComboBox* TwoWayTriggerProperties::getSceneAltComboBox()
{
	return sceneAltComboBox;
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
		//connect(posXEdit, textChanged, trigger, changePosX)

		//connect(urlEdit, textChanged, trigger, changeUrl)

		//connect trigger, position change, this, onchangePos
		//connect trigger, scale change, this, onscaleChange
		connect(loopToggle, &QCheckBox::stateChanged, trigger, &TwoWayTrigger::toggleLoop);
	}
}
