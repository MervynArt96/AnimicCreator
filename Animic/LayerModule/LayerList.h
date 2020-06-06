#pragma once

#include <QListWidget>
#include <CanvasModule\AnimicScene.h>

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
	void onChangeScene(AnimicScene* sc);

};
