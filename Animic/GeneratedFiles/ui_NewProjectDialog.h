/********************************************************************************
** Form generated from reading UI file 'NewProjectDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECTDIALOG_H
#define UI_NEWPROJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewProjectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *newProjectPage1;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *animComic;
    QWidget *widget_2;
    QWidget *widget;
    QPushButton *tradComic;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *newProjectPage2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;

    void setupUi(QDialog *NewProjectDialog)
    {
        if (NewProjectDialog->objectName().isEmpty())
            NewProjectDialog->setObjectName(QString::fromUtf8("NewProjectDialog"));
        NewProjectDialog->resize(816, 559);
        verticalLayout = new QVBoxLayout(NewProjectDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(NewProjectDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        newProjectPage1 = new QWidget();
        newProjectPage1->setObjectName(QString::fromUtf8("newProjectPage1"));
        newProjectPage1->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newProjectPage1->sizePolicy().hasHeightForWidth());
        newProjectPage1->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(newProjectPage1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(10);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(10, 10, -1, -1);
        animComic = new QPushButton(newProjectPage1);
        animComic->setObjectName(QString::fromUtf8("animComic"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(animComic->sizePolicy().hasHeightForWidth());
        animComic->setSizePolicy(sizePolicy1);
        animComic->setMinimumSize(QSize(100, 100));
        animComic->setFocusPolicy(Qt::NoFocus);
        animComic->setAutoFillBackground(false);
        animComic->setCheckable(true);
        animComic->setChecked(false);

        gridLayout->addWidget(animComic, 0, 0, 1, 1);

        widget_2 = new QWidget(newProjectPage1);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        gridLayout->addWidget(widget_2, 0, 2, 1, 1);

        widget = new QWidget(newProjectPage1);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout->addWidget(widget, 1, 0, 1, 1);

        tradComic = new QPushButton(newProjectPage1);
        tradComic->setObjectName(QString::fromUtf8("tradComic"));
        sizePolicy1.setHeightForWidth(tradComic->sizePolicy().hasHeightForWidth());
        tradComic->setSizePolicy(sizePolicy1);
        tradComic->setMinimumSize(QSize(100, 100));
        tradComic->setFocusPolicy(Qt::NoFocus);
        tradComic->setCheckable(true);

        gridLayout->addWidget(tradComic, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        textBrowser = new QTextBrowser(newProjectPage1);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy2);
        textBrowser->setMinimumSize(QSize(0, 100));

        verticalLayout_2->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(newProjectPage1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(newProjectPage1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(newProjectPage1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(newProjectPage1);
        newProjectPage2 = new QWidget();
        newProjectPage2->setObjectName(QString::fromUtf8("newProjectPage2"));
        gridLayout_3 = new QGridLayout(newProjectPage2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        stackedWidget->addWidget(newProjectPage2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(NewProjectDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(NewProjectDialog);
    } // setupUi

    void retranslateUi(QDialog *NewProjectDialog)
    {
        NewProjectDialog->setWindowTitle(QCoreApplication::translate("NewProjectDialog", "NewProjectDialog", nullptr));
        animComic->setText(QCoreApplication::translate("NewProjectDialog", "Animated Comic", nullptr));
        tradComic->setText(QCoreApplication::translate("NewProjectDialog", "Traditional Comic", nullptr));
        pushButton_3->setText(QCoreApplication::translate("NewProjectDialog", "Back", nullptr));
        pushButton_2->setText(QCoreApplication::translate("NewProjectDialog", "Next", nullptr));
        pushButton->setText(QCoreApplication::translate("NewProjectDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewProjectDialog: public Ui_NewProjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECTDIALOG_H
