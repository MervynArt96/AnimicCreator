#include "stdafx.h"
#include "TriggerPropertiesHandler.h"

TriggerPropertiesHandler::TriggerPropertiesHandler(QWidget *parent, AnimicListView* list) : QWidget(parent)
{
	TWTriggerProperties = new TwoWayTriggerProperties(this, list);
	TMTriggerProperties = new TimedMashTriggerProperties(this, list);
	OWTriggerProperties = new OneWayTriggerProperties(this, list);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(TWTriggerProperties);
	this->setLayout(layout);

	connect(this, &TriggerPropertiesHandler::TWTriggerFocused, TWTriggerProperties, &TwoWayTriggerProperties::onFocusChanged);
	//connect(this, &TriggerPropertiesHandler::onReturnDefaultScene, TWTriggerProperties, &TwoWayTriggerProperties::scene)
	//connect(this, &TriggerPropertiesHandler::TMTriggerFocused, TMTriggerProperties, &TimedMashTriggerProperties::onFocusChanged);
	//connect(this, &TriggerPropertiesHandler::OWTriggerFocused, OWTriggerProperties, &OneWayTriggerProperties::onFocusChanged);
}

TriggerPropertiesHandler::~TriggerPropertiesHandler()
{

}

TwoWayTriggerProperties* TriggerPropertiesHandler::getTWTriggerProperties()
{
	return TWTriggerProperties;
}

TimedMashTriggerProperties* TriggerPropertiesHandler::getTMTriggerProperties()
{
	return TMTriggerProperties;
}

OneWayTriggerProperties* TriggerPropertiesHandler::getOWTriggerProperties()
{
	return OWTriggerProperties;
}

void TriggerPropertiesHandler::onSceneChanged(AnimicScene* sc)
{
	disconnect();
	connect(sc, &QGraphicsScene::focusItemChanged, this, &TriggerPropertiesHandler::onFocusChanged);
}

void TriggerPropertiesHandler::onFocusChanged(QGraphicsItem* target, QGraphicsItem* oldItem, Qt::FocusReason reason)
{
	TwoWayTrigger* TWtrigger = qgraphicsitem_cast<TwoWayTrigger*>(target);
	OneWayTrigger* OWtrigger = qgraphicsitem_cast<OneWayTrigger*>(target);
	TimedMashTrigger* TMtrigger = qgraphicsitem_cast<TimedMashTrigger*>(target);
	qDebug() << TWtrigger;
	if (TWtrigger != nullptr)
	{
		qDebug() << "Focused on TWTrigger";
		emit TWTriggerFocused(target, oldItem, reason);
		return;
	}

	if (OWtrigger != nullptr)
	{
		emit OWTriggerFocused(target, oldItem, reason);
		return;
	}

	if (TMtrigger != nullptr)
	{
		emit TMTriggerFocused(target, oldItem, reason);
		return;
	}
}