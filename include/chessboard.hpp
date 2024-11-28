#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "utils.hpp"

class ChessBoard {
public:
    ChessBoard();

    void draw(sf::RenderWindow& window);
    bool movePiece(int fromX, int fromY, int toX, int toY);
    void setPlayerPiece(int x, int y);
    void setAIPiece(int x, int y);
    bool isPlayerWinner();
    bool isAIWinner();

    Player getCell(int x, int y);

private:
    std::vector<std::vector<Player>> board;
};