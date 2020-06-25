//
// Created by ZNSY on 2020/5/23.
//

#ifndef FIVE_CHESS_LASTORDER_H
#define FIVE_CHESS_LASTORDER_H
#define DEPTH 6
#define AN 10
#include "board.h"
#include "Loops.h"
#include <iostream>
using namespace std;

struct Pos {
    int x;
    int y;
};


struct Points {
    Pos pos[AN];
    int score[AN];
};


struct Decision {
    Pos pos;
    int score;
};


class LastOrder {
public:
    LastOrder();
    int aiColor = AICOLOR;
    int humColor = HUMCOLOR;
    Decision decision;
    int chessStatus[4][4][4][4][4][4] = {{{{{{0}}}}}};
    void init_chessStatus();
    void playChess(int board[SIZE][SIZE], int &x, int &y);
    int evaluation(int board[SIZE][SIZE]);
    Points localSearch(int board[SIZE][SIZE]);
    int maxMinSearch(int board[SIZE][SIZE], int depth, int alpha, int beta);
    void allCheck();
};


#endif //FIVE_CHESS_LASTORDER_H
