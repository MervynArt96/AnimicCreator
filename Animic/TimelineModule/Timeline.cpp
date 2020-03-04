#include "stdafx.h"
#include "Timeline.h"

Timeline::Timeline(QWidget* parent) : QQuickWidget(parent)
{
	setResizeMode(QQuickWidget::SizeRootObjectToView);
	setSource(QUrl::fromLocalFile("D:/My Documents/Programming/ProjectAnimic/Animic/TimelineModule/TimelineQML/Timelineqml.qml"));
}

Timeline::~Timeline()
{


}


void Timeline::onSeeked()
{

}

void Timeline::addVideoObject()
{

}

void Timeline::addImageObject()
{

}

void Timeline::addAudioObject()
{

}

void Timeline::addDialogueObject()
{

}

