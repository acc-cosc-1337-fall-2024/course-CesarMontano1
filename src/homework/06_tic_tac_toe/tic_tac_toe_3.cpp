#include "tic_tac_toe_3.h"

bool TicTacToe_3::check_row_win() {
    // Check for a win in any row
    for (int i = 0; i < 3; ++i) {
        if (pegs[i * 3] == pegs[i * 3 + 1] && pegs[i * 3 + 1] == pegs[i * 3 + 2] && pegs[i * 3] != " ")
            return true;
    }
    return false;
}

bool TicTacToe_3::check_column_win() {
    // Check for a win in any column
    for (int i = 0; i < 3; ++i) {
        if (pegs[i] == pegs[i + 3] && pegs[i + 3] == pegs[i + 6] && pegs[i] != " ")
            return true;
    }
    return false;
}

bool TicTacToe_3::check_diagonal_win() {
    // Check for a win in any diagonal
    if ((pegs[0] == pegs[4] && pegs[4] == pegs[8] && pegs[0] != " ") ||
        (pegs[2] == pegs[4] && pegs[4] == pegs[6] && pegs[2] != " "))
        return true;
    return false;
}