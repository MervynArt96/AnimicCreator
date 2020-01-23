#include "stdafx.h"
#include "NewProjectDialog.h"
#include "QDebug"

typedef struct {
	int canvasWidth;
	int canvasHeight;
	int projectType;

} projectConfig;


NewProjectDialog::NewProjectDialog(QWidget *parent)	: QDialog(parent)
{
	ui.setupUi(this);
}

NewProjectDialog::~NewProjectDialog()
{
	
}
