#pragma once

#include <QDialog>
#include "ui_StitchingDialog.h"

#include "CanvasModule/AnimicView.h"
#include <ModelViewModule/AnimicListView.h>
#include <ModelViewModule/SceneListModel.h>
#include <QCloseEvent>
#include <ModelViewModule\SceneListDelegate.h>

class StitchingDialog : public QDialog
{
	Q_OBJECT

public:
	StitchingDialog(SceneListModel*);
	~StitchingDialog();

	void reject() override;

private:

	Ui::StitchingDialog ui;
	AnimicView* view;
	AnimicListView* sceneList;
	SceneListDelegate* stitchDelegate;
	QModelIndexList* changedSceneList;

	QGraphicsScene* dummy;


signals:

	void resetSceneList(QModelIndexList*);
	void closingDialog();

public slots:

	void openDialog();
	void onSwitchScene(AnimicScene*, QModelIndex);

};
