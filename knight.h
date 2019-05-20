#include "piece.h"

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight : public Piece {
public:
    Knight() : Piece() {}
    Knight(Player p);
    ~Knight() override {}

    bool validMove(Coordinate src, Coordinate dest) override;
    char display() const override;

};

#endif // KNIGHT_H
