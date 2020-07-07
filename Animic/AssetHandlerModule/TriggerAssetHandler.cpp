#include "stdafx.h"
#include "TriggerAssetHandler.h"

TriggerAssetHandler::TriggerAssetHandler(QObject *parent)	//reused class from AssetHandler
{
	setHeaderLabels({ "Name" , "Path" });		// name of the file, path of the file
	setDragEnabled(true);						// allow user to drag the item into a scene
	viewport()->setAcceptDrops(true);			// accept drops directly from file explorer
	setDropIndicatorShown(true);				
}

TriggerAssetHandler::~TriggerAssetHandler()
{

}

void TriggerAssetHandler::importAsset()
{
	QFileDialog* fileDialog = new QFileDialog();
	QString filters = "Video files (*.mp4 *.avi);; Image files (*.png *.jpg)";

	fileDialog->setAcceptMode(QFileDialog::AcceptOpen);
	QList<QUrl> urls = fileDialog->getOpenFileUrls(this, tr("Import Asset"), tr(""), filters);	//open file dialog here

	if (!urls.isEmpty())	//dialog accepted input
	{
		for (QUrl url : urls)
		{
			QString temp = url.path();
			temp.remove(0, 1);		//trim url

			QTreeWidgetItem* item = new QTreeWidgetItem(this);		//create a tree item & add item by url
			item->setText(0, url.fileName());
			item->setIcon(0, QIcon(url.path()));
			item->setText(1, temp);		//display trimmed url
		}
	}
}

void TriggerAssetHandler::importDirectory()	//same as import asset, but for directories
{
	QFileDialog* fileDialog = new QFileDialog();
	fileDialog->setAcceptMode(QFileDialog::AcceptOpen);

	QUrl url = fileDialog->getExistingDirectory(this, tr("Import Directory"), tr(""), QFileDialog::ShowDirsOnly);

	if (!url.isEmpty())
	{
		QDir dir(url.toString());

		QTreeWidgetItem* item = new QTreeWidgetItem();
		item->setText(0, url.fileName());
		item->setIcon(0, QIcon(url.path()));

		this->addTopLevelItem(item);	//add a parent item
		item->setFlags(Qt::ItemIsDragEnabled | Qt::ItemIsEnabled);

		QFileInfoList fileList = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);	//dot = current folder, dotdot = previous folder, not relevant to end user

		for (QFileInfo info : fileList)		//list down all the asset within the folder
		{
			if (!info.isDir())
			{
				QTreeWidgetItem* child = new QTreeWidgetItem(item);
				child->setText(0, info.fileName());
				child->setIcon(0, QIcon(url.path()));
				child->setText(1, info.filePath());

				item->addChild(child);
			}
		}
		item->setExpanded(true);
	}
}

void TriggerAssetHandler::deleteAsset()
{
	QList<QTreeWidgetItem*> itemList = this->selectedItems();

	if (!itemList.isEmpty())
	{
		for (QTreeWidgetItem* item : itemList)	//<- this is foreach loop, change this to the usual for loop in future to use less memory
		{
			if (!item->parent()) //delete the entire directory
			{
				this->takeTopLevelItem(this->indexOfTopLevelItem(item));
			}
			else
			{
				if (item->parent()->isExpanded())	//delete child in an expanded folder
				{
					delete item;
				}
				else
				{
					this->removeItemWidget(item, 0);
				}
			}
		}
	}
}


//Drag Drop Functions

QString TriggerAssetHandler::mimeTypes()
{
	return QString("video/mp4;; video/avi;; video/wmv;; image/png;; image/jpeg;; text/uri-list");	//list of supported file types
}

QString TriggerAssetHandler::getMimeTypeFromFile(const QString filepath)
{
	return QMimeDatabase().mimeTypeForFile(filepath).name();	//get file type from a given path
}

void TriggerAssetHandler::mousePressEvent(QMouseEvent* event)
{
	QTreeWidget::mousePressEvent(event);	//base movePressEvent, additional functions below this line

	if (event->button() == Qt::LeftButton)
	{
		QDrag* drag = new QDrag(this);			//create a new drag event
		QMimeData* mimeData = new QMimeData;

		QTreeWidgetItem* selectedItem = this->currentItem();	//get selected item
		QList<QUrl> urlList;

		if (selectedItem != nullptr)
			urlList.append(selectedItem->data(1, Qt::ItemDataRole::DisplayRole).value<QUrl>());	//display role = read only, add url to mime data

		mimeData->setUrls(urlList);

		drag->setMimeData(mimeData);

		Qt::DropAction dropAction = drag->exec();
		qDebug() << mimeData->urls();
	}
}

void TriggerAssetHandler::dragMoveEvent(QDragMoveEvent* event)
{
	
}

void TriggerAssetHandler::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->hasUrls())
	{
		event->acceptProposedAction();		//only accept drop event with mimedata containing url 
	}
}


void TriggerAssetHandler::dropEvent(QDropEvent* event)
{
	if (event->source() != this)
	{
		const QMimeData* mimeData = event->mimeData();		// get mimedata from event source

		for (QUrl url : mimeData->urls())
		{
			QString temp = url.path();
			temp.remove(0, 1);	//trim url

			QTreeWidgetItem* item = new QTreeWidgetItem(this);
			item->setText(0, url.fileName());
			item->setText(1, temp);	//trimed url
		}
	}
}

void TriggerAssetHandler::dragLeaveEvent(QDragLeaveEvent* event)
{

}