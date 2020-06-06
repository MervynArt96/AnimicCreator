#pragma once

#include <QDialog>
#include "ui_AnimicViewer.h"

class AnimicViewer : public QDialog
{
	Q_OBJECT

public:
	AnimicViewer(QWidget *parent = Q_NULLPTR);
	~AnimicViewer();

private:
	Ui::AnimicViewer ui;
};
