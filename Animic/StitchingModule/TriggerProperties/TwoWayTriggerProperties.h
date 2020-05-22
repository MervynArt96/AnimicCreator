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

	void connectTrigger(TwoWayTrigger*);
	void connectTrigger();

private:

	AnimicView* view;

	TwoWayTrigger* trigger;

	QLineEdit* nameEdit;

	QLineEdit* posXEdit;
	QLineEdit* posYEdit;

	QLineEdit* scaleEdit;
	DroppableLineEdit* urlEdit;

	QLabel* nameLabel;

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

	void onChangeScene();
	void onChangeName(QString);
	void onChangePosX(qreal);
	void onChangePosY(qreal);
	void onChangeScale(qreal);
	void onChangeUrl(QUrl);
	void onChangeUrl(QString str);

	void onToggleLoop();

	void TwoWayTriggerProperties::onChangeTrigger(TwoWayTrigger*);
};
