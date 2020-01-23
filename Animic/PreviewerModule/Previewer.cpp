#include "stdafx.h"
#include "Previewer.h"

void Previewer::ShowPreview()
{
	previewWindow->show();
}

void Previewer::playPreview()
{
	//play preview
}

void Previewer::pausePreview()
{
	//pause preview
}

void Previewer::stopPreview()
{
	//stop preview
	previewWindow->close();
}
