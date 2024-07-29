#include "DrawWindow.h"
#include <QtWidgets/QApplication>
#include <ui_CompGraph.h>
#include <QtWidgets/QMainWindow>
#include <QTImer>
#include "MainWindow.h"
#include "Controller.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    /*DrawWindow dw;
    dw.show();*/

    MainWindow mw;
    mw.show();
    

    return a.exec();
}
