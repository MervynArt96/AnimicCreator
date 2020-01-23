#pragma once
class AnimicObject
{
	public:
		float getPositionX();
		float getPositionY();
		float getScaleX();
		float getScaleY();
		int getZIndex() const;

		void setPositionX(float target);
		void setPositionY(float target);
		void setScaleX(float target);
		void setScaleY(float target);
		void setZIndex(int index);

	private:
		float posX = 0;
		float posY = 0;
		float scaleX = 1;
		float scaleY = 1;
		int zIndex = 0;
		
};

