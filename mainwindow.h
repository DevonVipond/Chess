#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDialog>
#include <QtCore>
#include <QtGui>

#include "view/square.h"
#include "coordinate.h"

static Square *collection[8][8];

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool drawBoard(QWidget *parent, std::vector<std::vector<char>> board);
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    int WINDOW_WIDTH = width();
    int TOP_LEFT_CORNER = 50;
};

#endif // MAINWINDOW_H
