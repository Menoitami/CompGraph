#include "PointField.h"

PointField::PointField(QWidget *parent, std::vector<double> values, size_t pointN)
	: QWidget(parent),
	pointN_(pointN)
{
	ui.setupUi(this);
	if (values.size() == 3) {
		ui.x->setText(QString::number(values[0]));
		ui.y->setText(QString::number(values[1]));
		ui.z->setText(QString::number(values[2]));
	}
	ui.pointN->setText(QString::number(pointN_));

	connect(ui.x, &QLineEdit::textChanged, this, [&]() {
		emit pointChanged_signal(pointN_, {ui.x->text().toDouble(),ui.y->text().toDouble(), ui.z->text().toDouble()});


		});
	connect(ui.y, &QLineEdit::textChanged, this, [&]() {
		emit pointChanged_signal(pointN_, { ui.x->text().toDouble(),ui.y->text().toDouble(), ui.z->text().toDouble() });


		});
	connect(ui.z, &QLineEdit::textChanged, this, [&]() {
		emit pointChanged_signal(pointN_, { ui.x->text().toDouble(),ui.y->text().toDouble(), ui.z->text().toDouble() });


		});
}

PointField::~PointField()
{}
