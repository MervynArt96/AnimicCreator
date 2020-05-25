#include "stdafx.h"
#include "StitchingDialog.h"

StitchingDialog::StitchingDialog(SceneListModel* model)
{
	ui.setupUi(this);
	
	QVBoxLayout* listLayout = new QVBoxLayout();

	sceneList = new AnimicListView();
	stitchDelegate = new SceneListDelegate(sceneList);


	listLayout->addWidget(sceneList);
	ui.listHolder->setLayout(listLayout);
	
	view = new AnimicView(ui.graphicsViewHolder);
	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	view->setAcceptDrops(true);

	dummy = new QGraphicsScene();
	view->setScene(dummy);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);

	ui.graphicsViewHolder->setLayout(layout);

	changedSceneList = new QModelIndexList();
	sceneList->setModel(model);
	sceneList->setItemDelegate(stitchDelegate);

	connect(sceneList, &AnimicListView::switchScene, this, &StitchingDialog::onSwitchScene);
}

StitchingDialog::~StitchingDialog()
{

}

void StitchingDialog::reject()
{
	view->setScene(dummy);
	//enable object dragging
	// disable trigger
	emit closingDialog();
	QDialog::reject();
}

void StitchingDialog::openDialog()
{
	view->setScene(dummy);
	this->move(200, 50);
	this->exec();
}

void StitchingDialog::onSwitchScene(AnimicScene* sc, QModelIndex index)
{
	qDebug() << "Switch scene";
	qDebug() << "SC : " << sc;
	qDebug() << "View SC: " << view->scene();
	//changedSceneList->append(index);
	view->setScene(sc);
}

