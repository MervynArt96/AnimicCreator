#pragma once
#include <QTreeView>
#include <QDebug>

class AssetHandler
{
public:
	
	AssetHandler();
	~AssetHandler();

	void assignTreeView(QTreeView*);
	QString getFilePath();
	void getAssetInfo();
	

private:

	QTreeView* assetTree;
	QFileSystemModel* fsModel;
	QList<QFileInfo>* assetList;

signals:



public slots:

};

