#include "stdafx.h"
#include "AssetHandler.h"


AssetHandler::AssetHandler()
{

}

AssetHandler::~AssetHandler()
{

}

void AssetHandler::importAsset()
{
	QFileDialog* fileDialog = new QFileDialog();

	QStringList filters;
	filters << "Video files (*.mp4 *.avi *.wmv)" << "Image files (*.png *.jpg)";
	fileDialog->setNameFilters(filters);
	
	QFileInfo* info = new QFileInfo();

	QStringList fileNames;
	QList<QUrl> filePaths;

	if (fileDialog->exec())
	{
		fileNames = fileDialog->selectedFiles();
		filePaths = fileDialog->getOpenFileUrls();
	}

}

void AssetHandler::importAssetFolder()
{
	QFileDialog* fileDialog = new QFileDialog();
	fileDialog->setFileMode(QFileDialog::Directory);

	QDir* dir = new QDir();
	QStringList dirPaths;


	if (fileDialog->exec())
	{

			
	}

}

void AssetHandler::deleteAsset()
{
	
}

void AssetHandler::assignTreeView(QTreeView* tree)
{
	assetTree = tree;
	//assetTree->setModel(fsModel);
}