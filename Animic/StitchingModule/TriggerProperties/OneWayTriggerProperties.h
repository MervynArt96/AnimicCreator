#pragma once

#include <QWidget>
#include "StitchingModule/Triggers/OneWayTrigger.h"
#include <ModelViewModule\AnimicListView.h>
#include <PropertiesModule\DroppableLineEdit.h>

class OneWayTriggerProperties : public QWidget
{
	Q_OBJECT

public:
	OneWayTriggerProperties(QWidget *parent, AnimicListView*);
	~OneWayTriggerProperties();

	QComboBox* getSceneDefaultComboBox();

	QLabel* getLabel();

private:

	OneWayTrigger* trigger;

	AnimicListView* list;

	QLabel* sceneDefaultLabel;

	QComboBox* sceneDefaultComboBox = new QComboBox();

	QLabel* posXLabel; 	QLineEdit* posXEdit;
	QLabel* posYLabel;	QLineEdit* posYEdit;

	QLabel* urlLabel; DroppableLineEdit* urlEdit;
	QLabel* scaleLabel; QLineEdit* scaleEdit;

	QLabel* timeLimitLabel; QLineEdit* timeLimitEdit;

signals:
	void returnDefaultScene(AnimicScene*);

public slots:

	void onChangePosX();
	void onChangePosY();
	void onChangeScale();

	void onFocusChanged(QGraphicsItem*, QGraphicsItem*, Qt::FocusReason);
	void onChangeTrigger(OneWayTrigger*);
	void disconnectTrigger();

	void getDefaultScene(int);

};
