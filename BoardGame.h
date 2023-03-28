#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <string>
#include <vector>
using namespace std;

/**
 * class of the boardgame and its functionalities
 * overall this class defines the board and the overall premise
 * of the game to be played
 */
class BoardGame {

    private:
        /**
         * private instance variables of the class
         */
        int rows;
        int cols;
        int inarow;
        int players;
        vector< vector<string> > board;
        vector<string> tokens;
        int m;

        /**
         * @brief Get the Board
         * @return vector< vector<string> > the board 
         */
        vector< vector<string> > getBoard();

        /**
         * @brief checks to see if there is any rows in-a-row
         * @return true if there is
         * @return false if not
         */
        bool isRowWin();

        /**
         * @brief checks to see if there is any cokumn in-a-row
         * @return true if there is
         * @return false if not
         */
        bool isColWin();

        /**
         * @brief checks to see if there is any top-to-bottom diagonal in-a-row
         * @return true if there is
         * @return false if not
         */
        bool isDiagonalTBWin();

        /**
         * @brief checks to see if there is any bottom-to-top diagonal in-a-row
         * @return true if there is
         * @return false if not
         */
        bool isDiagonalBTWin();

    public:
        /**
         * @brief Construct a new Board Game object
         * @param rows - number of rows the boardgame will have
         * @param cols - number of cols the boardgame will have
         * @param inarow - the number of tokens in a row you need to get to win
         * @param players - the number of players playing in a game
         */
        BoardGame(int rows, int cols, int inarow, int players);

        /**
         * @brief Destroy the Board Game object
         */
        ~BoardGame();

        /**
         * @brief displays/prints the board
         */
        void displayBoard();

        /**
         * @brief puts the player's token in a column
         * @param c - the column index shown in the display
         */
        void move(int c);

        /**
         * @brief checks if a move is valid
         * @param c - the column index shown in the display
         * @return true if a token can be placed in that column
         * @return false if token cannot be placed or if column is invalid
         */
        bool checkValidMove(int c);

        /**
         * @brief checks if a column is full or not
         * @param c - the column that we want to check
         * @return true if the column is filled
         * @return false if the column is not filled 
         */
        bool checkColFull(int c);

        /**
         * @brief checks if the entire board is filled
         * @return true if the board is completely filled
         * @return false if the board is not completely filled
         */
        bool isBoardFull();

        /**
         * @brief outputs the token of the player's turn
         * @return string token of the current player
         */
        string currentTurn();

        /**
         * @brief outputs the token of the previous player's turn
         * @return string token of the previous player
         */
        string prevTurn();

        /**
         * @brief checks if there is a inarow in-a-row amount of the same tokens
         * @return true if there is a winner
         * @return false if there is no winner
         */
        bool isWin();
};

#endif