#pragma once

#include "utils.hpp"
#include <SFML/Graphics.hpp>
#include "iostream"
#include "player.hpp"
#include "chessboard.hpp"
#include "ai.hpp"
#include "spdlog/spdlog.h"

class Game
{
public:
	Game();

	Game(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator = (const Game&) = delete;
	Game& operator = (Game&&) = delete;

	void start();
	void on_update(sf::RenderWindow& window);

private:
	std::vector<PlayerPiece> playerPieces;

	std::shared_ptr<ChessBoard> chessBoard;
	std::unique_ptr<AI> ai;

	bool isPlayerTurn = true;
	bool pieceSelected = false;
	int selectedX = -1;
	int	selectedY = -1;
	
	Player winner = Player::NONE;
};