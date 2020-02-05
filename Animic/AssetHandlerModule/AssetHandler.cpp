#include "stdafx.h"
#include "AssetHandler.h"


AssetHandler::AssetHandler()
{
	fsModel = new QFileSystemModel();
	assetList = new QList<QFileInfo>();
	assetTree = nullptr;
}

AssetHandler::~AssetHandler()
{
	delete fsModel;
	delete assetList;
	delete assetTree;
}

void AssetHandler::assignTreeView(QTreeView* tree)
{
	assetTree = tree;
	assetTree->setModel(fsModel);
}

void AssetHandler::importAsset()
{
	QFileDialog* fileDialog = new QFileDialog();

	QStringList filters;
	filters << "Video files (*.mp4 *.avi *.wmv)" << "Image files (*.png *.jpg)";
	fileDialog->setNameFilters(filters);

	QStringList fileNames;
	QList<QUrl> filePaths;
	QList<qint64> fileSize;

	if (fileDialog->exec())	//dialog accepts user input
	{
		assetList->append(fileDialog->getOpenFileName());
	}
}

void AssetHandler::importAssetFolder()
{
	QFileDialog* fileDialog = new QFileDialog();
	fileDialog->setFileMode(QFileDialog::Directory);

	QDir* dir = new QDir();
	QStringList dirPaths;

	if (fileDialog->exec())	//dialog accepts user input
	{
		
			
	}
}

void AssetHandler::removeAsset()
{
	
}

void AssetHandler::removeAssetFolder()
{
	
}

void AssetHandler::getAssetInfo()
{
	//for (int i = 0; i < assetList->length - 1; i++)
	{
		
	}
}

QString AssetHandler::getFilePath()
{
	//return file path from user selected item in asset tree view 
	return NULL;
}

