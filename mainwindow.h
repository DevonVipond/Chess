#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QWidget>

#include "view/square.h"
#include "coordinate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QWidget *window;

signals:
    void updateDisplay();
public slots:
    bool drawBoard();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    int WINDOW_WIDTH = width();
    int TOP_LEFT_CORNER = 50;
    Square *collection[8][8];

};

#endif // MAINWINDOW_H
