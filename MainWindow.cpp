#include "MainWindow.h"
#include "Rectangle.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <QCheckBox>
	


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    auto size = ui.drawWindow->size();
    double width = size.width();
    double height = size.height();
    ui.drawWindow->viewCenter = { width / 2.0, height / 2.0, 0,1 };

  /*  Rectangle* center = new Rectangle(-100, -100, -100, 200, 200, 200, ui.drawWindow->viewCenter);
    ui.drawWindow->addFigure(center);*/

    QRandomGenerator rg(QDateTime::currentSecsSinceEpoch());

    std::vector<std::vector<double>> points;

    for (int _ =0; _<2;++_){
        std::vector<double> pointA;
        std::vector<double> pointB;
        for (int __ = 0; __ < 3; ++__) {
            pointA.emplace_back(rg.bounded(-300, 300));
            pointB.emplace_back(rg.bounded(-100, 100));
        }

        points.emplace_back(pointA);
        points.emplace_back(pointB);
    }




    //segs = new Segments(points, ui.drawWindow->viewCenter);
    //ui.drawWindow->addFigure(segs);



    //segs->CutPoints(*center, ui.drawWindow->viewCenter);
    //connect(ui.showCutted, &QCheckBox::stateChanged, this, &MainWindow::showCutPoints_slot);


   

    auto bezieIndex = ui.drawWindow->addFigure(new BezieCurve(points, ui.drawWindow->viewCenter, 0.05));

    ui.bezieController->setObjN(bezieIndex);

    for (int i = 0; i < points.size(); ++i)
        ui.bezieController->addPoint(points[i], i);




   /* std::vector<std::vector<std::vector<double>>> bezieSurfacePoints =
    { 
    { {100,100, 0}, {66, 100, 0}, {33, 100, 0}, {0, 100,0} },
    { {100,100, 50}, {66, 100, 50}, {33, 100, 50}, {0, 100,50} },
    { {100,50, 100}, {66, 50, 100}, {33, 50, 100}, {0, 50,100} }
    };*/

    //BezieSurface* surface = new BezieSurface(bezieSurfacePoints, ui.drawWindow->viewCenter, 0.1);
    //ui.drawWindow->addFigure(surface);



    ui.drawWindow->rotateFigures();
    ui.drawWindow->drawScene();

    //connect(ui.bezieController, &Controller::pointChanged_signal, ui.drawWindow, &DrawWindow::objPointChanged_slot);

    

   

}

MainWindow::~MainWindow()
{}
