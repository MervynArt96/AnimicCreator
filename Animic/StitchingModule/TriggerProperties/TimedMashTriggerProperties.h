#pragma once

#include <QWidget>
#include "StitchingModule/Triggers/TimedMashTrigger.h"

class TimedMashTriggerProperties : public QWidget
{
	Q_OBJECT

public:
	TimedMashTriggerProperties(QWidget *parent);
	~TimedMashTriggerProperties();
};
