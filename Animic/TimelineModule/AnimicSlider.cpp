#include "stdafx.h"
#include "AnimicSlider.h"

AnimicSlider::AnimicSlider(QWidget *parent): QSlider(parent)
{
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

void AnimicSlider::onInsertVideo(qint64 length)
{
		qreal currentMax = this->maximum();
		qreal currentPos = this->sliderPosition();

		if (length > this->maximum())
		{
			this->setMaximum(length);
		}

}

void AnimicSlider::onRemoveVideo(qint64 targetLength)
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
