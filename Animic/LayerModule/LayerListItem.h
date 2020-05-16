#pragma once

#include <QListWidgetItem>

class LayerListItem : public QListWidgetItem
{
	Q_OBJECT

public:
	LayerListItem(QWidget *parent);
	~LayerListItem();
};
