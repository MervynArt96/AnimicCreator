#pragma once
#include "NewProjectDialog.h"
#include "QFileDialog"

class ProjectHandler
{
public:
	
	ProjectHandler();
	~ProjectHandler();
	void newProject();
	void loadProject();
	void saveProject();
	void exportProject();

	NewProjectDialog* getNewProjectDialog();



private:
	NewProjectDialog* npDialog;
	QFileDialog* fileDialog;


};

