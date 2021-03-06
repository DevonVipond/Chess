#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QString>
#include <iostream>

#include "view/mainwindow.h"
#include "ui_mainwindow.h"
#include "models/chessboard.h"
#include "models/gamestate.h"
#include "translations.h"

// TODO rename to chessview
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    window = new QWidget(this);
    window->setGeometry(0,0,900,800);
    window->show();
    window->focusWidget();

    undoMove = new Button(window);
    undoMove->setText("UNDO");
    undoMove->show();
    undoMove->raise();
    connect(undoMove, SIGNAL(updateDisplay(bool)), this, SLOT(drawBoard(bool)));

    drawBoard(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

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

            connect(square, SIGNAL(updateDisplay(bool)), this, SLOT(drawBoard(bool)));
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
            Coordinate src(r,c);
            if(chessBoard->getPiece(src) != nullptr)
            {
                std::string name = chessBoard->getPiece(src)->getName();
                Player player = chessBoard->getPiece(src)->getPlayer();

                createSquare(update, QString::fromStdString(name), player, r, c);
            }
           else
            {
                createSquare(update, QString(NO_PIECE_ICON), Player::UNKNOWN, r, c);
            }

            whiteTile = !whiteTile;
        }

        whiteTile = !whiteTile;
    }

    auto gameState = GameState::getInstance();
    if(gameState->getWinner() != Player::UNKNOWN)
    {
       this->announceWinner(gameState->getWinner());
    }

    return true;
}

void MainWindow::announceWinner(Player winner)
{
    QLabel *winnerDialog = new QLabel(window);
    winnerDialog->setGeometry(300,300,600,500);
    winnerDialog->show();
    winnerDialog->focusWidget();

    QString winnerStr = winner == Player::WHITE ? "WHITE" : "BLACK";
    winnerDialog->setText(winnerStr);
}

bool Button::event(QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        auto board = ChessBoard::getInstance();
        board->undoMove();
        emit updateDisplay(false);
    }
}
