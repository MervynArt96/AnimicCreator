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
	setupAssetHandler();
	setupDemo();
	ui.sceneListWidget->setSortingEnabled(false);
	stitchDialog = new StitchingDialog(ui.sceneListWidget);
	connectSignalSlots();
}

void Animic::setupScene()	//set up graphics scene and canvas
{
	graphicsView = new QGraphicsView(ui.tab);
	ui.tab->layout()->addWidget(graphicsView);
	graphicsView->adjustSize();
	scene = new AnimicScene(ui.sceneListWidget);
	graphicsView->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	graphicsView->setScene(scene);
	graphicsView->setBackgroundBrush(QBrush(Qt::gray, Qt::SolidPattern));
	graphicsView->setAcceptDrops(true);
	graphicsView->show();
}

void Animic::connectSignalSlots()
{
	connect(ui.actionNewProject, &QAction::triggered, projectHandler->getNewProjectDialog(), &NewProjectDialog::exec);
	connect(ui.actionStitching, &QAction::triggered, stitchDialog, &StitchingDialog::openDialog);
	connect(ui.SceneWindow, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
	
}

void Animic::setupAssetHandler()
{
	assetHandler = new AssetHandler();
	ui.treeHolder->layout()->addWidget(assetHandler);
}

void Animic::setupStitchingModule()
{

}

void Animic::setupDemo()
{
	QString path = "D:/My Documents/Digital Art/Asset/Logo.png";

	QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap(path));
	item->setScale(0.25);
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

void Animic::closeTab(int index)
{
	QGraphicsView* view = ui.SceneWindow->widget(index)->findChild<QGraphicsView*>();
	AnimicScene* sc = dynamic_cast<AnimicScene*>(view->scene());

	//disconnect(sc, &AnimicScene::objectInserted, item, &SceneAssetItem::onObjectInserted);

	if (sc)
	{
		sc->clear();
		sc->~AnimicScene();
	}

	if (view)
	{
		view->~QGraphicsView();
	}

	ui.SceneWindow->removeTab(index);
	sceneTabCount--;
}

void Animic::on_actionNewScene_triggered()
{
	QWidget* widget = new QWidget(ui.SceneWindow);

	ui.SceneWindow->addTab(widget, QString("Scene " + QString(sceneTabCount)));
	QGraphicsView* view = new QGraphicsView(widget);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);
	widget->setLayout(layout);

	AnimicScene* sc = new AnimicScene(ui.sceneListWidget);
	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	view->setScene(sc);
	view->setAcceptDrops(true);
	view->show();

	sceneTabCount++;

	SceneAssetItem* item = new SceneAssetItem(QString("Scene " + QString(sceneTabCount)), ui.sceneListWidget);
	ui.sceneListWidget->addItem(item);

	//connect(sc, &AnimicScene::objectInserted, item, &SceneAssetItem::onObjectInserted);
}

