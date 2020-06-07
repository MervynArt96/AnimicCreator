#include "stdafx.h"
#include "OneWayTriggerProperties.h"

OneWayTriggerProperties::OneWayTriggerProperties(QWidget *parent, AnimicListView* list)
	: QWidget(parent)
{
	this->list = list;
}

OneWayTriggerProperties::~OneWayTriggerProperties()
{
}
