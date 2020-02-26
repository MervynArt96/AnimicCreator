#pragma once
#include <QtWidgets/QMainWindow>
#include <QtCore>
#include <QtGui>
#include "ui_animic.h"
#include "ProjectHandler.h"
#include "CanvasModule/AnimicScene.h"
#include <QMediaPlayer>
#include <QDebug>
#include "CanvasModule/CanvasObject/VideoObject.h"
#include "AssetHandlerModule/AssetHandler.h"

class Animic : public QMainWindow
{
	Q_OBJECT

public:
	Animic(QWidget *parent = Q_NULLPTR);

	QFileSystemModel* fsModel;

	enum class dialogMode
	{
		fileMode,
		dirMode
	};

private:
	Ui::AnimicClass ui;
	void init();
	void connectSignalSlots();
	void setupScene();
	void setupTimeline();
	void setupAssetHandler();

	int sceneTabCount = 1;	//global var, for object naming

	ProjectHandler* projectHandler;			//modules
	AssetHandler* assetHandler;
	VideoObject* video = nullptr;
	QFileDialog* fileDialog;
	QGraphicsView* graphicsView;
	AnimicScene* scene;

	//test
	void addGraphic();

signals:


public slots:

	void on_btnImportAsset_clicked();
	void on_btnImportDir_clicked();
	void on_btnDeleteAsset_clicked();
};
