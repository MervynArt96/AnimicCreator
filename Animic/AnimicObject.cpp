#include "stdafx.h"
#include "AnimicObject.h"

float AnimicObject::getPositionX()
{
	return posX;
}

float AnimicObject::getPositionY()
{
	return posY;
}

float AnimicObject::getScaleX()
{
	return scaleX;
}

float AnimicObject::getScaleY()
{
	return scaleY;
}

void AnimicObject::setPositionX(const float target)
{
	posX = target;
}

void AnimicObject::setPositionY(const float target)
{
	posY = target;
}

void AnimicObject::setScaleX(const float target)
{
	scaleX = target;
}

void AnimicObject::setScaleY(const float target)
{
	scaleY = target;
}
