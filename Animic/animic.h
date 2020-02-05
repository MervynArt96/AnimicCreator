#pragma once
#include <QtWidgets/QMainWindow>
#include <QtCore>
#include <QtGui>
#include "ui_animic.h"
#include "ProjectHandler.h"
#include "AssetHandlerModule/AssetHandler.h"
#include "CanvasModule/Scene.h"
#include <QMediaPlayer>
#include <QGraphicsVideoItem>
#include <QDebug>


class Animic : public QMainWindow
{
	Q_OBJECT

public:
	Animic(QWidget *parent = Q_NULLPTR);

private:
	Ui::AnimicClass ui;
	void init();
	void connectSignalSlots();
	void setupScene();
	void setupTimeline();

	int sceneTabCount = 1;	//global var, for object naming

	ProjectHandler* projHandler;			//modules
	AssetHandler* assetHandler;

	Scene* canvas = nullptr;
	QGraphicsView* sceneView = nullptr;
	QMediaPlayer* player = nullptr;
	QGraphicsVideoItem* video = nullptr;

	//test
	void addVideo(QGraphicsScene*);
	void addGraphic(QGraphicsScene*);


};
