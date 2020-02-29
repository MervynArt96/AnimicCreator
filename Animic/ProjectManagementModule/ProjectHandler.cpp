#include "stdafx.h"
#include "ProjectHandler.h"


ProjectHandler::ProjectHandler()
{
	npDialog = new NewProjectDialog();
	fileDialog = new QFileDialog();
}

ProjectHandler::~ProjectHandler()
{

}

NewProjectDialog* ProjectHandler::getNewProjectDialog()
{
	return npDialog;
}