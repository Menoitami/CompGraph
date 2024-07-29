#pragma once

#include <QtWidgets/QMainWindow>
#include <qgraphicsview.h>
#include <qdebug.h>
#include <QMouseEvent>

class GraphicsViewWrapper : public QGraphicsView {
    Q_OBJECT

public:
    GraphicsViewWrapper::GraphicsViewWrapper(QWidget* parent = nullptr)
        : QGraphicsView(parent) {
        setMouseTracking(false);
    
    }




private:
    bool firstClick = true;


signals:

    void mouseMove_signal(QMouseEvent* event);
    void mouseStartPos_signal(QMouseEvent* event);
    void mouseScroll_signal(QWheelEvent* event);


protected:
    void mousePressEvent(QMouseEvent* event) {

        if (event->button() == Qt::MiddleButton && firstClick) {

            firstClick = false;
            setMouseTracking(true);
            emit mouseStartPos_signal(event);
        }
    }


    void GraphicsViewWrapper::mouseMoveEvent(QMouseEvent* event) {
        if (hasMouseTracking()) {
            emit mouseMove_signal(event);
        }
    }


    void mouseReleaseEvent(QMouseEvent* event) {

        if (event->button() == Qt::MiddleButton) {

            firstClick = true;
            setMouseTracking(false);
        }

    }

    void wheelEvent(QWheelEvent* event) {
        emit  mouseScroll_signal(event);
    }

};