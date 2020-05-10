#include "stdafx.h"
#include "SceneProperties.h"

SceneProperties::SceneProperties(QWidget *parent): QWidget(parent)
{
	QGridLayout* baseLayout = new QGridLayout();

	baseLayout->addWidget(nameLabel, 0 ,0);
	baseLayout->addWidget(nameText, 0, 1);
	baseLayout->addWidget(bgmLabel, 1, 0);
	baseLayout->addWidget(bgmName, 1, 1);
	baseLayout->addWidget(bgmUrl, 2, 0);

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

void SceneProperties::onChangeScene()
{
	
}
