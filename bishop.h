#include "piece.h"

#ifndef BISHOP_H
#define BISHOP_H

class Bishop : public Piece {
public:
    Bishop() : Piece() {}
    Bishop(Player p);
    ~Bishop() override {}

    bool validMove(Coordinate src, Coordinate dest) override;

    std::string getName() override {return player == Player::WHITE ? "WHITE_BISHOP" : "BLACK_BISHOP";}
};

#endif // BISHOP_H
