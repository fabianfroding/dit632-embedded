/* ==================================== 
File name: exerc_3_1.c
Date: 2019-02-15
Group Number:02
Members that contributed:
Fabian
Oliver
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

typedef struct
{
    int xpos, ypos;
    enum DIRECTION dir;
} ROBOT;

void printRobot(ROBOT robot)
{
    printf("Robot is at [%d, %d] in direcetion %u\n\n", robot.xpos, robot.ypos, robot.dir);
}

void move(ROBOT robot)
{
    if (robot.dir == N)
    {
        robot.xpos++;
    }
    else if (robot.dir == O)
    {
        robot.ypos = robot.ypos++;
    }
    else if (robot.dir == S)
    {
        robot.xpos = robot.xpos--;
    }
    else if (robot.dir == W)
    {
        robot.ypos = robot.ypos--;
    }
}

void turn(ROBOT robot)
{
    if (robot.dir == N)
    {
        robot.dir = O;
    }
    else if (robot.dir == O)
    {
        robot.dir = S;
    }
    else if (robot.dir == S)
    {
        robot.dir = W;
    }
    else if (robot.dir == W)
    {
        robot.dir = N;
    }
}

int main()
{
    char player[10];
    printf("===========\nRobo\n===========\n*if you wish to quit at any point in the game, press 'q'*...\n--------------------------------------------------------------\n");
    ROBOT robot = {0, 0, N};
    do
    {
        printf("--> press 'm' to move and 't' to turn...\n\n");
        scanf("%s", &player);
        if (player[0] == 'm')
        {
            move(robot);
        }
        else if (player[0] == 't')
        {
            turn(robot);
        }
        if (player[0] == 't' || player[0] == 'm')
        {
            printf("[success] ");
            printRobot(robot);
        }
        else
        {
            printf("[error] you typed '%s'. press 'm' to move and 't' to turn...\n\n\n", player);
        }
    } while (player[0] != 'q');
}