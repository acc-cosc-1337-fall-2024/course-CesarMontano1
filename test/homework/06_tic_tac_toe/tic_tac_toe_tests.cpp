#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X", "first_player_X") {
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
    REQUIRE(game.game_over() == false);
}

TEST_CASE("Test first player set to O", "first_player_O") {
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
    REQUIRE(game.game_over() == false);
}

TEST_CASE("Test game over if 9 slots are selected", "game_over_after_9_slots_selected") {
    TicTacToe game;
    game.start_game("X");

    for (int i = 1; i <= 9; ++i) {
        game.mark_board(i);
        REQUIRE(game.game_over() == (i == 9));
    }
}

TEST_CASE("Test win by first column", "win_by_first_column") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(4);
    game.mark_board(7);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second column", "win_by_second_column") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(8);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third column", "win_by_third_column") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(3);
    game.mark_board(6);
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by first row", "win_by_first_row") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(3);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second row", "win_by_second_row") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(4);
    game.mark_board(5);
    game.mark_board(6);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third row", "win_by_third_row") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(7);
    game.mark_board(8);
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win diagonally from top left", "win_diagonally_top_left") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(5);
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left", "win_diagonally_bottom_left") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(7);
    game.mark_board(5);
    game.mark_board(3);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test tie", "tie_game") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(3);
    game.mark_board(5);
    game.mark_board(4);
    game.mark_board(6);
    game.mark_board(8);
    game.mark_board(7);
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == 'C');
}