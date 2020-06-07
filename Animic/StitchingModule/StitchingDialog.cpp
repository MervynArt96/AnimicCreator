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
	connect(previewDialog, &PreviewDialog::closeDialogSignal, this, &StitchingDialog::onClosePreviewDialog);
	//connect(sceneList, &AnimicListView::returnSceneToTrigger, )
}

StitchingDialog::~StitchingDialog()
{

}

void StitchingDialog::reject()
{
	triggerProperties->getTWTriggerProperties()->getSceneDefaultComboBox()->clear();
	triggerProperties->getTWTriggerProperties()->getSceneAltComboBox()->clear();

	//do same stuff to TM and OW properties;

	view->setScene(nullptr);
	qobject_cast<SceneListModel*>(sceneList->model())->setSceneToEditMode();
	emit closingDialog();
	QDialog::reject();
}

void StitchingDialog::openDialog()
{
	QList<AnimicScene*>* list = qobject_cast<SceneListModel*>(sceneList->model())->getList();

	for (int i = 0; i < list->count() + 1; i++)
	{
		if (i == 0)
		{
			triggerProperties->getTWTriggerProperties()->getSceneDefaultComboBox()->insertItem(i, QString("Empty"));
			triggerProperties->getTWTriggerProperties()->getSceneAltComboBox()->insertItem(i, QString("Empty"));

			//do same stuff to TM and OW properties;

			continue;
		}

		triggerProperties->getTWTriggerProperties()->getSceneDefaultComboBox()->insertItem(i,list->at(i-1)->getName());
		triggerProperties->getTWTriggerProperties()->getSceneAltComboBox()->insertItem(i, list->at(i-1)->getName());

		//do same stuff to TM and OW properties;
	}
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

	//get trigger here 
	//check trigger type
	//connect to respective panels


	connect(this, &StitchingDialog::changedTrigger, sc, &AnimicScene::switchTriggerType);
	connect(slider, &AnimicSlider::valueChanged, sc, &AnimicScene::setVideoFrameTime);
	connect(sc, &AnimicScene::triggerInserted, this, &StitchingDialog::onTriggerInserted);
	connect(sc, &AnimicScene::focusItemChanged, triggerProperties, &TriggerPropertiesHandler::onFocusChanged);
}

void StitchingDialog::setupTriggerScene()
{
	view = new AnimicView(ui.graphicsViewHolder);
	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	view->setAcceptDrops(true);
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
	triggerProperties = new TriggerPropertiesHandler(ui.triggerPropertiesHolder, sceneList);
	QVBoxLayout* prop_layout = new QVBoxLayout();

	prop_layout->addWidget(triggerProperties);
	ui.triggerPropertiesHolder->setLayout(prop_layout);

	SceneListModel* model = qobject_cast<SceneListModel*>(sceneList->model());
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

void StitchingDialog::onClosePreviewDialog()
{
	//set previous scene back ?
}