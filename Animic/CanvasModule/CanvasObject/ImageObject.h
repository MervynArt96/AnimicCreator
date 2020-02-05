#pragma once
#include <QGraphicsPixmapItem>

class ImageObject : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:
	ImageObject(QObject *parent);
	~ImageObject();

	void disableImageObject();
	
private:




public slots:

	/*void onSliderChange();
	void onSliderEnter();
	void onSliderExit();
	void onDurationChanged();*/

};