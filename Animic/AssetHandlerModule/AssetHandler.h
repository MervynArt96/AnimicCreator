#pragma once
#include <QTreeView>

class AssetHandler
{
public:
	
	AssetHandler();
	~AssetHandler();
	void importAsset();
	void deleteAsset();
	void importAssetFolder();
	void assignTreeView(QTreeView*);

private:

	struct AssetConfig {
		
		QString fileName;
		QString filePath;
		
	};

	QTreeView* assetTree;
	QFileSystemModel* fsModel;
	QList<AssetConfig>* assetList;
	
};

