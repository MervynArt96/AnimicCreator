#include "stdafx.h"
#include "TriggerPropertiesHandler.h"

TriggerPropertiesHandler::TriggerPropertiesHandler(QWidget *parent, AnimicListView* list) : QWidget(parent) // container widget for all type of trigger properties
{
	TWTriggerProperties = new TwoWayTriggerProperties(this, list);
	TMTriggerProperties = new TimedMashTriggerProperties(this, list);
	OWTriggerProperties = new OneWayTriggerProperties(this, list);		//initialize all the properties 

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(TWTriggerProperties);
	layout->addWidget(TMTriggerProperties);
	layout->addWidget(OWTriggerProperties);

	TMTriggerProperties->setVisible(false);
	OWTriggerProperties->setVisible(false);

	this->setLayout(layout);

	connect(this, &TriggerPropertiesHandler::TWTriggerFocused, TWTriggerProperties, &TwoWayTriggerProperties::onFocusChanged);		//handle focus change event
	connect(this, &TriggerPropertiesHandler::TMTriggerFocused, TMTriggerProperties, &TimedMashTriggerProperties::onFocusChanged);
	connect(this, &TriggerPropertiesHandler::OWTriggerFocused, OWTriggerProperties, &OneWayTriggerProperties::onFocusChanged);

}

TriggerPropertiesHandler::~TriggerPropertiesHandler()
{

}

TwoWayTriggerProperties* TriggerPropertiesHandler::getTWTriggerProperties()		//get the properties widgets
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

void TriggerPropertiesHandler::onFocusChanged(QGraphicsItem* target, QGraphicsItem* oldItem, Qt::FocusReason reason)	//change which properties panel will be active, 
																														//depending on which trigger type is focused
{
	TwoWayTrigger* TWtrigger = qgraphicsitem_cast<TwoWayTrigger*>(target);
	OneWayTrigger* OWtrigger = qgraphicsitem_cast<OneWayTrigger*>(target);
	TimedMashTrigger* TMtrigger = qgraphicsitem_cast<TimedMashTrigger*>(target);

	if (TWtrigger != nullptr)
	{
		activateTwoWayProperties();
		emit TWTriggerFocused(target, oldItem, reason);
	}
	else if (TMtrigger != nullptr)
	{
		activateTimedMashProperties();
		emit TMTriggerFocused(target, oldItem, reason);
	}
	else if (OWtrigger != nullptr)
	{
		activateOneWayProperties();
		emit OWTriggerFocused(target, oldItem, reason);
	}
}

void TriggerPropertiesHandler::activateTwoWayProperties()		//panel activation
{
	TWTriggerProperties->setVisible(true);
	TMTriggerProperties->setVisible(false);
	OWTriggerProperties->setVisible(false);
}

void TriggerPropertiesHandler::activateTimedMashProperties()
{
	TWTriggerProperties->setVisible(false);
	TMTriggerProperties->setVisible(true);
	OWTriggerProperties->setVisible(false);
}

void TriggerPropertiesHandler::activateOneWayProperties()
{
	TWTriggerProperties->setVisible(false);
	TMTriggerProperties->setVisible(false);
	OWTriggerProperties->setVisible(true);
}