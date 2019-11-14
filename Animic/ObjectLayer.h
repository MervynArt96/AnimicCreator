#pragma once
#include "AnimicObject.h";
#include <vector>;

class ObjectLayer
{

public:
	
	typedef struct {

		AnimicObject obj;
		
		int zIndex;



	}LayerData;


private:

	std::vector<LayerData> layer;


};

