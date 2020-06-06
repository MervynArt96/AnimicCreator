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
	this->clear();
}

void LayerList::onObjectInserted()
{
	//add layer item here
}

void LayerList::onChangeScene(AnimicScene* sc)
{
	clearItems();
	connect(sc, &AnimicScene::objectInserted, this, &LayerList::onObjectInserted);

	QList<QGraphicsItem*> list = sc->items();
	for (QGraphicsItem* item : list)
	{
		
	}
}


