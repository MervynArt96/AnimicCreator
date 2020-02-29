#include "stdafx.h"
#include "animic.h"

Animic::Animic(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("Animic Creator");
	init();

}

void Animic::init()
{
	projectHandler = new ProjectHandler();

	setupScene();
	setupTimeline();
	setupAssetHandler();

	/*
	QUrl videoName = QUrl("D:/My Documents/Videos/singsing.mp4");
	video = new VideoObject(nullptr ,&videoName);
	video->getPlayer()->pause();
	scene->addItem(video);
	*/

	connectSignalSlots();
}

void Animic::setupScene()	//set up graphics scene and canvas
{
	graphicsView = new QGraphicsView();
	//graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
	ui.tab->layout()->addWidget(graphicsView);
	graphicsView->adjustSize();
	scene = new AnimicScene();
	graphicsView->setSceneRect(QRectF(QPointF(0, 0) , QPointF(800, 600)));
	graphicsView->setScene(scene);
	graphicsView->setAcceptDrops(true);
	graphicsView->show();
}

void Animic::setupTimeline()
{
	timelineWidget = new Timeline(ui.TimelineWindow);
	qDebug() << timelineWidget->errors();

	QVBoxLayout* layout = new QVBoxLayout(timelineWidget);
	ui.TimelineWindow->setLayout(layout);
	
}

void Animic::connectSignalSlots()
{
	connect(ui.actionNewProject, &QAction::triggered, projectHandler->getNewProjectDialog(), &NewProjectDialog::exec);

}

void Animic::setupAssetHandler()
{
	assetHandler = new AssetHandler();
	ui.treeHolder->layout()->addWidget(assetHandler);
}

//Debug functions

void Animic::addGraphic()
{
	QColor color = Qt::blue;
	QBrush brush = Qt::SolidPattern;
	brush.setColor(color);

	QGraphicsRectItem* item = new QGraphicsRectItem(0, 0, 100, 100);
	item->setFlag(QGraphicsItem::ItemIsMovable);
	item->setBrush(brush);

	scene->addItem(item);

}


//ui functions

void Animic::on_btnImportAsset_clicked()
{
	assetHandler->importAsset();
}

void Animic::on_btnImportDir_clicked()
{
	assetHandler->importDirectory();
}

void Animic::on_btnDeleteAsset_clicked()
{
	assetHandler->deleteAsset();
}