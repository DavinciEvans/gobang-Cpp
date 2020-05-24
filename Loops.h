//
// Created by ZNSY on 2020/5/20.
//

#ifndef FIVE_CHESS_LOOPS_H
#define FIVE_CHESS_LOOPS_H

#include "board.h"

class Loops {
public:
    Board board;
    int turns = 1;
    int firstHand = 1;
    int control(int color, int &x, int &y);
    void messages(int color, int &x, int &y);
    void games();
    void allCheck();
};


#endif //FIVE_CHESS_LOOPS_H
