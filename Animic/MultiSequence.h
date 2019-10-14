#pragma once
#include "BaseSequence.h"
class MultiSequence : protected BaseSequence
{
protected:

	std::vector<std::vector<SequenceObject>> branchList;
	int branchLocation = 0;
	short branchCount = 0;


};

