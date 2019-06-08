#include "pieces/piece.h"

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight : public Piece {
public:
    Knight() : Piece() {}
    Knight(Player p);
    ~Knight() override {}

    bool validMove(Coordinate src, Coordinate dest) override;
    std::string getName() override {return player == Player::WHITE ? "WHITE_KNIGHT" : "BLACK_KNIGHT";}
};

#endif // KNIGHT_H
