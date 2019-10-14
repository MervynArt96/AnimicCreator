#pragma once

#include <vector>
#include "AnimicObject.h"

class BaseSequence	//standard linear sequence
{
public:

	typedef struct
	{
		int second, minute, hour;
		AnimicObject object;
	}SequenceObject;

	BaseSequence();
	~BaseSequence();
	std::vector<SequenceObject> getObjectList();
	void setOjbectList(std::vector<SequenceObject>);

protected:

	std::vector<SequenceObject> objectList;
	BaseSequence* nextSequence = nullptr;
	BaseSequence* prevSequence = nullptr;

	//Timeline class
};

