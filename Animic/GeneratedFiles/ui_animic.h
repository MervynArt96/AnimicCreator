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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnimicClass
{
public:
    QAction *actionNew_Project;
    QAction *actionNew_Scene;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionOpen;
    QAction *actionOpen_Project;
    QAction *actionNew_Scene_2;
    QAction *actionSave_2;
    QAction *actionSave_As_2;
    QAction *actionOpen_2;
    QAction *actionPreference;
    QAction *actionClose_Scene;
    QAction *actionClose_Project;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QSplitter *AllSplitter;
    QSplitter *TopBottomSplotter;
    QGroupBox *ToolBox;
    QSplitter *PropMainSplitter;
    QSplitter *MainSplitter;
    QTabWidget *Scene;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGraphicsView *graphicsView;
    QScrollArea *Timeline;
    QWidget *scrollAreaWidgetContents;
    QSplitter *propertiesSplitter;
    QTabWidget *Properties;
    QWidget *tab_3;
    QTabWidget *Management;
    QWidget *tab_5;
    QWidget *tab_6;
    QGroupBox *AuxBox;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AnimicClass)
    {
        if (AnimicClass->objectName().isEmpty())
            AnimicClass->setObjectName(QString::fromUtf8("AnimicClass"));
        AnimicClass->resize(1248, 858);
        actionNew_Project = new QAction(AnimicClass);
        actionNew_Project->setObjectName(QString::fromUtf8("actionNew_Project"));
        actionNew_Scene = new QAction(AnimicClass);
        actionNew_Scene->setObjectName(QString::fromUtf8("actionNew_Scene"));
        actionSave = new QAction(AnimicClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(AnimicClass);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionOpen = new QAction(AnimicClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOpen_Project = new QAction(AnimicClass);
        actionOpen_Project->setObjectName(QString::fromUtf8("actionOpen_Project"));
        actionNew_Scene_2 = new QAction(AnimicClass);
        actionNew_Scene_2->setObjectName(QString::fromUtf8("actionNew_Scene_2"));
        actionSave_2 = new QAction(AnimicClass);
        actionSave_2->setObjectName(QString::fromUtf8("actionSave_2"));
        actionSave_As_2 = new QAction(AnimicClass);
        actionSave_As_2->setObjectName(QString::fromUtf8("actionSave_As_2"));
        actionOpen_2 = new QAction(AnimicClass);
        actionOpen_2->setObjectName(QString::fromUtf8("actionOpen_2"));
        actionPreference = new QAction(AnimicClass);
        actionPreference->setObjectName(QString::fromUtf8("actionPreference"));
        actionClose_Scene = new QAction(AnimicClass);
        actionClose_Scene->setObjectName(QString::fromUtf8("actionClose_Scene"));
        actionClose_Project = new QAction(AnimicClass);
        actionClose_Project->setObjectName(QString::fromUtf8("actionClose_Project"));
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
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
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
        Scene = new QTabWidget(MainSplitter);
        Scene->setObjectName(QString::fromUtf8("Scene"));
        Scene->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        sizePolicy1.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea_2 = new QScrollArea(tab);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        sizePolicy1.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy1);
        scrollArea_2->setMinimumSize(QSize(0, 300));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 760, 432));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_2->setSizePolicy(sizePolicy1);
        scrollAreaWidgetContents_2->setAcceptDrops(true);
        graphicsView = new QGraphicsView(scrollAreaWidgetContents_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(270, 100, 256, 192));
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea_2);

        Scene->addTab(tab, QString());
        MainSplitter->addWidget(Scene);
        Timeline = new QScrollArea(MainSplitter);
        Timeline->setObjectName(QString::fromUtf8("Timeline"));
        Timeline->setMinimumSize(QSize(0, 200));
        Timeline->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 788, 198));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        Timeline->setWidget(scrollAreaWidgetContents);
        MainSplitter->addWidget(Timeline);
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
        Properties = new QTabWidget(propertiesSplitter);
        Properties->setObjectName(QString::fromUtf8("Properties"));
        Properties->setMinimumSize(QSize(300, 0));
        Properties->setMaximumSize(QSize(16777215, 16777215));
        Properties->setTabsClosable(true);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        Properties->addTab(tab_3, QString());
        propertiesSplitter->addWidget(Properties);
        Management = new QTabWidget(propertiesSplitter);
        Management->setObjectName(QString::fromUtf8("Management"));
        Management->setMinimumSize(QSize(300, 0));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        Management->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        Management->addTab(tab_6, QString());
        propertiesSplitter->addWidget(Management);
        PropMainSplitter->addWidget(propertiesSplitter);
        TopBottomSplotter->addWidget(PropMainSplitter);
        AllSplitter->addWidget(TopBottomSplotter);
        AuxBox = new QGroupBox(AllSplitter);
        AuxBox->setObjectName(QString::fromUtf8("AuxBox"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(AuxBox->sizePolicy().hasHeightForWidth());
        AuxBox->setSizePolicy(sizePolicy6);
        AuxBox->setMinimumSize(QSize(0, 40));
        AuxBox->setMaximumSize(QSize(16777215, 40));
        AllSplitter->addWidget(AuxBox);

        gridLayout_2->addWidget(AllSplitter, 0, 0, 1, 1);

        AnimicClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AnimicClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1248, 26));
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
        AnimicClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AnimicClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        sizePolicy1.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy1);
        mainToolBar->setMinimumSize(QSize(0, 40));
        mainToolBar->setMovable(false);
        AnimicClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AnimicClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
        statusBar->setSizePolicy(sizePolicy8);
        AnimicClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_Project);
        menuFile->addAction(actionOpen_Project);
        menuFile->addSeparator();
        menuFile->addAction(actionNew_Scene_2);
        menuFile->addAction(actionSave_2);
        menuFile->addAction(actionSave_As_2);
        menuFile->addAction(actionOpen_2);
        menuFile->addSeparator();
        menuFile->addAction(actionPreference);
        menuFile->addSeparator();
        menuFile->addAction(actionClose_Scene);
        menuFile->addAction(actionClose_Project);
        menuHelp->addAction(actionAbout);

        retranslateUi(AnimicClass);

        Properties->setCurrentIndex(0);
        Management->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AnimicClass);
    } // setupUi

    void retranslateUi(QMainWindow *AnimicClass)
    {
        AnimicClass->setWindowTitle(QCoreApplication::translate("AnimicClass", "Animic", nullptr));
        actionNew_Project->setText(QCoreApplication::translate("AnimicClass", "New Project", nullptr));
        actionNew_Scene->setText(QCoreApplication::translate("AnimicClass", "New Scene", nullptr));
        actionSave->setText(QCoreApplication::translate("AnimicClass", "Save", nullptr));
        actionSave_As->setText(QCoreApplication::translate("AnimicClass", "Save As", nullptr));
        actionOpen->setText(QCoreApplication::translate("AnimicClass", "Open", nullptr));
        actionOpen_Project->setText(QCoreApplication::translate("AnimicClass", "Open Project", nullptr));
        actionNew_Scene_2->setText(QCoreApplication::translate("AnimicClass", "New Scene", nullptr));
        actionSave_2->setText(QCoreApplication::translate("AnimicClass", "Save", nullptr));
        actionSave_As_2->setText(QCoreApplication::translate("AnimicClass", "Save As", nullptr));
        actionOpen_2->setText(QCoreApplication::translate("AnimicClass", "Open", nullptr));
        actionPreference->setText(QCoreApplication::translate("AnimicClass", "Preference", nullptr));
        actionClose_Scene->setText(QCoreApplication::translate("AnimicClass", "Close Scene", nullptr));
        actionClose_Project->setText(QCoreApplication::translate("AnimicClass", "Close Project", nullptr));
        actionAbout->setText(QCoreApplication::translate("AnimicClass", "About", nullptr));
        ToolBox->setTitle(QCoreApplication::translate("AnimicClass", "Tool Box", nullptr));
        Scene->setTabText(Scene->indexOf(tab), QCoreApplication::translate("AnimicClass", "Scene 1", nullptr));
        Properties->setTabText(Properties->indexOf(tab_3), QCoreApplication::translate("AnimicClass", "Properties", nullptr));
        Management->setTabText(Management->indexOf(tab_5), QCoreApplication::translate("AnimicClass", "Assets", nullptr));
        Management->setTabText(Management->indexOf(tab_6), QCoreApplication::translate("AnimicClass", "Scenes", nullptr));
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
