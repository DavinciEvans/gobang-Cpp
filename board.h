//
// Created by ZNSY on 2020/5/19.
//

#ifndef FIVE_CHESS_BOARD_H
#define FIVE_CHESS_BOARD_H
#define CHESS 5
//标准棋盘15
#define SIZE 15
#define WHITE 1
#define BLACK 2
#define AICOLOR 2
#define HUMCOLOR 1



class Board {
public:
    int win = 0;
    int board[SIZE][SIZE] = {{0}};
    int place(int x, int y, int color);
    int check(int x, int y, int color, int length, int directX, int directY);
    void print();
};


#endif //FIVE_CHESS_BOARD_H
