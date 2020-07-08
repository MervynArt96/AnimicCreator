#include "stdafx.h"
#include "OneWayTriggerProperties.h"

OneWayTriggerProperties::OneWayTriggerProperties(QWidget* parent, AnimicListView* view) : QWidget(parent)	//properties panel for one way triggers
{
	trigger = nullptr;	//local reference of the trigger
	list = view;

	posXEdit = new QLineEdit();		//initialize ui widgets 
	posYEdit = new QLineEdit();

	scaleEdit = new QLineEdit();
	urlEdit = new DroppableLineEdit();
	timeLimitEdit = new QLineEdit();

	sceneDefaultLabel = new QLabel("Next Scene ");
	sceneDefaultComboBox->setInsertPolicy(QComboBox::InsertAtCurrent);

	posXLabel = new QLabel("Position X: ");
	posYLabel = new QLabel("Position Y: ");

	urlLabel = new QLabel("URL: ");
	scaleLabel = new QLabel("Scale: ");
	timeLimitLabel = new QLabel("Time Limit: ");

	QGridLayout* layout = new QGridLayout();

	layout->addWidget(posXLabel, 0, 0); layout->addWidget(posXEdit, 0, 1);
	layout->addWidget(posYLabel, 1, 0); layout->addWidget(posYEdit, 1, 1);
	layout->addWidget(scaleLabel, 2, 0); layout->addWidget(scaleEdit, 2 ,1);
	layout->addWidget(urlLabel, 3, 0); layout->addWidget(urlEdit, 3, 1);
	layout->addWidget(sceneDefaultLabel, 4, 0); layout->addWidget(sceneDefaultComboBox, 4, 1);
	layout->addWidget(timeLimitLabel, 5, 0); layout->addWidget(timeLimitEdit, 5, 1);

	this->setLayout(layout);
}

OneWayTriggerProperties::~OneWayTriggerProperties()
{

}

QComboBox* OneWayTriggerProperties::getSceneDefaultComboBox()
{
	return sceneDefaultComboBox;
}

void OneWayTriggerProperties::onChangeTrigger(OneWayTrigger* tr)
{
	trigger = tr;
	//connect trigger?
}

void OneWayTriggerProperties::onFocusChanged(QGraphicsItem* target, QGraphicsItem* oldItem, Qt::FocusReason reason)
{
	disconnectTrigger();	//disconnect the ui widgets from old item
	if (target != nullptr)
	{
		OneWayTrigger* tr = qgraphicsitem_cast<OneWayTrigger*>(target);		//connect to the new item
		if (tr != nullptr)
		{
			this->trigger = tr;
			posXEdit->setText(QString::number(tr->scenePos().x()));
			posYEdit->setText(QString::number(tr->scenePos().y()));
			scaleEdit->setText(QString::number(tr->scale()));
			timeLimitEdit->setText(QString::number(tr->getTimeLimit()));
			urlEdit->setText(tr->getUrl());

			connect(tr, &OneWayTrigger::xChanged, this, &OneWayTriggerProperties::onChangePosX);	//object change Line Edit
			connect(tr, &OneWayTrigger::yChanged, this, &OneWayTriggerProperties::onChangePosY);
			connect(tr, &OneWayTrigger::scaleChanged, this, &OneWayTriggerProperties::onChangeScale);

			connect(posXEdit, &QLineEdit::textEdited, tr, &OneWayTrigger::onPosXChanged);		//Line Edit change Object
			connect(posYEdit, &QLineEdit::textEdited, tr, &OneWayTrigger::onPosYChanged);
			connect(scaleEdit, &QLineEdit::textEdited, tr, &OneWayTrigger::onScaleChanged);
			connect(urlEdit, &QLineEdit::textChanged, tr, &OneWayTrigger::onUrlChanged);
			connect(timeLimitEdit, &QLineEdit::textEdited, tr, &OneWayTrigger::onTimeLimitChanged);

			connect(sceneDefaultComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &OneWayTriggerProperties::getDefaultScene);
			connect(this, &OneWayTriggerProperties::returnDefaultScene, tr, &OneWayTrigger::setDefaultScene);

		}
	}
}

void OneWayTriggerProperties::disconnectTrigger()
{
	if (trigger != nullptr) {
		disconnect(posXEdit);
		disconnect(posYEdit);
		disconnect(scaleEdit);
		disconnect(sceneDefaultComboBox);
		disconnect(urlEdit);
		disconnect(this, &OneWayTriggerProperties::returnDefaultScene, nullptr, nullptr);
	}
}


void OneWayTriggerProperties::onChangePosX()
{
	if (trigger != nullptr)
		posXEdit->setText(QString::number(trigger->x()));		//change text field based on the item properties
}

void OneWayTriggerProperties::onChangePosY()
{
	if (trigger != nullptr)
		posYEdit->setText(QString::number(trigger->y()));
}

void OneWayTriggerProperties::onChangeScale()
{
	if (trigger != nullptr)
		scaleEdit->setText(QString::number(trigger->scale()));
}

void OneWayTriggerProperties::getDefaultScene(int i)
{
	if (i <= 0)
		return;
	emit returnDefaultScene(qobject_cast<SceneListModel*>(list->model())->getList()->at(i - 1));
}