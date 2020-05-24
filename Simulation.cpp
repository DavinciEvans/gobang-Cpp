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
    print(ai.chessStatus[0][2][1][2][2][0]);
    Board board = Board();

}

void Simulation::print(int x) {
    cout << x << endl;
}
