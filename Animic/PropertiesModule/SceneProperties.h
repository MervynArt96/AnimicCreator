#pragma once

#include <QWidget>
#include <QLabel>
#include <CanvasModule\AnimicScene.h>

class SceneProperties : public QWidget
{
	Q_OBJECT

public:

	SceneProperties(QWidget *parent);
	SceneProperties();
	~SceneProperties();

	void updateProperties(const QString, bool);
	void manualConnect(AnimicScene*);

	void connectComponent();

private:

	QLabel* nameLabel = new QLabel(QString("Scene 1"));
	QCheckBox* entryToggle = new QCheckBox("Entry Scene");
	AnimicScene* scene = nullptr;

public slots:

	void onChangeScene(AnimicScene*);
	void onDisconnectScene(AnimicScene*);
};
