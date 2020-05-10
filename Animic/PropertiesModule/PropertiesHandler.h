#pragma once

#include "PropertiesModule/VideoProperties.h"
#include <PropertiesModule/SceneProperties.h>

class PropertiesHandler : public QWidget
{
	Q_OBJECT

public:

	enum ObjectType {
		Video, Image, Dialogue
	};


	PropertiesHandler();
	~PropertiesHandler();

	VideoProperties* getVideoPropertiesWidget();

	void changePropertiesType();

private:
	
	SceneProperties* sceneProperties;
	VideoProperties* videoProperties;
	//ImageProperties
	//AudioProperties
	//TextProperties

public slots:

	void updateCurrentProperties();

};

