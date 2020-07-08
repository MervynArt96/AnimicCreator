#include "stdafx.h"
#include "StitchingDialog.h"

StitchingDialog::StitchingDialog(SceneListModel* model)		//dialog window to stitch/combine/link multiple scenes together using triggers
{
	ui.setupUi(this);
	setupListModel();
	sceneList->setModel(model);						//assign list view to the backend model from main window, to sync the list between this dialog and main window
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
	triggerProperties->getTWTriggerProperties()->getSceneDefaultComboBox()->clear();		//reset all trigger properties' scene list 
	triggerProperties->getTWTriggerProperties()->getSceneAltComboBox()->clear();

	triggerProperties->getTMTriggerProperties()->getSceneDefaultComboBox()->clear();		
	triggerProperties->getTMTriggerProperties()->getSceneAltComboBox()->clear();

	triggerProperties->getOWTriggerProperties()->getSceneDefaultComboBox()->clear();		

	view->setScene(nullptr);																//set viewport to display dummy
	qobject_cast<SceneListModel*>(sceneList->model())->setSceneToEditMode();				//set all scene to main window mode
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
			triggerProperties->getTWTriggerProperties()->getSceneDefaultComboBox()->insertItem(i, QString("Empty"));		//add a dummy item to combo box
			triggerProperties->getTWTriggerProperties()->getSceneAltComboBox()->insertItem(i, QString("Empty"));

			triggerProperties->getTMTriggerProperties()->getSceneDefaultComboBox()->insertItem(i, QString("Empty"));
			triggerProperties->getTMTriggerProperties()->getSceneAltComboBox()->insertItem(i, QString("Empty"));

			triggerProperties->getOWTriggerProperties()->getSceneDefaultComboBox()->insertItem(i, QString("Empty"));

			continue;
		}

		triggerProperties->getTWTriggerProperties()->getSceneDefaultComboBox()->insertItem(i,list->at(i-1)->getName());					//fill combo box with the entire list of scenes
		triggerProperties->getTWTriggerProperties()->getSceneAltComboBox()->insertItem(i, list->at(i-1)->getName());

		triggerProperties->getTMTriggerProperties()->getSceneDefaultComboBox()->insertItem(i, list->at(i - 1)->getName());
		triggerProperties->getTMTriggerProperties()->getSceneAltComboBox()->insertItem(i, list->at(i - 1)->getName());

		triggerProperties->getOWTriggerProperties()->getSceneDefaultComboBox()->insertItem(i, list->at(i - 1)->getName());

	}
	this->move(200, 50);
	this->exec();
}

void StitchingDialog::onSwitchScene(AnimicScene* sc)
{
	disconnect(this, &StitchingDialog::changedTrigger, nullptr, nullptr);
	disconnect(slider, &AnimicSlider::valueChanged, nullptr, nullptr);
	disconnect(ui.st_PlayButton, &QPushButton::clicked, nullptr, nullptr);
	disconnect(ui.st_PauseButton, &QPushButton::clicked, nullptr, nullptr);
	disconnect(ui.st_StopButton, &QPushButton::clicked, nullptr, nullptr);
	if (sc != nullptr)
	{
		view->setScene(sc);
		if (ui.twRadio->isChecked())		//get initial trigger type from the radio group and assign to the active scene
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

		connect(ui.st_PlayButton, &QPushButton::clicked, sc, &AnimicScene::playTrigger);			//connect scene to playback control button
		connect(ui.st_PauseButton, &QPushButton::clicked, sc, &AnimicScene::pauseTrigger);
		connect(ui.st_StopButton, &QPushButton::clicked, sc, &AnimicScene::stopTrigger);

		if (sc->getMaxPlayer() != nullptr)
			slider->setMaximum(sc->getMaxPlayer()->duration());										//get longest duration video

		connect(this, &StitchingDialog::changedTrigger, sc, &AnimicScene::switchTriggerType);
		connect(slider, &AnimicSlider::valueChanged, sc, &AnimicScene::setVideoFrameTime);
		connect(sc, &AnimicScene::triggerInserted, this, &StitchingDialog::onTriggerInserted);
		connect(sc, &AnimicScene::focusItemChanged, triggerProperties, &TriggerPropertiesHandler::onFocusChanged);
	}
}

void StitchingDialog::setupTriggerScene()				//set up stitching dialog viewport
{
	view = new AnimicView(ui.graphicsViewHolder, 0);
	view->setSceneRect(QRectF(QPointF(0, 0), QPointF(800, 600)));
	view->setAcceptDrops(true);
	view->setScene(nullptr);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(view);

	ui.graphicsViewHolder->setLayout(layout);
}

void StitchingDialog::setupListModel()				//set up the list view 
{
	QVBoxLayout* listLayout = new QVBoxLayout();
	sceneList = new AnimicListView();
	stitchDelegate = new SceneListDelegate(sceneList);	

	listLayout->addWidget(sceneList);
	ui.listHolder->setLayout(listLayout);

	connect(sceneList, &AnimicListView::switchScene, this, &StitchingDialog::onSwitchScene);
}

void StitchingDialog::setupTriggerAssetList()		//set up trigger asset list widget 
{
	triggerAsset = new TriggerAssetHandler(nullptr);
	QVBoxLayout* trigger_layout = new QVBoxLayout();
	trigger_layout->addWidget(triggerAsset);

	ui.triggerAssetHolder->setLayout(trigger_layout);
}

void StitchingDialog::setupTriggerProperties()		//set up trigger properties panel 
{
	triggerProperties = new TriggerPropertiesHandler(ui.triggerPropertiesHolder, sceneList);
	QVBoxLayout* prop_layout = new QVBoxLayout();

	prop_layout->addWidget(triggerProperties);
	ui.triggerPropertiesHolder->setLayout(prop_layout);

	SceneListModel* model = qobject_cast<SceneListModel*>(sceneList->model());
}

void StitchingDialog::setupTimeline()					// setup sitching dialog timeline
{
	slider = new AnimicSlider(ui.st_SliderHolder);

	QVBoxLayout* layout = new QVBoxLayout();

	layout->addWidget(slider);
	ui.st_SliderHolder->setLayout(layout);
	slider->show();
}

void StitchingDialog::connectSignalSlot()
{
	connect(ui.twRadio, &QRadioButton::toggled, this, &StitchingDialog::onRadioToggle);		//connect the toggle functionalities
	connect(ui.tmRadio, &QRadioButton::toggled, this, &StitchingDialog::onRadioToggle);
	connect(ui.owRadio, &QRadioButton::toggled, this, &StitchingDialog::onRadioToggle);
}

void StitchingDialog::on_previewButton_clicked()		//preview the animated comic product so far
{
	view->setScene(nullptr);
	previewDialog->openDialog(*qobject_cast<SceneListModel*>(sceneList->model())->getList());
}

void StitchingDialog::on_st_ImportButton_clicked()		//import trigger asset
{
	triggerAsset->importAsset();
}

void StitchingDialog::on_st_RemoveButton_clicked()		//remove trigger asset
{
	triggerAsset->deleteAsset();
}

void StitchingDialog::onRadioToggle(bool checked)			//toggle what trigger to be created when drag and drop into viewport
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
	connect(ui.st_PlayButton, &QPushButton::clicked, qobject_cast<AnimicScene*>(view->scene()), &AnimicScene::playTrigger);		//connect the trigger to playback button controls
	connect(ui.st_PauseButton, &QPushButton::clicked, qobject_cast<AnimicScene*>(view->scene()), &AnimicScene::pauseTrigger);
	connect(ui.st_StopButton, &QPushButton::clicked, qobject_cast<AnimicScene*>(view->scene()), &AnimicScene::stopTrigger);
}

void StitchingDialog::closeEvent(QCloseEvent* e)		//default close operation
{
	reject();
}