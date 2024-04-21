#include <iostream>
#include <string>
#include <limits>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_3.h"

int main() 
{
   TicTacToeManager manager; // Create an instance of TicTacToeManager

    char choice;

    do {
        int game_type_choice;
        std::cout << "Choose a game type:\n1. Tic Tac Toe 3\n2. Tic Tac Toe 4\nEnter your choice: ";
        std::cin >> game_type_choice;

        std::unique_ptr<TicTacToe> game;
        if (game_type_choice == 1) {
            game = std::make_unique<TicTacToe_3>();
        } else if (game_type_choice == 2) {
            game = std::make_unique<TicTacToe_4>();
        } else {
            std::cout << "Invalid choice! Please enter 1 or 2." << std::endl;
            continue;
        }

        char firstPlayer;
        std::cout << "Enter the first player (X or O): ";
        std::cin >> firstPlayer;

        // Ensure the first player is either X or O
        while (toupper(firstPlayer) != 'X' && toupper(firstPlayer) != 'O') {
            std::cout << "Invalid input! Please enter X or O: ";
            std::cin >> firstPlayer;
        }

        game->start_game(std::string(1, toupper(firstPlayer))); // Convert firstPlayer to uppercase

        // Inner loop to play the game until a winner is determined
        while (!game->game_over()) {
            std::cout << "Current Player: " << game->get_player() << std::endl;
            game->display_board();

            int position;
            std::cout << "Enter position to mark (1-";
            if (game_type_choice == 1) {
                std::cout << "9): ";
            } else {
                std::cout << "16): ";
            }
            std::cin >> position;

            // Clear input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            game->mark_board(position);
            game->display_board(); // Display the board after each position mark
        }

        // Display the winner or a tie
        std::cout << "Game over!" << std::endl;
        game->display_board();
        char winner = game->get_winner();
        if (winner != ' ')
            std::cout << "Winner: " << winner << std::endl;
        else
            std::cout << "Tie game!" << std::endl;

        manager.save_game(std::move(game)); // Add the game instance to TicTacToeManager

        // Display running scores
        int x_wins, o_wins, ties;
        manager.get_winner_total(o_wins, x_wins, ties);
        std::cout << "Running Scores - X wins: " << x_wins << ", O wins: " << o_wins << ", Ties: " << ties << std::endl;

        std::cout << "Do you want to play another game? (Y/N): ";
        std::cin >> choice;

    } while (toupper(choice) == 'Y');

    // Display all games played before exiting
    std::cout << "Games Played:" << std::endl;
    std::cout << manager; // This uses the overloaded ostream operator in TicTacToeManager

    std::cout << "Thank you for playing Tic Tac Toe!" << std::endl;

    return 0;
}

