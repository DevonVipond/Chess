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

    //scene = new QGraphicsScene(this);
    //ui->graphicsView->setScene(scene);
    //scene->setSceneRect(0,0,800,800);
    //setFixedSize(800,800);

    QWidget *myWidget = new QWidget(this);
    myWidget->setGeometry(0,0,800,800);
    myWidget->show();
    myWidget->focusWidget();

    auto chessBoard = ChessBoard::getInstance();
    vector<vector<char>> board = chessBoard->getBoardAsVector();
    //``vector<vector<char>> board = {
    //``    {'P','P','P','P','P','P','P','P'},
    //``    {'p','p','p','p','p','p','p','p'},
    //``    {'p','p','p','p','p','p','p','p'},
    //``    {'p','p','p','p','p','p','p','p'},
    //``    {'p','p','p','p','p','p','p','p'},
    //``    {'p','p','p','p','p','p','p','p'},
    //``    {'p','p','p','p','p','p','p','p'},
    //``    {'p','p','p','p','p','p','p','p'}
    //``                             };
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

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    std::cout << "in mainWindow mousepressevent \n";
    // Pass event down to the square
    //int row = event->x();
    //int row = event->();


}

bool MainWindow::drawBoard(QWidget *parent, std::vector<std::vector<char>> board)
{
    static int log = 0;
    int shift = 100;
    bool whiteTile = true;

    // Returns an unordered_map which maps each pieces icon to its image
    auto getImagePath = [&]()
    {
        // black images
        std::unordered_map<char, QString> iconToImagePath = {
            {'P', "pawn.png"},
            {'K', "knight.png"},
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
            std::cout << "drawingSquare " << log++ << std::endl;

            char icon =  board[r][c];
            auto imageMap = getImagePath();
            auto  imagePath = imageMap.find(icon);

            Square *square;
            if(imagePath != imageMap.end())
                square = new Square(parent, imagePath->second, true);
            else
                square = new Square(parent, "");


            // TODO: fix hella memory leak
            collection[r][c] = square;
            square->xCord = r;
            square->yCord = c;
            square->setGeometry(r*shift, c*shift, 100, 100);
            if(whiteTile)
                square->setStyleSheet("QLabel {background-color: white;}:hover{background-color: blue;}");
            else
                square->setStyleSheet("QLabel {background-color: gray;}:hover{background-color: blue;}");

            whiteTile = !whiteTile;
        }

        whiteTile = !whiteTile;
    }

    return true;
}
