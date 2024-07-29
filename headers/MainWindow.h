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

public slots:
	void showCutPoints_slot(int state) {
		segs->showCut(bool(state));
		ui.drawWindow->clearScene();
		ui.drawWindow->drawScene();
	}



private:
	Ui::MainWindow ui;
	Segments* segs;
};
