
#include "stdafx.h"
#include "animic.h"

Animic::Animic(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);
	init();
}

void Animic::init()
{
	projHandler = new ProjectHandler();
	assetHandler = new AssetHandler();
	assetHandler->assignTreeView(ui.AssetTreeView);
	connectSignalSlots();
}

void Animic::connectSignalSlots()
{
	connect(ui.actionNewProject, &QAction::triggered, projHandler->getNewProjectDialog(), &NewProjectDialog::exec); //Opens new project dialog, modal mode
}
