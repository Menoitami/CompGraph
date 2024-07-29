#pragma once
#include "MyMath.h"

using namespace myMath;

class Matrix {

public:

	static Vector2D<double> rotateX(double angle);
	static Vector2D<double> rotateY(double angle);
	static Vector2D<double> rotateZ(double angle);

	static Vector2D<double> rotateVector(double angle, double x, double y, double z);

	static Vector2D<double> resize(double angle);

};