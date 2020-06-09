/********************************************************************************
** Form generated from reading UI file 'PreviewDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWDIALOG_H
#define UI_PREVIEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreviewDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *viewHolder;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *sceneName;

    void setupUi(QDialog *PreviewDialog)
    {
        if (PreviewDialog->objectName().isEmpty())
            PreviewDialog->setObjectName(QString::fromUtf8("PreviewDialog"));
        PreviewDialog->resize(1090, 778);
        verticalLayout = new QVBoxLayout(PreviewDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        viewHolder = new QWidget(PreviewDialog);
        viewHolder->setObjectName(QString::fromUtf8("viewHolder"));

        verticalLayout->addWidget(viewHolder);

        widget = new QWidget(PreviewDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(11, 0, -1, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        sceneName = new QLabel(widget);
        sceneName->setObjectName(QString::fromUtf8("sceneName"));
        sceneName->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Roboto"));
        font1.setPointSize(10);
        sceneName->setFont(font1);
        sceneName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(sceneName);


        verticalLayout->addWidget(widget);


        retranslateUi(PreviewDialog);

        QMetaObject::connectSlotsByName(PreviewDialog);
    } // setupUi

    void retranslateUi(QDialog *PreviewDialog)
    {
        PreviewDialog->setWindowTitle(QCoreApplication::translate("PreviewDialog", "PreviewDialog", nullptr));
        label->setText(QCoreApplication::translate("PreviewDialog", "Hint: Press Space to start playback", nullptr));
        sceneName->setText(QCoreApplication::translate("PreviewDialog", "Scene Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PreviewDialog: public Ui_PreviewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWDIALOG_H
