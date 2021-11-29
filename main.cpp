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
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
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

    for(i = 0; i < width + 1; i++)
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
    for(i = 0; i < width + 1; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout << "Rezultats: " << score << endl;
    cout << "Lai beigtu speli, spied taustinu x" << endl;
}

void Input()
{ 
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y, i, j;
    tailX[0] = snakeX;
    tailY[0] = snakeY;
    for(i = 1; i < lenTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(dir)
    {
        case LEFT:
            snakeX--;
            break;
        case RIGHT:
            snakeX++;
            break;
        case UP:
            snakeY--;
            break;
        case DOWN:
            snakeY++;
            break;
        default:
            break;
    }
    if(snakeX >= width)
    {
        snakeX = 0;
    }
    else if(snakeX < 0)
    {
        snakeX = width - 1;
    }
    if(snakeY >= height)
    {
        snakeY = 0;
    }
    else if(snakeY < 0)
    {
        snakeY = height - 1;
    } // ja čūska iziet no laukuma, tā parādās laukuma otrā galā

    for(i = 0; i < lenTail; i++)
    {
        if(tailX[i] == snakeX && tailY[i] == snakeY)
        {
            gameOver = true; // ja čūska ietriecas sevī, spēle beidzas
        }
    }

    if(snakeX == fruitX && snakeY == fruitY)
    // ja čūska tieši tajā laukumā, kur auglis, palielinām rezultātu, reģenerējam augli un pagarinām čūskas astes garumu
    {
        score += 1;
        fruitX = rand() % width;
        fruitY = rand() % height;
        lenTail++;
    }
}

int main()
{
    Initialize();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(10);
    }
    return 0;
}