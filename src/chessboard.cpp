#include "chessboard.hpp"

ChessBoard::ChessBoard() 
{
    board.resize(BOARD_SIZE, std::vector<Player>(BOARD_SIZE, Player::NONE));
}

void ChessBoard::draw(sf::RenderWindow& window) 
{
    for (int y = 0; y < BOARD_SIZE; ++y) 
    {
        for (int x = 0; x < BOARD_SIZE; ++x) 
        {
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);

            if ((x + y) % 2 == 0)
            {
                cell.setFillColor(sf::Color(255, 255, 255));
            }
            else
            {
                cell.setFillColor(sf::Color(49, 51, 53));
            }

            window.draw(cell);

            if (board[y][x] != Player::NONE) 
            {
                sf::CircleShape piece(CELL_SIZE / 4);
                piece.setPosition(x * CELL_SIZE + CELL_SIZE / 4, y * CELL_SIZE + CELL_SIZE / 4);
                if (board[y][x] == Player::PLAYER)
                {
                    piece.setFillColor(sf::Color::Green);
                }
                else
                {
                    piece.setFillColor(sf::Color::Black);
                }
                window.draw(piece);
            }
        }
    }
}

bool ChessBoard::movePiece(int fromX, int fromY, int toX, int toY) 
{
    if (abs(fromX - toX) == 1 && fromY == toY || abs(fromY - toY) == 1 && fromX == toX) 
    {
        if (toX >= 0 && toY >= 0 && toX < BOARD_SIZE && toY < BOARD_SIZE && board[toY][toX] == Player::NONE) 
        {
            board[toY][toX] = board[fromY][fromX];
            board[fromY][fromX] = Player::NONE;
            return true;
        }
    }
    return false;
}

void ChessBoard::setPlayerPiece(int x, int y) 
{
    if (board[y][x] == Player::NONE) {
        board[y][x] = Player::PLAYER;
    }
}

void ChessBoard::setAIPiece(int x, int y) 
{
    if (board[y][x] == Player::NONE) {
        board[y][x] = Player::AI;
    }
}

bool ChessBoard::isPlayerWinner() 
{

    return true;
}

bool ChessBoard::isAIWinner() 
{

    return true;
}

Player ChessBoard::getCell(int x, int y) 
{
    return board[y][x];
}