#include <iostream>
#include "Loops.h"
#include "LastOrder.h"
#include "Simulation.h"
using namespace std;

int main() {
//    Simulation s = Simulation();
    LastOrder chessAI = LastOrder();
    Loops loop = Loops();
    loop.games();
}
