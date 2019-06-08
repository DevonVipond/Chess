#include "piece.h"

#ifndef QUEEN_H
#define QUEEN_H

class Queen : public Piece {
public:
    Queen() : Piece() {}
    Queen(Player p);
    ~Queen() override {}

    bool validMove(Coordinate src, Coordinate dest) override;
    std::string getName() override{return player == Player::WHITE ? "WHITE_QUEEN" : "BLACK_QUEEN";}
};

#endif // QUEEN_H
