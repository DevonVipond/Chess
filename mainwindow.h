#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QGraphicsView>
//#include <QGraphicsItem>
//#include <QDialog>
//#include <QtCore>
//#include <QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
//    QGraphicsScene *scene;
//    QGraphicsEllipseItem * ellipse;
//    QGraphicsRectItem * rectangle;
};

#endif // MAINWINDOW_H
