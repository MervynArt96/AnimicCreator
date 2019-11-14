#pragma once
#include <QWidget>

class Previewer
{

public:

	void ShowPreview();
	void playPreview();
	void pausePreview();
	void stopPreview();

private:

	QWidget* previewWindow = new QWidget;
	


};

