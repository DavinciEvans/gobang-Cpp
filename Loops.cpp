//
// Created by ZNSY on 2020/5/20.
//
#include "Loops.h"

#define Windows

#ifdef Linux
#include<cstdio>
#include<cstdlib>
#include <termio.h>
#include<unistd.h>
#include<fcntl.h>
#define CLRSCR system("clear");
int kbhit();
int getch();
#endif

#ifdef Windows
#include<conio.h>
#define CLRSCR system("cls");
#endif

#ifdef Linux
int getch(void)                             ///LINUX special demand
{
    struct termios tm,tm_old;
    int fd=0,ch;
    if(tcgetattr(fd,&tm)<0) return -1;
    tm_old=tm;
    cfmakeraw(&tm);
    if(tcsetattr(fd,TCSANOW,&tm)<0) return -1;
    ch=getchar();
    if(tcsetattr(fd,TCSANOW,&tm_old)<0) return -1;
    return ch;
}

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO,&oldt);
    newt=oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&newt);
    oldf=fcntl(STDIN_FILENO,F_GETFL,0);
    fcntl(STDIN_FILENO,F_SETFL,oldf | O_NONBLOCK);
    ch=getchar();
    tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
    fcntl(STDIN_FILENO,F_SETFL,oldf);
    if(ch != EOF){ ungetc(ch,stdin); return 1; }
    return 0;
}
#endif


int Loops::control(int color, int &x, int &y) {
    int input;
    bool put = false;
    while (!put && (input = getch()) != 'q') {
        CLRSCR;
        int row = this->board.cursorPos[0], col = this->board.cursorPos[1];
        if (input == 'w' || input == 's' || input == 'a' || input == 'd' || input == ' ') {
            switch (input) {
                case 'w': {
                    if (row -1 >= 0) this->board.cursorPos[0] --;
                    break;
                }
                case 's': {
                    if (row + 1 < SIZE) this->board.cursorPos[0] ++;
                    break;
                }
                case 'a': {
                    if (col - 1 >= 0) this->board.cursorPos[1] --;
                    break;
                }
                case 'd': {
                    if (col + 1 < SIZE) this->board.cursorPos[1] ++;
                    break;
                }
                case ' ': {
                    if (this->board.place(row, col, color)) {
                        put = true;
                        x = row, y = col;
                        break;
                    }
                    else cout << "this position is not legal" << endl;
                    break;
                }
                default: break;
            }
        }
        this->board.print(true);
        this->messages(color, x, y);

    }
    if (input == 'q') {
        CLRSCR;
        exit(1);
    }
    return 1;
};

void Loops::games() {
    int nowColor = firstHand;
    int posX, posY;
    LastOrder lastOrder;
    CLRSCR;
    while (!this->board.win || this->turns == SIZE * SIZE) {
        if (nowColor == lastOrder.aiColor) {
            this->board.print(false);
            this->messages(nowColor, posX, posY);
            cout << endl;
            cout << "Last Order is thinking..." << endl;
            lastOrder.playChess(this->board.board, posX, posY);
            this->board.place(posX, posY, lastOrder.aiColor);
            CLRSCR;
        }
        else {
            this->board.print(true);
            this->messages(nowColor, posX, posY);
            this->control(nowColor, posX, posY);
            CLRSCR;
        }
        this->allCheck();
        this->turns ++;
        nowColor = nowColor == WHITE ? BLACK : WHITE;
    }
    cout << "- - - - - - - - - - - - - - " << endl;
    this->board.print(false);
    if (this->turns == SIZE * SIZE) cout << "There are no positions to put the chess, it is tie.";
    if (board.win == WHITE) cout << "White get the champion!!" << endl;
    else cout << "Black get the champion!!" << endl << endl;
    cout << "Game over" << endl << endl;
    cout << "print any key to exit." << endl;
    getch();
    CLRSCR;
    exit(1);
}

void Loops::messages(int color, int &x, int &y) {
    cout << "- - - - - - - - - - - - - - " << endl;
    if (this->turns == 1) {
        cout << "Game Start" << endl;
        cout << "Use w a s d to control the cursor,use space to put the chess , use q to exit." << endl;
    }
    cout << endl;
    if (color == 1)
        cout << "White turn" << endl;
    else cout << "Black turn" << endl;
    cout << endl;
}

void Loops::allCheck() {
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j < SIZE; j ++) {
            if (!this->board.board[i][j]) continue;
            else this->board.check(i, j, this->board.board[i][j], 0, 0, 0);
        }
    }
}
