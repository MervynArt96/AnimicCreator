#pragma once

#include <QWidget>
#include "StitchingModule/Triggers/TimedMashTrigger.h"
#include <ModelViewModule\AnimicListView.h>
#include <PropertiesModule\DroppableLineEdit.h>

class TimedMashTriggerProperties : public QWidget
{
	Q_OBJECT

public:
	TimedMashTriggerProperties(QWidget*, AnimicListView*);
	~TimedMashTriggerProperties();

	QComboBox* getSceneDefaultComboBox();
	QComboBox* getSceneAltComboBox();

	QLabel* getLabel();

private:

	TimedMashTrigger* trigger;

	AnimicListView* list;

	QLabel* sceneDefaultLabel;
	QLabel* sceneAltLabel;

	QComboBox* sceneDefaultComboBox = new QComboBox();
	QComboBox* sceneAltComboBox = new QComboBox();

	QLabel* posXLabel; 	QLineEdit* posXEdit;
	QLabel* posYLabel;	QLineEdit* posYEdit;

	QLabel* urlLabel; 	DroppableLineEdit* urlEdit;
	QLabel* scaleLabel;	QLineEdit* scaleEdit;

	QLabel* timeLimitLabel; QLineEdit* timeLimitEdit;
	QLabel* keyPressCountLabel; QLineEdit* keyPressCountEdit;

signals:
	void returnDefaultScene(AnimicScene*);
	void returnAltScene(AnimicScene*);

public slots:

	void onChangePosX();
	void onChangePosY();
	void onChangeScale();

	void onFocusChanged(QGraphicsItem*, QGraphicsItem*, Qt::FocusReason);
	void onChangeTrigger(TimedMashTrigger*);
	void disconnectTrigger();

	void getDefaultScene(int);
	void getAltScene(int);

};
