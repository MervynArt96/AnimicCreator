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

void Animic::setupScene()
{
	graphicsView = new AnimicView(ui.tab, 0);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(graphicsView);
	ui.tab->setLayout(layout);
	scene = new AnimicScene();
	scene->setName("Scene 1");
	scene->setEntry(true);
	graphicsView->setSceneRect(QRectF(QPointF(0, 0), QPointF(800,600)));
	graphicsView->setScene(scene);
	graphicsView->setAcceptDrops(true);
	graphicsView->show();

	connect(ui.playButton, &QPushButton::clicked, scene, &AnimicScene::playAll);
	connect(ui.pauseButton, &QPushButton::clicked, scene, &AnimicScene::pauseAll);
	connect(ui.stopButton, &QPushButton::clicked, scene, &AnimicScene::stopAll);
	connect(scene, &AnimicScene::deletingVideo, this, &Animic::safeRemoveVideo);
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

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(mainSlider);
	ui.SliderHolder->setLayout(layout);

	connect(mainSlider, SIGNAL(valueChanged(int)), scene, SLOT(setVideoFrameTime(int)));
	connect(scene, SIGNAL(objectInserted(qint64)), mainSlider, SLOT(onInsertVideo(qint64)));
	connect(scene, &AnimicScene::foundNewMax, mainSlider, &AnimicSlider::onRemoveVideo);

	//connect(scene, SIGNAL(subscribeTimeline(QMediaPlayer*)), mainSlider, SLOT(subscribeVideo(QMediaPlayer*)));	//This works but comes with performance issue
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
	connect(this, &Animic::sceneChanged, propHandler, &PropertiesHandler::sceneChanged);
	propHandler->getScenePropertiesWidget()->updateProperties(scene->getName(), scene->isEntry());
	propHandler->getScenePropertiesWidget()->manualConnect(scene);
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

	sceneModel->appendRow(scene);

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
				AnimicView* view = ui.SceneWindow->currentWidget()->findChild<AnimicView*>();

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
				sc->clearFocus();
				sc->clearSelection();
				sc->disconnectObject();
				sc->disconnect();
				//propHandler->getVideoPropertiesWidget()->disconnect(sc);
				disconnect(ui.playButton, &QPushButton::clicked, sc, &AnimicScene::playAll);
				disconnect(ui.pauseButton, &QPushButton::clicked, sc, &AnimicScene::pauseAll);
				disconnect(ui.stopButton, &QPushButton::clicked, sc, &AnimicScene::stopAll);
				disconnect(mainSlider, SIGNAL(valueChanged(int)), sc, SLOT(setVideoFrameTime(int)));
				propHandler->getScenePropertiesWidget()->onDisconnectScene(sc);
			}
		}
	}

	if (index >= 0)
	{
		currentTab = index;
		AnimicView* view = ui.SceneWindow->currentWidget()->findChild<AnimicView*>();
		if (view != nullptr)
		{
			AnimicScene* scc = qobject_cast<AnimicScene*>(view->scene());
			if (scc != nullptr)
			{
				if (scc->getMaxPlayer() != nullptr)
				{
					mainSlider->setMaximum(scc->getMaxPlayer()->duration());
				}

				qDebug() << scc->getName();

				propHandler->getScenePropertiesWidget()->updateProperties(scc->getName(), scc->isEntry());
				connect(ui.playButton, &QPushButton::clicked, scc, &AnimicScene::playAll);
				connect(ui.pauseButton, &QPushButton::clicked, scc, &AnimicScene::pauseAll);
				connect(ui.stopButton, &QPushButton::clicked, scc, &AnimicScene::stopAll);
				connect(mainSlider, SIGNAL(valueChanged(int)), scc, SLOT(setVideoFrameTime(int)));
				connect(scc, &AnimicScene::deletingVideo, this, &Animic::safeRemoveVideo);
				connect(scc, SIGNAL(objectInserted(qint64)), mainSlider, SLOT(onInsertVideo(qint64)));
				connect(scc, &AnimicScene::foundNewMax, mainSlider, &AnimicSlider::onRemoveVideo);
				connect(scc, &AnimicScene::focusItemChanged, propHandler, &PropertiesHandler::objectFocusChanged);
				
				emit sceneChanged(scc);

				//connect layer list
			}
		}
	}
}

void Animic::onDeleteScene(AnimicScene* sc)
{
	for (int i = 0; i < ui.SceneWindow->count(); i++)
	{
		AnimicView* view = ui.SceneWindow->widget(i)->findChild<AnimicView*>();

		if (view != nullptr)
		{
			if (view->scene() == qobject_cast<AnimicScene*>(sc))
			{
				view->setScene(nullptr);
				ui.SceneWindow->removeTab(i);
				break;
			}
		}
	}
	sceneModel->removeRows(mainList->currentIndex().row(), 1, QModelIndex());
	sc->disconnectObject();
	sc->disconnect();
	mainSlider->disconnect();
	propHandler->getVideoPropertiesWidget()->resetItem();
	propHandler->getScenePropertiesWidget()->onDisconnectScene(sc);
	sc->clear();

	QList<AnimicScene*> list = *sceneModel->getList();

	for (int i = 0; i < list.size(); i++)
	{
		list.at(i)->resetTriggerNextScene(sc);		//remove any pointers towards the deleted scene
	}
}

void Animic::safeRemoveVideo()
{
	mainSlider->disconnect();
	mainSlider->setMaximum(0);
	propHandler->getVideoPropertiesWidget()->resetItem();
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
	for (int i = 0; i < ui.SceneWindow->count(); i++)							
	{
		AnimicView* view = ui.SceneWindow->widget(i)->findChild<AnimicView*>();

		if (view != nullptr)
		{
			view->setScene(nullptr);   //prevent app freeze
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

	AnimicView* view = new AnimicView(widget , 0);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);
	widget->setLayout(layout);

	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800,600)));
	view->setScene(sc);
	view->setAcceptDrops(true);
	view->show();
	setCurrentScene(ui.SceneWindow->currentIndex());
}

void Animic::on_newSceneButton_clicked()
{
	QWidget* widget = new QWidget(ui.SceneWindow);

	AnimicScene* sc = new AnimicScene();
	AnimicView* view = new AnimicView(widget, 0);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);
	widget->setLayout(layout);

	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	view->setScene(sc);
	view->setAcceptDrops(true);
	view->show();

	sceneModel->appendRow(sc);
	int num = sceneModel->getList()->count();
	sc->setName(QString("Scene " + QString::number(num)));

	ui.SceneWindow->addTab(widget, sc->getName());
}


void Animic::openNewTab(AnimicScene* sc)
{
	QWidget* widget = new QWidget(ui.SceneWindow);
	AnimicView* view = new AnimicView(widget, 0);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);
	widget->setLayout(layout);

	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	view->setScene(sc);
	view->setAcceptDrops(true);
	view->show();
	ui.SceneWindow->addTab(widget, sc->getName());
}

void Animic::on_removeSceneButton_clicked()
{
	if (mainList->currentIndex().row() > -1)
	{
		QMetaObject::invokeMethod(mainList, "onDeleteScene");
	}
}
#pragma endregion

void Animic::debug()
{

}