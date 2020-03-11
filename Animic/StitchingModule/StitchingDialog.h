#pragma once

#include <QDialog>
#include "ui_StitchingDialog.h"

#include "SceneHandlerModule/SceneListWidget.h"
#include "CanvasModule/AnimicView.h"
#include "StitchingModule/StitchingScene.h"

class StitchingDialog : public QDialog
{
	Q_OBJECT

public:
	StitchingDialog(SceneListWidget*);
	~StitchingDialog();

private:
	Ui::StitchingDialog ui;

	SceneListWidget* refList;

public slots:

	void openDialog();


};
