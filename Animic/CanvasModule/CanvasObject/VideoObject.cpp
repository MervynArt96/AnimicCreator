#include "stdafx.h"
#include "VideoObject.h"

VideoObject::VideoObject(QObject *parent, QUrl path)
{
	videoPath = path;
}

VideoObject::~VideoObject()
{

}

QUrl VideoObject::getVideoPath()
{
	return videoPath;
}
