#include "piece.h"

#ifndef ROOK_H
#define ROOK_H

class Rook : public Piece {
public:
    Rook() : Piece(){}
    Rook(Player p);
    ~Rook() override {}

    bool validMove(Coordinate src, Coordinate dest) override;
    char display() const override;

};

#endif // ROOK_H
