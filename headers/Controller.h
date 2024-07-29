#pragma once

#include <QWidget>
#include "PointField.h"
#include "ui_Controller.h"

class Controller : public QWidget
{
	Q_OBJECT

public:
	Controller( QWidget *parent = nullptr);
	~Controller();

	void addPoint(std::vector<double> values, size_t pointN) {
		fields.push_back(new PointField(this, values, pointN));
		ui.verticalLayout->addWidget(fields.back());
		connect(fields.back(), &PointField::pointChanged_signal, this, &Controller::emitPointChanged_slot);
	}

	void setObjN(int objN) {
		objN_ = objN;
	}
public slots:
	void emitPointChanged_slot(size_t pointN, std::vector<double> values) {
		emit pointChanged_signal(objN_, pointN, values);
	}

signals:
	void pointChanged_signal(size_t objN, size_t pointN, std::vector<double> values);

private:
	Ui::ControllerClass ui;

	int objN_;

	//QVBoxLayout* layout;
	QVector<PointField*> fields;
};
