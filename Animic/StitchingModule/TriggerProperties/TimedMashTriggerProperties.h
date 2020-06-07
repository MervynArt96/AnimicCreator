#pragma once

#include <QWidget>
#include "StitchingModule/Triggers/TimedMashTrigger.h"
#include <ModelViewModule\AnimicListView.h>

class TimedMashTriggerProperties : public QWidget
{
	Q_OBJECT

public:
	TimedMashTriggerProperties(QWidget*, AnimicListView*);
	~TimedMashTriggerProperties();
};
