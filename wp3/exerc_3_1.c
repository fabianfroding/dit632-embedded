/* ==================================== 
File name: exerc_3_1.c
Date: 2019-02-15
Group Number:02
Members that contributed:
Oliver
Fabian
Demonstration code: [29413] 
====================================== */
#include <stdio.h>
enum DIRECTION
{
    N,
    O,
    S,
    W
};

typedef struct ROBOTS
{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

void printRobot(ROBOT robot)
{
    printf("Robot is at [%d, %d] in direcetion %u\n\n", robot.xpos, robot.ypos, robot.dir);
}

void move(ROBOT *pRobot)
{
    if ((*pRobot).dir == N)
    {
        (*pRobot).xpos++;
    }
    else if ((*pRobot).dir == O)
    {
        (*pRobot).ypos++;
    }
    else if ((*pRobot).dir == S)
    {
        (*pRobot).xpos--;
    }
    else if ((*pRobot).dir == W)
    {
        (*pRobot).ypos--;
    }
}

void turn(ROBOT *pRobot)
{
    if ((*pRobot).dir == N)
    {
        (*pRobot).dir = O;
    }
    else if ((*pRobot).dir == O)
    {
        (*pRobot).dir = S;
    }
    else if ((*pRobot).dir == S)
    {
        (*pRobot).dir = W;
    }
    else if ((*pRobot).dir == W)
    {
        (*pRobot).dir = N;
    }
}

int main()
{
    printf("===========\nRobo\n===========\n*if you wish to quit at any point in the game, press 'q'*...\n--------------------------------------------------------------\n");
    ROBOT robot = {0, 0, N};
    ROBOT *pRobot = NULL;
    pRobot = &robot;
    char journey[256];
    int x = -1, y = -1;
    do
    {
        printf("--> enter x-coordintae startpoint for Mr.Robot (0-100)\n");
        scanf("%d", &x);
        printf("--> enter y-coordintae startpoint for Mr.Robot (0-100)\n");
        scanf("%d", &y);
    } while ((100 < x || x < 0) || (100 < y || y < 0));

    printf("--> enter a string of 'm' to move and 't' to turn...\n");
    scanf("%s", &journey);
    int arrayLength = sizeof(journey) / sizeof(journey[0]);
    for (int i = 0; i < arrayLength; i++)
    {
        /* code */
        if (journey[i] == 'm')
        {
            printf("--> [MOVING!]\n");
            move(pRobot);
            printRobot(robot);
        }
        else if (journey[i] == 't')
        {
            turn(pRobot);
            printf("--> [Turning!]\n");
            printRobot(robot);
        }
    }

    printf("--> [Finally]");
    printRobot(robot);
}

/*
crucial to understand: https://stackoverflow.com/questions/18698317/pointers-as-function-arguments-in-c
*/