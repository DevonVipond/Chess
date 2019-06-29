#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QPushButton>

#include "view/square.h"
#include "coordinate.h"

class Button : public QPushButton
{
    Q_OBJECT
signals:
    void updateDisplay(bool update);
public:
    Button(QWidget *parent=nullptr):QPushButton(parent) {}
    bool event(QEvent *e);
};

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
    Button *undoMove;

signals:
    void updateDisplay(bool update=true);
public slots:
    bool drawBoard(bool update=true);
private:
    void announceWinner(Player winner);

    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    int WINDOW_WIDTH = width();
    int TOP_LEFT_CORNER = 50;
    Square *collection[8][8];

};

#endif // MAINWINDOW_H
