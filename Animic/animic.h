#pragma once
#include <QtWidgets/QMainWindow>
#include <QtCore>
#include <QtGui>
#include "ui_animic.h"
#include "ProjectHandler.h"
#include "CanvasModule/Scene.h"
#include <QMediaPlayer>
#include <QDebug>
#include "CanvasModule/CanvasObject/VideoObject.h"


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

	ProjectHandler* projHandler;			//modules
	Scene* canvas = nullptr;
	QGraphicsView* sceneView = nullptr;
	QMediaPlayer* player = nullptr;
	VideoObject* video = nullptr;
	QFileDialog* fileDialog;
	QGraphicsView* graphicsView;
	QGraphicsScene* scene;

	//test
	void addGraphic();

signals:


public slots:

	void on_btnImportAsset_clicked();
	void on_btnImportDir_clicked();
	void on_btnDeleteAsset_clicked();
};
