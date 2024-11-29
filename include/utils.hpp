#pragma once

#include <iostream>
#include <vector>

const int BOARD_SIZE = 8;
const int CELL_SIZE = 80;
const int WINDOW_SIZE = BOARD_SIZE * CELL_SIZE;

const int COUNT_OF_PIECES = 9;

const std::vector<int> PLAYER_PIECES_PER_ROW = {
	3, //первая строка
	3, //вторая строка
	3 //третья строка
};

enum class Player { NONE, PLAYER, AI };