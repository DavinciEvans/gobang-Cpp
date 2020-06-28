//
// Created by ZNSY on 2020/6/26.
//

#ifndef GOBANG_WIN_DEBUG_H
#define GOBANG_WIN_DEBUG_H

#include "LastOrder.h"
#include "board.h"
#include <cstring>
#include <iostream>
#include <conio.h>
#include <fstream>
#define CLRSCR system("cls")
using namespace std;



class Debug {
public:
    int history[SIZE * SIZE][3];
    int turns = 0;
    int nowTurns = 0;
    Board copyBoard;
    void control();
    void start(int x, int y);
    void init(Board board);
    void timeControl(int direct);
    void save();
    Board read();
    void testPut(int x, int y, int color);
    void reverse();
};


#endif //GOBANG_WIN_DEBUG_H
