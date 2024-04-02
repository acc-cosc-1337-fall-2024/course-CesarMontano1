#include <iostream>
#include <string>
#include <limits>
#include "tic_tac_toe.h"

int main() 
{
    char firstPlayer;
    char choice;

    do {
        std::cout << "Enter the first player (X or O): ";
        std::cin >> firstPlayer;

        // Ensure the first player is either X or O
        while (toupper(firstPlayer) != 'X' && toupper(firstPlayer) != 'O') {
            std::cout << "Invalid input! Please enter X or O: ";
            std::cin >> firstPlayer;
        }

        TicTacToe game;
        game.start_game(std::string(1, toupper(firstPlayer))); // Convert firstPlayer to uppercase

        // Inner loop to play the game until a winner is determined
        while (!game.game_over()) {
            std::cout << "Current Player: " << game.get_player() << std::endl;
            game.display_board();

            int position;
            std::cout << "Enter position to mark (1-9): ";
            std::cin >> position;

            // Clear input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            game.mark_board(position);
        }

        // Display the winner or a tie
        std::cout << "Game over!" << std::endl;
        game.display_board();
        char winner = game.get_winner();
        if (winner != ' ')
            std::cout << "Winner: " << winner << std::endl;
        else
            std::cout << "Tie game!" << std::endl;

        std::cout << "Do you want to play another game? (Y/N): ";
        std::cin >> choice;

    } while (toupper(choice) == 'Y');

    std::cout << "Thank you for playing Tic Tac Toe!" << std::endl;

	return 0;
}