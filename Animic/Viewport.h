#pragma once
#include "Canvas.h"

class Viewport
{
	//QT component

public:

	void zoomIn();
	void zoomOut();
	void resize(int, int);

	Canvas getCanvas();
	
private:

	int factors[10] = { 10, 25, 50, 75, 100, 125, 150, 200, 300, 400 };
	int currentIndex = 4;

	int width = 0;
	int height = 0;
	int zoomFactor = factors[currentIndex];

	Canvas canvas;
	
};

