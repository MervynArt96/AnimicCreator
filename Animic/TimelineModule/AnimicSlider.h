#pragma once

#include <QAbstractSlider>
#include "CanvasModule/AnimicScene.h"
#include <QElapsedTimer>

class AnimicSlider : public QAbstractSlider
{
	Q_OBJECT

public:
	AnimicSlider(QWidget *parent);
	~AnimicSlider();

private:

	AnimicScene* currentScene;

signals:

public slots:

	void onChangeTab();
	void onInsertVideo(int);
	void onRemoveVideo(int, int);
	void onRemoveScene();

	void onPlay();
	void onPause();
	void onStop();



};
