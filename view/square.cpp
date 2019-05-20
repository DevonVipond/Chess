#include "square.h"

Square::Square(QWidget *parent, QString imagePath) : QLabel(parent)
{
    //setRect(0,0,100,100);
    //brush.setStyle(Qt::SolidPattern);
    //setZValue(-1);

    setImage(imagePath);
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //TODO pass coor for src -> dest

}

void Square::setColor(QColor color)
{
    //brush.setColor(color);
    //setBrush(color);
}

void Square::setImage(QString imagePath)
{
    //if (imagePath == "" || imagePath == "!")
    //    return;

    this->setPixmap(QPixmap(":/images/pawn.png"));
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
