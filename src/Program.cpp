/*Learning OOP with the help of game "Snake"
//Coming soon:
    choose difficulty - speed;
    window with results after defeat;
    leaderboard;
+   various sizes of field for snake;
    opportunity to enter to the wall and exit on another side;

//Bugfix:
    why method 'Eat()' in class 'Snake' works unconstantly?

*/

#include "Program.h"

using namespace std;

int main(int argc, char** args)
{
    //Setting the resolution of console
    HANDLE hWin = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = {0, 0};

    cout << "Enter the size of gaming field" << endl
        << "x: ";
    cin >> bufferSize.X;
    cout << "y: ";
    cin >> bufferSize.Y;

    for (int j = 1; j < 3; j++) //Clear letttering
    {
        for (int i = 1; i < 5; i++)
        {
            COORD clear = { i, j };
            SetConsoleCursorPosition(hWin, clear);
            cout << ' ';
        }
    }

    SMALL_RECT src = { 0, 0, bufferSize.X - 1, bufferSize.Y - 1};
    SetConsoleWindowInfo(hWin, true, &src);
    SetConsoleScreenBufferSize(hWin, bufferSize);

    //Drawing the frame
    Walls walls(bufferSize.X, bufferSize.Y);
    walls.Draw();

    //Creating the snake
    point tall(4, 5, '*');
    Snake snake(tall, 4, RIGHT);
    snake.Draw();
    snake.Move();

    FoodCreator foodCreator(bufferSize.X - 1, bufferSize.Y - 1, '$');
    point food = foodCreator.CreateFood();
    food.Draw();

    while (true)
    {
        if (walls.IsHit(snake) || snake.IsHitTail()) break;
        
        if (snake.Eat(&food))
        {
            food = foodCreator.CreateFood();
            food.Draw();
        }

        //Difficulty - speed only

        Sleep(100);

        if (_kbhit())
        {
            snake.Behavior();
            while (_kbhit()) _getch();
        }
        
        snake.Move();
    }

    _getch(); //The delay of the console window
    return 0;
}