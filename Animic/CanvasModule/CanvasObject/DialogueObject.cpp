#include "stdafx.h"
#include "DialogueObject.h"
#include <string>

std::string DialogueObject::getDialogue() const
{
	return dialogue;
}

void DialogueObject::setDialogue(std::string text)
{
	dialogue = text;
}

float DialogueObject::getPlaybackSpeed() const
{
	return playbackSpeed;
}

void DialogueObject::setPlaybackSpeed(float speed)
{
	playbackSpeed = speed;
}

float DialogueObject::getFontSize() const
{
	return fontSize;
}

void DialogueObject::setFontSize(float size)
{
	fontSize = size;
}



