#include "stdafx.h"
#include "PropertiesHandler.h"

PropertiesHandler::PropertiesHandler()
{
	QGridLayout* baseLayout = new QGridLayout();
	setLayout(baseLayout);

}

PropertiesHandler::~PropertiesHandler()
{
	
}


VideoProperties* PropertiesHandler::getVideoPropertiesWidget()
{
	return videoProperties;
}

void PropertiesHandler::changePropertiesType()
{

}

void PropertiesHandler::updateCurrentProperties()
{

}