//cpp
#include "tic_tac_toe.h"
#include <iostream>

TicTacToe::TicTacToe() {}

void TicTacToe::start_game(std::string first_player) {
    if (first_player != "X" && first_player != "O") {
        std::cout << "Invalid starting player. Please choose 'X' or 'O'." << std::endl;
        return;
    }
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position) {
    if (position < 1 || position > 9) {
        std::cout << "Invalid position. Please choose a position between 1 and 9." << std::endl;
        return;
    }
    pegs[position - 1] = player;
    if (!game_over()) {
        set_next_player();
    }
}

std::string TicTacToe::get_player() const {
    return player;
}

void TicTacToe::display_board() const {
    for (int i = 0; i < 9; ++i) {
        std::cout << pegs[i];
        if ((i + 1) % 3 == 0)
            std::cout << std::endl;
        else
            std::cout << " | ";
    }
}

bool TicTacToe::game_over() {
    // Check for a win by rows, columns, or diagonals
    if (check_row_win() || check_column_win() || check_diagonal_win()) {
        return true;
    }
    // Check for a tie
    if (check_board_full()) {
        return true;
    }
    return false;
}

void TicTacToe::set_next_player() {
    if (player == "X")
        player = "O";
    else
        player = "X";
}

bool TicTacToe::check_board_full() {
    for (const std::string& peg : pegs) {
        if (peg == " ")
            return false; // There is an available slot
    }
    return true; // Board is full
}

void TicTacToe::clear_board() {
    pegs = std::vector<std::string>(9, " ");
}

bool TicTacToe::check_row_win() {
    // Check for a win in any row
    for (int i = 0; i < 3; ++i) {
        if (pegs[i * 3] == pegs[i * 3 + 1] && pegs[i * 3 + 1] == pegs[i * 3 + 2] && pegs[i * 3] != " ")
            return true;
    }
    return false;
}

bool TicTacToe::check_column_win() {
    // Check for a win in any column
    for (int i = 0; i < 3; ++i) {
        if (pegs[i] == pegs[i + 3] && pegs[i + 3] == pegs[i + 6] && pegs[i] != " ")
            return true;
    }
    return false;
}

bool TicTacToe::check_diagonal_win() {
    // Check for a win in any diagonal
    if ((pegs[0] == pegs[4] && pegs[4] == pegs[8] && pegs[0] != " ") ||
        (pegs[2] == pegs[4] && pegs[4] == pegs[6] && pegs[2] != " "))
        return true;
    return false;
}

char TicTacToe::get_winner() {
    if (check_row_win() || check_column_win() || check_diagonal_win()) {
        return player[0];
    }
    if (check_board_full()) {
        return 'C'; // Game ends in a tie
    }
    return ' '; // No winner yet
}