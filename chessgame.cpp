#include "mainwindow.h"
#include <QApplication>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "chessboard.h"

using namespace std;

MainWindow *view;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    view = new MainWindow();
    view->setGeometry(0,0,800,800);
    view->show();


    return a.exec();
}
