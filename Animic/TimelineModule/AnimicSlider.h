#pragma once

#include <QAbstractSlider>
#include "CanvasModule/AnimicScene.h"
#include <QElapsedTimer>

class AnimicSlider : public QSlider
{
	Q_OBJECT

public:
	AnimicSlider(QWidget *parent);
	~AnimicSlider();

private:

signals:

public slots:

	void onChangeTab();
	void onInsertVideo(qint64);
	void onRemoveVideo(qint64);

	void onPlay();
	void onPause();
	void onStop();

	void debugPosition();

	void subscribeVideo(QMediaPlayer*);
	void scrubPosition(qint64);
};
