#pragma once
#include <QTreeView>

class AssetHandler
{
public:
	
	AssetHandler();
	~AssetHandler();
	void importAsset();
	void removeAsset();
	void removeAssetFolder();
	void importAssetFolder();
	void assignTreeView(QTreeView*);
	QString getFilePath();
	void getAssetInfo();

private:

	QTreeView* assetTree;
	QFileSystemModel* fsModel;
	QList<QFileInfo>* assetList;
	
};

