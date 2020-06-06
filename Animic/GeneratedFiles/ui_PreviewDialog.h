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
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreviewDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *viewHolder;
    QLabel *label;

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

        label = new QLabel(PreviewDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);


        retranslateUi(PreviewDialog);

        QMetaObject::connectSlotsByName(PreviewDialog);
    } // setupUi

    void retranslateUi(QDialog *PreviewDialog)
    {
        PreviewDialog->setWindowTitle(QCoreApplication::translate("PreviewDialog", "PreviewDialog", nullptr));
        label->setText(QCoreApplication::translate("PreviewDialog", "Hint: Press ESC to close this window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PreviewDialog: public Ui_PreviewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWDIALOG_H
