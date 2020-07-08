#include "stdafx.h"
#include "PropertiesHandler.h"

PropertiesHandler::PropertiesHandler()		// a container widget for both scene properties and video properties,a middle man to connect the objects and this properties
{
	sceneProperties = new SceneProperties(nullptr);		//initializatin
	videoProperties = new VideoProperties(nullptr);
	QGridLayout* baseLayout = new QGridLayout();

	baseLayout->setMargin(0);

	baseLayout->addWidget(sceneProperties, 0, 0);
	baseLayout->addWidget(videoProperties, 1, 0);

	setLayout(baseLayout);

	connect(this, &PropertiesHandler::objectFocusChanged, videoProperties, &VideoProperties::onFocusChanged);	//the middle man connection
	connect(this, &PropertiesHandler::sceneChanged, sceneProperties, &SceneProperties::onChangeScene);

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
