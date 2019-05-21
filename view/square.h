#include "coordinate.h"

#ifndef CHESSBOX_H
#define CHESSBOX_H

//#include <QGraphicsRectItem>
//#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QLabel>
#include <QString>
//#include <QPushButton>

#include "piece.h"

static Coordinate firstSelectedSquare();

class Square : public QLabel
{
    Q_OBJECT
signals:
    void updateDisplay();
public:
     Square(QWidget *parent=nullptr):QLabel(parent) {}
     Square(QWidget *parent=nullptr, QString imagePath="", bool hasPiece=false);
    ~Square() override {}

    void mouseButtonPressEvent(QGraphicsSceneMouseEvent *event);
    void setColor();
    void setImage(QString imagePath);
    bool event(QEvent *e);

    int xCord;
    int yCord;
private:
    bool hasPiece;
    char pieceIcon;
    QBrush brush;
    QLabel* image;
};
#endif
