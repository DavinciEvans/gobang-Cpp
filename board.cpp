//
// Created by ZNSY on 2020/5/19.
//

#include "board.h"
#include <iostream>
#include <string>
using namespace std;

//放置棋子
int Board::place(int x, int y, int color) {
    if (!this->board[x][y]) {
        this->board[x][y] = color;
        return 1;
    }
    else
        return 0;
}

//检查获胜，检查时length = 0
int Board::check(int x, int y, int color, int length, int directX, int directY) {
    int nowLength;
//    获胜情况
    if (length == CHESS) {
        this->win = color;
        return CHESS;
    }
//    未获胜，如果是检查的第一颗棋子，遍历周围，并递归检查
    else if (directX == 0 && directY == 0){
//        遍历该棋子周围
        for (int i=-1; i<2; i++){
            for (int j=-1; j<2; j++){
//                遍历到自己或者是颜色不一致的棋子，跳过
                if ((i == 0 && j == 0) || (this->board[x+i][y+j] != color))
                    continue;
//                否则递归往下检查
                else {
                    nowLength = this->check(x+directX, y+directY, color, length+1, i, j);
                    if (nowLength == CHESS) return 5;
                }
            }
        }
    }
//    未获胜，如果是检查中途的棋子并且没获胜，继续递归
    else {
        if (this->board[x+directX][y+directY] == color)
            return this->check(x+directX, y+directY, color, length+1, directX, directY);
        else
            return 0;
    };
    return 0;
}

void Board::print(bool cur) {
    const string white=" ○ ", black =" ● ", cursor = " + ";
    const string LT   =" ┌ ", TOP   =" ┬ ", RT   =" ┐ ";
    const string LEFT =" ├ ", CENTER =" ┼ ", RIGHT=" ┤ ";
    const string LF   =" └ ", FOOT  =" ┴ ",  RF   =" ┘ ";
    const string SPACE="   ";

//    棋盘绘制初始化
    string display[2*SIZE+1][2*SIZE+1];
    for (int i = 0; i < 2 * SIZE + 1; i ++)
        for (int j = 0; j < 2 * SIZE + 1; j ++)
            display[i][j] = SPACE;

    display[0][0] = LT, display[0][2*SIZE] = RT, display[2*SIZE][0] = LF, display[2*SIZE][2*SIZE] = RF;
    for (int i = 2; i < 2 * SIZE; i += 2){
        display[0][i] = TOP, display[i][0] = LEFT, display[2*SIZE][i] = FOOT, display[i][2*SIZE] = RIGHT;
        for (int j = 2; j < 2 * SIZE; j += 2){
            display[i][j] = CENTER;
        }
    }
//    绘制棋子
    for (int i = 0; i < SIZE; i ++){
        for (int j = 0; j < SIZE; j ++){
            int piece = this->board[i][j];
            if (!piece) continue;
            else if (piece == WHITE) display[2*i+1][2*j+1] = white;
            else if (piece == BLACK) display[2*i+1][2*j+1] = black;
        }
    }

//    繪製光標
    if (cur) {
        int row = this->cursorPos[0], col = this->cursorPos[1];
        display[2 * row + 1][2 * col + 1] = cursor;
    }
//    输出
    for (int i = 0; i < 2 * SIZE + 1; i ++) {
        for (int j = 0; j < 2 * SIZE + 1; j++) {
            cout << display[i][j];
        }
        cout << endl;
    }
}

