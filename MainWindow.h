#pragma once

#include <QMainWindow>
#include "ui_MainWindow.h"
#include "DrawWindow.h"
#include "Controller.h"
#include <QTimer>


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();


private:
	Ui::MainWindow ui;
};
