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
#include "CanvasModule/AnimicView.h"
#include "PropertiesModule/PropertiesHandler.h"
#include "TimelineModule/AnimicSlider.h"
#include "ModelViewModule/AnimicListView.h"
#include "ModelViewModule/SceneListModel.h"
#include "ModelViewModule/SceneListDelegate.h"
#include <LayerModule\LayerList.h>

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
	void setupTimeline();
	void setupListModel();
	void setupProperties();

	int sceneTabCount = 1;	//global var, for object naming, might not need

	ProjectHandler* projectHandler;			
	AssetHandler* assetHandler;
	QFileDialog* fileDialog;
	StitchingDialog* stitchDialog;
	PropertiesHandler* propHandler;
	LayerList* layerList;

	AnimicSlider* mainSlider;

	AnimicListView* mainList = new AnimicListView();
	AnimicListView* stitchList = new AnimicListView();
	SceneListModel* sceneModel = new SceneListModel();
	SceneListDelegate* mainDelegate = new SceneListDelegate(this);
	SceneListDelegate* stitchDelegate = new SceneListDelegate(this);

	AnimicView* graphicsView;		//to skip new project
	AnimicScene* scene;

signals:


public slots:
	
	void on_btnImportAsset_clicked();
	void on_btnImportDir_clicked();
	void on_btnDeleteAsset_clicked();
	void on_actionNewScene_triggered();

	void closeTab(int);
	void setCurrentScene(int);

	void debug();
	
};
