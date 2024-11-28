#include "game.hpp"

Game::Game() { }

void Game::start()
{
    srand(time(0));

    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "ChessLike Game", sf::Style::Close);

    chessBoard = std::make_shared<ChessBoard>();
    ai = std::make_unique<AI>(chessBoard);

    for (int i = 0; i < PLAYER_PIECES_PER_ROW.size(); i++)
    {
        for (int j = 0; j < PLAYER_PIECES_PER_ROW[i]; j++)
        {
            chessBoard->setPlayerPiece(j, i);
            chessBoard->setAIPiece((BOARD_SIZE - 1) - j, (BOARD_SIZE - 1) - i);

            playerPieces.push_back(PlayerPiece(j, i));
        }
    }

    while (window.isOpen()) 
    {
        on_update(window);
    }
}

void Game::on_update(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed) 
        {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
        {
            int mouseX = event.mouseButton.x;
            int mouseY = event.mouseButton.y;

            if (!pieceSelected) 
            {
                for (auto& piece : playerPieces) 
                {
                    if (piece.contains(mouseX, mouseY)) 
                    {
                        piece.startDrag(mouseX, mouseY);
                        pieceSelected = true;
                        break;
                    }
                }
            }
        }

        if (event.type == sf::Event::MouseMoved && pieceSelected) 
        {
            int mouseX = event.mouseMove.x;
            int mouseY = event.mouseMove.y;

            for (auto& piece : playerPieces) 
            {
                if (piece.isDragging) 
                {
                    piece.drag(mouseX, mouseY);
                }
            }
        }

        if (event.type == sf::Event::MouseButtonReleased && pieceSelected) 
        {
            int mouseX = event.mouseButton.x / CELL_SIZE;
            int mouseY = event.mouseButton.y / CELL_SIZE;

            for (auto& piece : playerPieces) 
            {
                if (piece.isDragging) 
                {
                    if (chessBoard->movePiece(piece.x, piece.y, mouseX, mouseY)) 
                    {
                        piece.stopDrag(mouseX, mouseY);
                        isPlayerTurn = false;
                    }
                    else 
                    {
                        piece.stopDrag(piece.x, piece.y);
                    }
                    break;
                }
            }
            pieceSelected = false;
        }
    }

    if (!isPlayerTurn) 
    {
        ai->makeMove();
        isPlayerTurn = true;
    }

    window.clear();
    chessBoard->draw(window);
    for (auto& piece : playerPieces) 
    {
        piece.draw(window);
    }

    /*if (chessBoard->isPlayerWinner()) {
        spdlog::info("Player wins");
        return;
    }

    if (chessBoard->isAIWinner()) {
        spdlog::info("ai wins");
        return;
    }*/

    window.display();
}
