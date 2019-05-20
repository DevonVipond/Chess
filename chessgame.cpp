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
    view->show();

   // chessBoard->displayBoard();
   // cout << "\n";

   // while(1) {
   //     cout << "\n";
   //     int srcX, srcY, destX, destY;
   //     cin >> srcX;
   //     cin >> srcY;
   //     cin >> destX;
   //     cin >> destY;
   //     if(chessBoard->movePiece(Player::BLACK, Coordinate(srcX,srcY), Coordinate(destX,destY)))
   //     {
   //         cout << "valid move\n";
   //         chessBoard->displayBoard();
   //     }
   //     else
   //     {
   //         chessBoard->displayBoard();
   //         cout << "invalid move\n";
   //     }

   //     cout << "\n";

        return a.exec();
   // }
}

