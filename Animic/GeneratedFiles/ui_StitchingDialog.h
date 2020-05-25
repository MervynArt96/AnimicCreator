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
#include <QtWidgets/QRadioButton>
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
    QWidget *triggerAssetHolder;
    QSplitter *splitter_2;
    QWidget *graphicsViewHolder;
    QWidget *holder;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *st_SliderHolder;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *st_PauseButton;
    QPushButton *st_PlayButton;
    QPushButton *st_StopButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *previewButton;
    QWidget *triggerSetting;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *TW_RadioButton;
    QRadioButton *TM_RadioButton;
    QRadioButton *OW_RadioButton;
    QWidget *triggerPropertiesHolder;

    void setupUi(QDialog *StitchingDialog)
    {
        if (StitchingDialog->objectName().isEmpty())
            StitchingDialog->setObjectName(QString::fromUtf8("StitchingDialog"));
        StitchingDialog->resize(1490, 954);
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
        triggerAssetHolder = new QWidget(splitter);
        triggerAssetHolder->setObjectName(QString::fromUtf8("triggerAssetHolder"));
        triggerAssetHolder->setMinimumSize(QSize(250, 0));
        splitter->addWidget(triggerAssetHolder);
        splitter_3->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        graphicsViewHolder = new QWidget(splitter_2);
        graphicsViewHolder->setObjectName(QString::fromUtf8("graphicsViewHolder"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsViewHolder->sizePolicy().hasHeightForWidth());
        graphicsViewHolder->setSizePolicy(sizePolicy);
        graphicsViewHolder->setMinimumSize(QSize(700, 500));
        splitter_2->addWidget(graphicsViewHolder);
        holder = new QWidget(splitter_2);
        holder->setObjectName(QString::fromUtf8("holder"));
        holder->setMinimumSize(QSize(700, 0));
        holder->setMaximumSize(QSize(16777215, 150));
        verticalLayout_3 = new QVBoxLayout(holder);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        st_SliderHolder = new QWidget(holder);
        st_SliderHolder->setObjectName(QString::fromUtf8("st_SliderHolder"));

        verticalLayout_2->addWidget(st_SliderHolder);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        st_PauseButton = new QPushButton(holder);
        st_PauseButton->setObjectName(QString::fromUtf8("st_PauseButton"));

        horizontalLayout->addWidget(st_PauseButton);

        st_PlayButton = new QPushButton(holder);
        st_PlayButton->setObjectName(QString::fromUtf8("st_PlayButton"));

        horizontalLayout->addWidget(st_PlayButton);

        st_StopButton = new QPushButton(holder);
        st_StopButton->setObjectName(QString::fromUtf8("st_StopButton"));

        horizontalLayout->addWidget(st_StopButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        previewButton = new QPushButton(holder);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        horizontalLayout->addWidget(previewButton);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        splitter_2->addWidget(holder);
        splitter_3->addWidget(splitter_2);
        splitter_4->addWidget(splitter_3);
        triggerSetting = new QWidget(splitter_4);
        triggerSetting->setObjectName(QString::fromUtf8("triggerSetting"));
        triggerSetting->setMinimumSize(QSize(0, 200));
        triggerSetting->setMaximumSize(QSize(16777215, 200));
        horizontalLayout_2 = new QHBoxLayout(triggerSetting);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_2 = new QWidget(triggerSetting);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMaximumSize(QSize(150, 16777215));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        TW_RadioButton = new QRadioButton(groupBox);
        TW_RadioButton->setObjectName(QString::fromUtf8("TW_RadioButton"));

        verticalLayout_4->addWidget(TW_RadioButton);

        TM_RadioButton = new QRadioButton(groupBox);
        TM_RadioButton->setObjectName(QString::fromUtf8("TM_RadioButton"));

        verticalLayout_4->addWidget(TM_RadioButton);

        OW_RadioButton = new QRadioButton(groupBox);
        OW_RadioButton->setObjectName(QString::fromUtf8("OW_RadioButton"));

        verticalLayout_4->addWidget(OW_RadioButton);


        horizontalLayout_3->addWidget(groupBox);


        horizontalLayout_2->addWidget(widget_2);

        triggerPropertiesHolder = new QWidget(triggerSetting);
        triggerPropertiesHolder->setObjectName(QString::fromUtf8("triggerPropertiesHolder"));

        horizontalLayout_2->addWidget(triggerPropertiesHolder);

        splitter_4->addWidget(triggerSetting);

        verticalLayout->addWidget(splitter_4);


        retranslateUi(StitchingDialog);

        QMetaObject::connectSlotsByName(StitchingDialog);
    } // setupUi

    void retranslateUi(QDialog *StitchingDialog)
    {
        StitchingDialog->setWindowTitle(QCoreApplication::translate("StitchingDialog", "Stitch Scene", nullptr));
        st_PauseButton->setText(QCoreApplication::translate("StitchingDialog", "Pause", nullptr));
        st_PlayButton->setText(QCoreApplication::translate("StitchingDialog", "Play", nullptr));
        st_StopButton->setText(QCoreApplication::translate("StitchingDialog", "Stop", nullptr));
        previewButton->setText(QCoreApplication::translate("StitchingDialog", "Preview", nullptr));
        groupBox->setTitle(QCoreApplication::translate("StitchingDialog", "Trigger list", nullptr));
        TW_RadioButton->setText(QCoreApplication::translate("StitchingDialog", "Two Way", nullptr));
        TM_RadioButton->setText(QCoreApplication::translate("StitchingDialog", "Timed Mash", nullptr));
        OW_RadioButton->setText(QCoreApplication::translate("StitchingDialog", "One Way", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StitchingDialog: public Ui_StitchingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STITCHINGDIALOG_H
