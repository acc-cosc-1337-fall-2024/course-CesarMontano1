#include <iostream>
#include "tic_tac_toe.h"

int main() 
{
	char firstPlayer;
    char choice;

    std::cout << "Enter the first player (X or O): ";
    std::cin >> firstPlayer;

    TicTacToe game;
    game.start_game(std::string(1, firstPlayer));

    do {
        // User-controlled loop to play the game
        while (!game.game_over()) {
            std::cout << "Current Player: " << game.get_player() << std::endl;
            game.display_board();

            int position;
            std::cout << "Enter position to mark (1-9): ";
            std::cin >> position;
            game.mark_board(position);
        }

        std::cout << "Game over!" << std::endl;
        game.display_board();

        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> choice;

        // Clear the board for the next game
        game.clear();

    } while (toupper(choice) == 'Y');

    std::cout << "Thank you for playing Tic Tac Toe!" << std::endl;

	return 0;
}