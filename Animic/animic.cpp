#include "stdafx.h"
#include "animic.h"

Animic::Animic(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("Animic Creator");
	init();
	canvasSize = new QPointF(800, 600);
}

#pragma region Helper Functions

void Animic::init()
{
	projectHandler = new ProjectHandler();
	setupScene();
	setupAssetHandler();
	setupListModel();
	setupStitchingModule();
	setupTimeline();

	connectSignalSlots();
}

void Animic::setupScene()	//set up graphics scene and canvas
{
	graphicsView = new AnimicView(ui.tab);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(graphicsView);
	ui.tab->setLayout(layout);
	scene = new AnimicScene();
	graphicsView->setSceneRect(QRectF(QPointF(0, 0), QPointF(800,600)));
	graphicsView->setScene(&sc);
	//graphicsView->setBackgroundBrush(QBrush(Qt::darkGray, Qt::SolidPattern));
	graphicsView->setAcceptDrops(true);
	graphicsView->show();

	connect(ui.playButton, &QPushButton::clicked, &sc, &AnimicScene::playAll);
	connect(ui.pauseButton, &QPushButton::clicked, &sc, &AnimicScene::pauseAll);
	connect(ui.stopButton, &QPushButton::clicked, &sc, &AnimicScene::stopAll);
}

void Animic::connectSignalSlots()
{
	connect(ui.actionNewProject, &QAction::triggered, projectHandler->getNewProjectDialog(), &NewProjectDialog::exec);
	connect(ui.actionStitching, &QAction::triggered, stitchDialog, &StitchingDialog::openDialog);

	connect(ui.SceneWindow, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
	connect(ui.SceneWindow, SIGNAL(currentChanged(int)), this, SLOT(setCurrentScene(int)));

	connect(ui.stitchButton, &QPushButton::clicked, stitchDialog, &StitchingDialog::openDialog);
	connect(ui.SceneWindow, SIGNAL(currentChanged(int)), this, SLOT(debug()));
}

void Animic::setupTimeline()
{
	mainSlider = new AnimicSlider(ui.SliderHolder);
	mainSlider->setScene(scene);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(mainSlider);
	ui.SliderHolder->setLayout(layout);

	connect(mainSlider, SIGNAL(valueChanged(int)), scene, SLOT(setVideoFrameTime(int)));
	connect(scene, SIGNAL(objectInserted(qint64)), mainSlider, SLOT(onInsertVideo(qint64)));
	//connect(scene, SIGNAL(subscribeTimeline(QMediaPlayer*)), mainSlider, SLOT(subscribeVideo(QMediaPlayer*))); //performance issue
}

void Animic::setupAssetHandler()
{
	assetHandler = new AssetHandler();
	ui.treeHolder->layout()->addWidget(assetHandler);
}

void Animic::setupStitchingModule()
{
	stitchDialog = new StitchingDialog(stitchList, sceneModel);
}

void Animic::setupListModel()
{
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(mainList);
	ui.sceneListHolder->setLayout(layout);

	mainList->setModel(sceneModel);
	mainList->setListMode(true);
	mainList->setItemDelegate(mainDelegate);

	stitchList->setModel(sceneModel);
	stitchList->setItemDelegate(stitchDelegate);

	sceneModel->appendRow(scene);
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


#pragma endregion 

#pragma region Ui Functions

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

			//assign reference to list for future retrieval, not final???
		}
		view->~AnimicView();
	}

	ui.SceneWindow->removeTab(index);
}

void Animic::on_actionNewScene_triggered()
{
	QWidget* widget = new QWidget(ui.SceneWindow);
	ui.SceneWindow->addTab(widget, QString("Scene Model List Count here"));

	AnimicView* view = new AnimicView(widget);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);
	widget->setLayout(layout);

	AnimicScene* sc = new AnimicScene();
	view->setSceneRect(QRectF(QPointF(0, 0), *canvasSize));
	view->setScene(sc);
	view->setAcceptDrops(true);
	view->show();

	sceneModel->appendRow(sc);
	debug();

}
#pragma endregion


void Animic::debug()
{
	for (int i = 0; i < sceneModel->getList()->size()-1; i++)
	{
		qDebug() << sceneModel->getList()->size();
		qDebug() << sceneModel->getList()[i];
	}
}
