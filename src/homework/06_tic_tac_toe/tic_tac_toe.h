//h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <string>
#include <vector>

class TicTacToe {
private:
    std::string player;
    std::vector<std::string> pegs;

public:
    TicTacToe();
    void start_game(std::string first_player);
    void mark_board(int position);
    std::string get_player() const;
    void display_board() const;
    bool game_over();
    void set_next_player();
    bool check_board_full();
    void clear_board();
    bool check_row_win();
    bool check_column_win();
    bool check_diagonal_win();
    char get_winner(); // Declaration of get_winner() function
};

#endif /* TIC_TAC_TOE_H */