#include "stdafx.h"
#include "SceneProperties.h"

SceneProperties::SceneProperties(QWidget *parent): QWidget(parent)	//properties widget for scene
{
	QGridLayout* baseLayout = new QGridLayout();

	baseLayout->addWidget(nameLabel, 0 ,0);		//name of scene
	baseLayout->addWidget(entryToggle, 1, 0);	//toggle if the scene should be the first scene

	this->setLayout(baseLayout);
}

SceneProperties::SceneProperties()
{

}

SceneProperties::~SceneProperties()
{

}

void SceneProperties::connectComponent()
{

}

void SceneProperties::onChangeScene(AnimicScene* sc)		//user clicks on a different tab or close a tab
{
	
	if (scene != nullptr)													//disconnect the previous scene form ui controls
	{
		disconnect(entryToggle, &QCheckBox::toggled, scene, &AnimicScene::onSetEntry);		
		disconnect(scene, &AnimicScene::nameChanged, nameLabel, &QLabel::setText);
		scene = nullptr;
	}
	

	if (sc != nullptr)														//update the text field according to the new scene
	{
		nameLabel->setText(sc->getName());
		entryToggle->setChecked(sc->isEntry());

		connect(entryToggle, &QCheckBox::toggled, sc, &AnimicScene::onSetEntry);
		connect(sc, &AnimicScene::nameChanged, nameLabel, &QLabel::setText);
		scene = sc;
	}
}

void SceneProperties::onDisconnectScene(AnimicScene* sc)					
{
	if (scene != nullptr && scene == sc)
	{
		disconnect(entryToggle, &QCheckBox::toggled, scene, &AnimicScene::onSetEntry);
		disconnect(scene, &AnimicScene::nameChanged, nameLabel, &QLabel::setText);
		scene = nullptr;
	}

}

void SceneProperties::updateProperties(const QString str, bool x)
{
	nameLabel->setText(str);
	entryToggle->setChecked(x);
}

void SceneProperties::manualConnect(AnimicScene* sc)
{
	connect(entryToggle, &QCheckBox::toggled, sc, &AnimicScene::onSetEntry);
	connect(sc, &AnimicScene::nameChanged, nameLabel, &QLabel::setText);
	scene = sc;
}