#include "stdafx.h"
#include "animic.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);
	Animic main;
	main.show();
	return application.exec();
}
