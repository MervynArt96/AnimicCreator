#pragma once

#include "PropertiesModule/VideoProperties.h"
#include "CanvasModule/AnimicScene.h"
#include <PropertiesModule/SceneProperties.h>

class PropertiesHandler : public QWidget
{
	Q_OBJECT

public:

	PropertiesHandler();
	~PropertiesHandler();

	VideoProperties* getVideoPropertiesWidget();
	SceneProperties* getScenePropertiesWidget();

private:
	
	SceneProperties* sceneProperties;
	VideoProperties* videoProperties;

signals:

	void objectFocusChanged(QGraphicsItem* newFocusItem, QGraphicsItem* oldFocusItem, Qt::FocusReason reason);
	void sceneChanged(AnimicScene*);

public slots:
	
	void onSceneChanged(AnimicScene*);
};

