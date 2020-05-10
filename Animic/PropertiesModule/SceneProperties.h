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

	QLabel* nameLabel = new QLabel(QString("Scene: "));
	QLabel* nameText = new QLabel(QString(""));

	QLabel* bgmLabel = new QLabel(QString("BGM: "));
	QLabel* bgmName = new QLabel(QString(""));
	QLabel* bgmUrl = new QLabel(QString(""));

	/*QLabel* bgmLoopLabel = new QLabel("Loop BGM: ");
	QLabel* bgmLoopName = new QLabel("");
	QLabel* bgmLoopUrl = new QLabel("");*/

public slots:

	void onChangeScene();
	
};
