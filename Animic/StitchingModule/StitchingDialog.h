#pragma once

#include <QDialog>
#include "ui_StitchingDialog.h"

#include "CanvasModule/AnimicView.h"
#include <ModelViewModule/AnimicListView.h>
#include <ModelViewModule/SceneListModel.h>
#include <QCloseEvent>
#include <ModelViewModule\SceneListDelegate.h>
#include <StitchingModule\TriggerProperties\TriggerPropertiesHandler.h>
#include <TimelineModule\AnimicSlider.h>

class StitchingDialog : public QDialog
{
	Q_OBJECT

public:
	StitchingDialog(SceneListModel*);
	~StitchingDialog();

	void reject() override;

private:

	void setupTriggerScene();
	void setupListModel();
	void setupTriggerAssetList();
	void setupTriggerProperties();
	void setupTimeline();
	void connectSignalSlot();

	Ui::StitchingDialog ui;

	AnimicView* view;
	AnimicListView* sceneList;
	SceneListDelegate* stitchDelegate;
	QModelIndexList* changedSceneList;

	QGraphicsScene* dummy;
	TriggerAssetHandler* triggerAsset;
	TriggerPropertiesHandler* triggerProperties;
	
	AnimicSlider* slider;

	QRadioButton* twRadio = new QRadioButton();
	QRadioButton* tmRadio = new QRadioButton();
	QRadioButton* owRadio = new QRadioButton();

signals:

	void resetSceneList(QModelIndexList*);
	void closingDialog();

	void changedTrigger(int);

public slots:

	void on_st_PauseButton_clicked();
	void on_st_PlayButton_clicked();
	void on_st_StopButton_clicked();
	void on_previewButton_clicked();
	void on_st_ImportButton_clicked();
	void on_st_RemoveButton_clicked();

	void openDialog();
	void onSwitchScene(AnimicScene*);

	void onRadioToggle(bool);
};
