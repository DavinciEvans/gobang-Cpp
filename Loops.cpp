//
// Created by ZNSY on 2020/5/20.
//

#include "Loops.h"
#include <iostream>
#include "LastOrder.h"
using namespace std;

int Loops::control(int color, int &x, int &y) {
    cout << "Enter X: ";
    cin >> x;
    cout << "Enter Y: ";
    cin >> y;
    while (!this->board.place(x, y, color) || x > SIZE - 1 || y > SIZE - 1 || x < 0 || y < 0){
        cout << "This pos is illegal" << endl;
        cout << "Enter X: ";
        cin >> x;
        cout << "Enter Y: ";
        cin >> y;
    }
    return 1;
};

void Loops::games() {
    int nowColor = firstHand;
    int posX, posY, score;
    LastOrder lastOrder;
    cout << "game start" << endl;
    while (!this->board.win) {
        cout << "- - - - - - - - - - - - - - " << endl;
        this->board.print();
        if (nowColor == lastOrder.aiColor) {
            cout << "AI turns" << endl;
            lastOrder.playChess(this->board.board, posX, posY);
            this->board.place(posX, posY, lastOrder.aiColor);
        }
        else {
            this->messages(nowColor, posX, posY);
            this->control(nowColor, posX, posY);
        }
        this->allCheck();
        this->turns ++;
        nowColor = nowColor == WHITE ? BLACK : WHITE;
    }
    cout << "- - - - - - - - - - - - - - " << endl;
    this->board.print();
    if (board.win == 1) cout << "White get the champion!!" << endl;
    else cout << "Black get the champion!!" << endl;
    cout << "Game over" << endl;
}

void Loops::messages(int color, int &x, int &y) {
    if (this->turns != 1) {
        cout << "Last pos: " << endl;
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
    }
    if (color == 1)
        cout << "¡ð White turn" << endl;
    else cout << "¡ñ Black turn" << endl;
}

void Loops::allCheck() {
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j < SIZE; j ++) {
            if (!this->board.board[i][j]) continue;
            else this->board.check(i, j, this->board.board[i][j], 0, 0, 0);
        }
    }
}
