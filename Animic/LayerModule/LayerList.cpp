#include "stdafx.h"
#include "LayerList.h"

LayerList::LayerList(QWidget *parent): QListWidget(parent)
{
	setDragDropMode(QAbstractItemView::InternalMove);
}

LayerList::~LayerList()
{

}

void LayerList::clearItems()
{
	qDeleteAll(selectedItems());
}
