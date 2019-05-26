#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QString>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chessboard.h"
#include "translations.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    window = new QWidget(this);
    window->setGeometry(0,0,900,800);
    window->show();
    window->focusWidget();

    drawBoard(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// TODO: refactor
bool MainWindow::drawBoard(bool update)
{
    static int log = 0;
    std::cout << "drawingSquare " << log++ << std::endl;
    bool whiteTile = true;

    auto chessBoard = ChessBoard::getInstance();

    int x = WINDOW_WIDTH/2 - 400;
    int y = 50;

    auto createSquare = [=, &whiteTile](bool update, QString imagePath, Player player, int r=0, int c=0)
    {
        if(!update)
        {
            int shift = 100;
            Square *square;
            Coordinate coordinate(r,c);
            square = new Square(window, imagePath, player==Player::UNKNOWN?false:true, player, coordinate);
            square->setGeometry(r*shift, c*shift, 100, 100);

            collection[r][c] = square;

            if(whiteTile)
                square->setStyleSheet(WHITE_SQUARE_STYLE);
            else
                square->setStyleSheet(BLACK_SQUARE_STYLE);

            connect(square, SIGNAL(updateDisplay()), this, SLOT(drawBoard()));
        }
        else
        {
            collection[r][c]->update(imagePath, player==Player::UNKNOWN?false:true, player);
        }
    };

    for(int c = 0; c < MAX_HEIGHT; c++)
    {
        for(int r = 0; r < MAX_WIDTH; r++)
        {

            // Check if a piece exists at this location
            if(chessBoard->getPiece(r,c) != nullptr)
            {
                std::string name = chessBoard->getPiece(r,c)->getName();
                Player player = chessBoard->getPiece(r,c)->getPlayer();

                createSquare(update, QString::fromStdString(name), player, r, c);
            }
           else
            {
                createSquare(update, QString(NO_PIECE_ICON), Player::UNKNOWN, r, c);
            }

            // TODO: fix hella memory leak
            whiteTile = !whiteTile;
        }

        whiteTile = !whiteTile;
    }

    return true;
}
