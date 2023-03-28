#include "BoardBuilder.h"

BoardBuilder::BoardBuilder() {
    this->rows = 6;
    this->cols = 7;
    this->inarow = 4;
    this->players = 2;
}

BoardBuilder::~BoardBuilder() {
    // nothing
}

BoardBuilder* BoardBuilder::withRows(int r) {
    this->rows = r;
    return this;
}

BoardBuilder* BoardBuilder::withCols(int c) {
    this->cols = c;
    return this;
}

BoardBuilder* BoardBuilder::withInarow(int i) {
    this->inarow = i;
    return this;
}

BoardBuilder* BoardBuilder::withPlayers(int p) {
    this->players = p;
    return this;
}

BoardGame* BoardBuilder::build() {
    BoardGame* b = new BoardGame(this->rows, this->cols, this->inarow, this->players);
    return b;
}
