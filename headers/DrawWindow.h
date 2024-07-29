#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CompGraph.h"
#include <qgraphicsview.h>
#include <qdebug.h>
#include "Rectangle.h"
#include "MyMath.h"
#include <numbers>
#include "Matrix.h"
#include <QMouseEvent>
#include <qobject.h>
#include "GraphicsViewWrapper.h"




#define M_PIl          3.141592653589793238462643383279502884L 

#define HALF_PI         1.570796326794896619231321691639751442L



class DrawWindow : public QWidget
{
    Q_OBJECT

public:

    

    DrawWindow(QWidget *parent = nullptr);
    ~DrawWindow();
    void addSceneLine(int x, int y, int x_, int y_ );
    void clearScene();
    void calculateViewAngle();

    // return fig position in vector
    size_t addFigure(Figure* fig);
    std::vector<Figure*>::reference getFigure(size_t figIndex) {
        return figuresAtScene[figIndex];
    }

    void rotateFigures();
    void initialrotateFigure(Figure* figure);

    void drawScene();
    void changeViewPos(int x, int y, int z);
    void horizontalCircleMove(double angle);
    void verticalCircleMove(double angle);
    void resize(double koef);

    void matrixTransform(const Vector2D<double>& rotateMatrix);

public:
    std::vector<double> viewCenter = { 300, 300, 0, 1 };
   


public slots:
    void mouseMove_slot(QMouseEvent* event);
    void mouseStartPos_slot(QMouseEvent* event);
    void mouseScroll_slot(QWheelEvent* event);

    void objPointChanged_slot(size_t objN, size_t pointN, std::vector<double> values) {
        figuresAtScene[objN]->changePoint(pointN, values);
        scene->clear();
        initialrotateFigure(figuresAtScene[objN]);
        drawScene();
    }
    
private:
    std::vector<Figure*> figuresAtScene;
    double viewAngle[3] = { 0, 0, 0 };// vertical, horizontal
    
    
    double lastViewAngle[3] = { 0,0, 0 };
    std::vector<double> viewPos = { 0,0, -100, 1 };
    double kf = 1;

    QPointF mousePos = QPoint(0, 0);

    Ui::drawWindow ui;
    GraphicsViewWrapper* view;
    QGraphicsScene* scene;
    

};










