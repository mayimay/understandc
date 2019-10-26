#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GAMER 5
// 标识比较结果的初始状态，不能是0 -1 或1
#define FINGER_NOT_COMPARE 99
#define FINGER_DRAW 0
#define FINGER_LOSE -1

char *fingerList[] = {"剪刀", "石头", "布"};
char *resultDisplayList[] = {"失败", "平局", "胜利"};
enum Flag {
    QUIT, CHOOSE, GUESSING, WIN
};

enum ParticipantStatus {
    READY, OUT
};
//      剪刀  石头  布
//剪刀    0    -1   1
//石头    1     0  -1
//布      -1   1    0
int fingerResult[3][3] = {{0,  -1, 1},
                          {1,  0,  -1},
                          {-1, 1,  0}};

enum Flag STATUS = CHOOSE;
int gamerTotal;
int gamerStatus[MAX_GAMER] = {READY};
int gamerFingers[MAX_GAMER] = {0};
int gamerCompareResult[MAX_GAMER] = {FINGER_NOT_COMPARE, FINGER_NOT_COMPARE, FINGER_NOT_COMPARE, FINGER_NOT_COMPARE,
                                     FINGER_NOT_COMPARE};

void chooseGamer();

int scanInt(int min, int max);

void fingerGuessing();

int getGamerLeft();

int randRange(int min, int max);

void fillFingers();

void compete();

int compareFinger(int first, int second);

int findFirstGamerIndex();

void printRoundResult();

char *transferFingerNames(int finger);

char *transferResultDisplay(int result);

void changeGamerStatus();

int checkWinner();

void changeFlow();

void initGamerStatus();

void setAllCompareResultToDraw();

void changeAllDrawRecordToCurCompareRlt(int curCompareRlt);

int sleep(unsigned long ms) {
    clock_t stampTime = clock(), currentTime;
    do {
        if ((currentTime = clock()) < stampTime) {
            //不应该出现这种情况
            return 0;
        }
    } while (1000ul * (currentTime - stampTime) / CLOCKS_PER_SEC < ms);
    return 1;
}

int main() {

    srand(time(NULL));

    // 1 待选择人数
    // 2 选人人数结束-开始猜拳的状态
    // 3 胜出状态
    // 0 退出
    printf("进入猜拳游戏！\n");
    while (1) {
        switch (STATUS) {
            case CHOOSE:
                // 选择人数
                chooseGamer();
                break;
            case GUESSING:
                if (checkWinner()) {
                    STATUS = WIN;
                    break;
                }
                fingerGuessing();
                break;
            case WIN:
                // 有一人胜出，进行选择继续还是退出，还是返回上一级
                changeFlow();
                break;
            case QUIT:
                return 0;
            default:
                break;
        }
    }
}

void changeFlow() {
    printf("请选择：0.退出游戏，1.继续，2.返回上一级\n请输入：");
    int rlt = scanInt(0, 2);
    switch (rlt) {
        case 0:
            STATUS = QUIT;
            break;
        case 1:
            initGamerStatus();
            STATUS = GUESSING;
            break;
        case 2:
            initGamerStatus();
            STATUS = CHOOSE;
            break;
        default:
            break;
    }
}

void initGamerStatus() {
    for (int i = 0; i < MAX_GAMER; ++i) {
        gamerStatus[i] = READY;
        gamerCompareResult[i] = FINGER_NOT_COMPARE;
    }
}

void fingerGuessing() {
    fillFingers();
    compete();
    printRoundResult();
    changeGamerStatus();
}

/**
 *
 * @return 1 有胜出的人  0 还没有胜出的人
 */
int checkWinner() {
    int totalLeft = getGamerLeft();
    // 如果就剩一个人，就是胜出
    if (totalLeft == 1) {
        for (int i = 0; i < gamerTotal; ++i) {
            if (gamerStatus[i] == READY) {
                if (i == 0) {
                    printf("获胜者是玩家\n");
                } else {
                    printf("获胜者是电脑%d\n", i);
                }
            }
        }
        return 1;
    }
    return 0;
}

void changeGamerStatus() {
    for (int i = 0; i < gamerTotal; i++) {
        if (gamerStatus[i] == READY) {
            if (gamerCompareResult[i] == FINGER_LOSE) {
                gamerStatus[i] = OUT;
            }
            gamerCompareResult[i] = FINGER_NOT_COMPARE;
        }
    }
}

void printRoundResult() {
    for (int i = 0; i < gamerTotal; ++i) {
        if (gamerStatus[i] == READY) {
            if (i == 0) {
                printf("你出了%s,%s\n", transferFingerNames(gamerFingers[i]),
                       transferResultDisplay(gamerCompareResult[i]));
            } else {

                printf("电脑%d 出了%s,%s\n", i, transferFingerNames(gamerFingers[i]),
                       transferResultDisplay(gamerCompareResult[i]));
                sleep(1000);
            }
        }
    }
}

char *transferResultDisplay(int result) {
    return resultDisplayList[result + 1];
}

char *transferFingerNames(int finger) {
    return fingerList[finger];
}

void compete() {
    int firstGamerIndex = findFirstGamerIndex();
    int firstGamerFinger = gamerFingers[firstGamerIndex];
    int curCompareRlt;
    for (int i = 0; i < gamerTotal; i++) {
        if (gamerStatus[i] == READY && firstGamerIndex != i) {
            curCompareRlt = compareFinger(firstGamerFinger, gamerFingers[i]);
            // 第一次比较
            if (gamerCompareResult[firstGamerIndex] == FINGER_NOT_COMPARE) {
                gamerCompareResult[firstGamerIndex] = curCompareRlt;
                gamerCompareResult[i] = -curCompareRlt;
            } else if (gamerCompareResult[firstGamerIndex] == FINGER_DRAW) {
                changeAllDrawRecordToCurCompareRlt(curCompareRlt);
                gamerCompareResult[i] = -curCompareRlt;
            } else {
                // 如果结果不一致，并且不是平局，说明出了三种情况，直接都置成平局
                if (gamerCompareResult[firstGamerIndex] != curCompareRlt && curCompareRlt != FINGER_DRAW) {
                    setAllCompareResultToDraw();
                    // 将所有的比较结果置为平局，之后结束本轮
                    return;
                } else if (curCompareRlt == FINGER_DRAW) {
                    // 如果先比较出了结果后，再次比较出平局，只需要对应位置和第一个人的结果保持一致
                    gamerCompareResult[i] = gamerCompareResult[firstGamerIndex];
                } else {
                    // 结果一致，就改变另一个人的结果即可
                    gamerCompareResult[i] = -curCompareRlt;
                }
            }
        }
    }
}

void changeAllDrawRecordToCurCompareRlt(int curCompareRlt) {
    for (int j = 0; j < gamerTotal; ++j) {
        if (gamerCompareResult[j] == FINGER_DRAW) {
            gamerCompareResult[j] = curCompareRlt;
        }
    }
}

void setAllCompareResultToDraw() {
    for (int j = 0; j < gamerTotal; ++j) {
        if (gamerStatus[j] == READY) {
            gamerCompareResult[j] = FINGER_DRAW;
        }
    }
}

int findFirstGamerIndex() {
    for (int i = 0; i < gamerTotal; ++i) {
        if (gamerStatus[i] == READY) {
            return i;
        }
    }
}

/**
 *
 * @param first 第一个人的出拳
 * @param second 第二个人的出拳
 * @return 如果first赢了返回1，输了返回-1，平局返回0
 */
int compareFinger(int first, int second) {
    return fingerResult[first][second];
}

void fillFingers() {
    // 进行猜拳并且展示结果
    printf("开始猜拳，人数:%d\n", getGamerLeft());
    if (gamerStatus[0] == READY) {
        printf("请输入（0.剪刀，1.石头，2.布）");
        gamerFingers[0] = scanInt(0, 2);
    }

    for (int i = 1; i < gamerTotal; ++i) {
        if (gamerStatus[i] == READY) {
            gamerFingers[i] = randRange(0, 2);
        }
    }
}

int randRange(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/**
 * 查询当前还有多少人需要比较
 * @return
 */
int getGamerLeft() {
    int totalLeft = 0;
    for (int i = 0; i < gamerTotal; ++i) {
        if (gamerStatus[i] != OUT) {
            totalLeft++;
        }
    }
    return totalLeft;
}

void chooseGamer() {
    printf("请输入进行猜拳的人数：（2~%d)\n0.退出游戏\n1.继续\n请输入：", MAX_GAMER);
    gamerTotal = scanInt(0, MAX_GAMER);

    if (gamerTotal == 0) {
        STATUS = QUIT;
        return;
    }
    if (gamerTotal == 1) {
        return chooseGamer();
    }

    for (int i = gamerTotal; i < MAX_GAMER; i++) {
        gamerStatus[i] = OUT;
    }
    STATUS = GUESSING;
}

int scanInt(int min, int max) {
    int rlt, input;
    do {
        rlt = scanf("%d", &input);
        if (rlt == 0) {
            printf("输入不合法");
        }
        if (input < min || input > max) {
            printf("输入范围不满足:(%d~%d)\n", min, max);
            printf("请重新输入:");
            rlt = 0;
        }
    } while (rlt == 0);

    return input;
}
