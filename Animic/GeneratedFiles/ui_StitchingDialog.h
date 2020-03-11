/********************************************************************************
** Form generated from reading UI file 'StitchingDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STITCHINGDIALOG_H
#define UI_STITCHINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StitchingDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_4;
    QSplitter *splitter_3;
    QSplitter *splitter;
    QWidget *listHolder;
    QGroupBox *TriggerContainer;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton;
    QSplitter *splitter_2;
    QWidget *previewWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *sliderHolder;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_6;
    QWidget *triggerSetting;

    void setupUi(QDialog *StitchingDialog)
    {
        if (StitchingDialog->objectName().isEmpty())
            StitchingDialog->setObjectName(QString::fromUtf8("StitchingDialog"));
        StitchingDialog->resize(1097, 785);
        verticalLayout = new QVBoxLayout(StitchingDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter_4 = new QSplitter(StitchingDialog);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Vertical);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        listHolder = new QWidget(splitter);
        listHolder->setObjectName(QString::fromUtf8("listHolder"));
        listHolder->setMinimumSize(QSize(250, 0));
        splitter->addWidget(listHolder);
        TriggerContainer = new QGroupBox(splitter);
        TriggerContainer->setObjectName(QString::fromUtf8("TriggerContainer"));
        TriggerContainer->setMinimumSize(QSize(100, 0));
        verticalLayout_4 = new QVBoxLayout(TriggerContainer);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pushButton = new QPushButton(TriggerContainer);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_4->addWidget(pushButton);

        splitter->addWidget(TriggerContainer);
        splitter_3->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        previewWidget = new QWidget(splitter_2);
        previewWidget->setObjectName(QString::fromUtf8("previewWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(previewWidget->sizePolicy().hasHeightForWidth());
        previewWidget->setSizePolicy(sizePolicy);
        previewWidget->setMinimumSize(QSize(700, 500));
        splitter_2->addWidget(previewWidget);
        widget = new QWidget(splitter_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(700, 0));
        widget->setMaximumSize(QSize(16777215, 150));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        sliderHolder = new QWidget(widget);
        sliderHolder->setObjectName(QString::fromUtf8("sliderHolder"));

        verticalLayout_2->addWidget(sliderHolder);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout->addWidget(pushButton_6);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        splitter_2->addWidget(widget);
        splitter_3->addWidget(splitter_2);
        splitter_4->addWidget(splitter_3);
        triggerSetting = new QWidget(splitter_4);
        triggerSetting->setObjectName(QString::fromUtf8("triggerSetting"));
        triggerSetting->setMinimumSize(QSize(0, 200));
        splitter_4->addWidget(triggerSetting);

        verticalLayout->addWidget(splitter_4);


        retranslateUi(StitchingDialog);

        QMetaObject::connectSlotsByName(StitchingDialog);
    } // setupUi

    void retranslateUi(QDialog *StitchingDialog)
    {
        StitchingDialog->setWindowTitle(QCoreApplication::translate("StitchingDialog", "Stitch Scene", nullptr));
        TriggerContainer->setTitle(QCoreApplication::translate("StitchingDialog", "Triggers", nullptr));
        pushButton->setText(QCoreApplication::translate("StitchingDialog", "Button Trigger", nullptr));
        pushButton_5->setText(QCoreApplication::translate("StitchingDialog", "Back to Start", nullptr));
        pushButton_4->setText(QCoreApplication::translate("StitchingDialog", "Pause", nullptr));
        pushButton_3->setText(QCoreApplication::translate("StitchingDialog", "Play", nullptr));
        pushButton_2->setText(QCoreApplication::translate("StitchingDialog", "Stop", nullptr));
        pushButton_6->setText(QCoreApplication::translate("StitchingDialog", "Preview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StitchingDialog: public Ui_StitchingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STITCHINGDIALOG_H
