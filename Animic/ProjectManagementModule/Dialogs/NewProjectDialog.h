#pragma once

#include <QDialog>
#include "ui_NewProjectDialog.h"

class NewProjectDialog : public QDialog
{
	Q_OBJECT

public:
	NewProjectDialog(QWidget *parent = Q_NULLPTR);
	~NewProjectDialog();

private:
	Ui::NewProjectDialog ui;


signals:
	void createProject();

};
