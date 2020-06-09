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
	QCheckBox* entryToggle = new QCheckBox("Entry Scene");

public slots:

	void onChangeScene();
	
};
