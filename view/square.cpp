#include "square.h"
#include "chessboard.h"

#include "iostream"

static const QString IMAGE_DIRECTORY_PATH = ":/images/images/";

Square::Square(QWidget *parent, QString imagePath, bool hasPiece) : QLabel(parent)
{
    //setZValue(-1);
    this->hasPiece = hasPiece;
    setImage(imagePath);
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "in mousePressEvent\n";
    auto board = ChessBoard::getInstance();

    Coordinate firstSelectedSquare = board->getFirstSelectedPiece();
    Coordinate selectedSquare(this->xCord, this->yCord);
    if(firstSelectedSquare.isValid())
    {
        if(firstSelectedSquare == selectedSquare)
        {
            return;
        }
        else
        {
            if(board->movePiece(Player::WHITE, firstSelectedSquare, selectedSquare))
            {
                firstSelectedSquare.clear();
            }
            else
            {
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

void Square::setColor()
{

    //if(column%8)
    //    whiteTile = !whiteTile;
    //else
    //    column = -1;
    //column++;
}

void Square::setImage(QString imagePath)
{
    if (imagePath == "")
        return;

    // TODO: add error handling
    this->setPixmap(QPixmap(IMAGE_DIRECTORY_PATH + imagePath));
    //image = new QLabel(this);
    ///** set content to show center in label */
    //image->setAlignment(Qt::AlignCenter);
    //QPixmap pix;

    ///** to check wether load ok */
    //if(pix.load(imagePath)){
    //    /** scale pixmap to fit in label'size and keep ratio of pixmap */
    //    pix = pix.scaled(image->size(),Qt::KeepAspectRatio);
    //    image->setPixmap(pix);
    //}
}
