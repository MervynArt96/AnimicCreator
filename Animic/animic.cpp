
#include "stdafx.h"
#include "animic.h"

Animic::Animic(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);
	init();

}

void Animic::init()
{
	projHandler = new ProjectHandler();

	setupScene();
	setupTimeline();
	setupAssetHandler();

	QString videoName = "D:/My Documents/Videos/singsing.mp4";
	video = new VideoObject(videoName);
	player = video->getPlayer();

	scene->addItem(video);

	connectSignalSlots();
}

void Animic::setupScene()	//set up graphics scene and canvas
{
	graphicsView = new QGraphicsView();
	ui.tab->layout()->addWidget(graphicsView);
	graphicsView->adjustSize();
	scene = new QGraphicsScene();
	graphicsView->setScene(scene);
	graphicsView->show();
}

void Animic::setupTimeline()
{

}

void Animic::connectSignalSlots()
{
	connect(ui.actionNewProject, &QAction::triggered, projHandler->getNewProjectDialog(), &NewProjectDialog::exec);

}

void Animic::setupAssetHandler()
{
	QStringList headerList = { "Name" , "Path"};
	ui.assetTree->setHeaderLabels(headerList);
	ui.assetTree->setSelectionMode(QAbstractItemView::MultiSelection);
	
}

//Debug functions

void Animic::addGraphic()
{
	QColor color = Qt::blue;
	QBrush brush = Qt::SolidPattern;
	brush.setColor(color);


	QGraphicsRectItem* item = new QGraphicsRectItem(0, 0, 100, 100);
	item->setFlag(QGraphicsItem::ItemIsMovable);
	item->setBrush(brush);

	scene->addItem(item);

}


//ui functions

void Animic::on_btnImportAsset_clicked()
{
	QFileDialog* fileDialog = new QFileDialog();
	QString filters = "Video files (*.mp4 *.avi *.wmv);; Image files (*.png *.jpg)";

	fileDialog->setAcceptMode(QFileDialog::AcceptOpen);
	QList<QUrl> urls = fileDialog->getOpenFileUrls(this, tr("Import Asset"), tr(""), filters);

	if (!urls.isEmpty())	//dialog accepted input
	{
		for(QUrl url : urls)
		{
			QTreeWidgetItem* item = new QTreeWidgetItem(ui.assetTree);
			item->setText(0, url.fileName());
			item->setIcon(0, QIcon(url.path()));
			item->setText(1, url.path());
		}
	}

	//might need to keep track of path?
}

void Animic::on_btnImportDir_clicked()
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

		ui.assetTree->addTopLevelItem(item);
		
		QFileInfoList fileList = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);


		for (QFileInfo info : fileList)
		{
			QTreeWidgetItem* child = new QTreeWidgetItem(item);
			child->setText(0, info.fileName());
			child->setIcon(0, QIcon(url.path()));
			child->setText(1, info.path());

			item->addChild(child);
		}
		item->setExpanded(true);
	}
}

void Animic::on_btnDeleteAsset_clicked()
{
	QList<QTreeWidgetItem*> itemList = ui.assetTree->selectedItems();

	if (!itemList.isEmpty())
	{
		for (QTreeWidgetItem* item : itemList)
		{
			if (!item->parent()) //dir
			{
				ui.assetTree->takeTopLevelItem(ui.assetTree->indexOfTopLevelItem(item));
			}
			else
			{
				if (item->parent()->isExpanded())	//child file
				{
					delete item;
				}
				else
				{
					ui.assetTree->removeItemWidget(item, 0);
				}
			}
		}
	}
}