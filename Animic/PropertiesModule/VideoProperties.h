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

	void connectComponent();

private:

	VideoObject* obj = nullptr;

	qreal posX = 0;	qreal posY = 0;
	qreal scaleX = 1;	qreal scaleY = 1;

	QString url = "-";
	QString name = "-";

	qreal volume = 100; //in percent
	qreal playbackSpeed = 1;

	QLabel* nameLabel = new QLabel(QString("Name: "));
	QLabel* nameText = new QLabel("");

	QLabel* posXLabel = new QLabel(QString("Position X: "));
	QLabel* posYLabel = new QLabel(QString("Position Y: "));
	QLabel* scaleXLabel = new QLabel(QString("Scale X: "));
	QLabel* scaleYLabel = new QLabel(QString("Scale Y: "));
	QLabel* urlLabel = new QLabel(QString("File Url: "));

	QLineEdit* posXEdit = new QLineEdit();
	QLineEdit* posYEdit = new QLineEdit();
	QLineEdit* scaleXEdit = new QLineEdit();
	QLineEdit* scaleYEdit = new QLineEdit();
	DroppableLineEdit* urlEdit = new DroppableLineEdit();

	QCheckBox* muteSwitch = new QCheckBox("Mute");

signals:

	//to change every attribute
	void changePos();
	void changeScale();
	void changeUrl();


public slots:

	//on every attribute change
	void onFocusChanged(QGraphicsItem*);

	void onSizeXChanged();	void onSizeYChanged();
	void onScaleXChanged();	void onScaleYChanged();
	
};
