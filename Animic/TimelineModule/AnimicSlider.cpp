#include "stdafx.h"
#include "AnimicSlider.h"

AnimicSlider::AnimicSlider(QWidget *parent): QAbstractSlider(parent)
{
	currentScene = nullptr;
	this->setTracking(true);
}

AnimicSlider::~AnimicSlider()
{

}

void AnimicSlider::onChangeTab()
{

}

void AnimicSlider::onInsertVideo(int length)
{
	if (currentScene != nullptr)
	{
		qreal currentMax = this->maximum();
		qreal currentPos = this->sliderPosition();

		if (length > this->maximum())
		{
			this->setMaximum(length);
			// set slider position to = QtMAth.qCeil((current/this->maximum());
		}
		QMetaObject::invokeMethod(currentScene, "pauseAll", Qt::DirectConnection);
	}
}

void AnimicSlider::onRemoveVideo(int length, int targetLength)
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
	this->setSliderPosition(1);
}