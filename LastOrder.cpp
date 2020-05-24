//
// Created by ZNSY on 2020/5/23.
//

#include "LastOrder.h"

//棋型代号 下标 权重
#define OTHER 0//0
#define WIN 1//100000
#define LOSE 2//-10000000
#define FLEX4 3//50000
#define flex4 4//-100000
#define BLOCK4 5//400
#define block4 6//-100000
#define FLEX3 7//400
#define flex3 8//-8000
#define BLOCK3 9//20
#define block3 10//-50
#define FLEX2 11//20
#define flex2 12//-50
#define BLOCK2 13//1
#define block2 14//-3
#define FLEX1 15//1
#define flex1 16//-3

//白1，黑2，边界3
//电脑执黑

LastOrder::LastOrder() {
    this->init_chessStatus();
}

void LastOrder::init_chessStatus() {
    //黑连5,ai赢
    this->chessStatus[2][2][2][2][2][2]=WIN;
    this->chessStatus[2][2][2][2][2][0]=WIN;
    this->chessStatus[0][2][2][2][2][2]=WIN;
    this->chessStatus[2][2][2][2][2][1]=WIN;
    this->chessStatus[1][2][2][2][2][2]=WIN;
    this->chessStatus[3][2][2][2][2][2]=WIN;//边界考虑
    this->chessStatus[2][2][2][2][2][3]=WIN;
    //白连5,ai输
    this->chessStatus[1][1][1][1][1][1]=LOSE;
    this->chessStatus[1][1][1][1][1][0]=LOSE;
    this->chessStatus[0][1][1][1][1][1]=LOSE;
    this->chessStatus[1][1][1][1][1][2]=LOSE;
    this->chessStatus[2][1][1][1][1][1]=LOSE;
    this->chessStatus[3][1][1][1][1][1]=LOSE;
    this->chessStatus[1][1][1][1][1][3]=LOSE;
    //黑活4
    this->chessStatus[0][2][2][2][2][0]=FLEX4;
    //白活4
    this->chessStatus[0][1][1][1][1][0]=flex4;
    //黑活3
    this->chessStatus[0][2][2][2][0][0]=FLEX3;
    this->chessStatus[0][0][2][2][2][0]=FLEX3;
    this->chessStatus[0][2][0][2][2][0]=FLEX3;
    this->chessStatus[0][2][2][0][2][0]=FLEX3;
    //白活3
    this->chessStatus[0][1][1][1][0][0]=flex3;
    this->chessStatus[0][0][1][1][1][0]=flex3;
    this->chessStatus[0][1][0][1][1][0]=flex3;
    this->chessStatus[0][1][1][0][1][0]=flex3;
    //黑活2
    this->chessStatus[0][2][2][0][0][0]=FLEX2;
    this->chessStatus[0][2][0][2][0][0]=FLEX2;
    this->chessStatus[0][2][0][0][2][0]=FLEX2;
    this->chessStatus[0][0][2][2][0][0]=FLEX2;
    this->chessStatus[0][0][2][0][2][0]=FLEX2;
    this->chessStatus[0][0][0][2][2][0]=FLEX2;
    //白活2
    this->chessStatus[0][1][1][0][0][0]=flex2;
    this->chessStatus[0][1][0][1][0][0]=flex2;
    this->chessStatus[0][1][0][0][1][0]=flex2;
    this->chessStatus[0][0][1][1][0][0]=flex2;
    this->chessStatus[0][0][1][0][1][0]=flex2;
    this->chessStatus[0][0][0][1][1][0]=flex2;
    //黑活1
    this->chessStatus[0][2][0][0][0][0]=FLEX1;
    this->chessStatus[0][0][2][0][0][0]=FLEX1;
    this->chessStatus[0][0][0][2][0][0]=FLEX1;
    this->chessStatus[0][0][0][0][2][0]=FLEX1;
    //白活1
    this->chessStatus[0][1][0][0][0][0]=flex1;
    this->chessStatus[0][0][1][0][0][0]=flex1;
    this->chessStatus[0][0][0][1][0][0]=flex1;
    this->chessStatus[0][0][0][0][1][0]=flex1;

    int p1,p2,p3,p4,p5,p6,x,y,ix,iy;//x:左5中白个数,y:左5中黑个数,ix:右5中白个数,iy:右5中黑个数
    for(p1=0;p1<4;++p1){
        for(p2=0;p2<3;++p2){
            for(p3=0;p3<3;++p3){
                for(p4=0;p4<3;++p4){
                    for(p5=0;p5<3;++p5){
                        for(p6=0;p6<4;++p6){
                            x=y=ix=iy=0;

                            if(p1==1)x++;
                            else if(p1==2)y++;

                            if(p2==1){x++;ix++;}
                            else if(p2==2){y++;iy++;}

                            if(p3==1){x++;ix++;}
                            else if(p3==2){y++;iy++;}

                            if(p4==1){x++;ix++;}
                            else if(p4==2){y++;iy++;}

                            if(p5==1){x++;ix++;}
                            else if(p5==2){y++;iy++;}

                            if(p6==1)ix++;
                            else if(p6==2)iy++;

                            if(p1==3||p6==3){//有边界
                                if(p1==3&&p6!=3){//左边界
                                    //黑冲4
                                    if(ix==0&&iy==4){//若右边有空位是活4也没关系，因为活4权重远大于冲4，再加上冲4权重变化可以不计
                                        if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                            this->chessStatus[p1][p2][p3][p4][p5][p6]=BLOCK4;
                                    }
                                    //白冲4
                                    if(ix==4&&iy==0){
                                        if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                            this->chessStatus[p1][p2][p3][p4][p5][p6]=block4;
                                    }
                                    //黑眠3
                                    if(ix==0&&iy==3){
                                        if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                            this->chessStatus[p1][p2][p3][p4][p5][p6]=BLOCK3;
                                    }
                                    //白眠3
                                    if(ix==3&&iy==0){
                                        if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                            this->chessStatus[p1][p2][p3][p4][p5][p6]=block3;
                                    }
                                    //黑眠2
                                    if(ix==0&&iy==2){
                                        if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                            this->chessStatus[p1][p2][p3][p4][p5][p6]=BLOCK2;
                                    }
                                    //白眠2
                                    if(ix==2&&iy==0){
                                        if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                            this->chessStatus[p1][p2][p3][p4][p5][p6]=block2;
                                    }
                                }else if(p6==3&&p1!=3){//右边界
                                    //黑冲4
                                    if(x==0&&y==4){
                                        if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                            this->chessStatus[p1][p2][p3][p4][p5][p6]=BLOCK4;
                                    }
                                    //白冲4
                                    if(x==4&&y==0){
                                        if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                            this->chessStatus[p1][p2][p3][p4][p5][p6]=block4;
                                    }
                                    //黑眠3
                                    if(x==3&&y==0){
                                        if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                            this->chessStatus[p1][p2][p3][p4][p5][p6]=BLOCK3;
                                    }
                                    //白眠3
                                    if(x==0&&y==3){
                                        if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                            this->chessStatus[p1][p2][p3][p4][p5][p6]=block3;
                                    }
                                    //黑眠2
                                    if(x==2&&y==0){
                                        if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                            this->chessStatus[p1][p2][p3][p4][p5][p6]=BLOCK2;
                                    }
                                    //白眠2
                                    if(x==0&&y==2){
                                        if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                            this->chessStatus[p1][p2][p3][p4][p5][p6]=block2;
                                    }
                                }
                            }else{//无边界
                                //黑冲4
                                if((x==0&&y==4)||(ix==0&&iy==4)){
                                    if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                        this->chessStatus[p1][p2][p3][p4][p5][p6]=BLOCK4;
                                }
                                //白冲4
                                if((x==4&&y==0)||(ix==4&&iy==0)){
                                    if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                        this->chessStatus[p1][p2][p3][p4][p5][p6]=block4;
                                }
                                //黑眠3
                                if((x==0&&y==3)||(ix==0&&iy==3)){
                                    if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                        this->chessStatus[p1][p2][p3][p4][p5][p6]=BLOCK3;
                                }
                                //白眠3
                                if((x==3&&y==0)||(ix==3&&iy==0)){
                                    if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                        this->chessStatus[p1][p2][p3][p4][p5][p6]=block3;
                                }
                                //黑眠2
                                if((x==0&&y==2)||(ix==0&&iy==2)){
                                    if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                        this->chessStatus[p1][p2][p3][p4][p5][p6]=BLOCK2;
                                }
                                //白眠2
                                if((x==2&&y==0)||(ix==2&&iy==0)){
                                    if(this->chessStatus[p1][p2][p3][p4][p5][p6]==0)
                                        this->chessStatus[p1][p2][p3][p4][p5][p6]=block2;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int LastOrder::evaluation(int board[SIZE][SIZE]) {
//    权值
    int weight[17]={0,550000000,-100000000,50000,-1000000,400,-100000,400,-10000,20,-50,20,-50,1,-3,1,-3};
//    四个方向的棋形记录，每个位置对应一个权重值，如果包含一个该权重棋形则+1
    int shapeRecord[4][17] = {{0}};
//    大棋盘边界初始化
    int bigBoard[SIZE+2][SIZE+2] = {{0}};
    for (int i = 0; i < SIZE + 2; i ++) {
        bigBoard[0][i] = 3;
        bigBoard[i][0] = 3;
        bigBoard[SIZE+1][i] = 3;
        bigBoard[i][SIZE+1] = 3;
    }

//    棋盘复制
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j < SIZE; j++)
            bigBoard[i + 1][j + 1] = board[i][j];
    }

//    横向棋形统计
    for (int i = 1; i <= SIZE; i ++) {
        for (int j = 1; j < SIZE - 3; j++) {
            int type = this->chessStatus[bigBoard[i][j]][bigBoard[i][j+1]][bigBoard[i][j+2]][bigBoard[i][j+3]][bigBoard[i][j+4]][bigBoard[i][j+5]];
            shapeRecord[0][type] ++;
        }
    }
//    竖向棋形统计
    for (int i = 0; i < SIZE - 3; i ++) {
        for (int j = 1; j <= SIZE; j ++) {
            int type = this->chessStatus[bigBoard[i][j]][bigBoard[i+1][j]][bigBoard[i+2][j]][bigBoard[i+3][j]][bigBoard[i+4][j]][bigBoard[i+5][j]];
            shapeRecord[1][type] ++;
        }
    }
//    沿着左下→右上棋形统计
    for (int i = SIZE; i < SIZE - 3; i --) {
        for (int j = 0; j < SIZE - 3; j ++) {
            int type = this->chessStatus[bigBoard[i][j]][bigBoard[i-1][j+1]][bigBoard[i-2][j+2]][bigBoard[i-3][j+3]][bigBoard[i-4][j+4]][bigBoard[i-5][j+5]];
            shapeRecord[2][type] ++;
        }
    }
//    沿着右上→左下棋形统计
    for (int i = 0; i< SIZE - 3; i ++) {
        for (int j = 0; j < SIZE - 3; j ++) {
            int type = this->chessStatus[bigBoard[i][j]][bigBoard[i+1][j+1]][bigBoard[i+2][j+2]][bigBoard[i+3][j+3]][bigBoard[i+4][j+4]][bigBoard[i+5][j+5]];
            shapeRecord[3][type] ++;
        }
    }
//    分数统计
    int score = 0;
    int count = 0;
    for (int i = 0; i < 17; i ++) {
        score += weight[i] * shapeRecord[0][i] + weight[i] * shapeRecord[1][i] + weight[i] * shapeRecord[2][i] +
                 weight[i] * shapeRecord[3][i];
        count = shapeRecord[0][i] + shapeRecord[1][i] + shapeRecord[2][i] + shapeRecord[3][i];
    }
    return score;
}

void LastOrder::playChess(int board[SIZE][SIZE], int &x, int &y) {
//    建立临时棋盘用来落子
    int tempBoard[SIZE][SIZE];
    int myColor = this->aiColor;
    int score, highScore = -999999999;
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j < SIZE; j ++)
            tempBoard[i][j] = board[i][j];
    }
//    模拟落子并对落子后的局势进行评估
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j < SIZE; j ++) {
//            修改落子
//            如果有子，跳过
            if (tempBoard[i][j]) continue;
            tempBoard[i][j] = myColor;
            score = this->evaluation(tempBoard);
            if (score >= highScore) {
                highScore = score;
                x = i, y = j;
            }
//            还原
            tempBoard[i][j] = board[i][j];
        }
    }
}
