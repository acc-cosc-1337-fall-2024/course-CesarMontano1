//h
#include "tic_tac_toe.h"

class TicTacToe_4 : public TicTacToe
{
public:
        TicTacToe_4(): TicTacToe(4){};

private:
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();
};