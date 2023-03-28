#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <string>
#include <vector>
using namespace std;

class BoardGame {

    private:
        int rows;
        int cols;
        int inarow;
        int players;
        vector< vector<string> > board;
        vector<string> tokens;
        int m;
        vector< vector<string> > getBoard();
        bool checkColFull(int c);
        bool isRowWin();
        bool isColWin();
        bool isDiagonalTBWin();
        bool isDiagonalBTWin();

    public:
        BoardGame(int rows, int cols, int inarow, int players);
        ~BoardGame();
        void displayBoard();
        void move(int c);
        bool checkValidMove(int c);
        bool isBoardFull();
        string currentTurn();
        string prevTurn();
        bool isWin();
};

#endif
