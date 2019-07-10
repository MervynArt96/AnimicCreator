#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_animic.h"

class Animic : public QMainWindow
{
	Q_OBJECT

public:
	Animic(QWidget *parent = Q_NULLPTR);

private:
	Ui::AnimicClass ui;
};
