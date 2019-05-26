#include "square.h"
#include "chessboard.h"

#include "iostream"
#include <unordered_map>

Square::Square(QWidget *parent, QString imagePath, bool hasPiece, Player player, Coordinate coordinate) : QLabel (parent)
{
    this->hasPiece = hasPiece;
    this->player = player;
    this->location = coordinate;
    setImage(imagePath);
}

Square::~Square()
{
}

bool Square::event(QEvent *event)
{
    static int counter=0;
    if (event->type() == QEvent::MouseButtonPress)
    {
        auto board = ChessBoard::getInstance();

        Coordinate firstSelectedSquare = board->getFirstSelectedPiece();
        Coordinate selectedSquare(this->location.getX(), this->location.getY());
        if(firstSelectedSquare.isValid())
        {
            if(firstSelectedSquare == selectedSquare)
            {
                return true;
            }
            else
            {
                if(board->movePiece(this->player, firstSelectedSquare, selectedSquare))
                {
                    std::cout << "moving piece\n";
                    firstSelectedSquare.clear();
                    board->setFirstSelectedPiece(firstSelectedSquare);

                    emit updateDisplay();
                }
                else
                {
                    std::cout << "ERR: unable to move piece\n";

                    // TODO: IDK what to do here
                    // Prob make tile red
                }
            }
        }

        if(hasPiece)
        {
            std::cout << "resetting firstSelectedPiece\n";
            board->setFirstSelectedPiece(selectedSquare);
        }
    }

    return QWidget::event(event);
}

void Square::update(QString imagePath, bool hasPiece, Player player)
{
    this->hasPiece = hasPiece;
    setImage(imagePath);
}

void Square::mouseButtonPressEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "in mousePressEvent\n";
}

void Square::setColor()
{
}

void Square::setImage(QString imagePath)
{
    QString imageTranslation;

    if(imagePath ==  "WHITE_PAWN")
        imageTranslation = WHITE_PAWN;
    else if(imagePath == "WHITE_KNIGHT")
        imageTranslation = WHITE_KNIGHT;
    else if(imagePath == "WHITE_BISHOP")
        imageTranslation = WHITE_BISHOP;
    else if (imagePath ==  "WHITE_ROOK")
        imageTranslation = WHITE_ROOK;
    else if(imagePath == "WHITE_KING")
        imageTranslation = WHITE_KING;
    else if(imagePath == "WHITE_QUEEN")
        imageTranslation = WHITE_QUEEN;
    else if(imagePath == "BLACK_PAWN")
        imageTranslation = BLACK_PAWN;
    else if(imagePath == "BLACK_KNIGHT")
        imageTranslation = BLACK_KNIGHT;
    else if(imagePath == "BLACK_BISHOP")
        imageTranslation = BLACK_BISHOP;
    else if(imagePath == "BLACK_ROOK")
        imageTranslation = BLACK_ROOK;
    else if (imagePath  == "BLACK_KING")
        imageTranslation = BLACK_KING;
    else if (imagePath ==  "BLACK_QUEEN")
        imageTranslation = BLACK_QUEEN;
    else
        this->setPixmap(QPixmap());

    this->setPixmap(QPixmap(imageTranslation));
    //QPixmap pixmap;
    //if(pixmap.load(IMAGE_DIRECTORY_PATH + imagePath))
    //{
    //    //this->setPixmap(QPixmap(IMAGE_DIRECTORY_PATH + imagePath));
    //}
    //else
    //{
    //    std::cout << "No image found\n";
    //}
}
