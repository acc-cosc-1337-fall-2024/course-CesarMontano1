//h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include <string>
#include <vector>
#include <memory>


class TicTacToe {
private:
    std::string player;

public:
    TicTacToe();
    TicTacToe(long unsigned int size) : pegs(size*size, " "){};
    void start_game(std::string first_player);
    void mark_board(int position);
    std::string get_player() const;
    void display_board() const;
    bool game_over();
    void set_next_player();
    bool check_board_full();
    void clear_board();
    char get_winner(); // Declaration of get_winner() function

protected:
    std::vector<std::string> pegs;
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();
};

#endif /* TIC_TAC_TOE_H */
