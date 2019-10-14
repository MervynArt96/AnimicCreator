#pragma once
#include <vector>
#include "BaseSequence.h"
#include "Viewport.h"

class Scene
{
	//QT component

public:
	typedef struct
	{
		int playbackspeed = 1;
		// begin transition
		// end transition
		BaseSequence sequence;
	}SequenceData;
	Scene();
	~Scene();

	SequenceData getSequenceData(int);
	void setSequenceData(SequenceData,int);
	std::vector<SequenceData> getSequenceList();
	void setSequenceList(std::vector<SequenceData>&);

	void addToSequenceList(SequenceData);
	void addSequence(SequenceData, int);
	void deleteSequence(int);
	void deleteSequenceList();

private:

	std::vector<SequenceData> sequenceList;
	Viewport viewport;
};

