/* ==================================== 
File name: exerc_3_1.c
Date: 2019-02-15
Group Number:02
Members that contributed:
Oliver
Fabian
Demonstration code: [none] 
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
    char player[10];
    printf("===========\nRobo\n===========\n*if you wish to quit at any point in the game, press 'q'*...\n--------------------------------------------------------------\n");
    ROBOT robot = {0, 0, N};
    ROBOT *pRobot = NULL;
    pRobot = &robot;

    do
    {
        printf("--> press 'm' to move and 't' to turn...\n\n");
        scanf("%s", &player);
        if (player[0] == 'm')
        {
            move(pRobot);
        }
        else if (player[0] == 't')
        {
            turn(pRobot);
        }

        if (player[0] == 't' || player[0] == 'm')
        {
            printf("[success] ");
            printRobot(robot);
        }
        else if (player[0] == 'q')
        {
            printf("Robot says 'bye'");
        }
        else
        {
            printf("[error] you typed '%s'. press 'm' to move and 't' to turn...\n\n\n", player);
        }
    } while (player[0] != 'q');
}

/*
crucial to understand: https://stackoverflow.com/questions/18698317/pointers-as-function-arguments-in-c
*/