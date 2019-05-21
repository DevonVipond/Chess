#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QString>
#include <unordered_map>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chessboard.h"


//inline void log(std::string s){ std::cout << s << std::endl;}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    window = new QWidget(this);
    window->setGeometry(0,0,900,800);
    window->show();
    window->focusWidget();

    drawBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// TODO: refactor
bool MainWindow::drawBoard()
{
    static int log = 0;
    std::cout << "drawingSquare " << log++ << std::endl;
    int shift = 100;
    bool whiteTile = true;

    auto chessBoard = ChessBoard::getInstance();
    vector<vector<char>> board = chessBoard->getBoardAsVector();

    // Returns an unordered_map which maps each pieces icon to its image
    auto getImagePath = [&]()
    {
        // black images
        std::unordered_map<char, QString> iconToImagePath = {
            {'P', "pawn.png"},
            {'K', "horse.png"},
            {'R', "rook.png"},
            {'!', ""},
        };

        return iconToImagePath;
    };

    int x = WINDOW_WIDTH/2 - 400;
    int y = 50;

    for(int c = 0; c < board.size(); c++)
    {
        for(int r = 0; r < board[0].size(); r++)
        {

            char icon =  board[r][c];
            auto imageMap = getImagePath();
            auto imagePath = imageMap.find(icon);

            // if not create: create
            // else call update
            if(collection[r][c] == nullptr)
            {
                Square *square;
                if(imagePath != imageMap.end())
                    square = new Square(window, imagePath->second, true);
                else
                    square = new Square(window, "");

                collection[r][c] = square;
                square->xCord = r;
                square->yCord = c;
                square->setGeometry(r*shift, c*shift, 100, 100);

                if(whiteTile)
                    square->setStyleSheet("QLabel {background-color: white;}:hover{background-color: blue;}");
                else
                    square->setStyleSheet("QLabel {background-color: gray;}:hover{background-color: blue;}");

                connect(square, SIGNAL(updateDisplay()), this, SLOT(drawBoard()));
            }
            else
            {
                if(imagePath != imageMap.end())
                    collection[r][c]->update(imagePath->second, true);
                else
                    collection[r][c]->update("", false);
            }

            // TODO: fix hella memory leak


            whiteTile = !whiteTile;
        }

        whiteTile = !whiteTile;
    }

    return true;
}
