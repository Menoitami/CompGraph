#include "Matrix.h"


Vector2D<double> Matrix::rotateX(double angle) {

    return {
        {1,0,0, 0},
        {0,cos(angle),-sin(angle), 0},
        {0,sin(angle),cos(angle), 0},
        {0,0,0, 1} };

};



Vector2D<double> Matrix::rotateY(double angle) {

    return {
        {cos(angle),0,sin(angle), 0},
        {0,1,0, 0},
        {-sin(angle),0,cos(angle), 0},
        {0,0,0, 1} };

};

Vector2D<double> Matrix::rotateZ(double angle) {

    return {
        {cos(angle), -sin(angle), 0, 0},
        {sin(angle), cos(angle), 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

};


Vector2D<double> Matrix::rotateVector(double angle, double x, double y, double z) {


    double c = cos(angle);
    double s = sin(angle);
    double cm1 = (1 - c);

    return {
        {c+pow(x,2)*cm1, x*y*cm1-z*s, x * z * cm1 + y * s, 0},
        {y * x * cm1 + z * s, c + pow(y,2) * cm1, y*z*cm1-x*s, 0},
        {z*x*cm1-y*s, z*y*cm1+x*s, c + pow(z,2) * cm1, 0},
        {0, 0, 0, 1}
    };
}




Vector2D<double> Matrix::resize(double angle) {

    return {
        {angle, 0, 0, 0},
        {0, angle, 0, 0},
        {0, 0, angle, 0},
        {0, 0, 0, 1}
    };

};