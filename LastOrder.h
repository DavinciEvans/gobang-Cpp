//
// Created by ZNSY on 2020/5/23.
//

#ifndef FIVE_CHESS_LASTORDER_H
#define FIVE_CHESS_LASTORDER_H
#define DEPTH 6
#define AN 10
#include "board.h"
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
    LastOrder(bool debug = false);
    bool debugMode;
    int aiColor = AICOLOR;
    int humColor = HUMCOLOR;
    Decision decision;
    int chessStatus[4][4][4][4][4][4] = {{{{{{0}}}}}};
    void init_chessStatus();//初始化棋形
    void playChess(Board board, int &x, int &y);//主函数
    int evaluation(int board[SIZE][SIZE]);//评估函数
    Points localSearch(int board[SIZE][SIZE]);//局部搜索与启发式搜索
    int maxMinSearch(Board board, int depth, int alpha, int beta);//极大极小值搜素
};


#endif //FIVE_CHESS_LASTORDER_H
