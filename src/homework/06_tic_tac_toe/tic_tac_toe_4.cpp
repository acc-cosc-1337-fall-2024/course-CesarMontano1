#include "tic_tac_toe_4.h"

bool TicTacToe_4::check_row_win() {
    // Check for a win in any row
    for (int i = 0; i < 4; ++i) {
        if (pegs[i * 4] == pegs[i * 4 + 1] && pegs[i * 4 + 1] == pegs[i * 4 + 2] && pegs[i * 4 + 2] == pegs[i * 4 + 3] && pegs[i * 4] != " ")
            return true;
    }
    return false;
}

bool TicTacToe_4::check_column_win() {
    // Check for a win in any column
    for (int i = 0; i < 4; ++i) {
        if (pegs[i] == pegs[i + 4] && pegs[i + 4] == pegs[i + 8] && pegs[i + 8] == pegs[i + 12] && pegs[i] != " ")
            return true;
    }
    return false;
}

bool TicTacToe_4::check_diagonal_win() {
    // Check for a win in any diagonal
    if ((pegs[0] == pegs[5] && pegs[5] == pegs[10] && pegs[10] == pegs[15] && pegs[0] != " ") ||
        (pegs[3] == pegs[6] && pegs[6] == pegs[9] && pegs[9] == pegs[12] && pegs[3] != " "))
        return true;
    return false;
}