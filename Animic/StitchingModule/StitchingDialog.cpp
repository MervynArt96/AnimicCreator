#include "stdafx.h"
#include "StitchingDialog.h"

StitchingDialog::StitchingDialog(AnimicListView* listView, SceneListModel* model)
{
	ui.setupUi(this);
	
	QVBoxLayout* listLayout = new QVBoxLayout();
	listLayout->addWidget(listView);
	ui.listHolder->setLayout(listLayout);
	
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
	

	this->exec();
}

