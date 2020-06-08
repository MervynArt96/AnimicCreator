#include "stdafx.h"
#include "PreviewDialog.h"

PreviewDialog::PreviewDialog(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);

	engine = new PlaybackEngineCore();
	view = new AnimicView(this);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);

	ui.viewHolder->setLayout(layout);
	connect(engine, &PlaybackEngineCore::playNextScene, this, &PreviewDialog::onPlayNextScene);
	connect(engine, &PlaybackEngineCore::terminatePreview, this, &PreviewDialog::onTerminatePreview);
}

PreviewDialog::~PreviewDialog()
{

}

void PreviewDialog::closeDialog()
{
	for (int i = 0; i < engine->getList().count(); i++) //reset all scenes here
	{
		engine->getList().at(i)->deactivateTrigger();
		engine->getList().at(i)->stopAll();
	}

	view->setScene(nullptr);
	emit closeDialogSignal();
	QDialog::reject();
}


void PreviewDialog::openDialog(QList<AnimicScene*> scList)
{
	engine->setList(scList);
	for (int i = 0; i < engine->getList().count(); i++) //reset all scenes here
	{
		engine->getList().at(i)->deactivateTrigger();
		engine->getList().at(i)->stopAll();
	}
	engine->playback();
	this->move(200, 50);
	this->exec();
}

/*
void PreviewDialog::keyPressEvent(QKeyEvent* e)
{
	QDialog::keyPressEvent(e);
	qDebug() << "KeyPressing in Dialog";
	if (e->key() == Qt::Key::Key_Escape)
	{
		onTerminatePreview();
	}
}*/

void PreviewDialog::onTerminatePreview()
{
	//maybe need do some stuff here

	closeDialog();
}

void PreviewDialog::onPlayNextScene(AnimicScene* sc)
{
	sc->disableTrigger();
	qDebug() << "PlayBacking";
	view->setScene(sc);

	connect(sc, &AnimicScene::lastScene, engine, &PlaybackEngineCore::terminatePreview);
	connect(sc, &AnimicScene::nextScene, engine, &PlaybackEngineCore::onNextScene);

	sc->playThrough();
}