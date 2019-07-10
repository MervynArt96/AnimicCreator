#include "stdafx.h"
#include "animic.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Animic w;
	w.show();
	return a.exec();
}
