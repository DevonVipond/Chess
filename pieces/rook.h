#include "pieces/piece.h"

#ifndef ROOK_H
#define ROOK_H

class Rook : public Piece {
public:
    Rook() : Piece(){}
    Rook(Player p);
    ~Rook() override {}

    bool validMove(Coordinate src, Coordinate dest) override;

    std::string getName() override {return player == Player::WHITE ? "WHITE_ROOK" : "BLACK_ROOK";}
};

#endif // ROOK_H
