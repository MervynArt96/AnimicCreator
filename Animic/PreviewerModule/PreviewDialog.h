#pragma once

#include <QDialog>
#include "ui_PreviewDialog.h"
#include <CanvasModule\AnimicView.h>
#include <PreviewerModule\PlaybackEngine\PlaybackEngineCore.h>

class PreviewDialog : public QDialog
{
	Q_OBJECT

public:
	PreviewDialog(QWidget *parent = Q_NULLPTR);
	~PreviewDialog();

	void reject() override;
	void keyPressEvent(QKeyEvent* e) override;

private:
	Ui::PreviewDialog ui;

	AnimicView* view;
	PlaybackEngineCore* engine;

public slots:

	void openDialog(QList<AnimicScene*>);

};
