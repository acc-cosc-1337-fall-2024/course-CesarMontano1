//h
#include "tic_tac_toe.h"

class TicTacToe_3 : public TicTacToe
{
public:
        TicTacToe_3(): TicTacToe(3){};

private:
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();
};