#pragma once

#include <QDialog>
#include "ui_StitchingDialog.h"

#include "SceneHandlerModule/SceneListWidget.h"
#include "CanvasModule/AnimicView.h"
#include "StitchingModule/StitchingScene.h"
#include <ModelViewModule/AnimicListView.h>
#include <ModelViewModule/SceneListModel.h>

class StitchingDialog : public QDialog
{
	Q_OBJECT

public:
	StitchingDialog(AnimicListView*, SceneListModel*);
	~StitchingDialog();

private:
	Ui::StitchingDialog ui;

public slots:

	void openDialog();


};
