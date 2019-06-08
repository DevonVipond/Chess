
//#include <iostream>
//// TODO: consider moving into the controller into a ValidChessMove Class
//bool MoveValidator::movePiece(Player p, Coordinate src, Coordinate dest)
//{
//    // TODO: king cant move into danger
//    if(!src.isValid() || !dest.isValid())
//        return false;
//
//    Piece* srcPiece = board[src.getX()][src.getY()];
//
//    /*
//     * If no piece exits at src or
//     * if a piece exists at dest belongs to the same player, return false.
//     */
//    if(srcPiece ==  nullptr || (board[dest.getX()][dest.getY()] != nullptr &&
//                                board[dest.getX()][dest.getY()]->getPlayer() == p))
//    {
//        // No piece exits at src, return false
//        std::cout << "piece is null \n";
//        return false;
//    }
//
//    bool validMove = srcPiece->validMove(src, dest);
//
//    if(validMove)
//    {
//        Piece* destPiece = board[dest.getX()][dest.getY()];
//        Player srcPlayer = srcPiece->getPlayer();
//        Player destPlayer = destPiece->getPlayer();
//
//        // Check if its possible to capture an enemy piece at dest
//        if(destPiece != nullptr && srcPlayer != destPlayer);
//        {
//            // Capture the enemy piece
//            switch(destPlayer)
//            {
//                case Player::BLACK:
//                    capturedBlackPieces.push_back(destPiece);
//                    break;
//
//                case Player::WHITE:
//                    capturedWhitePieces.push_back(destPiece);
//                    break;
//                default:
//                    return false;
//            }
//        }
//
//        // Move Piece
//        board[dest.getX()][dest.getY()] = srcPiece;
//        board[src.getX()][src.getY()] = nullptr;
//    }
//
//    std::cout << "end of movePiece \n";
//    return validMove;
//}
//
