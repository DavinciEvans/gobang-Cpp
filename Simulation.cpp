//
// Created by ZNSY on 2020/5/23.
//

#include "Simulation.h"
#include <iostream>
#include "LastOrder.h"
#include "board.h"
using namespace std;

Simulation::Simulation() {
    LastOrder ai = LastOrder();
    print(ai.chessStatus[1][1][1][0][0][3]);
    Board board = Board();
    board.board[3][3] = WHITE;
    board.board[4][4] = BLACK;
    board.board[3][2] = WHITE;
    board.board[3][4] = BLACK;
    board.board[4][3] = WHITE;
    board.board[5][4] = BLACK;
    board.board[2][4] = WHITE;
    board.board[6][4] = BLACK;
    board.board[7][4] = WHITE;
    board.board[5][3] = BLACK;
    board.board[4][2] = WHITE;
    board.print();
    this->print(ai.evaluation(board.board));
    Points p = ai.localSearch(board.board);
    for (int i = 0; i < AN; i ++) {
        cout << p.pos[i].x <<" " << p.pos[i].y << " " << p.score[i] << endl;
    }
}

void Simulation::print(int x) {
    cout << x << endl;
}
