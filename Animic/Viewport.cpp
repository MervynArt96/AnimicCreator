#include "stdafx.h"
#include "Viewport.h"

void Viewport::zoomIn()
{
	if(currentIndex > 0)
		currentIndex -= 1;
}

void Viewport::zoomOut()
{
	if (currentIndex < 9)
		currentIndex += 1;
}

void Viewport::resize(int w, int h)
{
	width = w;
	height = h;
}

Canvas Viewport::getCanvas()
{
	return canvas;
}
