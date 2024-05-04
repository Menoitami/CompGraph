/********************************************************************************
** Form generated from reading UI file 'PointField.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTFIELD_H
#define UI_POINTFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PointFieldClass
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *pointN;
    QLineEdit *x;
    QLineEdit *y;
    QLineEdit *z;

    void setupUi(QWidget *PointFieldClass)
    {
        if (PointFieldClass->objectName().isEmpty())
            PointFieldClass->setObjectName(QString::fromUtf8("PointFieldClass"));
        PointFieldClass->resize(528, 53);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PointFieldClass->sizePolicy().hasHeightForWidth());
        PointFieldClass->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(PointFieldClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pointN = new QLabel(PointFieldClass);
        pointN->setObjectName(QString::fromUtf8("pointN"));
        QFont font;
        font.setPointSize(20);
        pointN->setFont(font);

        horizontalLayout->addWidget(pointN);

        x = new QLineEdit(PointFieldClass);
        x->setObjectName(QString::fromUtf8("x"));
        QFont font1;
        font1.setPointSize(18);
        x->setFont(font1);
        x->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(x);

        y = new QLineEdit(PointFieldClass);
        y->setObjectName(QString::fromUtf8("y"));
        y->setFont(font1);
        y->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(y);

        z = new QLineEdit(PointFieldClass);
        z->setObjectName(QString::fromUtf8("z"));
        z->setFont(font1);
        z->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(z);


        retranslateUi(PointFieldClass);

        QMetaObject::connectSlotsByName(PointFieldClass);
    } // setupUi

    void retranslateUi(QWidget *PointFieldClass)
    {
        PointFieldClass->setWindowTitle(QCoreApplication::translate("PointFieldClass", "PointField", nullptr));
        pointN->setText(QCoreApplication::translate("PointFieldClass", "N", nullptr));
        x->setText(QString());
        x->setPlaceholderText(QCoreApplication::translate("PointFieldClass", "X", nullptr));
        y->setText(QString());
        y->setPlaceholderText(QCoreApplication::translate("PointFieldClass", "Y", nullptr));
        z->setText(QString());
        z->setPlaceholderText(QCoreApplication::translate("PointFieldClass", "Z", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PointFieldClass: public Ui_PointFieldClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTFIELD_H
