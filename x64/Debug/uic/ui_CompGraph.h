/********************************************************************************
** Form generated from reading UI file 'CompGraph.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPGRAPH_H
#define UI_COMPGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_drawWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *drawWindow)
    {
        if (drawWindow->objectName().isEmpty())
            drawWindow->setObjectName(QString::fromUtf8("drawWindow"));
        drawWindow->resize(706, 693);
        verticalLayout = new QVBoxLayout(drawWindow);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(drawWindow);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        graphicsView->setMouseTracking(true);
        graphicsView->setFocusPolicy(Qt::ClickFocus);
        graphicsView->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(graphicsView);


        retranslateUi(drawWindow);

        QMetaObject::connectSlotsByName(drawWindow);
    } // setupUi

    void retranslateUi(QWidget *drawWindow)
    {
        drawWindow->setWindowTitle(QCoreApplication::translate("drawWindow", "drawWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class drawWindow: public Ui_drawWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPGRAPH_H
