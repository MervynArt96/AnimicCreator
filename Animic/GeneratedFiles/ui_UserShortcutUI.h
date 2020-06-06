/********************************************************************************
** Form generated from reading UI file 'UserShortcutUI.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSHORTCUTUI_H
#define UI_USERSHORTCUTUI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwindow.h"

QT_BEGIN_NAMESPACE

class Ui_UserShortcutUI
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWindow *UserShortcutUI)
    {
        if (UserShortcutUI->objectName().isEmpty())
            UserShortcutUI->setObjectName(QString::fromUtf8("UserShortcutUI"));
        UserShortcutUI->resize(918, 619);
        gridLayout = new QGridLayout(UserShortcutUI);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_3 = new QWidget(UserShortcutUI);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(200, 200));
        pushButton->setSizeIncrement(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Documents/Academic/CAT 400 FYP/Report/avenger.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(200, 200));

        verticalLayout_3->addWidget(pushButton);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        label_4->setFont(font);
        label_4->setFrameShape(QFrame::StyledPanel);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);


        gridLayout_2->addWidget(widget_3, 1, 0, 1, 1);

        label = new QLabel(UserShortcutUI);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Roboto"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label->setFont(font1);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);

        widget_2 = new QWidget(UserShortcutUI);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(200, 200));
        pushButton_3->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../Documents/Academic/CAT 400 FYP/Report/naruto.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(200, 200));

        verticalLayout_2->addWidget(pushButton_3);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::StyledPanel);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);


        gridLayout_2->addWidget(widget_2, 1, 3, 1, 1);

        widget = new QWidget(UserShortcutUI);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(200, 200));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../Digital Art/Asset/LogoWithBg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(200, 200));

        verticalLayout->addWidget(pushButton_2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Roboto"));
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);


        gridLayout_2->addWidget(widget, 1, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 5, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(UserShortcutUI);

        QMetaObject::connectSlotsByName(UserShortcutUI);
    } // setupUi

    void retranslateUi(QWindow *UserShortcutUI)
    {
        UserShortcutUI->setWindowTitle(QCoreApplication::translate("UserShortcutUI", "UserShortcutUI", nullptr));
        pushButton->setText(QString());
        label_4->setText(QCoreApplication::translate("UserShortcutUI", "Avenger Animic Example", nullptr));
        label->setText(QCoreApplication::translate("UserShortcutUI", "  Animic List", nullptr));
        pushButton_3->setText(QString());
        label_3->setText(QCoreApplication::translate("UserShortcutUI", "Naruto Animic Example", nullptr));
        pushButton_2->setText(QString());
        label_2->setText(QCoreApplication::translate("UserShortcutUI", "Educational Animic Example", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserShortcutUI: public Ui_UserShortcutUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSHORTCUTUI_H
