#pragma once

#include <QWidget>
#include "StitchingModule/Triggers/OneWayTrigger.h"
#include <ModelViewModule\AnimicListView.h>

class OneWayTriggerProperties : public QWidget
{
	Q_OBJECT

public:
	OneWayTriggerProperties(QWidget *parent, AnimicListView*);
	~OneWayTriggerProperties();

private: 

	AnimicListView* list;
};
