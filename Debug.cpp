//
// Created by ZNSY on 2020/6/26.
//

#include "Debug.h"


//Debug 部分

void Debug::control() {
    int input;
    cout << "use b to enter debug mode.";
    while ((input = getch()) != 'l') {
        CLRSCR;
        cout << "____DEBUG MODE____" << endl;
        cout << "Move: W A S D" << endl;
        cout << "Compute: Space" << endl;
        cout << "History: Q E" << endl;
        int row = this->copyBoard.cursorPos[0], col = this->copyBoard.cursorPos[1];
        switch (input) {
            case 'w': {
                if (row - 1 >= 0) this->copyBoard.cursorPos[0]--;
                break;
            }
            case 's': {
                if (row + 1 < SIZE) this->copyBoard.cursorPos[0]++;
                break;
            }
            case 'a': {
                if (col - 1 >= 0) this->copyBoard.cursorPos[1]--;
                break;
            }
            case 'd': {
                if (col + 1 < SIZE) this->copyBoard.cursorPos[1]++;
                break;
            }
            case 'q': {
                this->timeControl(-1);
                break;
            }
            case 'e': {
                this->timeControl(1);
                break;
            }
            case ' ': {
                if (this->copyBoard.board[row][col] == 0) {
                    this->start(row, col);
                }
                else cout << "this position is not legal" << endl;
                break;
            }
            case 'r': {
                this->reverse();
                break;
            }
            case '1': {
                this->testPut(row, col, WHITE);
                break;
            }
            case '2': {
                this->testPut(row, col, BLACK);
                break;
            }
            default:
                break;
        }
        this->copyBoard.print(true);
    }
    CLRSCR;
}

void Debug::init(Board board) {
    this->copyBoard = board;
    this->turns = nowTurns - 1;
}

void Debug::start(int x, int y) {
    LastOrder debuger(true);
    cout << "Now Evaluation: " << debuger.evaluation(copyBoard.board) << endl;
    Points p = debuger.localSearch(copyBoard.board);
    for (int i = 0; i < AN; i ++) {
        cout << i << endl;
        cout << "x: " << p.pos[i].x << endl;
        cout << "y: " << p.pos[i].y << endl;
        cout << "score: " << p.score[i] << endl;
        cout << "_______" << endl;
    }
    copyBoard.board[x][y] = BLACK;
    cout << "If put black here, Evaluation: " << debuger.evaluation(copyBoard.board) << endl;
    copyBoard.board[x][y] = 0;
    debuger.maxMinSearch(copyBoard, DEPTH, INT_MIN, INT_MAX);
    cout << "decision: " << debuger.decision.pos.x << " " << debuger.decision.pos.y << endl;
}

void Debug::timeControl(int direct) {
    if (this->turns + direct < nowTurns || this->turns + direct >= 0) {
        if (direct == 1) {
            this->turns++;
            int x = this->history[turns][0];
            int y = this->history[turns][1];
            int color = this->history[turns][2];
            this->copyBoard.board[x][y] = color;
        }
        if (direct == -1) {
            int x = this->history[turns][0];
            int y = this->history[turns][1];
            this->copyBoard.board[x][y] = 0;
            this->turns--;
        }
    }
}

void Debug::save() {
    ofstream record;
    record.open("goBang-record.txt");
    for (int i = 0; i < nowTurns; i ++)
        record << history[i][0] << history[i][1] << history[i][2] << endl;
    record << "END" << endl;
    record.close();
}

Board Debug::read() {
    string readHistory, temp;
    ifstream record;
    Board readBoard;
    turns = 0;
    nowTurns = 0;
    memset(history, 0, sizeof(history));
    record.open("goBang-record.txt");
    while (true) {
        record >> readHistory;
        if (readHistory == "END") {
            break;
        }
        temp = readHistory[0];
        int x = stoi(temp);
        temp = readHistory[1];
        int y = stoi(temp);
        temp = readHistory[2];
        int color = stoi(temp);
        readBoard.place(x, y, color);
        history[turns][0] = x, history[turns][1] = y, history[turns][2] = color;
        turns ++;
        nowTurns ++;
    }
    return readBoard;
}

void Debug::testPut(int x, int y, int color) {
    bool put = copyBoard.place(x, y, color);
    if (!put)
        cout << "This position is illegal." << endl;
}

void Debug::reverse() {
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j < SIZE; j ++) {
            if (copyBoard.board[i][j])
                copyBoard.board[i][j] = copyBoard.board[i][j] == BLACK ? WHITE : BLACK;
        }
    }
}
