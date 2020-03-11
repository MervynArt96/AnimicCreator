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
	setupSceneListWidget();
	setupStitchingModule();



	setupDemo();
	

	connectSignalSlots();
}

void Animic::setupScene()	//set up graphics scene and canvas
{
	graphicsView = new AnimicView(ui.tab);
	ui.tab->layout()->addWidget(graphicsView);
	scene = new AnimicScene(sceneListWidget);
	graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
	graphicsView->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	graphicsView->setScene(scene);
	//graphicsView->setBackgroundBrush(QBrush(Qt::darkGray, Qt::SolidPattern));
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
	stitchDialog = new StitchingDialog(sceneListWidget);
}

void Animic::setupSceneListWidget()
{
	sceneListWidget = new SceneListWidget(ui.sceneListHolder);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(sceneListWidget);
	ui.sceneListHolder->setLayout(layout);

	sceneListWidget->setSortingEnabled(false);
	sceneItem = new SceneAssetItem("ABC", sceneListWidget);
}

void Animic::setupDemo()
{
	QString path = "D:/My Documents/Digital Art/Asset/Logo.png";

	QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap(path));
	item->setScale(0.25);
	scene2 = new AnimicScene(sceneListWidget);

	scene2->addItem(item);
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
	AnimicView* view = ui.SceneWindow->widget(index)->findChild<AnimicView*>();
	AnimicScene* sc = dynamic_cast<AnimicScene*>(view->scene());

	//disconnect(sc, &AnimicScene::objectInserted, item, &SceneAssetItem::onObjectInserted);

	if (sc)
	{
		sc->clear();
		//sc->~AnimicScene();

		//assign reference to list for future retrieval
	}

	if (view)
	{
		view->~AnimicView();
	}

	ui.SceneWindow->removeTab(index);
}

void Animic::on_actionNewScene_triggered()
{
	sceneTabCount++;
	QWidget* widget = new QWidget(ui.SceneWindow);

	ui.SceneWindow->addTab(widget, QString("Scene " + QString::number(sceneTabCount)));
	AnimicView* view = new AnimicView(widget);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);
	widget->setLayout(layout);

	AnimicScene* sc = new AnimicScene(sceneListWidget);
	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	view->setScene(sc);
	view->setAcceptDrops(true);
	view->show();

	SceneAssetItem* item = new SceneAssetItem(QString("Scene " + QString::number(sceneTabCount)), sceneListWidget);
	sceneListWidget->addItem(item);

	//connect(sc, &AnimicScene::objectInserted, item, &SceneAssetItem::onObjectInserted);
}

