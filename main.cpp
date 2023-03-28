#include <iostream>
using namespace std;
#include "BoardBuilder.h"
#include "BoardGame.h"

bool isInt(string s){
    if(s.length() == 0){
        return false;
    }
    for(int i = 0; i < s.length(); i++){
        if(isdigit(s[i]) == false){
            return false;
        }
    }
    return true;
}

int main(){
    BoardBuilder* b = new BoardBuilder;
    int cols = 12;
    int rows = 6;
    int players = 3;
    int inarow = 7;
    b = b->withCols(cols)->withRows(rows)->withPlayers(players)->withInarow(inarow);
    BoardGame* ConnectGame = b->build();
    ConnectGame->displayBoard();

    while(!ConnectGame->isWin() && !ConnectGame->isBoardFull()){
        string move = "";
        bool again = false;
        while(!isInt(move) || !ConnectGame->checkValidMove(stoi(move))){
            string currMove = ConnectGame->currentTurn();

            if(again){
                cout << "Please enter a valid move " << currMove << ": ";
                cin >> move;
            }
            else{
                cout << "Enter move for " << currMove << ": ";
                cin >> move;
            }
            if(!again){
                again = true;
            }
        }
        ConnectGame->move(stoi(move));
        cout << "\n" << endl;
        ConnectGame->displayBoard();
    }

    if(ConnectGame->isWin()){
        cout << "Congratulations!! Player " << ConnectGame->prevTurn() << ", you have WON the game!" << endl;
    }
    else{
        cout << "Draw! Tie Game" << endl;
    }
}
