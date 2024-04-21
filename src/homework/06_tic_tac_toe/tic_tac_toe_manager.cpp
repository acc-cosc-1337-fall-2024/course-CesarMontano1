//cpp
#include <iostream>
#include "tic_tac_toe_manager.h"

// Constructor
TicTacToeManager::TicTacToeManager() {}

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>&& b) {
    game.push_back(std::move(b));
    char winner = game.back()->get_winner();
    std::string winnerString(1, winner);  // Convert char to std::string
    update_winner_count(winnerString);
}

void TicTacToeManager::get_winner_total(int& o, int& w, int& t) {
    o = o_win;
    w = x_win;
    t = ties;
}

void TicTacToeManager::update_winner_count(std::string winner) {
    if (winner == "X") {
        x_win++;
    } else if (winner == "O") {
        o_win++;
    } else {
        ties++;
    }
}
// Define the operator<< overload for TicTacToeManager
std::ostream& operator<<(std::ostream& os, const TicTacToeManager& manager) {
    os << "X wins: " << manager.x_win << ", O wins: " << manager.o_win << ", Ties: " << manager.ties;
    return os;
}