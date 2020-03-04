#pragma once
#include <QtWidgets/QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include "ui_animic.h"

#include "ProjectManagementModule/ProjectHandler.h"
#include "CanvasModule/AnimicScene.h"
#include "AssetHandlerModule/AssetHandler.h"
#include "StitchingModule/StitchingDialog.h"
#include "SceneHandlerModule/SceneAssetItem.h"

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
	void setupAssetHandler();
	void setupStitchingModule();

	void setupDemo();

	int sceneTabCount = 1;	//global var, for object naming

	ProjectHandler* projectHandler;			//modules
	AssetHandler* assetHandler;
	VideoObject* video = nullptr;
	QFileDialog* fileDialog;
	QGraphicsView* graphicsView;
	AnimicScene* scene;
	StitchingDialog* stitchDialog;

signals:


public slots:
	
	void on_btnImportAsset_clicked();
	void on_btnImportDir_clicked();
	void on_btnDeleteAsset_clicked();

	void on_actionNewScene_triggered();

	void closeTab(int);
	
};
