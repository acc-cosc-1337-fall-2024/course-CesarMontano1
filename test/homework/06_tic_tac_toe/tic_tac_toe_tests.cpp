#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

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

    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(6);
    REQUIRE(game.game_over() == false);
    game.mark_board(9);
    REQUIRE(game.game_over() == false);
    game.mark_board(8);
    REQUIRE(game.game_over() == false);
    game.mark_board(7);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by first column", "win_by_first_column") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(4);
    game.mark_board(5);
    game.mark_board(7);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second column", "win_by_second_column") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(2);
    game.mark_board(1);
    game.mark_board(5);
    game.mark_board(3);
    game.mark_board(8);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third column", "win_by_third_column") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(3);
    game.mark_board(1);
    game.mark_board(6);
    game.mark_board(2);
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by first row", "win_by_first_row") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(4);
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(3);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second row", "win_by_second_row") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(4);
    game.mark_board(1);
    game.mark_board(5);
    game.mark_board(2);
    game.mark_board(6);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third row", "win_by_third_row") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(7);
    game.mark_board(1);
    game.mark_board(8);
    game.mark_board(2);
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win diagonally from top left", "win_diagonally_top_left") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(3);
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left", "win_diagonally_bottom_left") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(7);
    game.mark_board(1);
    game.mark_board(5);
    game.mark_board(2);
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

TEST_CASE("Test get_winner function for X win", "get_winner_X") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(4);
    game.mark_board(5);
    game.mark_board(7);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == 'X');
}

TEST_CASE("Test get_winner function for O win", "get_winner_O") {
    TicTacToe game;
    game.start_game("O");
    game.mark_board(2);
    game.mark_board(1);
    game.mark_board(5);
    game.mark_board(3);
    game.mark_board(8);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == 'O');
}

TEST_CASE("Test get_winner_total function for TicTacToeManager") {
    TicTacToeManager manager;

    // Simulate playing at least 3 games with different winners and add them to the manager
    TicTacToe game1;
    game1.start_game("X");
    game1.mark_board(1);
    game1.mark_board(4);
    game1.mark_board(2);
    game1.mark_board(5);
    game1.mark_board(3);
    manager.save_game(game1);

    TicTacToe game2;
    game2.start_game("O");
    game2.mark_board(2);
    game2.mark_board(1);
    game2.mark_board(5);
    game2.mark_board(8);
    game2.mark_board(7);
    game2.mark_board(3);
    game2.mark_board(6);
    game2.mark_board(4);
    game2.mark_board(9);
    manager.save_game(game2);

    TicTacToe game3;
    game3.start_game("X");
    game3.mark_board(1);
    game3.mark_board(4);
    game3.mark_board(2);
    game3.mark_board(5);
    game3.mark_board(3);
    manager.save_game(game3);

    TicTacToe game4;
    game4.start_game("O");
    game4.mark_board(1);
    game4.mark_board(4);
    game4.mark_board(2);
    game4.mark_board(5);
    game4.mark_board(3);
    manager.save_game(game4);

    // Test get_winner_total function to verify correct tally
    int winnerX = 'X';
    int winnerO = 'O';
    int tie = 'C';

    manager.get_winner_total(winnerX, winnerO,tie);
    REQUIRE(winnerX == 1);
    REQUIRE(winnerO == 2);
    REQUIRE(tie == 1);
}