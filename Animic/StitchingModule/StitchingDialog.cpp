#include "stdafx.h"
#include "StitchingDialog.h"

StitchingDialog::StitchingDialog(SceneListModel* model)
{
	ui.setupUi(this);
	setupListModel();
	sceneList->setModel(model);
	sceneList->setItemDelegate(stitchDelegate);
	setupTriggerScene();
	setupTriggerAssetList();
	setupTriggerProperties();
	setupTimeline();

	connectSignalSlot();

	previewDialog = new PreviewDialog();
}

StitchingDialog::~StitchingDialog()
{

}

void StitchingDialog::reject()
{
	view->setScene(nullptr);
	qobject_cast<SceneListModel*>(sceneList->model())->setSceneToEditMode();
	emit closingDialog();
	QDialog::reject();
}

void StitchingDialog::openDialog()
{
	this->move(200, 50);
	this->exec();
}

void StitchingDialog::onSwitchScene(AnimicScene* sc)
{
	view->setScene(sc); 

	if (sc->getMaxPlayer() != nullptr)
		slider->setMaximum(sc->getMaxPlayer()->duration());

	if (ui.twRadio->isChecked())
	{
		sc->switchTriggerType(0);
	}
	else if (ui.tmRadio->isChecked())
	{
		sc->switchTriggerType(1);
	}
	else if (ui.owRadio->isChecked())
	{
		sc->switchTriggerType(2);
	}

	connect(this, &StitchingDialog::changedTrigger, sc, &AnimicScene::switchTriggerType);
	connect(slider, &AnimicSlider::valueChanged, sc, &AnimicScene::setVideoFrameTime);
	connect(sc, &AnimicScene::triggerInserted, this, &StitchingDialog::onTriggerInserted);
}

void StitchingDialog::setupTriggerScene()
{
	view = new AnimicView(ui.graphicsViewHolder);
	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	view->setAcceptDrops(true);

	//dummy = new QGraphicsScene();
	view->setScene(nullptr);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);

	ui.graphicsViewHolder->setLayout(layout);
}

void StitchingDialog::setupListModel()
{
	QVBoxLayout* listLayout = new QVBoxLayout();
	sceneList = new AnimicListView();
	stitchDelegate = new SceneListDelegate(sceneList);

	listLayout->addWidget(sceneList);
	ui.listHolder->setLayout(listLayout);

	connect(sceneList, &AnimicListView::switchScene, this, &StitchingDialog::onSwitchScene);
}

void StitchingDialog::setupTriggerAssetList()
{
	triggerAsset = new TriggerAssetHandler(nullptr);
	QVBoxLayout* trigger_layout = new QVBoxLayout();
	trigger_layout->addWidget(triggerAsset);

	ui.triggerAssetHolder->setLayout(trigger_layout);
}

void StitchingDialog::setupTriggerProperties()
{
	triggerProperties = new TriggerPropertiesHandler(ui.triggerPropertiesHolder);
	QVBoxLayout* prop_layout = new QVBoxLayout();

	prop_layout->addWidget(triggerProperties);
	ui.triggerPropertiesHolder->setLayout(prop_layout);

	SceneListModel* model = qobject_cast<SceneListModel*>(sceneList->model());

	for (int i = 0; i < model->getList()->count(); i++)
	{
		triggerProperties->getTWTriggerProperties()->getSceneDefaultComboBox()->addItem(model->getList()->at(i)->getName());
		triggerProperties->getTWTriggerProperties()->getSceneAltComboBox()->addItem(model->getList()->at(i)->getName());

		//add same stuff to TM and OW properties;

	}

}

void StitchingDialog::setupTimeline()
{
	slider = new AnimicSlider(ui.st_SliderHolder);

	QVBoxLayout* layout = new QVBoxLayout();

	layout->addWidget(slider);
	ui.st_SliderHolder->setLayout(layout);
	slider->show();
}

void StitchingDialog::connectSignalSlot()
{
	connect(ui.twRadio, &QRadioButton::toggled, this, &StitchingDialog::onRadioToggle);
	connect(ui.tmRadio, &QRadioButton::toggled, this, &StitchingDialog::onRadioToggle);
	connect(ui.owRadio, &QRadioButton::toggled, this, &StitchingDialog::onRadioToggle);
}

void StitchingDialog::on_previewButton_clicked()
{
	view->setScene(nullptr);
	previewDialog->openDialog(*qobject_cast<SceneListModel*>(sceneList->model())->getList());
}

void StitchingDialog::on_st_ImportButton_clicked()
{
	triggerAsset->importAsset();
}

void StitchingDialog::on_st_RemoveButton_clicked()
{
	triggerAsset->deleteAsset();
}

void StitchingDialog::onRadioToggle(bool checked)
{
	if (checked)
	{
		QRadioButton* btn = static_cast<QRadioButton*>(sender());
		if (btn->text() == "Two Way Trigger")
		{
			emit changedTrigger(0);
		}
		else if (btn->text() == "Timed Mash Trigger")
		{
			emit changedTrigger(1);
		}
		else if (btn->text() == "One Way Trigger")
		{
			emit changedTrigger(2);
		}
	}
}

void StitchingDialog::onTriggerInserted()
{
	connect(ui.st_PlayButton, &QPushButton::clicked, qobject_cast<AnimicScene*>(view->scene()), &AnimicScene::playTrigger);
	connect(ui.st_PauseButton, &QPushButton::clicked, qobject_cast<AnimicScene*>(view->scene()), &AnimicScene::pauseTrigger);
	connect(ui.st_StopButton, &QPushButton::clicked, qobject_cast<AnimicScene*>(view->scene()), &AnimicScene::stopTrigger);
}
