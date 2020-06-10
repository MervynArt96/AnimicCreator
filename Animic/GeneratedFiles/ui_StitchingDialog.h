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
#include <QtWidgets/QGridLayout>
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
    QWidget *triggerAssetColumn;
    QVBoxLayout *verticalLayout_5;
    QWidget *triggerAssetHolder;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *st_RemoveButton;
    QPushButton *st_ImportButton;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *radioGroup;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *twRadio;
    QRadioButton *tmRadio;
    QRadioButton *owRadio;
    QWidget *triggerPropertiesHolder;
    QSplitter *splitter_2;
    QWidget *graphicsViewHolder;
    QWidget *holder;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *st_PauseButton;
    QPushButton *st_PlayButton;
    QPushButton *st_StopButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *previewButton;
    QWidget *st_SliderHolder;

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
        splitter_4->setLineWidth(0);
        splitter_4->setMidLineWidth(1);
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setLineWidth(0);
        splitter_3->setMidLineWidth(1);
        splitter_3->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setLineWidth(0);
        splitter->setMidLineWidth(0);
        splitter->setOrientation(Qt::Horizontal);
        listHolder = new QWidget(splitter);
        listHolder->setObjectName(QString::fromUtf8("listHolder"));
        listHolder->setMinimumSize(QSize(100, 300));
        listHolder->setMaximumSize(QSize(150, 16777215));
        splitter->addWidget(listHolder);
        triggerAssetColumn = new QWidget(splitter);
        triggerAssetColumn->setObjectName(QString::fromUtf8("triggerAssetColumn"));
        triggerAssetColumn->setMinimumSize(QSize(150, 0));
        triggerAssetColumn->setMaximumSize(QSize(200, 16777215));
        verticalLayout_5 = new QVBoxLayout(triggerAssetColumn);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        triggerAssetHolder = new QWidget(triggerAssetColumn);
        triggerAssetHolder->setObjectName(QString::fromUtf8("triggerAssetHolder"));
        triggerAssetHolder->setMinimumSize(QSize(150, 0));
        triggerAssetHolder->setMaximumSize(QSize(200, 16777215));

        verticalLayout_5->addWidget(triggerAssetHolder);

        widget = new QWidget(triggerAssetColumn);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(100, 0));
        widget->setMaximumSize(QSize(200, 50));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        st_RemoveButton = new QPushButton(widget);
        st_RemoveButton->setObjectName(QString::fromUtf8("st_RemoveButton"));

        gridLayout->addWidget(st_RemoveButton, 0, 2, 1, 1);

        st_ImportButton = new QPushButton(widget);
        st_ImportButton->setObjectName(QString::fromUtf8("st_ImportButton"));

        gridLayout->addWidget(st_ImportButton, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 1);


        verticalLayout_5->addWidget(widget);

        radioGroup = new QGroupBox(triggerAssetColumn);
        radioGroup->setObjectName(QString::fromUtf8("radioGroup"));
        radioGroup->setMinimumSize(QSize(150, 0));
        radioGroup->setMaximumSize(QSize(200, 150));
        verticalLayout_4 = new QVBoxLayout(radioGroup);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(11, 0, 0, 11);
        twRadio = new QRadioButton(radioGroup);
        twRadio->setObjectName(QString::fromUtf8("twRadio"));
        twRadio->setChecked(true);

        verticalLayout_4->addWidget(twRadio);

        tmRadio = new QRadioButton(radioGroup);
        tmRadio->setObjectName(QString::fromUtf8("tmRadio"));

        verticalLayout_4->addWidget(tmRadio);

        owRadio = new QRadioButton(radioGroup);
        owRadio->setObjectName(QString::fromUtf8("owRadio"));

        verticalLayout_4->addWidget(owRadio);


        verticalLayout_5->addWidget(radioGroup);

        splitter->addWidget(triggerAssetColumn);
        splitter_3->addWidget(splitter);
        triggerPropertiesHolder = new QWidget(splitter_3);
        triggerPropertiesHolder->setObjectName(QString::fromUtf8("triggerPropertiesHolder"));
        triggerPropertiesHolder->setMinimumSize(QSize(0, 325));
        triggerPropertiesHolder->setMaximumSize(QSize(16777215, 200));
        splitter_3->addWidget(triggerPropertiesHolder);
        splitter_4->addWidget(splitter_3);
        splitter_2 = new QSplitter(splitter_4);
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

        st_SliderHolder = new QWidget(holder);
        st_SliderHolder->setObjectName(QString::fromUtf8("st_SliderHolder"));
        st_SliderHolder->setMinimumSize(QSize(0, 30));

        verticalLayout_3->addWidget(st_SliderHolder);

        splitter_2->addWidget(holder);
        splitter_4->addWidget(splitter_2);

        verticalLayout->addWidget(splitter_4);


        retranslateUi(StitchingDialog);

        QMetaObject::connectSlotsByName(StitchingDialog);
    } // setupUi

    void retranslateUi(QDialog *StitchingDialog)
    {
        StitchingDialog->setWindowTitle(QCoreApplication::translate("StitchingDialog", "Stitch Scene", nullptr));
        st_RemoveButton->setText(QCoreApplication::translate("StitchingDialog", "Remove", nullptr));
        st_ImportButton->setText(QCoreApplication::translate("StitchingDialog", "Import", nullptr));
        radioGroup->setTitle(QCoreApplication::translate("StitchingDialog", "Trigger Type", nullptr));
        twRadio->setText(QCoreApplication::translate("StitchingDialog", "Two Way Trigger", nullptr));
        tmRadio->setText(QCoreApplication::translate("StitchingDialog", "Timed Mash Trigger", nullptr));
        owRadio->setText(QCoreApplication::translate("StitchingDialog", "One Way Trigger", nullptr));
        st_PauseButton->setText(QCoreApplication::translate("StitchingDialog", "Pause", nullptr));
        st_PlayButton->setText(QCoreApplication::translate("StitchingDialog", "Play", nullptr));
        st_StopButton->setText(QCoreApplication::translate("StitchingDialog", "Stop", nullptr));
        previewButton->setText(QCoreApplication::translate("StitchingDialog", "Preview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StitchingDialog: public Ui_StitchingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STITCHINGDIALOG_H
