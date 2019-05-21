#include "square.h"
#include "chessboard.h"

#include "iostream"

static const QString IMAGE_DIRECTORY_PATH = ":/images/images/";

Square::Square(QWidget *parent, QString imagePath, bool hasPiece) : QLabel (parent)
{
    //setZValue(-1);
    this->hasPiece = hasPiece;
    setImage(imagePath);
}

bool Square::event(QEvent *event)
{
    static int counter=0;
    if (event->type() == QEvent::MouseButtonPress)
    {

        std::cout << "in mousebuttonpress event" << counter++ << endl;
        auto board = ChessBoard::getInstance();

        Coordinate firstSelectedSquare = board->getFirstSelectedPiece();
        Coordinate selectedSquare(this->xCord, this->yCord);
        if(firstSelectedSquare.isValid())
        {
            if(firstSelectedSquare == selectedSquare)
            {
                return true;
            }
            else
            {
                if(board->movePiece(Player::WHITE, firstSelectedSquare, selectedSquare))
                {
                    std::cout << "moving piece\n";
                    firstSelectedSquare.clear();

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

void Square::mouseButtonPressEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "in mousePressEvent\n";
}

void Square::setColor()
{
}

void Square::setImage(QString imagePath)
{
    if (imagePath == "")
        return;

        this->setPixmap(IMAGE_DIRECTORY_PATH + imagePath);
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
