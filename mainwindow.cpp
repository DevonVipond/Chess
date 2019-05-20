#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QString>
#include <unordered_map>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chessboard.h"

static const char NO_PIECE_ICON = '!';

//inline void log(std::string s){ std::cout << s << std::endl;}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QWidget *myWidget = new QWidget(this);
    myWidget->setGeometry(0,0,1370,700);
    myWidget->show();
    //scene->setSceneRect(0,0,1400,900);
    //setFixedSize(1400,900);

    auto chessBoard = ChessBoard::getInstance();
    //vector<vector<char>> board = chessBoard->getBoardAsVector();
    vector<vector<char>> board = {
        {'P','P','P','P','P','P','P','P'},
        {'p','p','p','p','p','p','p','p'},
        {'p','p','p','p','p','p','p','p'},
        {'p','p','p','p','p','p','p','p'},
        {'p','p','p','p','p','p','p','p'},
        {'p','p','p','p','p','p','p','p'},
        {'p','p','p','p','p','p','p','p'},
        {'p','p','p','p','p','p','p','p'}
                                 };
    if(!drawBoard(myWidget, board))
    {
        std::cout << "unable to draw board";
        exit(1);
    }
    else
    {
        std::cout << "successfully drawed board \n";
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::drawBoard(QWidget *parent, std::vector<std::vector<char>> board)
{
    static int log = 0;
    int shift = 100;
    bool whiteTile = true;

    // Returns an unordered_map which maps each pieces icon to its image
    //auto getImagePath = [&]()
    //{
    //    // black images
    //    std::unordered_map<char, QString> iconToImagePath = {
    //        {'p', "images/pawn.png"},
    //        {'K', "images/knight.png"},
    //        {'R', "images/rook.png"},
    //        {'!', ""},
    //    };

    //    return iconToImagePath;
    //};

    int x = WINDOW_WIDTH/2 - 400;
    int y = 50;

    for(int c = 0; c < board.size(); c++)
    {
        for(int r = 0; r < board[0].size(); r++)
        {
            std::cout << "drawingSquare " << log++ << std::endl;

            //char icon =  board[r][c];
            //auto imageMap = getImagePath();
            //auto  imagePath = imageMap.find(icon);

            //if(imagePath == imageMap.end())
            //return false;

            // TODO: fix hella memory leak
            Square *square = new Square(parent, "");//imagePath->second);
            collection[r][c] = square;
            square->xCord = r;
            square->yCord = c;
            square->setGeometry(r*shift, c*shift, 100, 100);
            square->setPixmap(QPixmap(":/images/images/pawn.png"));
            if(whiteTile)
                this->setStyleSheet("QLabel {background-color: rgb(120, 120, 90);}:hover{background-color: rgb(170,85,127);}");
            else
                this->setStyleSheet("QLabel {background-color: rgb(211, 211, 158);}:hover{background-color: rgb(170,95,127);}");

            whiteTile = !whiteTile;
            //scene->addItem(square);
        }

        whiteTile = !whiteTile;
    }

    return true;
}
