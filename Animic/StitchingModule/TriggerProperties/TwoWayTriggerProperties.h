#pragma once

#include <QWidget>
#include <PropertiesModule/DroppableLineEdit.h>
#include <StitchingModule/Triggers/TwoWayTrigger.h>
#include <CanvasModule\AnimicView.h>

class TwoWayTriggerProperties : public QWidget
{
	Q_OBJECT

public:
	TwoWayTriggerProperties(QWidget *parent);
	~TwoWayTriggerProperties();

private:

	AnimicView* view;

	TwoWayTrigger* trigger;

	QComboBox* sceneDefaultComboBox;
	QComboBox* sceneAltComboBox;
	
	QLineEdit* nameEdit;

	QLineEdit* posXEdit;
	QLineEdit* posYEdit;

	QLineEdit* scaleEdit;
	DroppableLineEdit* urlEdit;

	QLabel* nameLabel;

	QLabel* sceneDefaultLabel;
	QLabel* sceneAltLabel;

	QLabel* posXLabel;
	QLabel* posYLabel;

	QLabel* urlLabel;
	QLabel* scaleLabel;

signals:

	void changeName(QString);
	void changePosX(qreal);
	void changePosY(qreal);
	void changeScale(qreal);
	void changeUrl(QString);

public slots:

	void onChangeScene();
	void onChangeName(QString);
	void onChangePosX(qreal);
	void onChangePosY(qreal);
	void onChangeScale(qreal);
	void onChangeUrl(QString);

	void TwoWayTriggerProperties::onChangeTrigger(TwoWayTrigger*);
};
