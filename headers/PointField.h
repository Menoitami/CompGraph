#pragma once

#include <QWidget>
#include "ui_PointField.h"

class PointField : public QWidget
{
	Q_OBJECT

public:
	PointField(QWidget *parent = nullptr, std::vector<double> values = {}, size_t pointN = 0);
	~PointField();

signals:
	void pointChanged_signal(size_t pointN, std::vector<double> values);

private:
	size_t pointN_;
	Ui::PointFieldClass ui;
};
