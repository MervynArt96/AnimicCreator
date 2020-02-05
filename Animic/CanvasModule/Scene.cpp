#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{
	
}

Scene::~Scene()
{
	delete videoList;
	delete imageList;
	delete textList;
	deleteAllObject();
}

void Scene::setVideoList(QList<VideoObject>*)
{

}

void Scene::setImageList(QList<ImageObject>*)
{

}

void Scene::setTextList(QList<TextObject>*)
{

}


void Scene::addToTimeline(VideoObject*, int)
{

}
void Scene::addToTimeline(ImageObject*, int)
{

}

void Scene::addToTimeline(TextObject*, int)
{

}

void Scene::deleteObject()
{

}

void Scene::deleteAllObject()
{
	videoList->clear();
	imageList->clear();
	textList->clear();
}

QList<VideoObject>* Scene::getVideoList()
{
	return videoList;
}

QList<ImageObject>* Scene::getImageList()
{
	return imageList;
}

QList<TextObject>* Scene::getTextList()
{
	return textList;
}

bool Scene::isVideoObject()
{
	return false;
}

bool Scene::isImageObject()
{
	return false;
}

bool Scene::isTextObject()
{
	return false;
}