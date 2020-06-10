#include "stdafx.h"
#include "PropertiesHandler.h"

PropertiesHandler::PropertiesHandler()
{
	sceneProperties = new SceneProperties(nullptr);
	videoProperties = new VideoProperties(nullptr);
	QGridLayout* baseLayout = new QGridLayout();

	baseLayout->setMargin(0);

	baseLayout->addWidget(sceneProperties, 0, 0);
	baseLayout->addWidget(videoProperties, 1, 0);

	setLayout(baseLayout);

	connect(this, &PropertiesHandler::objectFocusChanged, videoProperties, &VideoProperties::onFocusChanged);
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
