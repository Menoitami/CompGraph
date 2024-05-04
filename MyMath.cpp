#include "MyMath.h"

#define BOTTOM 1   // 00 000001
#define LEFT   2   // 00 000010
#define TOP    4   // 00 000100
#define RIGHT  8   // 00 001000
#define BACK  16   // 00 010000
#define FRONT 32   // 00 100000


namespace myMath {

    void MyMath::calculateViewAngle(const std::vector<double>& viewPos, double& verticalAngle, double& horizontalAngle, double& zAngle) {
        const double v1x = viewPos[0];
        const double v1y = viewPos[1];
        const double v1z = viewPos[2];

        double v2x = 0;
        double v2z = 400; // изменено на положительное значение

        double scalar = v1x * v2x + v1z * v2z;
        double lengths = sqrt(pow(v1x, 2) + pow(v1z, 2)) * sqrt(pow(v2x, 2) + pow(v2z, 2));
        horizontalAngle = acos(scalar / lengths);

        if (v1x < 0) horizontalAngle = -horizontalAngle;

        v2x = viewPos[0];
        const double v2y = 0;
        v2z = viewPos[2];

        scalar = v1x * v2x + v1y * v2y + v1z * v2z;
        lengths = sqrt(pow(v1x, 2) + pow(v1y, 2) + pow(v1z, 2)) * sqrt(pow(v2x, 2) + pow(v2y, 2) + pow(v2z, 2));
        verticalAngle = acos(scalar / lengths);

        if (v1y < 0) verticalAngle = -verticalAngle;

        // Calculate angle along z-axis
        v2x = 0;
        v2z = viewPos[2];
        scalar = v1z * v2z;
        lengths = sqrt(pow(v1z, 2)) * sqrt(pow(v2z, 2));
        zAngle = acos(scalar / lengths);

        if (v1z < 0) zAngle = -zAngle;

        // Check for NaN values
        horizontalAngle = std::isnan(horizontalAngle) ? 0 : horizontalAngle;
        verticalAngle = std::isnan(verticalAngle) ? 0 : verticalAngle;
        zAngle = std::isnan(zAngle) ? 0 : zAngle;
    }



    void MyMath::multiplyMatrix4441(const Vector2D<double>& rotateMatrix, std::vector<double>& out41) {

        double result[4];
        for (int i = 0; i < 4; ++i) {
            result[i] = 0;
            for (int j = 0; j < 4; ++j) {
                result[i] += rotateMatrix[i][j] * out41[j];
            }
        }

        for (int i = 0; i < 4; ++i) {
            out41[i] = result[i];
        }


    };

    double MyMath::binomialCoefficient(int n, int k) {

        int result = 1;
        for (int i = 1; i <= k; ++i) {
            result *= (n - i + 1);
            result /= i;
        }
        return result;
    }

    double MyMath::bernstein(int n, int k, double t) {
        
        double binomialCoefficient = MyMath::binomialCoefficient(n, k);
       
        return binomialCoefficient * pow(t, k) * pow(1 - t, n - k);
    }

    void MyMath::calculateBezierPoints(std::vector<std::vector<double>>& points, std::vector<std::vector<double>>& displaypoints, double stepT) {

        if (!displaypoints.empty()) {
            throw std::runtime_error("Displaypoints vector is not empty!");
            return;
        };

        int len = points.size();
        std::vector<double> point;
        
        displaypoints.push_back(points.front());


        for (double t=stepT; t <= 1; t += stepT) {
            
            point = { 0,0,0,1 };

            for (int i = 0; i < len; i++) {
                double b = bernstein(len-1, i, t);
                point[0] += points[i][0] * b;
                point[1] += points[i][1] * b;
                point[2] += points[i][2] * b;
            }
          
            displaypoints.push_back(point);
        }

        
       
        
    }





    void MyMath::calculateBezierSurfacePoints(std::vector<std::vector<double>>& points, std::vector<std::vector<double>>& displaypoints, double stepT) {
        if (!displaypoints.empty()) {
            throw std::runtime_error("Displaypoints vector is not empty!");
            return;
        }

    }



    int MyMath::GetCode(const std::vector<double>& point, const Area& anArea) {
        int code = 0;
        if (point[1] > anArea.ylt)     // Точка выше области отсечения
            code |= TOP;
        else if (point[1] < anArea.yrb)// Точка ниже области отсечения
            code |= BOTTOM;
        if (point[0] > anArea.xrb)     // Точка правее области отсечения
            code |= RIGHT;
        else if (point[0] < anArea.xlt)// Точка левее области отсечения
            code |= LEFT;
        if (point[2] < anArea.zlt)     // Точка перед областью отсечения
            code |= FRONT;
        else if (point[2] > anArea.zrb)// Точка за областью отсечения    
            code |= BACK;
        return code;
    }




   

    std::vector<double> MyMath::findExtremePoint(std::vector<std::vector<double>>& points, std::function<bool(double, double)> compare) {
        if (points.empty()) {
            return {};
        }

        size_t dimensions = points[0].size();
        std::vector<double> extremePoint = points[0];

        for (const auto& point : points) {
            for (size_t i = 0; i < dimensions; ++i) {
                if (compare(point[i], extremePoint[i])) {
                    extremePoint[i] = point[i];
                }
            }
        }

        return extremePoint;
    }

}









