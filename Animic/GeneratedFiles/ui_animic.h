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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
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
    QAction *actionPreference;
    QAction *actionCloseScene;
    QAction *actionCloseProject;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *AllSplitter;
    QSplitter *TopBottomSplotter;
    QGroupBox *ToolBox;
    QSplitter *PropMainSplitter;
    QSplitter *MainSplitter;
    QTabWidget *SceneWindow;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QScrollArea *TimelineWindow;
    QWidget *scrollAreaWidgetContents;
    QSplitter *propertiesSplitter;
    QTabWidget *PropertiesTab;
    QWidget *propTab;
    QTabWidget *ManagementTab;
    QWidget *AssetTab;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QTreeWidget *assetTree;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnImportAsset;
    QPushButton *btnImportDir;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnDeleteAsset;
    QWidget *sceneManagementTab;
    QGroupBox *AuxBox;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AnimicClass)
    {
        if (AnimicClass->objectName().isEmpty())
            AnimicClass->setObjectName(QString::fromUtf8("AnimicClass"));
        AnimicClass->resize(1281, 858);
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
        actionPreference = new QAction(AnimicClass);
        actionPreference->setObjectName(QString::fromUtf8("actionPreference"));
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
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        AllSplitter = new QSplitter(centralWidget);
        AllSplitter->setObjectName(QString::fromUtf8("AllSplitter"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AllSplitter->sizePolicy().hasHeightForWidth());
        AllSplitter->setSizePolicy(sizePolicy1);
        AllSplitter->setOrientation(Qt::Vertical);
        AllSplitter->setChildrenCollapsible(false);
        TopBottomSplotter = new QSplitter(AllSplitter);
        TopBottomSplotter->setObjectName(QString::fromUtf8("TopBottomSplotter"));
        TopBottomSplotter->setOrientation(Qt::Horizontal);
        TopBottomSplotter->setChildrenCollapsible(false);
        ToolBox = new QGroupBox(TopBottomSplotter);
        ToolBox->setObjectName(QString::fromUtf8("ToolBox"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ToolBox->sizePolicy().hasHeightForWidth());
        ToolBox->setSizePolicy(sizePolicy2);
        ToolBox->setMinimumSize(QSize(50, 0));
        ToolBox->setMaximumSize(QSize(100, 16777215));
        ToolBox->setAlignment(Qt::AlignCenter);
        TopBottomSplotter->addWidget(ToolBox);
        PropMainSplitter = new QSplitter(TopBottomSplotter);
        PropMainSplitter->setObjectName(QString::fromUtf8("PropMainSplitter"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(20);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(PropMainSplitter->sizePolicy().hasHeightForWidth());
        PropMainSplitter->setSizePolicy(sizePolicy3);
        PropMainSplitter->setFrameShape(QFrame::HLine);
        PropMainSplitter->setOrientation(Qt::Horizontal);
        PropMainSplitter->setChildrenCollapsible(false);
        MainSplitter = new QSplitter(PropMainSplitter);
        MainSplitter->setObjectName(QString::fromUtf8("MainSplitter"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(30);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(MainSplitter->sizePolicy().hasHeightForWidth());
        MainSplitter->setSizePolicy(sizePolicy4);
        MainSplitter->setFrameShape(QFrame::HLine);
        MainSplitter->setOrientation(Qt::Vertical);
        MainSplitter->setChildrenCollapsible(false);
        SceneWindow = new QTabWidget(MainSplitter);
        SceneWindow->setObjectName(QString::fromUtf8("SceneWindow"));
        SceneWindow->setMinimumSize(QSize(0, 500));
        SceneWindow->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        sizePolicy1.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        SceneWindow->addTab(tab, QString());
        MainSplitter->addWidget(SceneWindow);
        TimelineWindow = new QScrollArea(MainSplitter);
        TimelineWindow->setObjectName(QString::fromUtf8("TimelineWindow"));
        TimelineWindow->setMinimumSize(QSize(0, 200));
        TimelineWindow->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 534, 198));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        TimelineWindow->setWidget(scrollAreaWidgetContents);
        MainSplitter->addWidget(TimelineWindow);
        PropMainSplitter->addWidget(MainSplitter);
        propertiesSplitter = new QSplitter(PropMainSplitter);
        propertiesSplitter->setObjectName(QString::fromUtf8("propertiesSplitter"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(10);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(propertiesSplitter->sizePolicy().hasHeightForWidth());
        propertiesSplitter->setSizePolicy(sizePolicy5);
        propertiesSplitter->setFrameShape(QFrame::HLine);
        propertiesSplitter->setOrientation(Qt::Vertical);
        propertiesSplitter->setChildrenCollapsible(false);
        PropertiesTab = new QTabWidget(propertiesSplitter);
        PropertiesTab->setObjectName(QString::fromUtf8("PropertiesTab"));
        PropertiesTab->setMinimumSize(QSize(0, 300));
        PropertiesTab->setMaximumSize(QSize(16777215, 16777215));
        PropertiesTab->setTabsClosable(true);
        propTab = new QWidget();
        propTab->setObjectName(QString::fromUtf8("propTab"));
        PropertiesTab->addTab(propTab, QString());
        propertiesSplitter->addWidget(PropertiesTab);
        ManagementTab = new QTabWidget(propertiesSplitter);
        ManagementTab->setObjectName(QString::fromUtf8("ManagementTab"));
        sizePolicy1.setHeightForWidth(ManagementTab->sizePolicy().hasHeightForWidth());
        ManagementTab->setSizePolicy(sizePolicy1);
        ManagementTab->setMinimumSize(QSize(0, 100));
        AssetTab = new QWidget();
        AssetTab->setObjectName(QString::fromUtf8("AssetTab"));
        verticalLayout_2 = new QVBoxLayout(AssetTab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        splitter = new QSplitter(AssetTab);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        assetTree = new QTreeWidget(splitter);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        assetTree->setHeaderItem(__qtreewidgetitem);
        assetTree->setObjectName(QString::fromUtf8("assetTree"));
        assetTree->setEnabled(true);
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(assetTree->sizePolicy().hasHeightForWidth());
        assetTree->setSizePolicy(sizePolicy6);
        assetTree->setMinimumSize(QSize(100, 0));
        splitter->addWidget(assetTree);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnImportAsset = new QPushButton(layoutWidget);
        btnImportAsset->setObjectName(QString::fromUtf8("btnImportAsset"));

        horizontalLayout->addWidget(btnImportAsset);

        btnImportDir = new QPushButton(layoutWidget);
        btnImportDir->setObjectName(QString::fromUtf8("btnImportDir"));

        horizontalLayout->addWidget(btnImportDir);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnDeleteAsset = new QPushButton(layoutWidget);
        btnDeleteAsset->setObjectName(QString::fromUtf8("btnDeleteAsset"));

        horizontalLayout->addWidget(btnDeleteAsset);

        splitter->addWidget(layoutWidget);

        verticalLayout_2->addWidget(splitter);

        ManagementTab->addTab(AssetTab, QString());
        sceneManagementTab = new QWidget();
        sceneManagementTab->setObjectName(QString::fromUtf8("sceneManagementTab"));
        ManagementTab->addTab(sceneManagementTab, QString());
        propertiesSplitter->addWidget(ManagementTab);
        PropMainSplitter->addWidget(propertiesSplitter);
        TopBottomSplotter->addWidget(PropMainSplitter);
        AllSplitter->addWidget(TopBottomSplotter);
        AuxBox = new QGroupBox(AllSplitter);
        AuxBox->setObjectName(QString::fromUtf8("AuxBox"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(AuxBox->sizePolicy().hasHeightForWidth());
        AuxBox->setSizePolicy(sizePolicy7);
        AuxBox->setMinimumSize(QSize(0, 40));
        AuxBox->setMaximumSize(QSize(16777215, 40));
        AllSplitter->addWidget(AuxBox);

        gridLayout->addWidget(AllSplitter, 0, 0, 1, 1);

        AnimicClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AnimicClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1281, 26));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy8);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        AnimicClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(AnimicClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QSizePolicy sizePolicy9(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
        statusBar->setSizePolicy(sizePolicy9);
        AnimicClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNewProject);
        menuFile->addAction(actionOpenProject);
        menuFile->addSeparator();
        menuFile->addAction(actionNewScene);
        menuFile->addAction(actionSave_2);
        menuFile->addAction(actionSaveAs);
        menuFile->addAction(actionOpen_2);
        menuFile->addSeparator();
        menuFile->addAction(actionPreference);
        menuFile->addSeparator();
        menuFile->addAction(actionCloseScene);
        menuFile->addAction(actionCloseProject);
        menuHelp->addAction(actionAbout);

        retranslateUi(AnimicClass);

        PropertiesTab->setCurrentIndex(0);
        ManagementTab->setCurrentIndex(0);


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
        actionPreference->setText(QCoreApplication::translate("AnimicClass", "Preference", nullptr));
        actionCloseScene->setText(QCoreApplication::translate("AnimicClass", "Close Scene", nullptr));
        actionCloseProject->setText(QCoreApplication::translate("AnimicClass", "Close Project", nullptr));
        actionAbout->setText(QCoreApplication::translate("AnimicClass", "About", nullptr));
        ToolBox->setTitle(QCoreApplication::translate("AnimicClass", "Tool Box", nullptr));
        SceneWindow->setTabText(SceneWindow->indexOf(tab), QCoreApplication::translate("AnimicClass", "Scene 1", nullptr));
        PropertiesTab->setTabText(PropertiesTab->indexOf(propTab), QCoreApplication::translate("AnimicClass", "Properties", nullptr));
        btnImportAsset->setText(QCoreApplication::translate("AnimicClass", "Import Asset", nullptr));
        btnImportDir->setText(QCoreApplication::translate("AnimicClass", "Import Directory", nullptr));
        btnDeleteAsset->setText(QCoreApplication::translate("AnimicClass", "Delete", nullptr));
        ManagementTab->setTabText(ManagementTab->indexOf(AssetTab), QCoreApplication::translate("AnimicClass", "Assets", nullptr));
        ManagementTab->setTabText(ManagementTab->indexOf(sceneManagementTab), QCoreApplication::translate("AnimicClass", "Scenes", nullptr));
        AuxBox->setTitle(QString());
        menuFile->setTitle(QCoreApplication::translate("AnimicClass", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("AnimicClass", "Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("AnimicClass", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnimicClass: public Ui_AnimicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMIC_H
