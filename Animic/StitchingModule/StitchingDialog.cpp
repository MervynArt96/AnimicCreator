#include "stdafx.h"
#include "StitchingDialog.h"

StitchingDialog::StitchingDialog(QListWidget* list)
{
	ui.setupUi(this);
	ui.SceneList = new QListWidget();
	refList = list;

}

StitchingDialog::~StitchingDialog()
{

}


void StitchingDialog::openDialog()
{
	ui.SceneList->clear();
	qDebug() << refList->count();

	for (int i = 0; i < refList->count(); i++)
	{
		qDebug() << refList->item(i)->text();
		ui.SceneList->addItem(refList->item(i));
	}

	this->exec();
}

