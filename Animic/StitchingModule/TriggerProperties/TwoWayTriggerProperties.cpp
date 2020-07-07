#include "stdafx.h"
#include "TwoWayTriggerProperties.h"

TwoWayTriggerProperties::TwoWayTriggerProperties(QWidget *parent, AnimicListView* view): QWidget(parent)
{
	trigger = nullptr;
	list = view;

	posXEdit = new QLineEdit();
	posYEdit = new QLineEdit();

	scaleEdit = new QLineEdit();
	urlEdit = new DroppableLineEdit();

	sceneDefaultLabel = new QLabel("Default Scene ");
	sceneAltLabel = new QLabel("Alternate Scene ");

	sceneDefaultComboBox->setInsertPolicy(QComboBox::InsertAtCurrent);
	sceneAltComboBox->setInsertPolicy(QComboBox::InsertAtCurrent);

	posXLabel = new QLabel("Position X: ");
	posYLabel = new QLabel("Position Y: ");

	urlLabel = new QLabel("URL: ");
	scaleLabel = new QLabel("Scale: ");

	//set double invalidator for each line edit

	QGridLayout* layout = new QGridLayout();

	layout->addWidget(posXLabel, 0, 0); layout->addWidget(posXEdit, 0 ,1);
	layout->addWidget(posYLabel, 1, 0); layout->addWidget(posYEdit, 1, 1);
	layout->addWidget(scaleLabel, 2, 0); layout->addWidget(scaleEdit, 2, 1);
	layout->addWidget(urlLabel, 3, 0); layout->addWidget(urlEdit, 3, 1);
	layout->addWidget(sceneDefaultLabel, 4, 0); layout->addWidget(sceneDefaultComboBox, 4, 1);
	layout->addWidget(sceneAltLabel, 5, 0); layout->addWidget(sceneAltComboBox, 5, 1);

	this->setLayout(layout);
}

TwoWayTriggerProperties::~TwoWayTriggerProperties()
{

}

QLabel* TwoWayTriggerProperties::getLabel()
{
	return sceneAltLabel;
}


QComboBox* TwoWayTriggerProperties::getSceneDefaultComboBox()
{
	return sceneDefaultComboBox;
}

QComboBox* TwoWayTriggerProperties::getSceneAltComboBox()
{
	return sceneAltComboBox;
}

void TwoWayTriggerProperties::onChangeTrigger(TwoWayTrigger* tr)
{
	trigger = tr;
	//connect trigger?
}

void TwoWayTriggerProperties::onFocusChanged(QGraphicsItem* target, QGraphicsItem* oldItem, Qt::FocusReason reason)
{
	disconnectTrigger();
	if (target != nullptr)
	{
		TwoWayTrigger* tr = qgraphicsitem_cast<TwoWayTrigger*>(target);
		if (tr != nullptr)
		{
			this->trigger = tr;
			posXEdit->setText(QString::number(tr->scenePos().x()));
			posYEdit->setText(QString::number(tr->scenePos().y()));
			scaleEdit->setText(QString::number(tr->scale()));

			urlEdit->setText(tr->getUrl());

			connect(tr, &TwoWayTrigger::xChanged, this, &TwoWayTriggerProperties::onChangePosX);	//object change Line Edit
			connect(tr, &TwoWayTrigger::yChanged, this, &TwoWayTriggerProperties::onChangePosY);
			connect(tr, &TwoWayTrigger::scaleChanged, this, &TwoWayTriggerProperties::onChangeScale);

			connect(posXEdit, &QLineEdit::textEdited, tr, &TwoWayTrigger::onPosXChanged);		//Line Edit change Object
			connect(posYEdit, &QLineEdit::textEdited, tr, &TwoWayTrigger::onPosYChanged);
			connect(scaleEdit, &QLineEdit::textEdited, tr, &TwoWayTrigger::onScaleChanged);
			connect(urlEdit, &QLineEdit::textChanged, tr, &TwoWayTrigger::onUrlChanged);
			 
			connect(sceneDefaultComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TwoWayTriggerProperties::getDefaultScene);
			connect(sceneAltComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TwoWayTriggerProperties::getAltScene);

			connect(this, &TwoWayTriggerProperties::returnDefaultScene, tr, &TwoWayTrigger::setDefaultScene);
			connect(this, &TwoWayTriggerProperties::returnAltScene, tr, &TwoWayTrigger::setAltScene);
		}
	}
}

void TwoWayTriggerProperties::disconnectTrigger()
{
	if (trigger != nullptr)
	{
		disconnect(posXEdit);
		disconnect(posYEdit);
		disconnect(scaleEdit);
		disconnect(sceneAltComboBox);
		disconnect(sceneDefaultComboBox);
		disconnect(urlEdit);
		disconnect(this, &TwoWayTriggerProperties::returnDefaultScene, nullptr, nullptr);
		disconnect(this, &TwoWayTriggerProperties::returnAltScene, nullptr, nullptr);
	}
}


void TwoWayTriggerProperties::onChangePosX()
{
	if (trigger != nullptr)
		posXEdit->setText(QString::number(trigger->x()));
}

void TwoWayTriggerProperties::onChangePosY()
{
	if (trigger != nullptr)
		posYEdit->setText(QString::number(trigger->y()));
}

void TwoWayTriggerProperties::onChangeScale()
{
	if(trigger != nullptr)
		scaleEdit->setText(QString::number(trigger->scale()));
}

void TwoWayTriggerProperties::getDefaultScene(int i)
{
	if (i <= 0)
		return;
	emit returnDefaultScene(qobject_cast<SceneListModel*>(list->model())->getList()->at(i-1)); //signal emitted during run time 
}

void TwoWayTriggerProperties::getAltScene(int i)
{
	if (i <= 0)
		return;
	emit returnDefaultScene(qobject_cast<SceneListModel*>(list->model())->getList()->at(i-1));
}