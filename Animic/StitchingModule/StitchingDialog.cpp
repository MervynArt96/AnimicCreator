#include "stdafx.h"
#include "StitchingDialog.h"

StitchingDialog::StitchingDialog(SceneListWidget* list)
{
	ui.setupUi(this);
	//insert Scene list init here
	refList = list;

	AnimicView* view = new AnimicView(ui.previewWidget);
	StitchingScene* scene = new StitchingScene();
	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	view->setAcceptDrops(true);

	QVBoxLayout* layout = new QVBoxLayout(view);

	ui.previewWidget->setLayout(layout);

}

StitchingDialog::~StitchingDialog()
{

}


void StitchingDialog::openDialog()
{
	qDebug() << refList->count();

	for (int i = 0; i < refList->count(); i++)
	{
		qDebug() << refList->item(i)->text();
		
	}

	this->exec();
}

