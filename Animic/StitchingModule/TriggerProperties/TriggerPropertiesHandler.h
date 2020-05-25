#pragma once

#include <QWidget>
#include "StitchingModule/TriggerProperties/TwoWayTriggerProperties.h"
#include <StitchingModule\TriggerProperties\TimedMashTriggerProperties.h>
#include <StitchingModule\TriggerProperties\OneWayTriggerProperties.h>

class TriggerPropertiesHandler : public QWidget
{
	Q_OBJECT

public:

	TriggerPropertiesHandler(QWidget *parent);
	~TriggerPropertiesHandler();

	TwoWayTriggerProperties* getTWTriggerProperties();
	TimedMashTriggerProperties* getTMTriggerProperties();
	OneWayTriggerProperties* getOWTriggerProperties();

private:

	TwoWayTriggerProperties* TWTriggerProperties;
	TimedMashTriggerProperties* TMTriggerProperties;
	OneWayTriggerProperties* OWTriggerProperties;

public slots:

	void onSceneChanged(AnimicScene*);
	void onFocusChanged(QGraphicsItem* newFocusItem, QGraphicsItem* oldFocusItem, Qt::FocusReason reason);
};
