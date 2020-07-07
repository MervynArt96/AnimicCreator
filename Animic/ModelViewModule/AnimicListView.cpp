#include "stdafx.h"
#include "AnimicListView.h"

AnimicListView::AnimicListView() 	//One of the Model-View Controller component, this is the view
{
	setMovement(QListView::Free);	//can be rearranged
	setEditTriggers(EditTrigger::EditKeyPressed);	//allows for editing list item
	setContextMenuPolicy(Qt::CustomContextMenu);	//right click context menu
	setSelectionMode(QAbstractItemView::SingleSelection);	//can only select one item at a time

	connect(this, &AnimicListView::doubleClicked, this, &AnimicListView::onDoubleClicked);		//listen for double click
	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)),this, SLOT(showContextMenu(const QPoint&)));	//listen for right click
}

AnimicListView::~AnimicListView()
{

}

void AnimicListView::setListMode(bool x)
{
	mode = x; //true = list view at the main window, false = list view at the stitching dialog
}

void AnimicListView::onDoubleClicked(const QModelIndex& index)
{
	if (mode) //for main window
	{
		emit openNewSceneTab(qvariant_cast<AnimicScene*>(model()->data(index, Qt::BackgroundRole)), index);	//tell the model to open the scene in a new tab based on index
	}
	else // for stitching dialog 
	{
		emit switchScene(qvariant_cast<AnimicScene*>(model()->data(index, Qt::BackgroundRole)), index); //tell the model to switch the old scene in a hard coded viewport to this current one
	}
}

void AnimicListView::showContextMenu(const QPoint& pos) //right click menu here
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


void AnimicListView::onRenameScene()	//rename a scene in the list
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

void AnimicListView::onDeleteScene()	//delete a scene from the list
{
	if (selectedIndexes().size() > 0)
	{
		emit deleteScene(qvariant_cast<AnimicScene*>(currentIndex().data(Qt::BackgroundRole)));
	}
}


void AnimicListView::getScene(int i)	//return a scene from the list
{
	emit returnSceneToTrigger(qobject_cast<SceneListModel*>(this->model())->getList()->at(i));
}