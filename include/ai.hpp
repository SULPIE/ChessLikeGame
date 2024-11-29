#include <SFML/Graphics.hpp>
#include <iostream>
#include "utils.hpp"
#include "chessboard.hpp"

class AI {
public:
    AI(std::shared_ptr<ChessBoard> chessBoard);

    void makeMove();

    std::pair<int, int> findNearestTarget(int fromX, int fromY, const std::vector<std::pair<int, int>>& targetCells);

    bool moveToTarget(int fromX, int fromY, int toX, int toY);

private:
    std::shared_ptr<ChessBoard> board;
};