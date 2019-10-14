#pragma once
#include "Color.h"

class Canvas
{
	//QT component

private:
	int height = 0;
	int width = 0;

	Colour canvasColour;

public:
	Canvas();
	~Canvas();

	int getCanvasWidth();
	int getCanvasHeight();
	Colour::colourValue getCanvasColour();

	void setCanvasHeight(int);
	void setCanvasWidth(int);
	void setCanvasColour(float, float, float, float);

};

