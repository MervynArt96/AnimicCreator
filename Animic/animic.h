#pragma once
#include <QtWidgets/QMainWindow>
#include <QtCore>
#include <QtGui>
#include "ui_animic.h"
#include "ProjectHandler.h"
#include "AssetHandlerModule/AssetHandler.h"

class Animic : public QMainWindow
{
	Q_OBJECT

public:
	Animic(QWidget *parent = Q_NULLPTR);

private:
	Ui::AnimicClass ui;
	void init();
	void connectSignalSlots();

	ProjectHandler* projHandler;
	AssetHandler* assetHandler;

};
