#pragma once

#include <QWidget>
#include "StitchingModule/Triggers/OneWayTrigger.h"

class OneWayTriggerProperties : public QWidget
{
	Q_OBJECT

public:
	OneWayTriggerProperties(QWidget *parent);
	~OneWayTriggerProperties();
};
