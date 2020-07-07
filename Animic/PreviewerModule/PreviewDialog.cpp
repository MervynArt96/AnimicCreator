#include "stdafx.h"
#include "PreviewDialog.h"

PreviewDialog::PreviewDialog(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);

	endScene = new QGraphicsScene();				// A dummy scene to be shown after preview has reached the end
	endText = new QGraphicsTextItem("End Scene");	
	endScene->addItem(endText);

	endText->setScale(5);

	engine = new PlaybackEngineCore();
	view = new AnimicView(this, 1);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);

	ui.viewHolder->setLayout(layout);
	connect(engine, &PlaybackEngineCore::playNextScene, this, &PreviewDialog::onPlayNextScene);			//connect engine to required functionalities
	connect(engine, &PlaybackEngineCore::terminatePreview, this, &PreviewDialog::onTerminatePreview);
	connect(engine, &PlaybackEngineCore::disableSpace, this, &PreviewDialog::onDisableSpace);
	connect(view, &AnimicView::startPreview, engine, &PlaybackEngineCore::playback);
}

PreviewDialog::~PreviewDialog()
{

}

void PreviewDialog::closeEvent(QCloseEvent* e)
{
	disconnect(view, &AnimicView::startPreview, engine, &PlaybackEngineCore::playback);		//disconnect the playback engine
	closeDialog();
}

void PreviewDialog::showEvent(QShowEvent* e)
{
	QDialog::showEvent(e);
}

void PreviewDialog::onDisableSpace()
{
	disconnect(view, &AnimicView::startPreview, engine, &PlaybackEngineCore::playback);	//prevents user from press space multiple times
}

void PreviewDialog::closeDialog()
{
	for (int i = 0; i < engine->getList().count(); i++) //reset all scenes here
	{
		engine->getList().at(i)->deactivateTrigger();
		engine->getList().at(i)->stopAll();
		engine->getList().at(i)->disengageLoopingVideo();
	}

	view->setScene(nullptr);
	emit closeDialogSignal();	//to reset stitching dialog
	QDialog::reject();
}


void PreviewDialog::openDialog(QList<AnimicScene*> scList)
{
	engine->setList(scList);
	for (int i = 0; i < engine->getList().count(); i++) //reset all scenes here
	{
		engine->getList().at(i)->disableTrigger();
		engine->getList().at(i)->disableObjectDragging();
		engine->getList().at(i)->stopAll();
	}
	connect(view, &AnimicView::startPreview, engine, &PlaybackEngineCore::playback);
	view->setScene(nullptr);
	ui.sceneName->setText("Scene Name");
	this->move(200, 50);
	this->exec();
}

void PreviewDialog::onTerminatePreview()
{
	view->setScene(endScene);
	ui.sceneName->setText("End of Scene");	//just a status text at the bottom right corner
	connect(view, &AnimicView::startPreview, engine, &PlaybackEngineCore::playback);	//reconenct back the space bar, to allow user to start playback again
}

void PreviewDialog::onPlayNextScene(AnimicScene* sc)
{
	connect(sc, &AnimicScene::lastScene, engine, &PlaybackEngineCore::terminatePreview);	//connect the logic to determine if the preview should continue
	connect(sc, &AnimicScene::nextScene, engine, &PlaybackEngineCore::onNextScene);

	sc->disableTrigger();			//set up the scene for preview
	sc->disengageLoopingVideo();
	view->setScene(sc);
	ui.sceneName->setText(sc->getName());

	sc->playThrough();	//plays the scene here
}