#include "stdafx.h"
#include "StitchingDialog.h"

StitchingDialog::StitchingDialog(SceneListWidget* list)
{
	ui.setupUi(this);
	//insert Scene list init here
	refList = list;

	AnimicView* view = new AnimicView(ui.previewWidget);
	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	view->setAcceptDrops(true);

	StitchingScene* scene = new StitchingScene();

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);

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

