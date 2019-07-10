#pragma once
class AnimicObject
{
	public:
		float getPositionX();
		float getPositionY();
		float getScaleX();
		float getScaleY();
		void setPositionX(float target);
		void setPositionY(float target);
		void setScaleX(float target);
		void setScaleY(float target);

		private:
		float posX = 0;
		float posY = 0;
		float scaleX = 1;
		float scaleY = 1;

		
};

