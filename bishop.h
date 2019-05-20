#include "piece.h"

#ifndef BISHOP_H
#define BISHOP_H

class Bishop : public Piece {
public:
    Bishop() : Piece() {}
    Bishop(Player p);
    ~Bishop() override {}

    bool validMove(Coordinate src, Coordinate dest) override;
    char display() const override;

    static const char icon = 'B';
};

#endif // BISHOP_H
