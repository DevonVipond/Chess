#include <vector>
#include <iostream>

#include "ai/aimovedeterminator.h"

typedef std::vector<double> Array;
typedef std::vector<Array> TwoDArray;

AIMoveDeterminator::AIMoveDeterminator()
{
}

std::vector<Coordinate> allPossibleMoves(Coordinate src)
{
    auto board = ChessBoard::getInstance();
    auto piece = board->getPiece(src.getX(), src.getY());

    std::vector<Coordinate> possibleMoves;
    for(int x = 0; x < MAX_WIDTH; x++)
        for(int y = 0; y < MAX_WIDTH; y++)
        {
            Coordinate possibleMove(x,y);
            if(piece->validMove(x,y))
            {
                possibleMoves.push_back(possibleMove);
            }
            else if(piece->validCapture(x,y))
            {
                possibleMoves.push_back(possibleMove);
            }
        }

    return possibleMoves;
}

double AIMoveDeterminator::evaluateBoard()
{
    auto board = ChessBoard::getInstance();

    double boardEval;
    for(int r = 0; r < MAX_WIDTH; r++)
        for(int c = 0; c < MAX_WIDTH; c++)
        {
            Coordinate coordinate(r,c);
            Piece *piece = board->getPiece(coordinate);

            if(piece == nullptr)
                continue;

            boardEval += piece->positionStrength(coordinate);
        }

    return boardEval;
}

double AIMoveDeterminator::minimax(int depth, int alpha, int beta, Player player, bool isMaximizer)
{
    if(depth == 0)
    {
        return -evaluateBoard();
    }

    auto board = ChessBoard::getInstance();

    int bestMove;
    if(isMaximizer)
    {
        bestMove = -9999;
        for(int r = 0; r < MAX_WIDTH; r++)
        {
            for(int c = 0; c < MAX_WIDTH; c++)
            {
                Coordinate coordinate(r,c);
                auto piece = board->getPiece(coordinate);

                if(piece == nullptr || piece->getPlayer() != player)
                    continue;

                std::vector<Coordinate> possibleMoves = allPossibleMoves(coordinate);

                Player oppositePlayer = (player == Player::WHITE ? Player::BLACK : Player::WHITE);
                for(Coordinate move : possibleMoves)
                {
                    if(board->movePiece(player, coordinate, move, true))
                    {
                        int moveEval = minimax(depth-1, alpha, beta, oppositePlayer, !isMaximizer);
                        bestMove = (bestMove > moveEval ? bestMove : moveEval);

                        // Revert to original position
                        board->movePiece(player, move, coordinate, true);

                        alpha = (alpha > bestMove ? alpha : bestMove);
                        if(beta <= alpha)
                            return bestMove;
                    }
                }
            }
        }

        return bestMove;
    }
    else
    {
        bestMove = 9999;
        for(int r = 0; r < MAX_WIDTH; r++)
        {
            for(int c = 0; c < MAX_WIDTH; c++)
            {
                Coordinate coordinate(r,c);
                auto piece = board->getPiece(coordinate);

                if(piece == nullptr || piece->getPlayer() != player)
                    continue;

                std::vector<Coordinate> possibleMoves = allPossibleMoves(coordinate);

                Player oppositePlayer = (player == Player::WHITE ? Player::BLACK : Player::WHITE);
                for(Coordinate move : possibleMoves)
                {
                    if(board->movePiece(player, coordinate, move, true))
                    {
                        int moveEval = minimax(depth-1, alpha, beta, oppositePlayer, !isMaximizer);
                        bestMove = (bestMove < moveEval ? bestMove : moveEval);

                        // Revert to original position
                        board->movePiece(player, move, coordinate, true);

                        beta = (beta < bestMove ? beta : bestMove);
                        if(beta <= alpha)
                            return bestMove;
                    }
                }
            }
        }

        return bestMove;
    }
}

void AIMoveDeterminator::minimaxRoot(const Player player)
{
    auto board = ChessBoard::getInstance();

    double bestMove = -9999;
    Coordinate bestCordDest, bestCordSrc;
    Piece *bestPiece = nullptr;
    for(int r = 0; r < MAX_WIDTH; r++)
        for(int c = 0; c < MAX_WIDTH; c++)
        {
            Coordinate coordinate(r,c);
            auto piece = board->getPiece(coordinate);

            if(piece == nullptr || piece->getPlayer() != player)
                continue;

            std::vector<Coordinate> possibleMoves = allPossibleMoves(coordinate);

            Player oppositePlayer = (player == Player::WHITE ? Player::BLACK : Player::WHITE);
            for(Coordinate move : possibleMoves)
            {

                if(board->movePiece(player, coordinate, move, true))
                {
                    double ret = minimax(3, -1000, 10000, oppositePlayer, false);
                    if(ret >= bestMove)
                    {
                        bestMove = ret;
                        bestCordSrc = coordinate;
                        bestCordDest = move;
                        bestPiece = piece;

                        std::cout << "Resetting bestMove: " << " " << bestCordDest.getX() << " "
                                  << bestCordDest.getY() << std::endl;
                    }

                    if(!board->movePiece(player, move, coordinate, true))
                    {
                        std::cout << "Error: unable to undo move. Board in invalid state\n";
                    }
                }
            }
        }

    std::cout << (player == Player::WHITE ? "WHITE\n" : "BLACK\n");
    if(bestPiece != nullptr)
    {
        std::cout << "Moving " << " " << bestCordDest.getX() << " "
                  << bestCordDest.getY() << std::endl;
        board->movePiece(player, bestCordSrc, bestCordDest, false);
    }
    else
    {
        std::cout << "Error: unable to move AI\n";
    }


}

