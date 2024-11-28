#pragma once 

#include "utils.hpp"
#include <SFML/Graphics.hpp>
#include "iostream"

class PlayerPiece
{
public:
    PlayerPiece(int x, int y);

    void draw(sf::RenderWindow& window);
    bool contains(int mouseX, int mouseY);
    void startDrag(int mouseX, int mouseY);

    void drag(int mouseX, int mouseY);

    void stopDrag(int x, int y);

    sf::CircleShape piece;
    int x, y;
    bool isDragging;
    float offsetX = 0;
    float offsetY = 0;
};