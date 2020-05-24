//
// Created by ZNSY on 2020/5/23.
//

#ifndef FIVE_CHESS_LASTORDER_H
#define FIVE_CHESS_LASTORDER_H
#include "board.h"
#include <iostream>
using namespace std;


class LastOrder {
public:
    LastOrder();
    int aiColor = BLACK;
    int chessStatus[4][4][4][4][4][4] = {{{{{{0}}}}}};
    void init_chessStatus();
    void playChess(int board[SIZE][SIZE], int &x, int &y);
    int evaluation(int board[SIZE][SIZE]);
};


#endif //FIVE_CHESS_LASTORDER_H
