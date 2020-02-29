#pragma once
#include <QtWidgets/QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QQmlComponent>
#include <QQuickWidget>
#include <QQmlProperty>
#include "ui_animic.h"

#include "ProjectManagementModule/ProjectHandler.h"
#include "CanvasModule/AnimicScene.h"
#include "CanvasModule/CanvasObject/VideoObject.h"
#include "AssetHandlerModule/AssetHandler.h"
#include "TimelineModule/Timeline.h"

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
	Timeline* timelineWidget;
	//QQuickWidget* timelineWidget;


	//test
	void addGraphic();

signals:


public slots:

	void on_btnImportAsset_clicked();
	void on_btnImportDir_clicked();
	void on_btnDeleteAsset_clicked();
};
