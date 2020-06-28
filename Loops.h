//
// Created by ZNSY on 2020/5/20.
//

#ifndef FIVE_CHESS_LOOPS_H
#define FIVE_CHESS_LOOPS_H

#include "board.h"
#include "Debug.h"
#include <iostream>
#include "LastOrder.h"



using namespace std;

class Loops {
public:
    Board board;
    Debug debug;
    int turns = 0;
    int firstHand = 1;
    int control(int color, int &x, int &y);
    void messages(int color);
    void games();
    void allCheck();
};


#endif //FIVE_CHESS_LOOPS_H
