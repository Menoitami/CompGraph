#pragma once

#include <vector>
#include <qgraphicsview.h>
#include "ui_CompGraph.h"
#include "MyMath.h"

using namespace myMath;


class Figure {
public:
	virtual ~Figure() {}

	virtual void matrixTransform(const Vector2D<double>& rotateMatrix);
	virtual void addPointToDisplay(std::vector<double> scalar);
	virtual void reducePointToDisplay(std::vector<double> scalar);
	void setDefaultDisplayPoints();

	virtual void draw(QGraphicsScene& scene) = 0;
	virtual void calcPoints() = 0;

	virtual void changePoint(size_t pointN, std::vector<double> values) {
		points[pointN] = { values[0],values[1],values[2],1};
		displaypoints.clear();
		calcPoints();
	}
	std::vector<std::vector<double>> points;
protected:
	Figure() {};
	std::vector<std::vector<double>> displaypoints;
	void addSceneLine(int x, int y, int x_, int y_, QGraphicsScene& scene);
	void addSceneLineWColor(int x, int y, int x_, int y_, QGraphicsScene& scene, const QColor& color);
	void addSceneDot(int x, int y,int size, QGraphicsScene& scene);


};


class Rectangle: public Figure {

public:

	Rectangle(int x, int y,int z, int width, int height, int deep, std::vector<double> scalar);
	~Rectangle() {  };
	void calcPoints()  override {
	}
	void draw(QGraphicsScene& scene) override;

private:
	void fillPoints(int x, int y, int z, int width, int height, int deep, std::vector<double> scalar);

};




class BezieCurve : public Figure {
public:


	BezieCurve(std::vector<std::vector<double>> vecPoints, std::vector<double> center, double stepT);
	void draw(QGraphicsScene& scene) override;

	void calcPoints()  override {
		MyMath::calculateBezierPoints(points, displaypoints, stepT_);
		addPointToDisplay(center_);
	}

	void changePoint(size_t pointN, std::vector<double> values) override {
		points[pointN] = { values[0],values[1],values[2],1 };
		displayMainpoints = points;
		displaypoints.clear();
		calcPoints();
	}

	void matrixTransform(const Vector2D<double>& rotateMatrix) override;
	void addPointToDisplay(std::vector<double> scalar) override;
	void reducePointToDisplay(std::vector<double> scalar) override;

private:
	double stepT_;
	std::vector<double> center_;
	std::vector<std::vector<double>> displayMainpoints;


};


class BezieSurface : public Figure {
public:


	BezieSurface(std::vector<std::vector<std::vector<double>>>& vecPoints, std::vector<double> center, double stepT);

	void draw(QGraphicsScene& scene) override;
	void calcPoints()  override {
	}
	int curveSize;
	

};




class Segments : public Figure {

public:
	Segments(std::vector<std::vector<double>> vecPoints, std::vector<double> center);

	void draw(QGraphicsScene& scene) override;
	

	std::vector<std::vector<double>> cuttedpoints;
	std::vector<std::vector<double>> displayCuttedpoints;
	
	void CutPoints(Rectangle& rectangle, std::vector<double>& center);
	void calcPoints()  override {
	}

	void matrixTransform(const Vector2D<double>& rotateMatrix) override;
	void addPointToDisplay(std::vector<double> scalar) override;
	void reducePointToDisplay(std::vector<double> scalar) override;
	void showCut(bool a);

private:

	
	bool clipSegment(std::vector<double>& startPoint, std::vector<double>& endPoint, const Area& anArea);
	bool showCutted = false;




};