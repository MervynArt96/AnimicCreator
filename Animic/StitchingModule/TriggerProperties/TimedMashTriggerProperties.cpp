#include "stdafx.h"
#include "TimedMashTriggerProperties.h"

TimedMashTriggerProperties::TimedMashTriggerProperties(QWidget* parent, AnimicListView* view) : QWidget(parent)
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

	timeLimitLabel = new QLabel("Time Limit: "); 
	timeLimitEdit = new QLineEdit();
	keyPressCountLabel = new QLabel("Keypress Count: ");
	keyPressCountEdit = new QLineEdit();

	QGridLayout* layout = new QGridLayout();

	layout->addWidget(posXLabel, 0, 0); layout->addWidget(posXEdit, 0, 1);
	layout->addWidget(posYLabel, 1, 0); layout->addWidget(posYEdit, 1, 1);
	layout->addWidget(scaleLabel, 2, 0); layout->addWidget(scaleEdit, 2, 1);
	layout->addWidget(urlLabel, 3, 0); layout->addWidget(urlEdit, 3, 1);
	layout->addWidget(sceneDefaultLabel, 4, 0); layout->addWidget(sceneDefaultComboBox, 4, 1);
	layout->addWidget(sceneAltLabel, 5, 0); layout->addWidget(sceneAltComboBox, 5, 1);
	layout->addWidget(timeLimitLabel, 6, 0); layout->addWidget(timeLimitEdit, 6 ,1);
	layout->addWidget(keyPressCountLabel, 7 ,0); layout->addWidget(keyPressCountEdit, 7 ,1);

	this->setLayout(layout);

}

TimedMashTriggerProperties::~TimedMashTriggerProperties()
{

}

QLabel* TimedMashTriggerProperties::getLabel()
{
	return sceneAltLabel;
}


QComboBox* TimedMashTriggerProperties::getSceneDefaultComboBox()
{
	return sceneDefaultComboBox;
}

QComboBox* TimedMashTriggerProperties::getSceneAltComboBox()
{
	return sceneAltComboBox;
}

void TimedMashTriggerProperties::onChangeTrigger(TimedMashTrigger* tr)
{
	trigger = tr;
}

void TimedMashTriggerProperties::onFocusChanged(QGraphicsItem* target, QGraphicsItem* oldItem, Qt::FocusReason reason)
{
	disconnectTrigger();
	if (target != nullptr)
	{
		TimedMashTrigger* tr = qgraphicsitem_cast<TimedMashTrigger*>(target);
		if (tr != nullptr)
		{
			this->trigger = tr;
			posXEdit->setText(QString::number(tr->scenePos().x()));
			posYEdit->setText(QString::number(tr->scenePos().y()));
			scaleEdit->setText(QString::number(tr->scale()));
			keyPressCountEdit->setText(QString::number(tr->getKeyMax()));
			timeLimitEdit->setText(QString::number(tr->getTimeLimit()));
			urlEdit->setText(tr->getUrl());

			connect(tr, &TimedMashTrigger::xChanged, this, &TimedMashTriggerProperties::onChangePosX);	//object change Line Edit
			connect(tr, &TimedMashTrigger::yChanged, this, &TimedMashTriggerProperties::onChangePosY);
			connect(tr, &TimedMashTrigger::scaleChanged, this, &TimedMashTriggerProperties::onChangeScale);

			connect(posXEdit, &QLineEdit::textEdited, tr, &TimedMashTrigger::onPosXChanged);		//Line Edit change Object
			connect(posYEdit, &QLineEdit::textEdited, tr, &TimedMashTrigger::onPosYChanged);
			connect(scaleEdit, &QLineEdit::textEdited, tr, &TimedMashTrigger::onScaleChanged);
			connect(urlEdit, &QLineEdit::textChanged, tr, &TimedMashTrigger::onUrlChanged);
			connect(timeLimitEdit, &QLineEdit::textEdited, tr, &TimedMashTrigger::onTimeLimitChanged);
			connect(keyPressCountEdit, &QLineEdit::textEdited, tr, &TimedMashTrigger::onKeyMaxChanged);

			connect(sceneDefaultComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TimedMashTriggerProperties::getDefaultScene);
			connect(sceneAltComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TimedMashTriggerProperties::getAltScene);

			connect(this, &TimedMashTriggerProperties::returnDefaultScene, tr, &TimedMashTrigger::setDefaultScene);
			connect(this, &TimedMashTriggerProperties::returnAltScene, tr, &TimedMashTrigger::setAltScene);
		}
	}
}

void TimedMashTriggerProperties::disconnectTrigger()
{
	if (trigger != nullptr) 
	{
		disconnect(posXEdit);
		disconnect(posYEdit);
		disconnect(scaleEdit);
		disconnect(sceneAltComboBox);
		disconnect(sceneDefaultComboBox);
		disconnect(urlEdit);
		disconnect(timeLimitEdit);
		disconnect(keyPressCountEdit);
		disconnect(this, &TimedMashTriggerProperties::returnDefaultScene, nullptr, nullptr);
		disconnect(this, &TimedMashTriggerProperties::returnAltScene, nullptr, nullptr);
	}
}


void TimedMashTriggerProperties::onChangePosX()
{
	if (trigger != nullptr)
		posXEdit->setText(QString::number(trigger->x()));
}

void TimedMashTriggerProperties::onChangePosY()
{
	if (trigger != nullptr)
		posYEdit->setText(QString::number(trigger->y()));
}

void TimedMashTriggerProperties::onChangeScale()
{
	if (trigger != nullptr)
		scaleEdit->setText(QString::number(trigger->scale()));
}

void TimedMashTriggerProperties::getDefaultScene(int i)
{
	if (i <= 0)
		return;
	emit returnDefaultScene(qobject_cast<SceneListModel*>(list->model())->getList()->at(i - 1));
}

void TimedMashTriggerProperties::getAltScene(int i)
{
	if (i <= 0)
		return;
	emit returnDefaultScene(qobject_cast<SceneListModel*>(list->model())->getList()->at(i - 1));
}