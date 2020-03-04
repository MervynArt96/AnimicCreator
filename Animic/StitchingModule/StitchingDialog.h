#pragma once

#include <QDialog>
#include "ui_StitchingDialog.h"

class StitchingDialog : public QDialog
{
	Q_OBJECT

public:
	StitchingDialog(QListWidget*);
	~StitchingDialog();

private:
	Ui::StitchingDialog ui;

	QListWidget* refList;

public slots:

	void openDialog();


};
