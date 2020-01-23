#pragma once
#include "AnimicObject.h"
#include <string>

class DialogueObject : protected AnimicObject
{
	//QT component here??

private:
	std::string dialogue = nullptr;
	float playbackSpeed = 1;
	float fontSize = 12;

public:
	std::string getDialogue() const;
	void setDialogue(std::string text);
	float getPlaybackSpeed() const;
	void setPlaybackSpeed(float speed);
	float getFontSize() const;
	void setFontSize(float size);

};

