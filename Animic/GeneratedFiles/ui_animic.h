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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
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
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AnimicClass)
    {
        if (AnimicClass->objectName().isEmpty())
            AnimicClass->setObjectName(QString::fromUtf8("AnimicClass"));
        AnimicClass->resize(1046, 733);
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
        centralWidget = new QWidget(AnimicClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        AnimicClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AnimicClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1046, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        AnimicClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AnimicClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AnimicClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AnimicClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AnimicClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
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

        retranslateUi(AnimicClass);

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
        menuFile->setTitle(QCoreApplication::translate("AnimicClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnimicClass: public Ui_AnimicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMIC_H
