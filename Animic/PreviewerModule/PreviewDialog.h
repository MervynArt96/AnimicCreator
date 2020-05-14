#pragma once

#include <QDialog>
#include "ui_PreviewDialog.h"

class PreviewDialog : public QDialog
{
	Q_OBJECT

public:
	PreviewDialog(QWidget *parent = Q_NULLPTR);
	~PreviewDialog();

private:
	Ui::PreviewDialog ui;
};
