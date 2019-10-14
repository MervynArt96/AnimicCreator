#pragma once
#include "BaseSequence.h"

class SubSequence : protected BaseSequence
{
private:
	BaseSequence* parent = nullptr;

public:
	void setParentSequence(BaseSequence target);
	BaseSequence getParentSequence();

};

