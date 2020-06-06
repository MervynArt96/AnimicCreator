/********************************************************************************
** Form generated from reading UI file 'AnimicViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMICVIEWER_H
#define UI_ANIMICVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnimicViewer
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QPushButton *narutoButton;
    QLabel *label;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_5;
    QPushButton *eduButton;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *avengerButton;
    QLabel *label_4;

    void setupUi(QDialog *AnimicViewer)
    {
        if (AnimicViewer->objectName().isEmpty())
            AnimicViewer->setObjectName(QString::fromUtf8("AnimicViewer"));
        AnimicViewer->resize(953, 676);
        gridLayout_2 = new QGridLayout(AnimicViewer);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        widget_2 = new QWidget(AnimicViewer);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        narutoButton = new QPushButton(widget_2);
        narutoButton->setObjectName(QString::fromUtf8("narutoButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(narutoButton->sizePolicy().hasHeightForWidth());
        narutoButton->setSizePolicy(sizePolicy);
        narutoButton->setMinimumSize(QSize(200, 200));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Documents/Academic/CAT 400 FYP/Report/naruto.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        narutoButton->setIcon(icon);
        narutoButton->setIconSize(QSize(200, 200));

        verticalLayout->addWidget(narutoButton);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        label->setFont(font);
        label->setFrameShape(QFrame::StyledPanel);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        gridLayout_2->addWidget(widget_2, 1, 2, 1, 1);

        widget_3 = new QWidget(AnimicViewer);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_5 = new QVBoxLayout(widget_3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        eduButton = new QPushButton(widget_3);
        eduButton->setObjectName(QString::fromUtf8("eduButton"));
        sizePolicy.setHeightForWidth(eduButton->sizePolicy().hasHeightForWidth());
        eduButton->setSizePolicy(sizePolicy);
        eduButton->setMinimumSize(QSize(200, 200));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../Digital Art/Asset/LogoWithBg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        eduButton->setIcon(icon1);
        eduButton->setIconSize(QSize(200, 200));

        verticalLayout_5->addWidget(eduButton);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setFrameShape(QFrame::StyledPanel);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_5);


        gridLayout_2->addWidget(widget_3, 1, 4, 1, 1);

        label_6 = new QLabel(AnimicViewer);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Roboto"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);
        label_6->setFrameShape(QFrame::StyledPanel);
        label_6->setLineWidth(2);
        label_6->setMargin(2);

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 5, 1, 1);

        widget = new QWidget(AnimicViewer);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        avengerButton = new QPushButton(widget);
        avengerButton->setObjectName(QString::fromUtf8("avengerButton"));
        sizePolicy.setHeightForWidth(avengerButton->sizePolicy().hasHeightForWidth());
        avengerButton->setSizePolicy(sizePolicy);
        avengerButton->setMinimumSize(QSize(200, 200));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../Documents/Academic/CAT 400 FYP/Report/avenger.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        avengerButton->setIcon(icon2);
        avengerButton->setIconSize(QSize(200, 200));

        verticalLayout_3->addWidget(avengerButton);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setFrameShape(QFrame::StyledPanel);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(AnimicViewer);

        QMetaObject::connectSlotsByName(AnimicViewer);
    } // setupUi

    void retranslateUi(QDialog *AnimicViewer)
    {
        AnimicViewer->setWindowTitle(QCoreApplication::translate("AnimicViewer", "AnimicViewer", nullptr));
        narutoButton->setText(QString());
        label->setText(QCoreApplication::translate("AnimicViewer", "Naruto Animic Exmaple", nullptr));
        eduButton->setText(QString());
        label_5->setText(QCoreApplication::translate("AnimicViewer", "Educational Animic Exmaple", nullptr));
        label_6->setText(QCoreApplication::translate("AnimicViewer", " Animic List", nullptr));
        avengerButton->setText(QString());
        label_4->setText(QCoreApplication::translate("AnimicViewer", "Avenger Animic Exmaple", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnimicViewer: public Ui_AnimicViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMICVIEWER_H
