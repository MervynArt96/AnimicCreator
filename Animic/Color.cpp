#include "stdafx.h"
#include "Color.h"

Colour::Colour()
{
	
}

Colour::~Colour()
{
	delete &colour;
}

Colour::colourValue Colour::getColourValue()
{
	return colour;
}

float Colour::getColourRed()
{
	return colour.r;
}

float Colour::getColourGreen()
{
	return colour.g;
}

float Colour::getColourBlue()
{
	return colour.b;
}

float Colour::getColourAlpha()
{
	return colour.a;
}

void Colour::setColourValue(float r, float g, float b, float a)
{
	colour.r = r;
	colour.g = g;
	colour.b = b;
	colour.a = a;
}

void Colour::setColourRed(float r)
{
	colour.r = r;
}

void Colour::setColourGreen(float g)
{
	colour.g = g;
}

void Colour::setColourBlue(float b)
{
	colour.b = b;
}

void Colour::setColourAlpha(float a)
{
	colour.a = a;
}