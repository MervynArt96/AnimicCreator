#pragma once
#include <QTreeWidgetItem>
#include <QDebug>

class AssetItem : public QTreeWidgetItem
{
public:
	AssetItem(QObject *parent);
	~AssetItem();

	/*void mousePressEvent(QMouseEvent*);
	void dragEvent(QDragMoveEvent* event);
	*/
};
