#include "PointFields.h"
#include <QtWidgets>


PointFields::PointFields(QWidget *parent, std::optional<std::vector<double>> values)
	: QWidget(parent)
{
    x = new QTextEdit("X");
    y = new QTextEdit("Y");
    z = new QTextEdit("Z");

    if (values.has_value()) {
        x->setText(QString::number(values.value()[0]));
        y->setText(QString::number(values.value()[1]));
        z->setText(QString::number(values.value()[2]));
    }
     layout = new QHBoxLayout(this);

    layout->addWidget(x);
    layout->addWidget(y);
    layout->addWidget(z);

    this->setLayout(layout);
}

PointFields::~PointFields()
{}
