#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{
	
}

Scene::~Scene()
{
	deleteSequenceList();
	
}

Scene::SequenceData Scene::getSequenceData(int index)
{
	return sequenceList[index];
}

void Scene::setSequenceData(SequenceData seq, int index)
{
	sequenceList[index] = seq;
}

std::vector<Scene::SequenceData> Scene::getSequenceList()
{
	return sequenceList;
}

void Scene::setSequenceList(std::vector<SequenceData>& list)
{
	sequenceList = list;
}
void Scene::addToSequenceList(SequenceData data) //add to back
{
	sequenceList.push_back(data);
}

void Scene::addSequence(SequenceData data, int index)
{
	const auto it = sequenceList.begin();
	sequenceList.emplace(it +index, data);
}
void Scene::deleteSequence(int index)
{
	const auto it = sequenceList.begin();
	sequenceList.erase(it+ index);
}

void Scene::deleteSequenceList()
{
	delete &sequenceList; //temp
}