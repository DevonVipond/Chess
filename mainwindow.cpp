#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QGraphicsScene scene;
//    QGraphicsRectItem *rect = scene.addRect(QRectF(0, 0, 100, 100));

//    scene = new QGraphicsScene(this);
//    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
