#ifndef AIMOVEDETERMINATOR_H
#define AIMOVEDETERMINATOR_H

#include <vector>
#include "models/chessboard.h"

class AIMoveDeterminator
{
public:
    AIMoveDeterminator();

    void minimaxRoot(const Player player);

private:
    double minimax(int depth, int alpha, int beta, Player player, bool isMaximizer);
    double evaluateBoard();

    int searchDeph = 3;
};

#endif // AIMOVEDETERMINATOR_H
