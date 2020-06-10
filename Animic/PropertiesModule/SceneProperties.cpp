#include "stdafx.h"
#include "SceneProperties.h"

SceneProperties::SceneProperties(QWidget *parent): QWidget(parent)
{
	QGridLayout* baseLayout = new QGridLayout();

	baseLayout->addWidget(nameLabel, 0 ,0);
	baseLayout->addWidget(entryToggle, 1, 0);
	//baseLayout->addWidget(bgmLabel, 1, 0);
	//baseLayout->addWidget(bgmName, 1, 1);
	//baseLayout->addWidget(bgmUrl, 2, 0);

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

void SceneProperties::onChangeScene(AnimicScene* sc)
{
	
	if (scene != nullptr)
	{
		disconnect(entryToggle, &QCheckBox::toggled, scene, &AnimicScene::onSetEntry);
		disconnect(scene, &AnimicScene::nameChanged, nameLabel, &QLabel::setText);
		scene = nullptr;
	}
	

	if (sc != nullptr) 
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

	//updateProperties("", false);
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