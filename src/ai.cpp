#include "ai.hpp"
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

AI::AI(std::shared_ptr<ChessBoard> chessBoard) : board(chessBoard) {}

void AI::makeMove() 
{
    std::vector<std::pair<int, int>> targetCells = 
    {
        {0, 0}, {1, 0}, {2, 0},
        {0, 1}, {1, 1}, {2, 1},
        {0, 2}, {1, 2}, {2, 2}
    };

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

    for (auto& [fromX, fromY] : aiPieces) 
    {
        if (std::find(targetCells.begin(), targetCells.end(), std::make_pair(fromX, fromY)) != targetCells.end()) 
        {
            std::vector<std::pair<int, int>> directions = 
            {
                {fromX - 1, fromY}, {fromX, fromY - 1} 
            };

            for (const auto& [toX, toY] : directions) 
            {
                if (toX >= 0 && toX < BOARD_SIZE && toY >= 0 && toY < BOARD_SIZE) 
                {
                    if (board->getCell(toX, toY) == Player::NONE && board->movePiece(fromX, fromY, toX, toY)) 
                    {
                        return; 
                    }
                }
            }
            continue; 
        }


        std::pair<int, int> closestTarget = targetCells[0];
        int minDist = std::abs(fromX - closestTarget.first) + std::abs(fromY - closestTarget.second);

        for (const auto& target : targetCells) 
        {
            if (board->getCell(target.first, target.second) == Player::NONE) 
            {  
                int dist = std::abs(fromX - target.first) + std::abs(fromY - target.second);
                if (dist < minDist) 
                {
                    closestTarget = target;
                    minDist = dist;
                }
            }
        }

        int targetX = closestTarget.first;
        int targetY = closestTarget.second;

        std::vector<std::pair<int, int>> directions = 
        {
            {fromX + 1, fromY}, {fromX - 1, fromY}, {fromX, fromY + 1}, {fromX, fromY - 1}
        };

        std::sort(directions.begin(), directions.end(), [targetX, targetY](const std::pair<int, int>& a, const std::pair<int, int>& b) 
        {
            return (std::abs(a.first - targetX) + std::abs(a.second - targetY)) < (std::abs(b.first - targetX) + std::abs(b.second - targetY));
        });

        for (const auto& [toX, toY] : directions) 
        {
            if (toX >= 0 && toX < BOARD_SIZE && toY >= 0 && toY < BOARD_SIZE) 
            {
                if (board->getCell(toX, toY) == Player::NONE && board->movePiece(fromX, fromY, toX, toY)) 
                {
                    return;
                }
            }
        }
    }
}














