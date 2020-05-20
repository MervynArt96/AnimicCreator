#include "stdafx.h"
#include "TriggerPropertiesHandler.h"

TriggerPropertiesHandler::TriggerPropertiesHandler(QWidget *parent) : QWidget(parent)
{

}

TriggerPropertiesHandler::~TriggerPropertiesHandler()
{

}

void TriggerPropertiesHandler::onSceneChanged(AnimicScene* sc)
{
	disconnect();
	connect(sc, &QGraphicsScene::focusItemChanged, this, &onFocusChanged);
}

void TriggerPropertiesHandler::onFocusChanged(QGraphicsItem* newFocusItem, QGraphicsItem* oldFocusItem, Qt::FocusReason reason)
{
	TwoWayTrigger* TWtrigger = qgraphicsitem_cast<TwoWayTrigger*>(newFocusItem);
	OneWayTrigger* OWtrigger = qgraphicsitem_cast<OneWayTrigger*>(newFocusItem);
	TimedMashTrigger* TMtrigger = qgraphicsitem_cast<TimedMashTrigger*>(newFocusItem);

	if (TWtrigger != nullptr)
	{
		//connect slots to this trigger
		//disable other type of properties
		return;
	}

	if (OWtrigger != nullptr)
	{

		return;
	}

	if (TMtrigger != nullptr)
	{

		return;
	}

}