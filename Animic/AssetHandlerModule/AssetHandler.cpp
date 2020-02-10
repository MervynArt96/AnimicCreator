#include "stdafx.h"
#include "AssetHandler.h"


AssetHandler::AssetHandler()
{
	assetList = new QList<QFileInfo>();
	assetTree = nullptr;
}

AssetHandler::~AssetHandler()
{
	delete assetList;
	delete assetTree;
}


