#ifndef BOARD_BUILDER_H
#define BOARD_BUILDER_H
#include "BoardGame.h"

class BoardBuilder{

    private:
        int inarow;
        int players;
        int rows;
        int cols;

    public:
        BoardBuilder();
        ~BoardBuilder();
        BoardBuilder* withRows(int r);
        BoardBuilder* withCols(int c);
        BoardBuilder* withInarow(int i);
        BoardBuilder* withPlayers(int p);
        BoardGame* build();
};

#endif
