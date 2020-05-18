#include "stdafx.h"
#include "AnimicListView.h"

AnimicListView::AnimicListView()
{
	setMovement(QListView::Free);
	setEditTriggers(EditTrigger::EditKeyPressed);
	setContextMenuPolicy(Qt::CustomContextMenu);

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

void AnimicListView::mousePressEvent(QMouseEvent* event)
{
	QAbstractItemView::mousePressEvent(event);
	if (event->button() == Qt::RightButton)
	{

	}
}

void AnimicListView::onDoubleClicked(const QModelIndex& index)
{
	//override edit?
	if (mode)
	{
		qDebug() << this->model()->data(index, Qt::DisplayRole);
		//get scene from list
		//create new tab, set active tab if haven't
		//create new animic view
		//set sceneRect
		//connect playback buttons, layer, properties, slider
	}
	else
	{
		qDebug() << this->model()->data(index, Qt::DisplayRole);
	}
}

void AnimicListView::showContextMenu(const QPoint& pos)
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
		for (int i = 0; i < selectedIndexes().size();i ++)
		{
			//remove current scene from main view 
			//close tab
			//disconnect from slider, 
				//playback buttons, 
				//layer, 
				//properties
			setCurrentIndex(selectedIndexes()[i]);
			model()->removeRows(selectedIndexes()[i].row(), 1, QModelIndex());
		}
	}
}
