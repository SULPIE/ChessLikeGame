#include "player.hpp"

PlayerPiece::PlayerPiece(int x, int y) : x(x), y(y), isDragging(false) {
    piece.setRadius(CELL_SIZE / 4);
    piece.setFillColor(sf::Color::Green);
    piece.setPosition(x * CELL_SIZE + CELL_SIZE / 4, y * CELL_SIZE + CELL_SIZE / 4);
}

void PlayerPiece::draw(sf::RenderWindow& window)
{
    window.draw(piece);
}

bool PlayerPiece::contains(int mouseX, int mouseY)
{
    sf::FloatRect bounds = piece.getGlobalBounds();
    return bounds.contains(mouseX, mouseY);
}

void PlayerPiece::startDrag(int mouseX, int mouseY)
{
    offsetX = mouseX - piece.getPosition().x;
    offsetY = mouseY - piece.getPosition().y;
    isDragging = true;
}

void PlayerPiece::drag(int mouseX, int mouseY)
{
    if (isDragging) 
    {
        piece.setPosition(mouseX - offsetX, mouseY - offsetY);
    }
}

void PlayerPiece::stopDrag(int x, int y)
{
    isDragging = false;
    this->x = x;
    this->y = y;
    piece.setPosition(x * CELL_SIZE + CELL_SIZE / 4, y * CELL_SIZE + CELL_SIZE / 4);
}