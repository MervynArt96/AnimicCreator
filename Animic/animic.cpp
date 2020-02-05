
#include "stdafx.h"
#include "animic.h"
#include "CanvasModule/CanvasObject/VideoObject.h"

Animic::Animic(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);
	init();
}

void Animic::init()
{
	projHandler = new ProjectHandler();
	assetHandler = new AssetHandler();
	player = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
	video = new QGraphicsVideoItem();

	assetHandler->assignTreeView(ui.AssetTreeView);

	setupScene();
	setupTimeline();

	connectSignalSlots();
}

void Animic::setupScene()	//set up graphics scene and canvas
{
	QGraphicsView* graphicsView = new QGraphicsView();
	ui.tab->layout()->addWidget(graphicsView);
	graphicsView->adjustSize();
	QGraphicsScene* scene = new QGraphicsScene();
	graphicsView->setScene(scene);

	QString videoName = "D:/My Documents/Programming/ProjectAnimic/Animic/XIII.mp4";

	if (QFile::exists(videoName))
	{
		video->setFlag(QGraphicsVideoItem::ItemIsMovable);

		graphicsView->scene()->addItem(video);
		player->setMedia(QUrl::fromLocalFile(videoName));
		player->setVideoOutput(video);
		player->play();

		//debug
		QColor color = Qt::black;
		QBrush brush = Qt::SolidPattern;
		brush.setColor(color);
		scene->setBackgroundBrush(brush);
		qDebug() << player->error();
	}


	// addVideo(scene);
	addGraphic(scene);
	
	graphicsView->showFullScreen();
}

void Animic::setupTimeline()
{

}

void Animic::connectSignalSlots()
{
	connect(ui.actionNewProject, &QAction::triggered, projHandler->getNewProjectDialog(), &NewProjectDialog::exec); //Opens new project dialog, modal mode
}

//Test functions
void Animic::addVideo(QGraphicsScene* scene)
{
	if (true)
	{

	}
	else
	{
		QColor color = Qt::blue;
		QBrush brush = Qt::SolidPattern;
		brush.setColor(color);
		scene->setBackgroundBrush(brush);
	}
}

void Animic::addGraphic(QGraphicsScene* scene)
{
	QColor color = Qt::blue;
	QBrush brush = Qt::SolidPattern;
	brush.setColor(color);


	QGraphicsRectItem* item = new QGraphicsRectItem(0, 0, 100, 100);
	item->setFlag(QGraphicsItem::ItemIsMovable);
	item->setBrush(brush);

	scene->addItem(item);

}