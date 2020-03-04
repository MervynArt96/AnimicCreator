#include "stdafx.h"
#include "SceneAssetItem.h"

SceneAssetItem::SceneAssetItem(QString name,QListWidget* parent): QListWidgetItem(name, parent)
{

}

SceneAssetItem::~SceneAssetItem()
{
}


void SceneAssetItem::onObjectInserted(AssetType type, QUrl)
{
	if (type == AssetType::Video)
	{
		
		
	}

}

void SceneAssetItem::onObjectRemoved(AssetType, QUrl)
{

}
