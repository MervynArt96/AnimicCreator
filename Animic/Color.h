#pragma once

class Colour
{
public:
	typedef struct {
		float r, g, b, a;
	}colourValue;

	Colour();
	~Colour();

	colourValue getColourValue();
	float getColourRed();
	float getColourBlue();
	float getColourGreen();
	float getColourAlpha();

	void setColourValue(float, float, float, float);
	void setColourRed(float);
	void setColourGreen(float);
	void setColourBlue(float);
	void setColourAlpha(float);

private:
	colourValue colour;

};
