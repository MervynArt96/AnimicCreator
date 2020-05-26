#pragma once

#include <QWidget>
#include <QLabel>

class SceneProperties : public QWidget
{
	Q_OBJECT

public:

	SceneProperties(QWidget *parent);
	SceneProperties();
	~SceneProperties();

	void connectComponent();

private:

	QLabel* nameLabel = new QLabel(QString("Scene 1"));

	//QLabel* bgmLabel = new QLabel(QString("BGM: "));
	//QLabel* bgmName = new QLabel(QString("Testing"));
	//QLabel* bgmUrl = new QLabel(QString("Test Url"));

public slots:

	void onChangeScene();
	
};
