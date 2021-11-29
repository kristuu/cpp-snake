#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int snakeX, snakeY, fruitX, fruitY, score;
int tailX[100], tailY[100];
int lenTail;
enum eDirecton {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;

void Initialize()
{
    gameOver = false;
    dir = STOP; // snake is "frozen"
    snakeX = width / 2;
    snakeY = height / 2; // places the snake in the middle of the field
    fruitX = rand() % width;
    fruitY = rand() % height; // places the fruit randomly within the field
    score = 0;
}

void Draw()
{
    int i, j, k;
    system("cls");

    for(i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            if(j == 0)
            {
                cout << "#";
            }
            else if(i == snakeY && j == snakeX)
            {
                cout << "O";
            }
            else if(i == fruitY && j == fruitX)
            {
                cout << "F";
            }
            else
            {
                bool printed = false;
                for(k = 0; k < lenTail; k++)
                {
                    if(tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        printed = true;
                    }
                }
                if(!printed)
                {
                    cout << " ";
                }
            }
            if(j == width - 1) // ja beidzamā vērtība rindā; -1, jo for loop sākam ar 0, bet platums definēts, skaitot no 1
            {
                cout << "#";
            }
        }
        cout << endl;
    }
    for(i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
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