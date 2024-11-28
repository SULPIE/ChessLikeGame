#include "ai.hpp"

AI::AI(std::shared_ptr<ChessBoard> chessBoard) : board(chessBoard) {}

void AI::makeMove() 
{
    std::vector<std::pair<int, int>> aiPieces;

    for (int y = 0; y < BOARD_SIZE; ++y) 
    {
        for (int x = 0; x < BOARD_SIZE; ++x) 
        {
            if (board->getCell(x, y) == Player::AI) 
            {
                aiPieces.push_back({ x, y });
            }
        }
    }

    if (!aiPieces.empty()) 
    {
        auto& [fromX, fromY] = aiPieces[rand() % aiPieces.size()];

        std::vector<std::pair<int, int>> directions = 
        {
            {fromX + 1, fromY}, {fromX - 1, fromY}, {fromX, fromY + 1}, {fromX, fromY - 1}
        };

        for (const auto& [toX, toY] : directions) 
        {
            if (toX >= 0 && toX < BOARD_SIZE && toY >= 0 && toY < BOARD_SIZE &&
                board->movePiece(fromX, fromY, toX, toY)) 
            {
                return;
            }
        }
    }
}