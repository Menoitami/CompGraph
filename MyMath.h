#pragma once

#include <qgraphicsview.h>
#include <qdebug.h>
#include <array>
#include <iostream>
#include "Area.h"

namespace myMath {

	struct Vector3 {
		double x, y, z;

		Vector3 operator-(const Vector3& v) const {
			return { x - v.x, y - v.y, z - v.z };
		}

		Vector3 cross(const Vector3& v) const {
			return { y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x };
		}

		Vector3 normalize() const {
			double len = std::sqrt(x * x + y * y + z * z);
			return { x / len, y / len, z / len };
		}
	};


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