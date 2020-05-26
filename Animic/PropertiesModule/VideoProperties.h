#pragma once

#include <QWidget>
#include <QLabel>
#include "CanvasModule/CanvasObject/VideoObject.h"
#include "PropertiesModule/DroppableLineEdit.h"

class VideoProperties : public QWidget
{
	Q_OBJECT

public:

	VideoProperties(QWidget *parent);
	~VideoProperties();

private:

	VideoObject* object;

	qreal posX = 0;	qreal posY = 0;
	qreal scaleX = 1;

	QString url = "-";
	QString name = "-";

	QLabel* nameLabel = new QLabel(QString("Video Object"));

	QLabel* posXLabel = new QLabel(QString("Position X: "));
	QLabel* posYLabel = new QLabel(QString("Position Y: "));
	QLabel* scaleLabel = new QLabel(QString("Scale: "));
	QLabel* urlLabel = new QLabel(QString("Url: "));

	QLineEdit* posXEdit = new QLineEdit();
	QLineEdit* posYEdit = new QLineEdit();
	QLineEdit* scaleEdit = new QLineEdit();
	DroppableLineEdit* urlEdit = new DroppableLineEdit();

	QCheckBox* muteToggle = new QCheckBox("Mute Video");

signals:

	//to change every attribute
	void changePosX();
	void changePosY();
	void changeScale();
	void changeUrl();

public slots:

	//on every attribute change
	void onFocusChanged(QGraphicsItem*, QGraphicsItem* , Qt::FocusReason);

	void onPositionXChanged();	
	void onPositionYChanged();
	void onScaleChanged();
	
};
