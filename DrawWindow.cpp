#include "DrawWindow.h"
#include <QGraphicsRectItem>





DrawWindow::DrawWindow(QWidget *parent)
    : QWidget(parent)
{

    ui.setupUi(this);
    this->setGeometry(QRect(0,0,800,800));

    ui.graphicsView->hide();
    view = new GraphicsViewWrapper(this);
    view->setGeometry(QRect(0,0, 800,800));
   

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene = new QGraphicsScene(0, 0, view->geometry().width(), view->geometry().height(), ui.graphicsView);
    view->setMouseTracking(true);
    view->setScene(scene);
    view->show();


    connect(view, &GraphicsViewWrapper::mouseMove_signal, this, &DrawWindow::mouseMove_slot);
    connect(view, &GraphicsViewWrapper::mouseStartPos_signal, this, &DrawWindow::mouseStartPos_slot);
    connect(view, &GraphicsViewWrapper::mouseScroll_signal, this, &DrawWindow::mouseScroll_slot);
    view->setMouseTracking(false);
}

DrawWindow::~DrawWindow()
{

    for (Figure* fig : figuresAtScene) {
        delete fig;
        fig = nullptr;
    }
}


void DrawWindow::addSceneLine(int x, int y, int x_, int y_) {

    QGraphicsLineItem* line = new QGraphicsLineItem(x, y, x_, y_);
    scene->addItem(line);
}




void DrawWindow::clearScene() {

    QList<QGraphicsItem*> items = scene->items();
    for (QGraphicsItem* item : items) {
        delete item;
    }
}




void DrawWindow::calculateViewAngle(){

    MyMath::calculateViewAngle(viewPos, viewAngle[0], viewAngle[1], viewAngle[2]);
}


size_t DrawWindow::addFigure(Figure* fig) {

    figuresAtScene.push_back(fig);
    return figuresAtScene.size() - 1;


}




void DrawWindow::rotateFigures() {

    for (int i = 0; i < 3; ++i) lastViewAngle[i] = viewAngle[i];

    calculateViewAngle();
    for (Figure* figure : figuresAtScene) {

        
        
        figure->reducePointToDisplay(viewCenter);

        figure->matrixTransform(Matrix::rotateY(viewAngle[1]- lastViewAngle[1]));
        figure->matrixTransform(Matrix::rotateX(viewAngle[0] -lastViewAngle[0]));
        figure->matrixTransform(Matrix::rotateZ(viewAngle[2] - lastViewAngle[2]));


        /*qDebug() << viewPos[0] << viewPos[1] << viewPos[2];
        qDebug() <<"angle"<< viewAngle[0] << viewAngle[1];*/

        figure->addPointToDisplay(viewCenter);

    }
    
    
}


void DrawWindow::initialrotateFigure(Figure* figure) {


    calculateViewAngle();
     



    figure->reducePointToDisplay(viewCenter);

    figure->matrixTransform(Matrix::rotateY(viewAngle[1]));
    figure->matrixTransform(Matrix::rotateX(viewAngle[0]));
    figure->matrixTransform(Matrix::rotateZ(viewAngle[2]));


    /*qDebug() << viewPos[0] << viewPos[1] << viewPos[2];
    qDebug() <<"angle"<< viewAngle[0] << viewAngle[1];*/

    figure->addPointToDisplay(viewCenter);



}



void DrawWindow::drawScene() {

    for (Figure* figure : figuresAtScene) figure->draw(*scene);

}

void DrawWindow::changeViewPos(int x, int y, int z) { //not made

    viewPos[0] += x;
    viewPos[1] -= y;
    viewPos[2] += z;
    clearScene();
    rotateFigures();

};


void DrawWindow::matrixTransform(const Vector2D<double>& rotateMatrix) {

        MyMath::multiplyMatrix4441(rotateMatrix, viewPos);

}





void DrawWindow::horizontalCircleMove(double angle) {



    matrixTransform(Matrix::rotateY(angle));

    //qDebug() << viewPos[0] <<viewPos[1]<< viewPos[2];
    
    
}


void DrawWindow::verticalCircleMove(double angle) {


    if (viewAngle[0] > 1.45 &&  angle<0) return;
    if (viewAngle[0] < -1.45 && angle>0) return;

    double len = sqrt(pow(viewPos[0], 2) + pow(viewPos[2], 2));
    double x = viewPos[0] / len;
    double z = viewPos[2] / len;

    //qDebug() << pow
    
    matrixTransform(Matrix::rotateVector(angle, z ,0,-x));

    
}


void DrawWindow::resize(double koef) {

    
    matrixTransform(Matrix::resize(koef));
    for (Figure* figure : figuresAtScene) {
        figure->reducePointToDisplay(viewCenter);



        figure->matrixTransform(Matrix::resize(koef));


        

        figure->addPointToDisplay(viewCenter);
    }

    


}



//////////////////////////////////////////////////////////////////////////////////

void DrawWindow::mouseStartPos_slot(QMouseEvent* event) {

    mousePos = event->localPos();
}


void DrawWindow::mouseMove_slot(QMouseEvent* event) {

    double posX = event->localPos().x() - mousePos.x();
    double posY = event->localPos().y() - mousePos.y();

    

    clearScene();
    horizontalCircleMove(-(double)posX / 100);
    verticalCircleMove((double)posY / 100);
    rotateFigures();
    drawScene();
    mousePos = event->localPos();

}

void DrawWindow::mouseScroll_slot(QWheelEvent* event) {

    int y =event->angleDelta().y();
   
    if (y > 0) resize(0.95);
    else resize(1.05);
    clearScene();
    drawScene();
    
}




