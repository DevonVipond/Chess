#include "coordinate.h"

#ifndef CHESSBOX_H
#define CHESSBOX_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QLabel>
#include <QString>

#include "piece.h"

static Coordinate firstSelectedSquare();

class Square : public QLabel
{
public:

    //Constructor
    Square(QWidget *parent=nullptr):QLabel(parent) {}
//Square::Square(QLabel *parent, QString imagePath) : QLabel(parent)
    Square(QWidget *parent=nullptr, QString imagePath="", bool hasPiece=false);
    ~Square() override {}

    //public member function
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setColor();
    void setImage(QString imagePath);

    int xCord;
    int yCord;
private:
    bool hasPiece;
    char pieceIcon;
    QBrush brush;
    QLabel* image;
};
#endif
