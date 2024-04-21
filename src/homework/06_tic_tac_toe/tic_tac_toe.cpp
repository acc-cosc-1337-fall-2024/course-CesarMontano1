//cpp
#include "tic_tac_toe.h"
#include <iostream>
#include <memory>
using std::cout;

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

void TicTacToe::display_board() const
{
    if(pegs.size() == 9)
    {
        for(long unsigned int i = 0; i < pegs.size(); i += 3)
        {
            std::cout<<pegs[i]<<" | "<<pegs[i+1]<<" | "<<pegs[i+2]<<"\n";
            if(i != 6){std::cout<<"- + - + - \n";}
        }
    }
    else if(pegs.size() == 16)
    {
        for(long unsigned int i = 0; i < pegs.size(); i += 4)
        {
            std::cout<<pegs[i]<<" | "<<pegs[i+1]<<" | "<<pegs[i+2]<<" | "<<pegs[i+3]<<"\n";
            if(i != 12){std::cout<<"- + - + - + - \n";}
        }
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
    return false;
}

bool TicTacToe::check_column_win() {
    return false;
}

bool TicTacToe::check_diagonal_win() {
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
