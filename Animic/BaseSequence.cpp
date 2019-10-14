#include "stdafx.h"
#include "BaseSequence.h"

BaseSequence::BaseSequence()
{
	
}

BaseSequence::~BaseSequence()
{
	
}

std::vector<BaseSequence::SequenceObject> BaseSequence::getObjectList()
{
	return objectList;
}

void BaseSequence::setOjbectList(std::vector<SequenceObject> list)
{
	objectList = list;
}

