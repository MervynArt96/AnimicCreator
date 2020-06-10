#pragma once

#include <QWidget>
#include <PropertiesModule/DroppableLineEdit.h>
#include <StitchingModule/Triggers/TwoWayTrigger.h>
#include <CanvasModule/AnimicView.h>
#include <ModelViewModule\AnimicListView.h>

class TwoWayTriggerProperties : public QWidget
{
	Q_OBJECT

public:

	TwoWayTriggerProperties(QWidget*, AnimicListView*);
	~TwoWayTriggerProperties();

	QComboBox* getSceneDefaultComboBox();
	QComboBox* getSceneAltComboBox();

	QLabel* getLabel();

private:

	TwoWayTrigger* trigger;

	AnimicListView* list;

	QLabel* sceneDefaultLabel;
	QLabel* sceneAltLabel;

	QComboBox* sceneDefaultComboBox = new QComboBox();
	QComboBox* sceneAltComboBox = new QComboBox();

	QLabel* posXLabel; 	QLineEdit* posXEdit;
	QLabel* posYLabel;	QLineEdit* posYEdit;

	QLabel* urlLabel; DroppableLineEdit* urlEdit;
	QLabel* scaleLabel; QLineEdit* scaleEdit;

signals:
	void returnDefaultScene(AnimicScene*);
	void returnAltScene(AnimicScene*);

public slots:

	void onChangePosX();
	void onChangePosY();
	void onChangeScale();

	void onFocusChanged(QGraphicsItem* , QGraphicsItem*, Qt::FocusReason);
	void onChangeTrigger(TwoWayTrigger*);
	void disconnectTrigger();

	void getDefaultScene(int);
	void getAltScene(int);
};
