#include "Rectangle.h"
#include "MyMath.h"
#include <QGraphicsItem>

#define BOTTOM 1   // 00 000001
#define LEFT   2   // 00 000010
#define TOP    4   // 00 000100
#define RIGHT  8   // 00 001000
#define BACK  16   // 00 010000
#define FRONT 32   // 00 100000


void Figure::addSceneLine(int x, int y, int x_, int y_, QGraphicsScene& scene) {
    QGraphicsLineItem* line = new QGraphicsLineItem(x, y, x_, y_);
    scene.addItem(line);
}


void Figure::addSceneLineWColor(int x, int y, int x_, int y_, QGraphicsScene& scene, const QColor& color) {
    QGraphicsLineItem* line = new QGraphicsLineItem(x, y, x_, y_);
    QPen pen;
    pen.setColor(color);
    line->setPen(pen);
    scene.addItem(line);
}


void Figure::addSceneDot(int x, int y,int size, QGraphicsScene& scene) {

    QGraphicsEllipseItem* point = new QGraphicsEllipseItem(x - size / 2, y - size / 2, size, size);
    point->setBrush(QBrush(Qt::black)); 
    scene.addItem(point);

}


void Figure::matrixTransform(const Vector2D<double>& rotateMatrix) {

    for (auto row = displaypoints.begin(); row != displaypoints.end(); ++row)
        MyMath::multiplyMatrix4441(rotateMatrix, *row);
    
}


void Figure::addPointToDisplay(std::vector<double> scalar) {
    for (int i = 0; i < displaypoints.size(); i++) {
        for (int j = 0; j < 3; j++) {

            displaypoints[i][j] = displaypoints[i][j] + scalar[j];
        }

    }
   
}


void Figure::reducePointToDisplay(std::vector<double> scalar) {
    for (int i = 0; i < displaypoints.size(); i++) {
        for (int j = 0; j < 3; j++) {

            displaypoints[i][j] = displaypoints[i][j] - scalar[j];
        }

    }
}


void Figure::setDefaultDisplayPoints() {

    displaypoints = points;
        

}


Rectangle::Rectangle(int x, int y,int z, int width, int height, int deep,std::vector<double> scalar):Figure() {
    fillPoints(x, y,z, width, height, deep,scalar);
    addPointToDisplay(scalar);
}


void Rectangle::fillPoints(double x, double y, double z, double width, double height, double deep, std::vector<double> scalar) {
    points.resize(8);
    for (int i = 0; i < 8; ++i) {
        points[i].resize(4);
    }

    points[0] = { x,        y,        z,        1 };
    points[1] = { x + width, y,        z,        1 };
    points[2] = { x + width, y + height, z,        1 };
    points[3] = { x,        y + height, z,        1 };
    points[4] = { x,        y,        z + deep, 1 };
    points[5] = { x + width, y,        z + deep, 1 };
    points[6] = { x + width, y + height, z + deep, 1 };
    points[7] = { x,        y + height, z + deep, 1 };
    
    setDefaultDisplayPoints();
}


void Rectangle::draw(QGraphicsScene& scene) {

    int k = 0;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {

            addSceneLine(displaypoints[k][0], displaypoints[k][1], displaypoints[k + 1][0], displaypoints[k + 1][1], scene);
            k++;

        }
        addSceneLine(displaypoints[k][0],displaypoints[k][1],displaypoints[k - 3][0],displaypoints[k - 3][1], scene);
        k = 4;
    }

    k = 0;
    for (int i = 0; i < 4; i++) {

        addSceneLine(displaypoints[k][0],displaypoints[k][1],displaypoints[k + 4][0], displaypoints[k + 4][1], scene);
        k++;

    }

}


void Rectangle::drawRec(QGraphicsScene& scene, std::vector<double> viewPos) {

    for (int i = 0; i < faceIndices.size();++i) {

        std::vector<double> koefs = roberts(i);
        double form = (koefs[0] * -viewPos[0] + koefs[1] * viewPos[1] + koefs[2] * viewPos[2] + koefs[3]);
        if (form > 0) {

            const std::vector<int>& face = faceIndices[i];
            for (size_t j = 0; j < face.size(); ++j) {
                int current = face[j];
                int next = face[(j + 1) % face.size()];
                addSceneLine(displaypoints[current][0], displaypoints[current][1],
                    displaypoints[next][0], displaypoints[next][1], scene);
            }

        }
        

    }



}

std::vector<double> Rectangle::roberts(int faceId) {
  
    std::vector<int> face = faceIndices[faceId];
    Vector3 p0 = { points[face[0]][0], points[face[0]][1], points[face[0]][2] };
    Vector3 p1 = { points[face[1]][0], points[face[1]][1], points[face[1]][2] };
    Vector3 p2 = { points[face[2]][0], points[face[2]][1], points[face[2]][2] };

    Vector3 v1 = p1 - p0;
    Vector3 v2 = p2 - p0;
    double A = v1.y * v2.z - v2.y * v1.z;
    double B = v1.z * v2.x - v2.z * v1.x;
    double C = v1.x * v2.y - v2.x * v1.y;
    double D = -(A * v1.x + B * v1.y + C * v1.z);

    Vector3 W = { 0, 0, 0 };
    for (int i = 0; i < 4; ++i) {
        W.x += points[face[i]][0];
        W.y += points[face[i]][1];
        W.z += points[face[i]][2];
    }
    W.x /= 4;
    W.y /= 4;
    W.z /= 4;

    double m = (A*W.x + B*W.y + C*W.z + D) > 0? -1:1;

    A *= m;
    B *= m;
    C *= m;
    D *= m;

    return std::vector<double>{A, B, C, D};
}


BezieCurve::BezieCurve(std::vector<std::vector<double>> vecPoints, std::vector<double> center, double stepT):
stepT_(stepT),
center_(center)
{

    for (std::vector<double> point : vecPoints) {
        point.push_back(1);
        points.push_back(std::move(point));
    }

    displayMainpoints = points;

    MyMath::calculateBezierPoints(points, displaypoints, stepT);

    
    addPointToDisplay(center);

}


void BezieCurve::matrixTransform(const Vector2D<double>& rotateMatrix) {

    for (auto row = displaypoints.begin(); row != displaypoints.end(); ++row)
        MyMath::multiplyMatrix4441(rotateMatrix, *row);

    for (auto row = displayMainpoints.begin(); row != displayMainpoints.end(); ++row)
        MyMath::multiplyMatrix4441(rotateMatrix, *row);
}


void BezieCurve::addPointToDisplay(std::vector<double> scalar) {
    for (int i = 0; i < displaypoints.size(); i++) {
        for (int j = 0; j < 3; j++) {

            displaypoints[i][j] = displaypoints[i][j] + scalar[j];
        }

    }

    for (int i = 0; i < displayMainpoints.size(); i++) {
        for (int j = 0; j < 3; j++) {

            displayMainpoints[i][j] = displayMainpoints[i][j] + scalar[j];
        }

    }

}


void BezieCurve::reducePointToDisplay(std::vector<double> scalar) {
    for (int i = 0; i < displaypoints.size(); i++) {
        for (int j = 0; j < 3; j++) {

            displaypoints[i][j] = displaypoints[i][j] - scalar[j];
        }

    }

    for (int i = 0; i < displayMainpoints.size(); i++) {
        for (int j = 0; j < 3; j++) {

            displayMainpoints[i][j] = displayMainpoints[i][j] - scalar[j];
        }

    }
}



void BezieCurve::draw(QGraphicsScene& scene) {

    
    for (auto row = 0; row < displaypoints.size() -1; row++) {
        
        
        addSceneLine(displaypoints[row][0], displaypoints[row][1], displaypoints[row + 1][0], displaypoints[row + 1][1], scene);
        addSceneDot(displaypoints[row][0], displaypoints[row][1], 5, scene);
    }
    addSceneDot(displaypoints.back()[0], displaypoints.back()[1], 5, scene);

    for (auto row = 0; row < displayMainpoints.size() - 1; row++) {


        addSceneLine(displayMainpoints[row][0], displayMainpoints[row][1], displayMainpoints[row + 1][0], displayMainpoints[row + 1][1], scene);
        addSceneDot(displayMainpoints[row][0], displayMainpoints[row][1], 5, scene);
    }
    addSceneDot(displayMainpoints.back()[0], displayMainpoints.back()[1], 5, scene);

}


BezieSurface::BezieSurface(std::vector<std::vector<std::vector<double>>>& vecPoints, std::vector<double> center, double stepT) {

    std::vector<std::vector<double>> bezieCurve;
    std::vector<std::vector<std::vector<double>>> bezieCurves;
    std::vector<std::vector<double>> newBezieCurve;
    
    for (std::vector<std::vector<double>> controlPointsCurve : vecPoints) {
        bezieCurve.clear();
        MyMath::calculateBezierPoints(controlPointsCurve, bezieCurve, stepT);
        bezieCurves.push_back(bezieCurve);
    }

    curveSize = bezieCurve.size();
    int sizeCurves = bezieCurves.size();
   
   
    for (int i = 0; i < curveSize; ++i) {
        bezieCurve.clear();
        newBezieCurve.clear();
        for (int j = 0; j < sizeCurves; ++j) {
            newBezieCurve.push_back(bezieCurves[j][i]);
        }

        MyMath::calculateBezierPoints(newBezieCurve, bezieCurve, stepT);
        bezieCurves.push_back(bezieCurve);

    }

   for (int i = 1; i < sizeCurves - 1; ++i) {
        bezieCurves.erase(bezieCurves.begin() + 1);
        qDebug() << "qqw";
    }



    for (std::vector<std::vector<double>> curve : bezieCurves) {
        for (std::vector<double> dot : curve) {
            dot.push_back(1);
            displaypoints.push_back(dot);
        }
    };

    addPointToDisplay(center);
  
    

}

void BezieSurface::draw(QGraphicsScene& scene) {

    int curveStart = 0;


    while (curveStart < displaypoints.size()) {
        int curveEnd = curveStart + curveSize - 1;

        for (auto dot = curveStart; dot < curveEnd; dot++) {

            addSceneLine(displaypoints[dot][0], displaypoints[dot][1], displaypoints[dot + 1][0], displaypoints[dot + 1][1], scene);
            addSceneDot(displaypoints[dot][0], displaypoints[dot][1], 5, scene);
        }
        addSceneDot(displaypoints[curveEnd][0], displaypoints[curveEnd][1], 5, scene);

        curveStart = curveEnd + 1;
    }

}


Segments::Segments(std::vector<std::vector<double>> vecPoints, std::vector<double> center) {
    // Проверяем, четное ли количество точек в vecPoints
    if (vecPoints.size() % 2 != 0 && !vecPoints.empty()) {
        // Удаляем последнюю точку, если количество нечетное
        vecPoints.pop_back();
    }

    for (std::vector<double>& point : vecPoints) {
        point.push_back(1);
        points.push_back(std::move(point));
    }
    displaypoints = points;

    Figure::addPointToDisplay(center);
}

void Segments::draw(QGraphicsScene& scene) {

    for (auto row = 0; row < displaypoints.size(); row+=2) {


        addSceneLine(displaypoints[row][0], displaypoints[row][1], displaypoints[row + 1][0], displaypoints[row + 1][1], scene);
        addSceneDot(displaypoints[row][0], displaypoints[row][1], 5, scene);
        addSceneDot(displaypoints[row+1][0], displaypoints[row+1][1], 5, scene);
    }
    
    if (showCutted) {

        for (auto row = 0; row < displayCuttedpoints.size(); row += 2) {


            addSceneLineWColor(displayCuttedpoints[row][0], displayCuttedpoints[row][1], displayCuttedpoints[row + 1][0], displayCuttedpoints[row + 1][1], scene, Qt::red);
            addSceneDot(displayCuttedpoints[row][0], displayCuttedpoints[row][1], 5, scene);
            addSceneDot(displayCuttedpoints[row + 1][0], displayCuttedpoints[row + 1][1], 5, scene);
        }

    }


}


void Segments::CutPoints(Rectangle& rectangle, std::vector<double>& center){

    Area area = Area(rectangle.points[3], rectangle.points[5]);
    bool a;
    std::vector<double> startPoint;
    std::vector<double> endPoint;


    for (auto row = 0; row < points.size(); row+=2) {

        std::vector<double> startPoint = points[row];
        std::vector<double> endPoint = points[row+1];

        if (clipSegment(startPoint, endPoint, area)) {

            cuttedpoints.push_back(startPoint);
            cuttedpoints.push_back(endPoint);

        }
 
    }
    displayCuttedpoints = cuttedpoints;
    Figure::reducePointToDisplay(center);
    Segments::addPointToDisplay(center);



}

bool Segments::clipSegment(std::vector<double>& startPoint, std::vector<double>& endPoint, const Area& anArea) {
    // Получаем коды начальной и конечной точек отрезка
    int outcode0 = MyMath::GetCode(startPoint, anArea);
    int outcode1 = MyMath::GetCode(endPoint, anArea);

    // Переменные для хранения временных координат точек пересечения
    std::vector<double>& tempPoint0 = startPoint;
    std::vector<double>& tempPoint1 = endPoint;

    // Переменная для хранения флага завершения отсечения
    bool done = false;

    do {
        if (!(outcode0 | outcode1)) { // Отрезок полностью видимый
            done = true;
        }
        else if (outcode0 & outcode1) { // Отрезок полностью невидимый
            return false;
            done = true;
        }
        else { // Отрезок частично видимый. Вычисление точек пересечения отрезка и области отсечения
            int outcodeOut = outcode0 ? outcode0 : outcode1;
            double x, y, z;

            // Находим точку пересечения отрезка с границей прямоугольника
            if (outcodeOut & TOP) {
                x = tempPoint0[0] + (tempPoint1[0] - tempPoint0[0]) * (anArea.ylt - tempPoint0[1]) / (tempPoint1[1] - tempPoint0[1]);
                z = tempPoint0[2] + (tempPoint1[2] - tempPoint0[2]) * (anArea.ylt - tempPoint0[1]) / (tempPoint1[1] - tempPoint0[1]);
                y = anArea.ylt;
            }
            else if (outcodeOut & BOTTOM) {
                x = tempPoint0[0] + (tempPoint1[0] - tempPoint0[0]) * (anArea.yrb - tempPoint0[1]) / (tempPoint1[1] - tempPoint0[1]);
                z = tempPoint0[2] + (tempPoint1[2] - tempPoint0[2]) * (anArea.yrb - tempPoint0[1]) / (tempPoint1[1] - tempPoint0[1]);
                y = anArea.yrb;
            }
            else if (outcodeOut & RIGHT) {
                y = tempPoint0[1] + (tempPoint1[1] - tempPoint0[1]) * (anArea.xrb - tempPoint0[0]) / (tempPoint1[0] - tempPoint0[0]);
                z = tempPoint0[2] + (tempPoint1[2] - tempPoint0[2]) * (anArea.xrb - tempPoint0[0]) / (tempPoint1[0] - tempPoint0[0]);
                x = anArea.xrb;
            }
            else if (outcodeOut & LEFT) {
                y = tempPoint0[1] + (tempPoint1[1] - tempPoint0[1]) * (anArea.xlt - tempPoint0[0]) / (tempPoint1[0] - tempPoint0[0]);
                z = tempPoint0[2] + (tempPoint1[2] - tempPoint0[2]) * (anArea.xlt - tempPoint0[0]) / (tempPoint1[0] - tempPoint0[0]);
                x = anArea.xlt;
            }
            else if (outcodeOut & FRONT) {
                x = tempPoint0[0] + (tempPoint1[0] - tempPoint0[0]) * (anArea.zlt - tempPoint0[2]) / (tempPoint1[2] - tempPoint0[2]);
                y = tempPoint0[1] + (tempPoint1[1] - tempPoint0[1]) * (anArea.zlt - tempPoint0[2]) / (tempPoint1[2] - tempPoint0[2]);
                z = anArea.zlt;
            }
            else if (outcodeOut & BACK) {
                x = tempPoint0[0] + (tempPoint1[0] - tempPoint0[0]) * (anArea.zrb - tempPoint0[2]) / (tempPoint1[2] - tempPoint0[2]);
                y = tempPoint0[1] + (tempPoint1[1] - tempPoint0[1]) * (anArea.zrb - tempPoint0[2]) / (tempPoint1[2] - tempPoint0[2]);
                z = anArea.zrb;
            }

            // Обновляем координаты точки пересечения
            if (outcodeOut == outcode0) {
                tempPoint0[0] = x;
                tempPoint0[1] = y;
                tempPoint0[2] = z;
                outcode0 = MyMath::GetCode(tempPoint0, anArea);
            }
            else {
                tempPoint1[0] = x;
                tempPoint1[1] = y;
                tempPoint1[2] = z;
                outcode1 = MyMath::GetCode(tempPoint1, anArea);
            }
        }
    } while (!done);
    return true;
}




void Segments::matrixTransform(const Vector2D<double>& rotateMatrix) {

    for (auto row = displaypoints.begin(); row != displaypoints.end(); ++row)
        MyMath::multiplyMatrix4441(rotateMatrix, *row);

    for (auto row = displayCuttedpoints.begin(); row != displayCuttedpoints.end(); ++row)
        MyMath::multiplyMatrix4441(rotateMatrix, *row);
}


void Segments::addPointToDisplay(std::vector<double> scalar) {
    for (int i = 0; i < displaypoints.size(); i++) {
        for (int j = 0; j < 3; j++) {

            displaypoints[i][j] = displaypoints[i][j] + scalar[j];
        }

    }

    for (int i = 0; i < displayCuttedpoints.size(); i++) {
        for (int j = 0; j < 3; j++) {

            displayCuttedpoints[i][j] = displayCuttedpoints[i][j] + scalar[j];
        }

    }

}


void Segments::reducePointToDisplay(std::vector<double> scalar) {
    for (int i = 0; i < displaypoints.size(); i++) {
        for (int j = 0; j < 3; j++) {

            displaypoints[i][j] = displaypoints[i][j] - scalar[j];
        }

    }

    for (int i = 0; i < displayCuttedpoints.size(); i++) {
        for (int j = 0; j < 3; j++) {

            displayCuttedpoints[i][j] = displayCuttedpoints[i][j] - scalar[j];
        }

    }
}

void Segments::showCut(bool a) {

    showCutted = a;
}