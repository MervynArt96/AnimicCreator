#pragma once

#include <QWidget>
#include "StitchingModule/TriggerProperties/TwoWayTriggerProperties.h"
#include <StitchingModule\TriggerProperties\TimedMashTriggerProperties.h>
#include <StitchingModule\TriggerProperties\OneWayTriggerProperties.h>

class TriggerPropertiesHandler : public QWidget
{
	Q_OBJECT

public:

	TriggerPropertiesHandler(QWidget*, AnimicListView*);
	~TriggerPropertiesHandler();

	TwoWayTriggerProperties* getTWTriggerProperties();
	TimedMashTriggerProperties* getTMTriggerProperties();
	OneWayTriggerProperties* getOWTriggerProperties();

	void TriggerPropertiesHandler::activateTwoWayProperties();
	void TriggerPropertiesHandler::activateTimedMashProperties();
	void TriggerPropertiesHandler::activateOneWayProperties();

private:

	TwoWayTriggerProperties* TWTriggerProperties;
	TimedMashTriggerProperties* TMTriggerProperties;
	OneWayTriggerProperties* OWTriggerProperties;

signals:
	
	void TWTriggerFocused(QGraphicsItem* newFocusItem, QGraphicsItem* oldFocusItem, Qt::FocusReason reason);
	void TMTriggerFocused(QGraphicsItem* newFocusItem, QGraphicsItem* oldFocusItem, Qt::FocusReason reason);
	void OWTriggerFocused(QGraphicsItem* newFocusItem, QGraphicsItem* oldFocusItem, Qt::FocusReason reason);

public slots:

	void onSceneChanged(AnimicScene*);
	void onFocusChanged(QGraphicsItem* newFocusItem, QGraphicsItem* oldFocusItem, Qt::FocusReason reason);
	//void onReturnDefaultScene(AnimicScene*);
};
