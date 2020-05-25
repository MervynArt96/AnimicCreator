/********************************************************************************
** Form generated from reading UI file 'animic.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMIC_H
#define UI_ANIMIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnimicClass
{
public:
    QAction *actionNewProject;
    QAction *actionNew_Scene;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionOpen;
    QAction *actionOpenProject;
    QAction *actionNewScene;
    QAction *actionSave_2;
    QAction *actionSaveAs;
    QAction *actionOpen_2;
    QAction *actionStitching;
    QAction *actionCloseScene;
    QAction *actionCloseProject;
    QAction *actionAbout;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter_3;
    QGroupBox *ToolBox;
    QSplitter *splitter_4;
    QSplitter *MainSplitter;
    QSplitter *splitter_2;
    QTabWidget *SceneWindow;
    QWidget *tab;
    QWidget *PlaybackButtonHolder;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *stopButton;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *stitchButton;
    QWidget *SliderHolder;
    QSplitter *MainRightSplitter;
    QTabWidget *PropertiesTab;
    QWidget *propTab;
    QVBoxLayout *verticalLayout_3;
    QWidget *propHolder;
    QWidget *layerTab;
    QVBoxLayout *verticalLayout;
    QWidget *layerHolder;
    QTabWidget *ManagementTab;
    QWidget *AssetTab;
    QHBoxLayout *horizontalLayout_4;
    QSplitter *splitter;
    QWidget *treeHolder;
    QHBoxLayout *horizontalLayout_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnImportAsset;
    QPushButton *btnImportDir;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnDeleteAsset;
    QWidget *sceneManagementTab;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QWidget *sceneListHolder;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *newSceneButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *removeSceneButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuView;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AnimicClass)
    {
        if (AnimicClass->objectName().isEmpty())
            AnimicClass->setObjectName(QString::fromUtf8("AnimicClass"));
        AnimicClass->resize(1252, 825);
        actionNewProject = new QAction(AnimicClass);
        actionNewProject->setObjectName(QString::fromUtf8("actionNewProject"));
        actionNewProject->setEnabled(true);
        actionNew_Scene = new QAction(AnimicClass);
        actionNew_Scene->setObjectName(QString::fromUtf8("actionNew_Scene"));
        actionSave = new QAction(AnimicClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(AnimicClass);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionOpen = new QAction(AnimicClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOpenProject = new QAction(AnimicClass);
        actionOpenProject->setObjectName(QString::fromUtf8("actionOpenProject"));
        actionNewScene = new QAction(AnimicClass);
        actionNewScene->setObjectName(QString::fromUtf8("actionNewScene"));
        actionSave_2 = new QAction(AnimicClass);
        actionSave_2->setObjectName(QString::fromUtf8("actionSave_2"));
        actionSaveAs = new QAction(AnimicClass);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionOpen_2 = new QAction(AnimicClass);
        actionOpen_2->setObjectName(QString::fromUtf8("actionOpen_2"));
        actionStitching = new QAction(AnimicClass);
        actionStitching->setObjectName(QString::fromUtf8("actionStitching"));
        actionCloseScene = new QAction(AnimicClass);
        actionCloseScene->setObjectName(QString::fromUtf8("actionCloseScene"));
        actionCloseProject = new QAction(AnimicClass);
        actionCloseProject->setObjectName(QString::fromUtf8("actionCloseProject"));
        actionAbout = new QAction(AnimicClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(AnimicClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(50);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(0, 0));
        horizontalLayout_6 = new QHBoxLayout(centralWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        splitter_3->setChildrenCollapsible(false);
        ToolBox = new QGroupBox(splitter_3);
        ToolBox->setObjectName(QString::fromUtf8("ToolBox"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ToolBox->sizePolicy().hasHeightForWidth());
        ToolBox->setSizePolicy(sizePolicy1);
        ToolBox->setMinimumSize(QSize(50, 0));
        ToolBox->setMaximumSize(QSize(100, 16777215));
        ToolBox->setAlignment(Qt::AlignCenter);
        splitter_3->addWidget(ToolBox);
        splitter_4 = new QSplitter(splitter_3);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_4->setChildrenCollapsible(false);
        MainSplitter = new QSplitter(splitter_4);
        MainSplitter->setObjectName(QString::fromUtf8("MainSplitter"));
        MainSplitter->setOrientation(Qt::Vertical);
        MainSplitter->setChildrenCollapsible(false);
        splitter_2 = new QSplitter(MainSplitter);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter_2->setChildrenCollapsible(false);
        SceneWindow = new QTabWidget(splitter_2);
        SceneWindow->setObjectName(QString::fromUtf8("SceneWindow"));
        SceneWindow->setMinimumSize(QSize(800, 500));
        SceneWindow->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy2);
        SceneWindow->addTab(tab, QString());
        splitter_2->addWidget(SceneWindow);
        PlaybackButtonHolder = new QWidget(splitter_2);
        PlaybackButtonHolder->setObjectName(QString::fromUtf8("PlaybackButtonHolder"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(PlaybackButtonHolder->sizePolicy().hasHeightForWidth());
        PlaybackButtonHolder->setSizePolicy(sizePolicy3);
        PlaybackButtonHolder->setMinimumSize(QSize(0, 50));
        PlaybackButtonHolder->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_8 = new QHBoxLayout(PlaybackButtonHolder);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_2 = new QSpacerItem(182, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        stopButton = new QPushButton(PlaybackButtonHolder);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        horizontalLayout_8->addWidget(stopButton);

        playButton = new QPushButton(PlaybackButtonHolder);
        playButton->setObjectName(QString::fromUtf8("playButton"));

        horizontalLayout_8->addWidget(playButton);

        pauseButton = new QPushButton(PlaybackButtonHolder);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        horizontalLayout_8->addWidget(pauseButton);

        horizontalSpacer_3 = new QSpacerItem(181, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        stitchButton = new QPushButton(PlaybackButtonHolder);
        stitchButton->setObjectName(QString::fromUtf8("stitchButton"));

        horizontalLayout_8->addWidget(stitchButton);

        splitter_2->addWidget(PlaybackButtonHolder);
        MainSplitter->addWidget(splitter_2);
        SliderHolder = new QWidget(MainSplitter);
        SliderHolder->setObjectName(QString::fromUtf8("SliderHolder"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(30);
        sizePolicy4.setHeightForWidth(SliderHolder->sizePolicy().hasHeightForWidth());
        SliderHolder->setSizePolicy(sizePolicy4);
        SliderHolder->setMaximumSize(QSize(16777215, 50));
        MainSplitter->addWidget(SliderHolder);
        splitter_4->addWidget(MainSplitter);
        MainRightSplitter = new QSplitter(splitter_4);
        MainRightSplitter->setObjectName(QString::fromUtf8("MainRightSplitter"));
        MainRightSplitter->setOrientation(Qt::Vertical);
        MainRightSplitter->setChildrenCollapsible(false);
        PropertiesTab = new QTabWidget(MainRightSplitter);
        PropertiesTab->setObjectName(QString::fromUtf8("PropertiesTab"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(PropertiesTab->sizePolicy().hasHeightForWidth());
        PropertiesTab->setSizePolicy(sizePolicy5);
        PropertiesTab->setMinimumSize(QSize(100, 200));
        PropertiesTab->setMaximumSize(QSize(16777215, 400));
        PropertiesTab->setTabsClosable(false);
        propTab = new QWidget();
        propTab->setObjectName(QString::fromUtf8("propTab"));
        verticalLayout_3 = new QVBoxLayout(propTab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        propHolder = new QWidget(propTab);
        propHolder->setObjectName(QString::fromUtf8("propHolder"));

        verticalLayout_3->addWidget(propHolder);

        PropertiesTab->addTab(propTab, QString());
        layerTab = new QWidget();
        layerTab->setObjectName(QString::fromUtf8("layerTab"));
        verticalLayout = new QVBoxLayout(layerTab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        layerHolder = new QWidget(layerTab);
        layerHolder->setObjectName(QString::fromUtf8("layerHolder"));

        verticalLayout->addWidget(layerHolder);

        PropertiesTab->addTab(layerTab, QString());
        MainRightSplitter->addWidget(PropertiesTab);
        ManagementTab = new QTabWidget(MainRightSplitter);
        ManagementTab->setObjectName(QString::fromUtf8("ManagementTab"));
        sizePolicy2.setHeightForWidth(ManagementTab->sizePolicy().hasHeightForWidth());
        ManagementTab->setSizePolicy(sizePolicy2);
        ManagementTab->setMinimumSize(QSize(0, 200));
        AssetTab = new QWidget();
        AssetTab->setObjectName(QString::fromUtf8("AssetTab"));
        horizontalLayout_4 = new QHBoxLayout(AssetTab);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(AssetTab);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMinimumSize(QSize(300, 0));
        splitter->setOrientation(Qt::Vertical);
        treeHolder = new QWidget(splitter);
        treeHolder->setObjectName(QString::fromUtf8("treeHolder"));
        treeHolder->setAutoFillBackground(false);
        horizontalLayout_3 = new QHBoxLayout(treeHolder);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        splitter->addWidget(treeHolder);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(7);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnImportAsset = new QPushButton(layoutWidget);
        btnImportAsset->setObjectName(QString::fromUtf8("btnImportAsset"));
        btnImportAsset->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(btnImportAsset);

        btnImportDir = new QPushButton(layoutWidget);
        btnImportDir->setObjectName(QString::fromUtf8("btnImportDir"));
        btnImportDir->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(btnImportDir);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnDeleteAsset = new QPushButton(layoutWidget);
        btnDeleteAsset->setObjectName(QString::fromUtf8("btnDeleteAsset"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(btnDeleteAsset->sizePolicy().hasHeightForWidth());
        btnDeleteAsset->setSizePolicy(sizePolicy6);
        btnDeleteAsset->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(btnDeleteAsset);

        splitter->addWidget(layoutWidget);

        horizontalLayout_4->addWidget(splitter);

        ManagementTab->addTab(AssetTab, QString());
        sceneManagementTab = new QWidget();
        sceneManagementTab->setObjectName(QString::fromUtf8("sceneManagementTab"));
        horizontalLayout_5 = new QHBoxLayout(sceneManagementTab);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        sceneListHolder = new QWidget(sceneManagementTab);
        sceneListHolder->setObjectName(QString::fromUtf8("sceneListHolder"));

        verticalLayout_2->addWidget(sceneListHolder);

        widget = new QWidget(sceneManagementTab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 30));
        widget->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_7 = new QHBoxLayout(widget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        newSceneButton = new QPushButton(widget);
        newSceneButton->setObjectName(QString::fromUtf8("newSceneButton"));

        horizontalLayout_7->addWidget(newSceneButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        removeSceneButton = new QPushButton(widget);
        removeSceneButton->setObjectName(QString::fromUtf8("removeSceneButton"));

        horizontalLayout_7->addWidget(removeSceneButton);


        verticalLayout_2->addWidget(widget);


        horizontalLayout_5->addLayout(verticalLayout_2);

        ManagementTab->addTab(sceneManagementTab, QString());
        MainRightSplitter->addWidget(ManagementTab);
        splitter_4->addWidget(MainRightSplitter);
        splitter_3->addWidget(splitter_4);

        horizontalLayout_2->addWidget(splitter_3);


        horizontalLayout_6->addLayout(horizontalLayout_2);

        AnimicClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AnimicClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1252, 26));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy7);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        AnimicClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(AnimicClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        sizePolicy5.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
        statusBar->setSizePolicy(sizePolicy5);
        AnimicClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNewProject);
        menuFile->addAction(actionOpenProject);
        menuFile->addSeparator();
        menuFile->addAction(actionNewScene);
        menuFile->addAction(actionSave_2);
        menuFile->addAction(actionSaveAs);
        menuFile->addAction(actionOpen_2);
        menuFile->addSeparator();
        menuFile->addAction(actionStitching);
        menuFile->addSeparator();
        menuFile->addAction(actionCloseScene);
        menuFile->addAction(actionCloseProject);
        menuHelp->addAction(actionAbout);

        retranslateUi(AnimicClass);

        PropertiesTab->setCurrentIndex(0);
        ManagementTab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AnimicClass);
    } // setupUi

    void retranslateUi(QMainWindow *AnimicClass)
    {
        AnimicClass->setWindowTitle(QCoreApplication::translate("AnimicClass", "Animic", nullptr));
        actionNewProject->setText(QCoreApplication::translate("AnimicClass", "New Project", nullptr));
        actionNew_Scene->setText(QCoreApplication::translate("AnimicClass", "New Scene", nullptr));
        actionSave->setText(QCoreApplication::translate("AnimicClass", "Save", nullptr));
        actionSave_As->setText(QCoreApplication::translate("AnimicClass", "Save As", nullptr));
        actionOpen->setText(QCoreApplication::translate("AnimicClass", "Open", nullptr));
        actionOpenProject->setText(QCoreApplication::translate("AnimicClass", "Open Project", nullptr));
        actionNewScene->setText(QCoreApplication::translate("AnimicClass", "New Scene", nullptr));
        actionSave_2->setText(QCoreApplication::translate("AnimicClass", "Save", nullptr));
        actionSaveAs->setText(QCoreApplication::translate("AnimicClass", "Save As", nullptr));
        actionOpen_2->setText(QCoreApplication::translate("AnimicClass", "Open", nullptr));
        actionStitching->setText(QCoreApplication::translate("AnimicClass", "Stitch Scene", nullptr));
        actionCloseScene->setText(QCoreApplication::translate("AnimicClass", "Close Scene", nullptr));
        actionCloseProject->setText(QCoreApplication::translate("AnimicClass", "Close Project", nullptr));
        actionAbout->setText(QCoreApplication::translate("AnimicClass", "About", nullptr));
        ToolBox->setTitle(QCoreApplication::translate("AnimicClass", "Tool Box", nullptr));
        SceneWindow->setTabText(SceneWindow->indexOf(tab), QCoreApplication::translate("AnimicClass", "Scene 1", nullptr));
        stopButton->setText(QCoreApplication::translate("AnimicClass", "Stop", nullptr));
        playButton->setText(QCoreApplication::translate("AnimicClass", "Play", nullptr));
        pauseButton->setText(QCoreApplication::translate("AnimicClass", "Pause", nullptr));
        stitchButton->setText(QCoreApplication::translate("AnimicClass", "Stitch", nullptr));
        PropertiesTab->setTabText(PropertiesTab->indexOf(propTab), QCoreApplication::translate("AnimicClass", "Properties", nullptr));
        PropertiesTab->setTabText(PropertiesTab->indexOf(layerTab), QCoreApplication::translate("AnimicClass", "Layer", nullptr));
        btnImportAsset->setText(QCoreApplication::translate("AnimicClass", "Import Asset", nullptr));
        btnImportDir->setText(QCoreApplication::translate("AnimicClass", "Import Directory", nullptr));
        btnDeleteAsset->setText(QCoreApplication::translate("AnimicClass", "Delete", nullptr));
        ManagementTab->setTabText(ManagementTab->indexOf(AssetTab), QCoreApplication::translate("AnimicClass", "Assets", nullptr));
        newSceneButton->setText(QCoreApplication::translate("AnimicClass", "New Scene", nullptr));
        removeSceneButton->setText(QCoreApplication::translate("AnimicClass", "Remove", nullptr));
        ManagementTab->setTabText(ManagementTab->indexOf(sceneManagementTab), QCoreApplication::translate("AnimicClass", "Scene", nullptr));
        menuFile->setTitle(QCoreApplication::translate("AnimicClass", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("AnimicClass", "Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("AnimicClass", "Help", nullptr));
        menuView->setTitle(QCoreApplication::translate("AnimicClass", "Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnimicClass: public Ui_AnimicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMIC_H
