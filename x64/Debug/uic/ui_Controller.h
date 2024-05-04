/********************************************************************************
** Form generated from reading UI file 'Controller.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLER_H
#define UI_CONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControllerClass
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *ControllerClass)
    {
        if (ControllerClass->objectName().isEmpty())
            ControllerClass->setObjectName(QString::fromUtf8("ControllerClass"));
        ControllerClass->resize(565, 394);
        ControllerClass->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(ControllerClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(ControllerClass);

        QMetaObject::connectSlotsByName(ControllerClass);
    } // setupUi

    void retranslateUi(QWidget *ControllerClass)
    {
        ControllerClass->setWindowTitle(QCoreApplication::translate("ControllerClass", "Controller", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControllerClass: public Ui_ControllerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLER_H
