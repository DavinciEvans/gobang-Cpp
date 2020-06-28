//
// Created by ZNSY on 2020/5/23.
//

#include "Simulation.h"
#include <iostream>
#include "LastOrder.h"
#include "board.h"
#include "Debug.h"
using namespace std;

Simulation::Simulation() {
    Debug debug;
    cout << "Is Simulation" << endl;
    debug.read();
}

void Simulation::print(int x) {
    cout << x << endl;
}
