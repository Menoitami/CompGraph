#pragma once

#include <qgraphicsview.h>
#include <qdebug.h>
#include <array>
#include <iostream>
#include "Area.h"

namespace myMath {
	template <class T>
	using Vector2D = std::vector<std::vector<T>>;


	template <class T>
	using Point = std::array<T, 4>;


	using BeziePointsT = std::shared_ptr< std::vector<std::vector<double>>>;

	class MyMath {


	public:
		static void calculateViewAngle(const std::vector<double>& viewPos, double& verticalAngle, double& horizontalAngle, double &zAngle);

		static void multiplyMatrix4441(const Vector2D<double>& rotateMatrix,
			std::vector<double>& out41);



		static double binomialCoefficient(int n, int k);
		//static void vectorProduct(std::vector<double>& base, std::vector<double>& out);
		static double bernstein(int k, int n, double t);

		static void calculateBezierPoints(std::vector<std::vector<double>>& points, std::vector<std::vector<double>>& displaypoints, double stepT);

		static void calculateBezierSurfacePoints(std::vector<std::vector<double>>& points, std::vector<std::vector<double>>& displaypoints, double stepT);

		static int MyMath::GetCode(const std::vector<double>& point, const Area& anArea);
		static std::vector<double> findExtremePoint(std::vector<std::vector<double>>& points, std::function<bool(double, double)> compare);
	};
}