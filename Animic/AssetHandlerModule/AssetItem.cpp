#include "stdafx.h"
#include "AssetItem.h"

AssetItem::AssetItem(QObject *parent)
{

}

AssetItem::~AssetItem()
{

}

/*
void AssetItem::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		QModelIndexList index;

		QDrag* drag = new QDrag(;
		QMimeData* mimeData = new QMimeData;

		mimeData->setUrls();
		drag->setMimeData(mimeData);

		Qt::DropAction dropAction = drag->exec();
	}
}

void AssetItem::dragEvent(QDragMoveEvent* event)
{
	const QMimeData* mimeData = event->mimeData();

	qDebug() << mimeData->urls();
	qDebug() << mimeData->data(mimeUrl()[0]);
}*/