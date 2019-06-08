#ifndef CHESSBOX_H
#define CHESSBOX_H

#include <QGraphicsSceneMouseEvent>
#include <QLabel>
#include <QString>

#include "pieces/piece.h"

static Coordinate firstSelectedSquare();

class Square : public QLabel
{
    Q_OBJECT
signals:
    void updateDisplay();
public:
     Square(QWidget *parent=nullptr):QLabel(parent) {}
     Square(QWidget *parent=nullptr, QString imagePath="", bool hasPiece=false,
            Player player=Player::UNKNOWN, Coordinate coordinate=NULL);
    ~Square() override;

    void mouseButtonPressEvent(QGraphicsSceneMouseEvent *event);
    void setColor();
    void setImage(QString imagePath);
    bool event(QEvent *e);
    void update(QString imagePath, bool hasPiece, Player player);

    Coordinate location;
private:
    Player player;
    bool hasPiece;
};
#endif
