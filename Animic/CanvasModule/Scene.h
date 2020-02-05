#pragma once
#include "CanvasObject/VideoObject.h"
#include "CanvasObject/ImageObject.h"
#include "CanvasObject/TextObject.h"

class Scene : public QGraphicsScene
{
	Q_OBJECT

public:

	Scene();
	~Scene();

	void setVideoList(QList<VideoObject>*);
	void setImageList(QList<ImageObject>*);
	void setTextList(QList<TextObject>*);

	void addToTimeline(VideoObject*, int);
	void addToTimeline(ImageObject*, int);
	void addToTimeline(TextObject*, int);

	void deleteObject();
	void deleteAllObject();

	QList<VideoObject>* getVideoList();
	QList<ImageObject>* getImageList();
	QList<TextObject>* getTextList();

	bool isVideoObject();
	bool isImageObject();
	bool isTextObject();

private:

	QList<VideoObject>* videoList;
	QList<ImageObject>* imageList;
	QList<TextObject>* textList;

};

