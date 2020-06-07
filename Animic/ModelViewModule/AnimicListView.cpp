#include "stdafx.h"
#include "AnimicListView.h"

AnimicListView::AnimicListView()
{
	setMovement(QListView::Free);
	setEditTriggers(EditTrigger::EditKeyPressed);
	setContextMenuPolicy(Qt::CustomContextMenu);
	setSelectionMode(QAbstractItemView::SingleSelection);

	connect(this, &AnimicListView::doubleClicked, this, &AnimicListView::onDoubleClicked);
	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)),this, SLOT(showContextMenu(const QPoint&)));
}

AnimicListView::~AnimicListView()
{

}

void AnimicListView::setListMode(bool x)
{
	mode = x; //true = main, false = stitch
}

void AnimicListView::onDoubleClicked(const QModelIndex& index)
{
	if (mode)
	{
		emit openNewSceneTab(qvariant_cast<AnimicScene*>(model()->data(index, Qt::BackgroundRole)), index);
	}
	else
	{
		emit switchScene(qvariant_cast<AnimicScene*>(model()->data(index, Qt::BackgroundRole)), index);
	}
}

void AnimicListView::showContextMenu(const QPoint& pos)
{
	if (mode)
	{
		QMenu contextMenu(tr("Context menu"), this);

		QAction renameAction("Rename Scene", this);
		connect(&renameAction, SIGNAL(triggered()), this, SLOT(onRenameScene()));
		contextMenu.addAction(&renameAction);

		QAction deleteAction("Delete Scene", this);
		connect(&deleteAction, SIGNAL(triggered()), this, SLOT(onDeleteScene()));
		contextMenu.addAction(&deleteAction);

		contextMenu.exec(mapToGlobal(pos));
	}
}


void AnimicListView::onRenameScene()
{
	if (selectedIndexes().size() > 0)
	{
		for (int i = 0; i < selectedIndexes().size(); i++)
		{
			setCurrentIndex(selectedIndexes()[i]);
			edit(currentIndex());
		}
	}
}

void AnimicListView::onDeleteScene()
{
	if (selectedIndexes().size() > 0)
	{
		emit deleteScene(qvariant_cast<AnimicScene*>(currentIndex().data(Qt::BackgroundRole)));
	}
}


void AnimicListView::getScene(int i)
{
	emit returnSceneToTrigger(qobject_cast<SceneListModel*>(this->model())->getList()->at(i));
}