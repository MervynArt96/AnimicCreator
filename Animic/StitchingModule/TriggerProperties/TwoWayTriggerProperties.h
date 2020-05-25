#pragma once

#include <QWidget>
#include <PropertiesModule/DroppableLineEdit.h>
#include <StitchingModule/Triggers/TwoWayTrigger.h>
#include <CanvasModule/AnimicView.h>

class TwoWayTriggerProperties : public QWidget
{
	Q_OBJECT

public:

	TwoWayTriggerProperties(QWidget*);
	~TwoWayTriggerProperties();

	QComboBox* getSceneDefaultComboBox();
	QComboBox* getSceneAltComboBox();

	void connectTrigger(TwoWayTrigger*);
	void connectTrigger();

private:

	//AnimicView* view;

	TwoWayTrigger* trigger;

	QLineEdit* posXEdit;
	QLineEdit* posYEdit;

	QLineEdit* scaleEdit;
	DroppableLineEdit* urlEdit;

	QLabel* sceneDefaultLabel;
	QLabel* sceneAltLabel;

	QComboBox* sceneDefaultComboBox;
	QComboBox* sceneAltComboBox;

	QLabel* posXLabel;
	QLabel* posYLabel;

	QLabel* urlLabel;
	QLabel* scaleLabel;

	QCheckBox* loopToggle;

signals:

public slots:

	void onChangeScene(AnimicScene*);
	void onChangePosX(qreal);
	void onChangePosY(qreal);
	void onChangeScale(qreal);
	void onChangeUrl(QUrl);
	void onChangeUrl(QString str);

	void onToggleLoop();

	void onChangeTrigger(TwoWayTrigger*);
};
