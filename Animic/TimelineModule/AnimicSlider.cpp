#include "stdafx.h"
#include "AnimicSlider.h"

AnimicSlider::AnimicSlider(QWidget *parent): QSlider(parent)
{
	currentScene = nullptr;
	this->setOrientation(Qt::Horizontal);
	this->setParent(parent);
	this->setTracking(true);
	this->setMinimum(0);
	//connect(this, SIGNAL(valueChanged(int)), this, SLOT(debugPosition()));
}

AnimicSlider::~AnimicSlider()
{

}

void AnimicSlider::onChangeTab()
{

}

void AnimicSlider::setScene(AnimicScene* scene)
{
	this->currentScene = scene;
}

void AnimicSlider::onInsertVideo(qint64 length)
{
	if (currentScene != nullptr)
	{
		qreal currentMax = this->maximum();
		qreal currentPos = this->sliderPosition();

		if (length > this->maximum())
		{
			this->setMaximum(length);
		}
		QMetaObject::invokeMethod(currentScene, "pauseAll", Qt::DirectConnection);
	}
}

void AnimicSlider::onRemoveVideo(qint64 length, qint64 targetLength)
{
	if (currentScene != nullptr)
	{
		if (this->sliderPosition() < length)
		{
			this->setSliderPosition(targetLength-1);
		}

		if (this->maximum() < length)
		{
			this->setMaximum(targetLength);

		}
		QMetaObject::invokeMethod(currentScene, "pauseAll", Qt::DirectConnection);
	}
}

void AnimicSlider::onRemoveScene()
{
	currentScene = nullptr;
}

//for self positioning slider, might not need

void AnimicSlider::onPlay() 
{

}

void AnimicSlider::onPause()
{

}

void AnimicSlider::onStop()
{
	this->setSliderPosition(0);
}

void AnimicSlider::debugPosition()
{
	qDebug() << this->value();
	qDebug() << this->sliderPosition();
}

void AnimicSlider::scrubPosition(qint64 val)
{
	this->setValue(val);
}

void AnimicSlider::subscribeVideo(QMediaPlayer* player)
{
	connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(scrubPosition(qint64)),Qt::UniqueConnection);
}
