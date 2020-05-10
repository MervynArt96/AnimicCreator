#include "stdafx.h"
#include "AssetHandler.h"


AssetHandler::AssetHandler()
{
	setHeaderLabels({ "Name" , "Path" });
	//setSelectionMode(QAbstractItemView::MultiSelection);
	setDragEnabled(true);
	viewport()->setAcceptDrops(true);
	setDropIndicatorShown(true);
}

AssetHandler::~AssetHandler()
{

}

void AssetHandler::importAsset()
{
	QFileDialog* fileDialog = new QFileDialog();
	QString filters = "Video files (*.mp4 *.avi);; Image files (*.png *.jpg)";

	fileDialog->setAcceptMode(QFileDialog::AcceptOpen);
	QList<QUrl> urls = fileDialog->getOpenFileUrls(this, tr("Import Asset"), tr(""), filters);

	if (!urls.isEmpty())	//dialog accepted input
	{
		for (QUrl url : urls)
		{
			QString temp = url.path();
			temp.remove(0, 1);

			QTreeWidgetItem* item = new QTreeWidgetItem(this);
			item->setText(0, url.fileName());
			item->setIcon(0, QIcon(url.path()));
			item->setText(1, temp);
		}
	}
}

void AssetHandler::importDirectory()
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

		this->addTopLevelItem(item);
		item->setFlags(Qt::ItemIsDragEnabled | Qt::ItemIsEnabled);

		QFileInfoList fileList = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

		for (QFileInfo info : fileList)
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

void AssetHandler::deleteAsset()
{
	QList<QTreeWidgetItem*> itemList = this->selectedItems();

	if (!itemList.isEmpty())
	{
		for (QTreeWidgetItem* item : itemList)
		{
			if (!item->parent()) //dir
			{
				this->takeTopLevelItem(this->indexOfTopLevelItem(item));
			}
			else
			{
				if (item->parent()->isExpanded())	//child file
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

QString AssetHandler::mimeTypes()
{
	return QString("video/mp4;; video/avi;; video/wmv;; image/png;; image/jpeg;; text/uri-list");
}

QString AssetHandler::getMimeTypeFromFile(const QString filepath)
{
	return QMimeDatabase().mimeTypeForFile(filepath).name();
}

void AssetHandler::mousePressEvent(QMouseEvent* event)
{
	QTreeWidget::mousePressEvent(event);

	if (event->button() == Qt::LeftButton) 
	{
		QDrag* drag = new QDrag(this);
		QMimeData* mimeData = new QMimeData;

		QTreeWidgetItem* selectedItem = this->currentItem();
		QList<QUrl> urlList;

		if(selectedItem != nullptr)
			urlList.append(selectedItem->data(1, Qt::ItemDataRole::DisplayRole).value<QUrl>());

		mimeData->setUrls(urlList);

		drag->setMimeData(mimeData);

		Qt::DropAction dropAction = drag->exec();
		qDebug() << mimeData->urls();
	}
}

void AssetHandler::dragMoveEvent(QDragMoveEvent* event)
{

}

void AssetHandler::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->hasUrls())
	{
		event->acceptProposedAction();
	}
}


void AssetHandler::dropEvent(QDropEvent* event)
{
	if (event->source() != this)
	{
		const QMimeData* mimeData = event->mimeData();

		QString format = event->mimeData()->formats().at(0);
		QByteArray data = event->mimeData()->data(format);
		QDataStream stream(&data, QIODevice::ReadOnly);

		for (QUrl url : mimeData->urls())
		{
			QString temp = url.path();
			temp.remove(0, 1);

			QTreeWidgetItem* item = new QTreeWidgetItem(this);
			item->setText(0, url.fileName());
			item->setText(1, temp);	//trim here

			//check type here
		}
	}
}

void AssetHandler::dragLeaveEvent(QDragLeaveEvent* event)
{

}


