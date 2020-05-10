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

	connectSignalSlots();
}

void Animic::setupScene()	//set up graphics scene and canvas
{
	graphicsView = new AnimicView(ui.tab);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(graphicsView);
	ui.tab->setLayout(layout);
	scene = new AnimicScene(sceneListWidget);
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
	connect(ui.stitchButton, &QPushButton::clicked, stitchDialog, &StitchingDialog::openDialog);
	connect(ui.playButton, &QPushButton::clicked, scene, &AnimicScene::playAll);
	connect(ui.SceneWindow, SIGNAL(currentChanged(int)), this, SLOT(setCurrentScene(int)));

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
	//disconnect(sc, &AnimicScene::objectInserted, item, &SceneAssetItem::onObjectInserted);

	if (view)
	{
		AnimicScene* sc = dynamic_cast<AnimicScene*>(view->scene());
		if (sc)
		{
			//disconnect objects 

			sc->stopAll();
			//sc->~AnimicScene();

			//assign reference to list for future retrieval, not final???
		}
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

void Animic::setCurrentScene(int index)
{
	if (index >= 0)
	{
		AnimicView* view = ui.SceneWindow->currentWidget()->findChild<AnimicView*>();

		if (view != nullptr)
		{
			AnimicScene* sc = dynamic_cast<AnimicScene*>(view->scene());

			if (sc != nullptr)
			{
				connect(ui.playButton, &QPushButton::clicked, sc, &AnimicScene::playAll);
				connect(ui.pauseButton, &QPushButton::clicked, sc, &AnimicScene::playAll);
				connect(ui.stopButton, &QPushButton::clicked, sc, &AnimicScene::playAll);

				QList<QGraphicsItem*> allItems = sc->items();

				foreach(QGraphicsItem * item, allItems)
				{
					VideoObject* videoObj = qgraphicsitem_cast<VideoObject*>(item);
					if (videoObj != nullptr)
					{
						//get videoObj attribute
						//update layer window
						//reconnect slider
					}
					else return;
				}

				//update properties window, maybe need to clear only
			}
		}
	}
}

