#include "BoardGame.h"
#include <string>
#include <iostream>
using namespace std;

BoardGame::BoardGame(int rows, int cols, int inarow, int players) {
    this->rows = rows;
    this->cols = cols;
    this->inarow = inarow;
    this->players = players;
    this->m = 1;
    this->tokens.push_back("R");
    this->tokens.push_back("Y");
    this->tokens.push_back("B");
    this->tokens.push_back("G");
    this->tokens.push_back("P");
    this->tokens.push_back("S");
    this->tokens.push_back("T");
    for(int i = 0; i < this->rows; i++){
        vector<string> temp;
        for(int j = 0; j < this->cols; j++){
            temp.push_back(".");
        }
        this->board.push_back(temp);
    }
}

BoardGame::~BoardGame(){
    // nothing
}

vector< vector<string> > BoardGame::getBoard() {
    return this->board;
}

void BoardGame::move(int c){
    string str_cpr(".");
    for(int i = this->rows - 1; i >= 0; i --){
        if(this->getBoard()[i][c - 1].compare(str_cpr) == 0){
            this->board[i][c - 1] = this->tokens[(this->m - 1) % this->players];
            this->m ++;
            break;
        }
    }
}

bool BoardGame::checkValidMove(int c){
    if(c <= 0 || c > this->cols){
        return false;
    }
    else if(this->checkColFull(c)){
        return false;
    }
    return true;
}

bool BoardGame::isBoardFull(){
    string str_cpr(".");
    for(int i = 0; i < this->cols; i++){
        if(this->getBoard()[0][i].compare(str_cpr) == 0){
            return false;
        } 
    }
    return true;
}

bool BoardGame::checkColFull(int c){
    string str_cpr(".");
    for(int i = this->rows - 1; i >= 0; i--){
        if(this->getBoard()[i][c - 1].compare(str_cpr) == 0){
            return false;
        }
    }
    return true;
}

string BoardGame::currentTurn() {
    return this->tokens[(this->m - 1) % this->players];
}
string BoardGame::prevTurn() {
    return this->tokens[(this->m + this->players - 2) % this->players];
}

bool BoardGame::isWin(){
    if(this->isRowWin() || this->isColWin()
    || this->isDiagonalBTWin() || this->isDiagonalTBWin()){
        return true;
    }
    return false;
}

bool BoardGame::isRowWin(){
    if(this->cols < this->inarow){
        return false;
    }

    string str_cpr(".");
    for(int i = 0; i < this->rows; i++){
        int p1 = 0;
        int p2 = 0;
        while(p2 < this->cols - 1){
            if(this->getBoard()[i][p2].compare(str_cpr) == 0){
                p2 ++;
                p1 = p2;
            }
            else if(this->getBoard()[i][p2].compare(this->getBoard()[i][p2 + 1]) != 0){
                p2 ++;
                p1 ++;
            }
            else if(this->getBoard()[i][p2].compare(this->getBoard()[i][p2 + 1]) == 0){
                p2 ++;
                if(p2 + 1 - p1 == this->inarow){
                    return true;
                }
            }
        }
    }
    return false;
}

bool BoardGame::isColWin(){
    if(this->rows < this->inarow){
        return false;
    }

    string str_cpr(".");
    for(int i = 0; i < this->cols; i++){
        int p1 = 0;
        int p2 = 0;
        while(p2 < this->rows - 1){
            if(this->getBoard()[p2][i].compare(str_cpr) == 0){
                p2 ++;
                p1 = p2;
            }
            else if(this->getBoard()[p2][i].compare(this->getBoard()[p2 + 1][i]) != 0){
                p2 ++;
                p1 = p2;
            }
            else if(this->getBoard()[p2][i].compare(this->getBoard()[p2 + 1][i]) == 0){
                p2 ++;
                if(p2 + 1 - p1 == this->inarow){
                    return true;
                }
            }
        }
    }
    return false;
}

bool BoardGame::isDiagonalTBWin(){
    if(this->rows < this->inarow || this->cols < this->inarow){
        return false;
    }

    string str_cpr(".");
    for(int i = 0; i <= this->rows - this->inarow; i++){
        for(int j = 0; j <= this->cols - this->inarow; j++){
            int rowC = i;
            int colC = j;
            int counter = 1;
            while(true){
                if(counter == this->inarow){
                    return true;
                }
                if(this->getBoard()[rowC][colC].compare(this->getBoard()[rowC + 1][colC + 1]) == 0
                && this->getBoard()[rowC][colC].compare(str_cpr) != 0){
                    counter ++;
                    rowC ++;
                    colC ++;
                }
                else{
                    break;
                }
            }
        }
    }
    return false;
}

bool BoardGame::isDiagonalBTWin(){
    if(this->rows < this->inarow || this->cols < this->inarow){
        return false;
    }
    
    string str_cpr(".");
    for(int i = this->inarow - 1; i < this->rows; i++){
        for(int j = 0; j < this->cols - this->inarow; j++){
            int rowC = i;
            int colC = j;
            int counter = 1;
            while(true){
                if(counter == this->inarow){
                    return true;
                }
                if(this->getBoard()[rowC][colC].compare(this->getBoard()[rowC - 1][colC + 1]) == 0
                && this->getBoard()[rowC][colC].compare(str_cpr) != 0){
                    counter ++;
                    rowC --;
                    colC ++;
                }
                else{
                    break;
                }
            }
        }
    }
    return false;
}

void BoardGame::displayBoard() {
    string pr = "";
    for(int i = 1; i <= this->cols; i++){
        pr += (to_string(i) + " ");
    }
    pr += "\n";
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            pr += this->getBoard()[i][j];
            for(int k = 0; k < to_string(j + 1).length(); k++){
                pr += " ";
            }
        }
        pr += "\n";
    }
    cout << pr << endl;
}
