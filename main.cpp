#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;

void Initialize()
{
    gameOver = false;
    dir = STOP; // snake is "frozen"
    x = width / 2;
    y = height / 2; // places the snake in the middle of the field
    fruitX = rand() % width;
    fruitY = rand() % height; // places the fruit randomly within the field
    score = 0;
}

void Draw()
{
    
}
void Input()
{
    
}
void Logic()
{
    
}
int main()
{
    Initialize();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
    return 0;
}