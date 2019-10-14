#include "stdafx.h"
#include "Canvas.h"

Canvas::Canvas()
{
	
}
Canvas::~Canvas()
{
	
}

int Canvas::getCanvasWidth()
{
	return width;
}

int Canvas::getCanvasHeight()
{
	return height;
}

Colour::colourValue Canvas::getCanvasColour()
{
	return canvasColour.getColourValue();
}

void Canvas::setCanvasHeight(int h)
{
	height = h;
}

void Canvas::setCanvasWidth(int w)
{
	width = w;
}

void Canvas::setCanvasColour(float r, float g, float b, float a)
{
	canvasColour.setColourValue(r, g, b, a);
}