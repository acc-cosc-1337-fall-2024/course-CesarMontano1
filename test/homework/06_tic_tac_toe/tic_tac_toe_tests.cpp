#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over if 9 slots are selected", "game_over") {
    TicTacToe game;
    game.start_game("X");

    // Mark all slots on the board
    for (int i = 1; i <= 9; ++i) {
        game.mark_board(i);
        REQUIRE(game.game_over() == (i == 9)); // Game should be over after all slots are selected
    }
}

