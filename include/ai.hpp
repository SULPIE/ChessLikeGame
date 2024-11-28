#include <SFML/Graphics.hpp>
#include <iostream>
#include "utils.hpp"
#include "chessboard.hpp"

class AI {
public:
    AI(std::shared_ptr<ChessBoard> chessBoard);

    void makeMove();

private:
    std::shared_ptr<ChessBoard> board;
};