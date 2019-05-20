#include "piece.h"

#ifndef PAWN_H
#define PAWN_H

// TODO: first move can move two spaces
class Pawn : public Piece {
public:
    Pawn() : Piece()
    {}
    Pawn(Player p);
    ~Pawn() override {}

    bool validMove(Coordinate src, Coordinate dest) override;
    char display() const override;
};

#endif // PAWN_H


