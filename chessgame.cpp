#include "mainwindow.h"
#include <QApplication>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "chessboard.h"
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    auto chessBoard = ChessBoard::getInstance();

    chessBoard->displayBoard();
    cout << "\n";

  //  while() {
        int srcX, srcY, destX, destY;
        srcX = 1;
        srcY = 1;
        destX = 2;
        destY = 1;
        if(chessBoard->movePiece(Player::BLACK, Coordinate(srcX,srcY), Coordinate(destX,destY)))
        {
            cout << "valid move";
            chessBoard->displayBoard();
        }
        else
            cout << "invalid move";

        cout << "\n";
        //return a.exec();
   // }
}

