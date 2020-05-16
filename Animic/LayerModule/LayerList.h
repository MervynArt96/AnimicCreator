#pragma once

#include <QListWidget>

class LayerList : public QListWidget
{
	Q_OBJECT

public:
	LayerList(QWidget *parent);
	~LayerList();

	void clearItems();

signals:

	void removeSceneObject();

public slots:

	void onObjectInserted();


};
