#include "stdafx.h"
#include "AnimicSlider.h"

AnimicSlider::AnimicSlider(QWidget *parent): QSlider(parent)
{
	this->setOrientation(Qt::Horizontal);	
	this->setParent(parent);	//set parent widget
	this->setTracking(true);	//track mouse movement
	this->setMinimum(0);	
}

AnimicSlider::~AnimicSlider()
{

}

void AnimicSlider::onChangeTab()
{

}

void AnimicSlider::onInsertVideo(qint64 length)
{
		if (length > this->maximum())	// if the new inserted video has longer duration than current max
		{	
			this->setMaximum(length);	// set new max duration
		}

}

void AnimicSlider::onRemoveVideo(qint64 targetLength)	//actually not needed, Qt auto handles scenario where the current value is greater than maximum
{
	if (this->maximum() < targetLength)
	{
		this->setMaximum(targetLength);
	}
}


void AnimicSlider::onPlay() 
{

}

void AnimicSlider::onPause()
{

}

void AnimicSlider::onStop()	//reset slider value/position to 0
{
	this->setSliderPosition(0);
}

void AnimicSlider::debugPosition()	//debug only function
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
	connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(scrubPosition(qint64)),Qt::UniqueConnection);	//connect slider to the longest duration video in a scene, 
																												//when the media plays, slider will change position as well
																												// performance issue, ignored in latest build
}
