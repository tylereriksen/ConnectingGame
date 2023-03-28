#ifndef BOARD_BUILDER_H
#define BOARD_BUILDER_H
#include "BoardGame.h"

/**
 * builder class is used to build the boardgame
 * used a builder design pattern in case the default values were wanted
 * and were not specified to make the board and game
 */
class BoardBuilder{

    private:
        /**
         * private instance variables of the class
         */
        int inarow;
        int players;
        int rows;
        int cols;

    public:

        /**
         * @brief Construct a new Board Builder object
         */
        BoardBuilder();

        /**
         * @brief Destroy the Board Builder object
         */
        ~BoardBuilder();

        /**
         * @brief build a board with a particular number of rows
         * @param r - number of rows
         * @return BoardBuilder* this boardgame builder
         */
        BoardBuilder* withRows(int r);

        /**
         * @brief build a board with a particular number of columns
         * @param c - number of columns
         * @return BoardBuilder* this boardgame builder
         */
        BoardBuilder* withCols(int c);

        /**
         * @brief build a game with the condition that winning involves
         * a certain number of tokens in a row
         * @param i - the number of tokens in a row to win
         * @return BoardBuilder* this boardgame builder
         */
        BoardBuilder* withInarow(int i);

        /**
         * @brief build a game with a particular number of players to play
         * @param p - number of players needed to play the game
         * @return BoardBuilder* this boardgame builder
         */
        BoardBuilder* withPlayers(int p);

        /**
         * @brief build the boardgame with the current state of instance
         * variables
         * @return BoardGame* BoardGame with these current parameters 
         */
        BoardGame* build();
};

#endif