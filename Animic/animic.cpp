#include "stdafx.h"
#include "animic.h"

Animic::Animic(QWidget *parent): QMainWindow(parent)	//program entry point
{
	ui.setupUi(this);
	this->setWindowTitle("Animic Creator");
	init();
}

#pragma region Helper Functions

void Animic::init()	//initialize the program
{
	projectHandler = new ProjectHandler();	//future addition, now is just a dummy placeholder
	setupScene();	//setup initial scene, to skip creating new project process
	setupAssetHandler();	// setup asset handling window at, bottom right corner
	setupStitchingModule();	// setup stitching module, accessible from file -> stich scene or stitch button next to playback control buttons
	setupListModel();	// setup Model View Controller, model holds data, view displays data
	setupTimeline();	// setup slider to control video frame by sliding
	setupProperties();	//setup properties window to display video object properties (position, scale, etc.), at top right corner

	connectSignalSlots();
}

void Animic::setupScene()
{
	graphicsView = new AnimicView(ui.tab, 0);

	QVBoxLayout* layout = new QVBoxLayout();	//vertical box layout
	layout->addWidget(graphicsView);	// add viewport into the layout
	ui.tab->setLayout(layout);	// set the layout that contains the viewport
	scene = new AnimicScene();	// create a scene, container for graphic objects 
	scene->setName("Scene 1");
	scene->setEntry(true);	// set as entry scene, aka the first scene during final preview 
	graphicsView->setSceneRect(QRectF(QPointF(0, 0), QPointF(800,600)));	// set viewport size to be a fixed 800 x 600, user determined size -> future work
	graphicsView->setScene(scene);	// set the scene into the viewport to be rendered
	graphicsView->setAcceptDrops(true);	// viewport accept drag and drop funtionality
	graphicsView->show();	// show the viewport

	connect(ui.playButton, &QPushButton::clicked, scene, &AnimicScene::playAll);	//connect scene to playback control buttons, to control video playback using buttons
	connect(ui.pauseButton, &QPushButton::clicked, scene, &AnimicScene::pauseAll);
	connect(ui.stopButton, &QPushButton::clicked, scene, &AnimicScene::stopAll);
	connect(scene, &AnimicScene::deletingVideo, this, &Animic::safeRemoveVideo);	// connect scene to helper function, to prevent dangling pointers and ensure safe deletion 
}

void Animic::connectSignalSlots()
{
	connect(ui.actionNewProject, &QAction::triggered, projectHandler->getNewProjectDialog(), &NewProjectDialog::exec);	// connect file->new project action button to intended function 

	connect(ui.SceneWindow, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));	// connect tab close to intended functions
	connect(ui.SceneWindow, SIGNAL(currentChanged(int)), this, SLOT(setCurrentScene(int)));	// connect changing tab widget to intended functions 
}

void Animic::setupTimeline()
{
	mainSlider = new AnimicSlider(ui.SliderHolder);	// This is the timeline slider

	QVBoxLayout* layout = new QVBoxLayout();	
	layout->addWidget(mainSlider);
	ui.SliderHolder->setLayout(layout);

	connect(mainSlider, SIGNAL(valueChanged(int)), scene, SLOT(setVideoFrameTime(int)));	// change video object frame when user is done sliding
	connect(scene, SIGNAL(objectInserted(qint64)), mainSlider, SLOT(onInsertVideo(qint64)));	// everytime user inserts a video, slider may change maximum duration
	connect(scene, &AnimicScene::foundNewMax, mainSlider, &AnimicSlider::onRemoveVideo);		//same thing for video removal

	//connect(scene, SIGNAL(subscribeTimeline(QMediaPlayer*)), mainSlider, SLOT(subscribeVideo(QMediaPlayer*)));	// allows the video object to change frame while sliding
																										//This works but comes with performance issue
}

void Animic::setupAssetHandler()
{
	assetHandler = new AssetHandler();	//a list widget that holds URL of the imported files
	ui.treeHolder->layout()->addWidget(assetHandler);	// tree holder is an empty ui placeholder, to reserve an empty space for the asset list widget
}

void Animic::setupProperties()
{
	propHandler = new PropertiesHandler();	//custom QWidget that holds a custom QWidget for scene properties and for videoObject (see SceneProperties & VideoProperties) 

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(propHandler);
	ui.propHolder->setLayout(layout);

	connect(scene, &AnimicScene::focusItemChanged, propHandler, &PropertiesHandler::objectFocusChanged);	// Listen for focus change to update corresponding text fields.  
	connect(this, &Animic::sceneChanged, propHandler, &PropertiesHandler::sceneChanged);	//list for scene change to update corresponding text fields
	propHandler->getScenePropertiesWidget()->updateProperties(scene->getName(), scene->isEntry());	// update text fiels with initial values
	propHandler->getScenePropertiesWidget()->manualConnect(scene);	//connect scene properties with various event listeners
}

void Animic::setupStitchingModule()
{
	stitchDialog = new StitchingDialog(sceneModel);	//a dialog window for stitching process

	connect(ui.actionStitching, &QAction::triggered, stitchDialog, &StitchingDialog::openDialog);	//allows the button to open the dialog
}

void Animic::setupListModel()
{
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(mainList);		//main list is the list "VIEW", the widget that displays the backend data from a custom data model
	ui.sceneListHolder->setLayout(layout);

	mainList->setModel(sceneModel);	//this is the custom data model (see SceneListModel @ ModelViewModule)
	mainList->setListMode(true);	// list mode true = allows modification of the list (rename, delete, etc.), false by default
	mainList->setItemDelegate(mainDelegate);	//delegate is the representation of each data, in this case it's just a simple text field

	sceneModel->appendRow(scene);	//adds the hard coded scene into the list model, to be removed when new project dialog functionalities are implemented

	connect(mainList, &AnimicListView::openNewSceneTab, this, &Animic::openNewTab);	// allows for opening new tab widget on double click
	connect(mainList, &AnimicListView::deleteScene, this, &Animic::onDeleteScene);	// allows for safe scene deletion and close tab widget if the scene is currently opened
	connect(stitchDialog, &StitchingDialog::closingDialog, this, &Animic::resetTabOnCloseDialog);	//this is to overcome a rendering deadlock bug
																									//deadlock occurs when main wnidow and stitching dialog 
																																			//display the same scene
																									//workaround: set all viewport to display nothing in main window 
																															//when going to stitching dialog and vice versa
}

void Animic::resetTabOnCloseDialog()	//work around for deadlock bug
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
					view->setScene(sceneModel->getList()->at(j));		//set the appropriate scene back to the viewport
				}
			}
		}
	}

	AnimicView* view = ui.SceneWindow->currentWidget()->findChild<AnimicView*>();

	if (view != nullptr)
	{
		AnimicScene* sc = qobject_cast<AnimicScene*>(view->scene());		//reconnect the scene
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

void Animic::setCurrentScene(int index)	// This function deals with scene connections when switching tab or closing tab
{
	if (currentTab != -1)		//check if the signal comes from deleting a scene or user switch tab
	{
		AnimicView* view = ui.SceneWindow->widget(currentTab)->findChild<AnimicView*>();	//find viewport in the current tab widget, nullptr if no conversion available
																																//or no viewport found

		if (view != nullptr)
		{
			AnimicScene* sc = dynamic_cast<AnimicScene*>(view->scene());	//find scene from the viewport, nullptr if no conversion available or no scene at all

			if (sc != nullptr)
			{
				sc->clearFocus();		//remove all connection to the non-active scene, reset non-active scene as well
				sc->clearSelection();
				sc->disconnectObject();
				sc->disconnect();
				disconnect(ui.playButton, &QPushButton::clicked, sc, &AnimicScene::playAll);
				disconnect(ui.pauseButton, &QPushButton::clicked, sc, &AnimicScene::pauseAll);
				disconnect(ui.stopButton, &QPushButton::clicked, sc, &AnimicScene::stopAll);
				disconnect(mainSlider, SIGNAL(valueChanged(int)), sc, SLOT(setVideoFrameTime(int)));
				propHandler->getScenePropertiesWidget()->onDisconnectScene(sc);
			}
		}
	}

	if (index >= 0)	// if there is an active tab, index will be > 0 
						//meaning either closing a tab and left with at least one active tab, or user simple switch to another tab
	{
		currentTab = index;
		AnimicView* view = ui.SceneWindow->currentWidget()->findChild<AnimicView*>();
		if (view != nullptr)
		{
			AnimicScene* scc = qobject_cast<AnimicScene*>(view->scene());
			if (scc != nullptr)
			{
				if (scc->getMaxPlayer() != nullptr)	//max player = the video object with the longest duration video
				{
					mainSlider->setMaximum(scc->getMaxPlayer()->duration()); //set slider to the maximum duration
				}

				propHandler->getScenePropertiesWidget()->updateProperties(scc->getName(), scc->isEntry()); //connect back all relevant connections to the current scene 
				connect(ui.playButton, &QPushButton::clicked, scc, &AnimicScene::playAll);
				connect(ui.pauseButton, &QPushButton::clicked, scc, &AnimicScene::pauseAll);
				connect(ui.stopButton, &QPushButton::clicked, scc, &AnimicScene::stopAll);
				connect(mainSlider, SIGNAL(valueChanged(int)), scc, SLOT(setVideoFrameTime(int)));
				connect(scc, &AnimicScene::deletingVideo, this, &Animic::safeRemoveVideo);
				connect(scc, SIGNAL(objectInserted(qint64)), mainSlider, SLOT(onInsertVideo(qint64)));
				connect(scc, &AnimicScene::foundNewMax, mainSlider, &AnimicSlider::onRemoveVideo);
				connect(scc, &AnimicScene::focusItemChanged, propHandler, &PropertiesHandler::objectFocusChanged);
				
				//connect layer list when implemented 

				emit sceneChanged(scc);	
			}
		}
	}
}

void Animic::onDeleteScene(AnimicScene* sc)	//for safe deletion
{
	for (int i = 0; i < ui.SceneWindow->count(); i++)
	{
		AnimicView* view = ui.SceneWindow->widget(i)->findChild<AnimicView*>();

		if (view != nullptr)
		{
			if (view->scene() == qobject_cast<AnimicScene*>(sc))
			{
				view->setScene(nullptr);		//remove active scene from viewport
				ui.SceneWindow->removeTab(i);
				break;
			}
		}
	}
	sceneModel->removeRows(mainList->currentIndex().row(), 1, QModelIndex());	//remove scene from list
	sc->disconnectObject();														//disconnect all video object
	sc->disconnect();															//disconnect all connections from this scene
	mainSlider->disconnect();													//disconnect timeline slider connection to this scene
	propHandler->getVideoPropertiesWidget()->resetItem();						//reset properties widget to display nothing
	propHandler->getScenePropertiesWidget()->onDisconnectScene(sc);				//disconnect properties widget
	sc->clear();																//remove all video object from scene

	QList<AnimicScene*> list = *sceneModel->getList();

	for (int i = 0; i < list.size(); i++)
	{
		list.at(i)->resetTriggerNextScene(sc);		//remove any pointers towards the deleted scene
	}
}

void Animic::safeRemoveVideo()	//the name says it all
{
	mainSlider->disconnect();									
	mainSlider->setMaximum(0);
	propHandler->getVideoPropertiesWidget()->resetItem();
}

#pragma endregion 

#pragma region Ui Functions

void Animic::on_btnImportAsset_clicked()	//import a single video file
{
	assetHandler->importAsset();
}

void Animic::on_btnImportDir_clicked()	//import a directory containing all the assets 
{
	assetHandler->importDirectory();
}

void Animic::on_btnDeleteAsset_clicked()	//remove asset item from asset list widget
{
	assetHandler->deleteAsset();
}

void Animic::closeTab(int index)	//close tab funtionalities
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

void Animic::on_stitchButton_clicked()	// push button to open stitching dialog window
{
	for (int i = 0; i < ui.SceneWindow->count(); i++)							
	{
		AnimicView* view = ui.SceneWindow->widget(i)->findChild<AnimicView*>();

		if (view != nullptr)
		{
			view->setScene(nullptr);   //workaround to prevent app freeze by removing all active scene from viewport in main window
		}
	}

	sceneModel->setSceneToStitchMode();	// change all scene behaviour to stitching mode (can't drag video object around, etc.)
	stitchDialog->openDialog();
}

void Animic::on_actionNewScene_triggered() //action button for new scene, file -> new scene, same function as on_newSceneButton_clicked
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

void Animic::on_newSceneButton_clicked()			// push button version of creating new scene
{
	QWidget* widget = new QWidget(ui.SceneWindow);				

	AnimicScene* sc = new AnimicScene();										// create a new scene instance
	AnimicView* view = new AnimicView(widget, 0);								// create a viewport for the scene
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);
	widget->setLayout(layout);

	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	view->setScene(sc);
	view->setAcceptDrops(true);
	view->show();

	sceneModel->appendRow(sc);													//add a reference pointer to the scene instance to the list model
	int num = sceneModel->getList()->count();									// manual scene number count for scene display name purposes
	sc->setName(QString("Scene " + QString::number(num)));

	ui.SceneWindow->addTab(widget, sc->getName());
}


void Animic::openNewTab(AnimicScene* sc)
{
	QWidget* widget = new QWidget(ui.SceneWindow);					// create a QWidget to be added to the tab widget
	AnimicView* view = new AnimicView(widget, 0);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);
	widget->setLayout(layout);

	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	view->setScene(sc);
	view->setAcceptDrops(true);
	view->show();
	ui.SceneWindow->addTab(widget, sc->getName());		//set tab widget display name
}

void Animic::on_removeSceneButton_clicked()
{
	if (mainList->currentIndex().row() > -1)
	{
		QMetaObject::invokeMethod(mainList, "onDeleteScene");		//delete scene funtionalities
	}
}
#pragma endregion

void Animic::debug()
{

}