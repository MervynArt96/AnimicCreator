#include "stdafx.h"
#include "PreviewDialog.h"

PreviewDialog::PreviewDialog(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);

	engine = new PlaybackEngineCore();
	view = new AnimicView(nullptr);
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);

	ui.viewHolder->setLayout(layout);

}

PreviewDialog::~PreviewDialog()
{

}

void PreviewDialog::closeDialog()
{
	for (int i = 0; i < engine->getList().count(); i++)
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
	this->move(200, 50);
	this->exec();
}

void PreviewDialog::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == Qt::Key::Key_Escape)
	{
		closeDialog();
	}
}