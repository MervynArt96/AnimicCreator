#include "stdafx.h"
#include "animic.h"

Animic::Animic(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("Animic Creator");
	init();
}

#pragma region Helper Functions

void Animic::init()
{
	projectHandler = new ProjectHandler();
	setupScene();
	setupAssetHandler();
	setupStitchingModule();
	setupListModel();
	setupTimeline();
	setupProperties();

	connectSignalSlots();
}

void Animic::setupScene()	//set up graphics scene and canvas
{
	graphicsView = new AnimicView(ui.tab);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(graphicsView);
	ui.tab->setLayout(layout);
	scene = new AnimicScene();
	dummy = new QGraphicsScene();
	scene->setName("Scene 1");
	graphicsView->setSceneRect(QRectF(QPointF(0, 0), QPointF(800,600)));
	graphicsView->setScene(scene);
	graphicsView->setAcceptDrops(true);
	graphicsView->show();

	connect(ui.playButton, &QPushButton::clicked, scene, &AnimicScene::playAll);
	connect(ui.pauseButton, &QPushButton::clicked, scene, &AnimicScene::pauseAll);
	connect(ui.stopButton, &QPushButton::clicked, scene, &AnimicScene::stopAll);
}

void Animic::connectSignalSlots()
{
	connect(ui.actionNewProject, &QAction::triggered, projectHandler->getNewProjectDialog(), &NewProjectDialog::exec);

	connect(ui.SceneWindow, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
	connect(ui.SceneWindow, SIGNAL(currentChanged(int)), this, SLOT(setCurrentScene(int)));

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

void Animic::setupProperties()
{
	propHandler = new PropertiesHandler();

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(propHandler);
	ui.propHolder->setLayout(layout);

	connect(scene, &AnimicScene::focusItemChanged, propHandler, &PropertiesHandler::objectFocusChanged);
	connect(mainList, &AnimicListView::openNewSceneTab, propHandler, &PropertiesHandler::onSceneChanged);
}

void Animic::setupStitchingModule()
{
	stitchDialog = new StitchingDialog(sceneModel);

	connect(ui.actionStitching, &QAction::triggered, stitchDialog, &StitchingDialog::openDialog);
}

void Animic::setupListModel()
{
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(mainList);
	ui.sceneListHolder->setLayout(layout);

	mainList->setModel(sceneModel);
	mainList->setListMode(true);
	mainList->setItemDelegate(mainDelegate);

	sceneModel->appendRow(scene);	//demo

	connect(mainList, &AnimicListView::openNewSceneTab, this, &Animic::openNewTab);
	connect(mainList, &AnimicListView::deleteScene, this, &Animic::onDeleteScene);
	connect(stitchDialog, &StitchingDialog::closingDialog, this, &Animic::resetTabOnCloseDialog);
}

void Animic::resetTabOnCloseDialog()
{
	for (int i = 0; i < ui.SceneWindow->count(); i++)
	{
		for (int j = 0; j < sceneModel->getList()->count(); j++)
		{
			QString name = sceneModel->getList()->at(j)->getName();

			if (ui.SceneWindow->tabText(i) == name)
			{
				AnimicView* view = ui.SceneWindow->widget(currentTab)->findChild<AnimicView*>();

				if (view != nullptr)
				{
					view->setScene(sceneModel->getList()->at(j));
				}
			}
		}
	}

	AnimicView* view = ui.SceneWindow->currentWidget()->findChild<AnimicView*>();

	if (view != nullptr)
	{
		AnimicScene* sc = qobject_cast<AnimicScene*>(view->scene());
		if (sc != nullptr)
		{
			connect(ui.playButton, &QPushButton::clicked, sc, &AnimicScene::playAll);
			connect(ui.pauseButton, &QPushButton::clicked, sc, &AnimicScene::pauseAll);
			connect(ui.stopButton, &QPushButton::clicked, sc, &AnimicScene::stopAll);
			connect(mainSlider, SIGNAL(valueChanged(int)), scene, SLOT(setVideoFrameTime(int)));
			connect(scene, SIGNAL(objectInserted(qint64)), mainSlider, SLOT(onInsertVideo(qint64)));
		}
	}
}

void Animic::setCurrentScene(int index)
{
	if (currentTab != -1)		//check if the signal comes from deleting a scene or user switch tab
	{
		AnimicView* view = ui.SceneWindow->widget(currentTab)->findChild<AnimicView*>();

		if (view != nullptr)
		{
			AnimicScene* sc = dynamic_cast<AnimicScene*>(view->scene());

			if (sc != nullptr)
			{
				sc->disconnectObject();
				sc->disconnect();
			}
		}
	}

	//clear layer list

	if (index >= 0)
	{
		currentTab = index;
		AnimicView* view = ui.SceneWindow->currentWidget()->findChild<AnimicView*>();

		if (view != nullptr)
		{
			AnimicScene* sc = dynamic_cast<AnimicScene*>(view->scene());

			if (sc != nullptr)
			{
				if(sc->getMaxPlayer() != nullptr)
					mainSlider->setMaximum(sc->getMaxPlayer()->duration());

				connect(ui.playButton, &QPushButton::clicked, sc, &AnimicScene::playAll);
				connect(ui.pauseButton, &QPushButton::clicked, sc, &AnimicScene::pauseAll);
				connect(ui.stopButton, &QPushButton::clicked, sc, &AnimicScene::stopAll);
				connect(mainSlider, SIGNAL(valueChanged(int)), scene, SLOT(setVideoFrameTime(int)));
				connect(scene, SIGNAL(objectInserted(qint64)), mainSlider, SLOT(onInsertVideo(qint64)));

				//update properties window, maybe need to clear only
				//connect scene to properties window
					//model edit name to label set text

				//connect layer list
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

	if (view != nullptr)
	{
		AnimicScene* sc = dynamic_cast<AnimicScene*>(view->scene());
		if (sc != nullptr)
		{
			sc->stopAll();
			sc->disconnectObject();
			sc->disconnectScene();
		}
		view->~AnimicView();
	}

	ui.SceneWindow->removeTab(index);
}

void Animic::on_stitchButton_clicked()
{
	for (int i = 0; i < ui.SceneWindow->count(); i++)							//prevent app freeze
	{
		AnimicView* view = ui.SceneWindow->widget(i)->findChild<AnimicView*>();

		if (view != nullptr)
		{
			view->setScene(dummy);
			
		}
	}

	sceneModel->setSceneToStitchMode();
	stitchDialog->openDialog();
}

void Animic::on_actionNewScene_triggered()
{
	QWidget* widget = new QWidget(ui.SceneWindow);

	AnimicScene* sc = new AnimicScene();

	sceneModel->appendRow(sc);
	int num = sceneModel->getList()->count();
	sc->setName(QString("Scene " + QString::number(num)));

	ui.SceneWindow->addTab(widget, sc->getName());

	AnimicView* view = new AnimicView(widget);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);
	widget->setLayout(layout);

	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800,600)));
	view->setScene(sc);
	view->setAcceptDrops(true);
	view->show();
}

void Animic::on_newSceneButton_clicked()
{
	QWidget* widget = new QWidget(ui.SceneWindow);

	AnimicScene* sc = new AnimicScene();

	sceneModel->appendRow(sc);
	int num = sceneModel->getList()->count();
	sc->setName(QString("Scene " + QString::number(num)));

	ui.SceneWindow->addTab(widget, sc->getName());

	AnimicView* view = new AnimicView(widget);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);
	widget->setLayout(layout);

	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	view->setScene(sc);
	view->setAcceptDrops(true);
	view->show();
}

void Animic::on_removeSceneButton_clicked()
{
	qDebug() << mainList->currentIndex();
	if (mainList->currentIndex().row() > -1)
	{
		QMetaObject::invokeMethod(mainList, "onDeleteScene");
	}
}

#pragma endregion

void Animic::openNewTab(AnimicScene* sc)
{
	QWidget* widget = new QWidget(ui.SceneWindow);

	ui.SceneWindow->addTab(widget, sc->getName());

	AnimicView* view = new AnimicView(widget);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);
	widget->setLayout(layout);

	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	view->setScene(sc);
	view->setAcceptDrops(true);
	view->show();
}

void Animic::onDeleteScene(AnimicScene* sc)
{
	for (int i = 0; i < ui.SceneWindow->count(); i++)
	{
		AnimicView* view = ui.SceneWindow->widget(i)->findChild<AnimicView*>();

		if (view != nullptr) 
		{
			if (view->scene() == qobject_cast<QGraphicsScene*>(sc))
			{
				sc->clear();
				view->~AnimicView();
				ui.SceneWindow->removeTab(i);
				currentTab = -1;
				break;
			}
		}
	}
	sceneModel->removeRows(mainList->currentIndex().row(), 1, QModelIndex());
	//clear layer list
}

void Animic::debug()
{

}
