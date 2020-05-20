#include "stdafx.h"
#include "PropertiesHandler.h"

PropertiesHandler::PropertiesHandler()
{
	QGridLayout* baseLayout = new QGridLayout();
	setLayout(baseLayout);

	baseLayout->addWidget(sceneProperties, 0, 0);
	baseLayout->addWidget(videoProperties, 1, 0);
}

PropertiesHandler::~PropertiesHandler()
{
	
}

VideoProperties* PropertiesHandler::getVideoPropertiesWidget()
{
	return videoProperties;
}

SceneProperties* PropertiesHandler::getScenePropertiesWidget()
{
	return sceneProperties;
}

void PropertiesHandler::onSceneChanged(AnimicScene*)
{
	disconnect();
	//connect back signal slots;
}

void PropertiesHandler::onFocusChanged(QGraphicsItem* newFocusItem, QGraphicsItem* oldFocusItem, Qt::FocusReason reason)
{
	VideoObject* obj = qgraphicsitem_cast<VideoObject*>(newFocusItem);	//this is assuming one type of supported object for now, to be expanded in future work
	if ( obj != nullptr)
	{
		//connect slots to this obj
	}
}